#include <iostream>
#include <vector>

int solution(int size, std::vector<int> stations, int range)
{
    auto count = 0;
    auto current_station_idx = 0;   // 현재 기지국의 인덱스
    auto current_location = 1;      // 현재 위치

    while (current_location <= size)
    {
        // 현재 기지국이 범위 외부에 있다면 
        if (current_station_idx < stations.size() and current_location >= stations[current_station_idx] - range)
        {
            // 현재 스테이션의 범위 외부로 이동한다.
            current_location = stations[current_station_idx] + range + 1;
            current_station_idx++;
        }
        // 현재 기지국이 범위 내부에 있다면
        else
        {
            // 현재 위치에 기지국을 깔고 범위 외부로 이동한다.
            current_location += 2 * range + 1;
            count++;
        }
    }

    return count;
}