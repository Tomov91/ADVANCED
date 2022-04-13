#pragma once
#ifndef JOIN_H
#define JOIN_H
#include"Split.h"
#include<sstream>
template<typename T>
std::string join(std::vector<T>& song, std::string joinstr) {
	std::ostringstream ostr;
	for (const auto& obj : song){
		ostr << obj;
		ostr << joinstr;
	}
	return ostr.str();
}

#endif // !JOIN_H
