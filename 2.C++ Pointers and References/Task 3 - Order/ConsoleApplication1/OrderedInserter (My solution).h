#pragma once
#ifndef ORDERINSERTER_H
#define ORDERINSERTER_H
#include<vector>
#include<iostream>
using namespace std;

class OrderedInserter {
private:
	vector<const Company*>& companies;
public:
	OrderedInserter(vector<const Company*>& companies): 
		companies(companies){
	}

	void insert(const Company* comp) {
		if (companies.empty()) {
			companies.push_back(comp);
		}
		for (auto it = companies.begin(); it != companies.end();it++) {
			if (comp->getId() < (*it)->getId()) {
				companies.insert(it, comp);
				break;
			}
		}
	}
};

#endif // !ORDERINSERTER
