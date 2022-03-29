
#pragma once
#include<iostream>
#include<vector>
#include <utility>
#include <memory>

#include "Company.h"

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& input)
{
	std::vector<std::pair<char, char>> tempPairs;
	for (size_t i = 2; i < input.size(); i++)
	{
		tempPairs.push_back(std::make_pair(input[i][0], input[i][1]));
	}

	std::shared_ptr<Company> obj(new Company(std::stoi(input[0]), input[1], tempPairs));

	return obj;
}

