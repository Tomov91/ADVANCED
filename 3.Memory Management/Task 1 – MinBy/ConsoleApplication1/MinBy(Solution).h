#ifndef MinBy
#define MinBy
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
std::string minBy(std::vector<std::string>& values, bool func(const std::string& a, const std::string& b))
{
	std::sort(values.begin(), values.end(), func);

	return values[0];
}

#endif // !MinBy
	
