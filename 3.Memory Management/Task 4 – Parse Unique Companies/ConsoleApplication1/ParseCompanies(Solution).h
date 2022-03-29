#pragma once
#ifndef MAKECOMPANY_H
#define MAKECOMPANY_H


#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "Company.h"
#include<sstream>
Company* parseUniqueCompanies(std::string input, int& numCompanies, std::string(*uniqueArg)(const Company& c))
{

	std::stringstream str(input);
	std::string tempStr;

	std::vector<std::string> companies;

	while (str >> tempStr)
	{
		companies.push_back(tempStr);
	}

	std::vector<std::string>tempVec;

	for (size_t i = 0; i < companies.size(); i += 2)
	{
		Company tempComp = Company(std::stoi(companies[i]), companies[i + 1]);
		if (!(std::find(tempVec.begin(), tempVec.end(), uniqueArg(tempComp)) != tempVec.end()))
		{
			tempVec.push_back(companies[i]);
			tempVec.push_back(companies[i + 1]);
		}
	}

	numCompanies = tempVec.size() / 2;


	Company* returnPtr = new Company[numCompanies];
	int index = 0;
	for (size_t i = 0; i < tempVec.size(); i += 2)
	{
		returnPtr[index] = Company(std::stoi(tempVec[i]), tempVec[i + 1]);
		index++;
	}

	return returnPtr;
}

#endif // !MAKECOMPANY_H