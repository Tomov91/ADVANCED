#ifndef OPERATORS_H
#define OPERATORS_H
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
std::vector<std::string>& operator<<( std::vector<std::string>& myvec, const std::string line) {

	std::stringstream str(line);
	
	myvec.push_back(str.str());

	return myvec;
}

void operator<<(std::ostream& COUT, std::vector<std::string>& myVec) {
	for (const auto s : myVec) {
		COUT << s << std::endl;
		//return COUT;
		
	}
}

std::string& operator<<(std::string& left,std::string& right){
	
	return left += right;
}

std::string operator+(std::string& addStr, const int num) {
	
	return addStr+=std::to_string(num);
}
#endif // !OPERATORS_H
