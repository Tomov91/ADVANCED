
#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H
#include<vector>
#include<string>

std::vector<std::string> operator+(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
	std::vector<std::string> answer;
	std::string input;

	for (size_t i = 0; i < a.size(); i++)
	{
		input += a[i];
		input += " ";
		input += b[i];
		answer.emplace_back(input);
		input.clear();
	}

	return answer;
}

#endif // !SUMOFVECTORS_H
