#pragma once

#include<string>
#include<sstream>
#include<set>

template <typename T>
class Parser
{
private:
	std::istream& m_line;
	std::string& m_stopLine;
	std::string m_currentString;
public:

	Parser(std::istream& LINE, std::string& stopLine) : m_line(LINE), m_stopLine(stopLine) {}

	bool readNext(T& element)
	{
		std::cin >> element;
		std::stringstream stream;
		stream << element;
		stream >> m_currentString;

		if (stream.str() == this->m_stopLine)
		{
			return false;
		}
		return true;
	}
};
template<typename P>
struct LessThan
{
	bool operator()(P& a,P& b) {
		return a < b;
	}
};
template<typename S, typename Comp>
class Reverse {
public:
	bool operator()(const S& a, S& b) {
		return Comp()(b, a);
	}
};

