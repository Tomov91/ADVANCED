#pragma once
#include<vector>
#include<list>

class ArrayOfPointers {
private:
	std::vector<Company> myVec;
public:
	ArrayOfPointers() {
		this->myVec = myVec;
	}
	//ArrayOfPointers(std::vector<Company> myVec) : myVec(myVec) {}

	void add(const Company* c) {
		 myVec.emplace_back(*c);
	}
	int getSize() {
		return myVec.size();
	}
	Company* get(const size_t n) {
		
		Company* comp = &myVec[n];
		return comp;
	}
};