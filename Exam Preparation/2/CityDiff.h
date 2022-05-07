#ifndef CITYDIFF_H_
#define CITYDIFF_H_

#include "City.h"

#include <ostream>

class CityDiff
{
    public:
        CityDiff(const City & first, const City & second);
        ~CityDiff();

        friend std::ostream & operator<<(std::ostream & stream, CityDiff & city);

    private:
        std::string _name;
        size_t      _populationDiff;
        char        _populationSign;
};

std::ostream & operator<<(std::ostream & stream, CityDiff & cityDiff);

#endif /* CITYDIFF_H_ */
