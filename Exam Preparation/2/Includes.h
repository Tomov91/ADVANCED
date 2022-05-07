#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <vector>
#include <iostream>
#include <istream>

#include "City.h"
#include "CityDiff.h"


std::istream & operator>>(std::istream & stream, City & city)
{
    unsigned int censusYear;
    std::string name;
    size_t population;

    stream >> name >> population >> censusYear;

    city = City(censusYear, name, population);

    return stream;
}

CityDiff operator-(const City & left, const City & right)
{
    return CityDiff(left, right);
}



#endif /* INCLUDES_H_ */
