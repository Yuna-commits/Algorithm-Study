#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

auto vowels = std::vector<char>{ 'a', 'e', 'i', 'o', 'u' };

auto password_length = 0, alphabet_count = 0;

void dfs(const std::vector<char>& alphabet_vector, int now, std::string password
									, int vowel_count, int consonant_count)
{
	password.push_back(alphabet_vector[now]);

	if (std::find(vowels.begin(), vowels.end(), alphabet_vector[now]) != vowels.end())
		vowel_count++;
	else
		consonant_count++;

	if (password.length() == password_length)
	{
		if (vowel_count >= 1 and consonant_count >= 2)
			std::cout << password << '\n';
		
		return;
	}

	for (auto i = now + 1; i < alphabet_count; i++)
		dfs(alphabet_vector, i, password, vowel_count, consonant_count);
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> password_length >> alphabet_count;

	auto alphabet_vector = std::vector<char>(alphabet_count);
	for (auto i = 0; i < alphabet_count; i++)
		std::cin >> alphabet_vector[i];

	std::sort(alphabet_vector.begin(), alphabet_vector.end());

	for (auto i = 0; i < alphabet_count; i++)
		dfs(alphabet_vector, i, "", 0, 0);

	return 0;
}