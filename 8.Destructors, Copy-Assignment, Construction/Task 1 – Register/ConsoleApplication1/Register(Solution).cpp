#include "Register.h"
#include "Company.h"
#include<algorithm>
#include <string>
#include<sstream>
#include<memory>
#include<iostream>
Register::Register(size_t numCompanies)
{
	numAdded = 0,
	this->companiesArray = new Company[numCompanies];
}


void Register::add(const Company& c)
{
		companiesArray[numAdded] = c;
		++numAdded;
}

Company Register::get(int companyId) const
{
	std::stringstream str;
	Company c;
	int i = 0;
	while (true)
	{
		if (companiesArray[i].getId() == companyId) {
			str << companiesArray[i];
			str >> c;
			return c;
		}
		else
		{
			i++;
		}
	}
}

Register::~Register()
{
	delete[] this->companiesArray;
}
