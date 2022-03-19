#pragma once
#ifndef FIND_H
#define FIND_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
acme 424242420
itjoro 878968302
softuni_foundation 20140414
end
878968302

*/

Company* find(vector<Company*>& myVec, const int& find) {
	//vector<Company*>::const_iterator it = find_if(myVec.begin(),myVec.end(),[&](Company* comp){comp return})	
	// [](Company* comp) {}
	
	for (Company* &ptr : myVec) {
		if (ptr->getId() == find) {
			return ptr;
		}
	}
	return nullptr;
	
}

#endif // !FIND_H
