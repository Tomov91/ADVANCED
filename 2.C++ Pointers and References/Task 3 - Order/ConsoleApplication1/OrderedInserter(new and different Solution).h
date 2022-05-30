#pragma once
#include<algorithm>
bool byID(const Company* a, const Company* b) { return a->getId() < b->getId(); }

class OrderedInserter {
public:
	std::vector<const Company*>& companies;

	void insert(const Company* c) {
		this->companies.push_back(c);

		std::sort(companies.begin(), companies.end(), byID); // [] ( const auto& a , const auto& b) { return a.Id() < b.Id(); }
		
	}
};