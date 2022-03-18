#pragma once
#ifndef TRYPARSE_H
#define TRYPARSE_H
#include<iostream>
using namespace std;
bool tryParse(string& smh, int& a) {
	if (isalpha(smh[0])) {
		return false;
	}
		a = stoi(smh);
		return true;
}

#endif // !TRYPARSE_H
