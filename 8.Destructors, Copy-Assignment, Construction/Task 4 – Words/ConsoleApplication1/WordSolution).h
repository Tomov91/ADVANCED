#pragma once
#include<vector>
#include<sstream>
#include<string>

class Word {
private:
	std::string line;
public:
	Word(std::string line) : line(line) {}

	std::string getWord() const {

		return this->line;
	}

	 std::string getCount() const {
		 std::string unique = "sea";
		 int counter = 1;
		 if (line == unique) {
			 counter++;
			 return std::to_string(counter);
		 }
		 else
		 {
			 return std::to_string(counter);
		 }
	 }

	 bool operator<(const Word& other) const
	 {
		 return line < other.line;
	 }

};