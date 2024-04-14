#include <string>
#include <vector>
#include <unordered_map>

bool solution(std::vector<std::string> phone_book) 
{
	// 전화번호부에 등록되어 있는 전화번호를 키값으로 모두 true로 설정한다.
	auto number_exist = std::unordered_map<std::string, bool>();
	for (auto& number : phone_book)
		number_exist[number] = true;

	// 각 전화번호의 길이만큼 문자열을 증가해가며 해시테이블과 비교한다.
	for (auto& number : phone_book)
		for (auto i = 0; i < number.size(); i++)
			if (number_exist[std::string(number.begin(), number.begin() + i)])
				return false;

	return true;
}