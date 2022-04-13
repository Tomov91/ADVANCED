#pragma once
#ifndef SPLIT_H
#define SPLIT_H
#include<vector>
#include<sstream>
#include<string>
template<typename T>
std::vector<T> split(std::string& line, char& separator) {
	std::vector<T> result;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == separator) {
			line[i] = ' ';
		}
	}
	std::stringstream str(line);
	T current;
	while (str >> current)
	{
		result.emplace_back(current);
	}
		return result;
}

#endif // !SPLIT_H
