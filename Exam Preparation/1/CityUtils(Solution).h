#ifndef CITYUTILS_H_
#define CITYUTILS_H_

#include "City.h"

#include <map>
#include <vector>


City * initCity(const std::string & name, const size_t population)
{
    return new City(name, population);
}

std::map<size_t, const City *> groupByPopulation(
                          const std::vector<const City *> & cities,
                          size_t &                          outTotalPopulation)
{
    std::map<size_t, const City *> result;
    size_t currPopulation = 0;
    outTotalPopulation = 0;

    const size_t SIZE = cities.size();

    for(size_t i = 0; i < SIZE; ++i)
    {
        currPopulation = cities[i]->getPopulation();
        outTotalPopulation += currPopulation;

        result[currPopulation] = cities[i];
    }

    return result;
}



#endif /* CITYUTILS_H_ */
