#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
template<typename T>
class TypedStream {
protected:
	std::string line;
	std::stringstream stream;
public:
	TypedStream(const std::string& line) :line(line) {}

	virtual TypedStream<T>& operator>>(T& i) = 0;

	std::string readToEnd() {
		std::string temp;
		this->line.erase(std::remove(this->line.begin(), this->line.end(), '\n'), this->line.end());
		//std::istringstream str();
		return line;
	}
	/*	std::vector<T> readToEnd()
	{
		T curr;
		std::vector<T>result;

		while (this->operator>>(curr).stream.good())
		{
			result.push_back(curr);
		}

		return result;
	}*/
};