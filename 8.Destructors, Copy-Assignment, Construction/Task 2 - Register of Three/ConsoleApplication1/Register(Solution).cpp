#include"Company.h"
#include"Register.h"
#include<sstream>
#include<string>
#include<vector>

std::vector<Company> myVec;

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}


void Register:: add(const Company& c) {

	this->companiesArray[this->numAdded] = c;
	
	myVec.push_back(companiesArray[numAdded]);
	numAdded++;
	
}

Company Register::get(int companyId) const {

	std::vector<Company>::iterator it;
	
	for (it = myVec.begin(); it != myVec.end(); it++) {
		if (it->getId() == companyId) {
			return *it;
		}
	}
	
}

Register& Register::operator=(const Register& other) {

	if (this != &other) {
		if (this->companiesArray != nullptr) {
			delete[] this->companiesArray;
		}

		this->numAdded = other.numAdded;
		this->companiesArray = new Company[other.numAdded];

		int arrSize = (size_t)other.numAdded;
		for (int i = 0; i < arrSize; ++i) {
			this->companiesArray[i] = other.companiesArray[i];
		}
	}
	return *this;
}

Register::~Register() {
	delete[]  this->companiesArray;
}
