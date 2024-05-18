import java.text.SimpleDateFormat;
import java.time.LocalTime;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Soluti sol = new Soluti();

        sol.solution(new int[]{1, 461, 1, 10},
                new String[]{"00:00 1234 IN"});
    }
}

class Soluti {
    List<List<String>> recordList; // records를 각 색인 별로 나누어서 담아놓은 리스트

    Map<String, Integer> inTimeSum; // 차량 번호로 입차 시간의 합
    Map<String, Integer> outTimeSum; // 차량 번호로 출차 시간의 합
    Map<String, Integer> accumulParkTime; // 차량 번호로 총 누적 주차 시간 합
    Map<String, Integer> feeByCarNum; // 차량 번호로 주차 금액

    int baseFee;
    int baseTime;
    int extraFee;
    int extraTime;

    public int[] solution(int[] fees, String[] records) {
        recordList = new ArrayList<>();

        baseTime = fees[0];
        baseFee = fees[1];
        extraTime = fees[2];
        extraFee = fees[3];

        // 기록 값 String -> 유효 정보로 변환
        for (String record : records) {
            recordList.add(Arrays.stream(record.split(" ")).toList());
        }

        // 차량 번호로 우선 오름차순 정렬, 차량 번호가 같다면 시각 순으로 오름차순 정렬
        recordList.sort((o1, o2) -> {
            if (Integer.parseInt(o1.get(1)) < Integer.parseInt(o2.get(1))) return -1;
            else if (Integer.parseInt(o1.get(1)) > Integer.parseInt(o2.get(1))) return 1;
            else {
                return o1.get(0).compareTo(o2.get(0));
            }
        });

        recordList.forEach(System.out::println);

        inTimeSum = new HashMap<>();
        outTimeSum = new HashMap<>();

        // 각 차량 번호로 입차 시간의 합 그리고 출차 시간의 합 구하기
        for (List<String> record : recordList) {
            if (record.get(2).equals("IN")) { // 입차라면
                if (inTimeSum.containsKey(record.get(1))) { // 차가 등록되어 있다면 기존 입차 시간에 새로운 입차 시간 더하기
                    inTimeSum.put(record.get(1), inTimeSum.get(record.get(1)) + timeTrans(record.get(0)));
                } else { // 차량 번호가 없다면 새로운 입차 시간 등록
                    inTimeSum.put(record.get(1), timeTrans(record.get(0)));
                }
            } else if (record.get(2).equals("OUT")) { // 출차일 때의 경우
                if (outTimeSum.containsKey(record.get(1))) {
                    outTimeSum.put(record.get(1), outTimeSum.get(record.get(1)) + timeTrans(record.get(0)));
                } else {
                    outTimeSum.put(record.get(1), timeTrans(record.get(0)));
                }
            }
        }

        Set<String> carNumSet;
        carNumSet = inTimeSum.keySet();

        // 입차와 출차 시간을 비교해서 마지막 출차가 없다면 23:59 을 출차에 넣기
        for (String carNum : carNumSet) { // 차량 번호로 조회하면서
            int inTotal = inTimeSum.get(carNum);

            outTimeSum.putIfAbsent(carNum, 0); // 입차만 있고 출차는 없다면 출차 값 0으로 임시 초기화
            int outTotal = outTimeSum.get(carNum);

            if (inTotal >= outTotal) { // 마지막에 출차가 없다면(무조건 입차가 큼, 등호는 00:00에 입차하고 출차가 없을 때의 경우 방지)
                outTimeSum.put(carNum, outTimeSum.get(carNum) + timeTrans("23:59")); // 23:59 출차 시간 더해버리기
            }
        }

        accumulParkTime = new HashMap<>();

        // 출차 시간 - 입차 시간을 통해 총 주차 누적 시간 구하기
        for (String carNum : carNumSet) {
            accumulParkTime.put(carNum, outTimeSum.get(carNum) - inTimeSum.get(carNum));
            System.out.println(carNum + " : " + accumulParkTime.get(carNum));
        }

        feeByCarNum = new HashMap<>();
        // 주차 누적시간을 통해 feeCalculate 메소드로 주차 금액 구하기
        for (String carNum : carNumSet) {
            feeByCarNum.put(carNum, feeCalculate(accumulParkTime.get(carNum)));
            System.out.println(feeByCarNum.get(carNum));
        }

        // 주차 금액 자료구조는 Map 이기 때문에 정렬 필요 -> List로 변환 후 정렬
        List<String> keySet = new ArrayList<>(accumulParkTime.keySet());
        Collections.sort(keySet);

        List<Integer> feeList = new ArrayList<>();


        for(String key : keySet) {
            feeList.add(feeByCarNum.get(key));
        }

        return feeList.stream().mapToInt(i -> i).toArray();

    }

    public int timeTrans(String time) {
        String[] timeList = time.split(":");

        int hour = Integer.parseInt(timeList[0]);
        int minute = Integer.parseInt(timeList[1]);

        return hour * 60 + minute;
    }

    public int feeCalculate(int time) {
        if (time <= baseTime) { return baseFee; }

        time = time - baseTime;
        if(time % extraTime == 0) { return baseFee + ((time/extraTime) * extraFee); }
        else { return baseFee + ((time/extraTime + 1) * extraFee); }
    }
}
