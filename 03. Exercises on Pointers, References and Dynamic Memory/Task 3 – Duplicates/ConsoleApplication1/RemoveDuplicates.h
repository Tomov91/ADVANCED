#pragma once
#ifndef REMOVEDUPLICATES_H
#define REMOVEDUPLICATES_H
#include<string>
#include<set>
#include"Company.h"

// The program has memory leak because of the skeleton!

void removeDuplicates(std::list<Company*>& companies) {
	std::set<std::string> uniqueCompanies;
	std::string currCompanyName;
	for (std::list<Company*>::iterator it = companies.begin(); it != companies.end();) {
		currCompanyName = (*it)->getName();
		if (uniqueCompanies.find(currCompanyName) == uniqueCompanies.end()) {
			uniqueCompanies.insert(currCompanyName);
			++it;
		}else{
		//	delete (*it);
			it = companies.erase(it);
			//duplicate
		}
	}
}

#endif // !REMOVEDUPLICATES_H
