#ifndef Parser_H
#define Parser_H

#include <iostream>
#include <string>
#include <sstream>

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

#endif // !Parser_