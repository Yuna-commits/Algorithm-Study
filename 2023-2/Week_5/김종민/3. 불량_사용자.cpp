// 아이디어1: *이 등장하는 인덱스를 저장한 다음에 유저 아이디를 *과 마스킹하여 비교하는건?
// - 시간 복잡도: O(n^3)
// - 문제점: 비슷한 아이디를 가진 유저가 있는 경우 처리를 못함

// 아이디어2: 비슷한 아이디를 가진 유저가 있는 경우만 처리를 해보려고 플래그 해시테이블 생성
// - 시간 복잡도: O(n^3)
// - 문제점: 이번에는 *****와 같이 *로만 구성된 경우를 처리하지 못함

// 아이디어3: 
// 1. 문자열 길이에 따른 범위 조정
// 2. 길이가 일치한다면 *이 아닌 인덱스와 비교?
// 3. 아니면 continue
// 여전히 중복 문제가 존재

// 아이디어4: 중복 해결이 문제라면 set?
// std::next_permutation을 사용하여 순열을 만들고
// 이를 set에 넣어서 중복체크를 하면?

#include <string>
#include <vector>
#include <algorithm>
#include <set>

std::set<std::string> id_list;

bool check(const std::string& user, const std::string& ban)
{
	// 불량 사용자와 사용자의 ID 길이가 일치하는 경우
	if (user.length() == ban.length())
		for (auto i = 0; i < user.length(); i++)
		{
			// banned_id에 *이 있거나 문자가 일치하면 패스
			if (ban[i] == '*' or user[i] == ban[i])
				continue;
			return false;
		}
	else
		return false;
	return true;
}

int solution(std::vector<std::string> user_id, std::vector<std::string> banned_id)
{
	// 중복 경우를 제외하기 위한 set 선언
	auto id_list = std::set<std::string>();

	// std::next_permutation을 사용하기 위해서는 오름차순 정렬이 필수
	std::sort(user_id.begin(), user_id.end());
	do
	{
		auto temp = std::vector<std::string>();
		auto id = std::string("");

		// 조건을 만족하는 id의 경우에만 탐색 진행
		for (auto i = 0; i < banned_id.size(); i++)
			if (check(user_id[i], banned_id[i]))
				temp.push_back(user_id[i]);

		// banned_id의 크기만큼만 선택
		if (temp.size() == banned_id.size())
		{
			std::sort(temp.begin(), temp.end());
			for (const auto& element : temp)
				id += element;
			id_list.insert(id);
		}
	} while (std::next_permutation(user_id.begin(), user_id.end()));

	auto answer = static_cast<int>(id_list.size());
	return answer;
}