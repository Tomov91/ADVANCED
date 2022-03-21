#pragma once
#ifndef ProfitReport_H
#define ProfitReport_H
#include "Company.h"
#include "ProfitCalculator.h"
#include<vector>
#include<iostream>
#include<tuple>
using namespace std;

string getProfitReport(Company* compUno,Company* compDuo, map<int, ProfitCalculator>& myMap) {
	string s;
	string space = " = ";
	string answer;
	stringstream getIN;
	ostringstream ostr;
	tuple<string, string, string> myVec;
	int temp = myMap.size();
	Company* ptr = compUno;

	while (temp--){
		for (map<int, ProfitCalculator>::iterator it = myMap.begin(); it != myMap.end(); it++) {

			if (ptr->getId() == it->first) {
				ostr << ptr->getName();
				ostr << space;
				ostr << it->second.calculateProfit(*ptr);
				ostr << '\n';
				
			}
		}
		ptr++;
	}
	return ostr.str();
}

#endif // !ProfitReport_H
