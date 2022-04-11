#include"Article13Filter.h"
#include<set>
#include<iostream>
#include<vector>
#include<string>




Article13Filter::Article13Filter(std::set<std::string> copyrighted):copyrighted(copyrighted) {};
	


	bool Article13Filter::blockIfCopyrighted ( std::string s) {
		std::set<std::string>::iterator it;
		for (it = copyrighted.begin(); it != copyrighted.end(); it++) {
			if ((*it) == s) {
				blocked.push_back(*it);
				return true;
			}
		}
		return false;
	}

	bool Article13Filter::isCopyrighted(std::string s){
		return true;
	}

	std::vector<std::string> Article13Filter::getBlocked() {
	
		return this->blocked;
	
	}
	
