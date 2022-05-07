#include "CityDiff.h"

CityDiff::CityDiff(const City & first, const City & second)
{
    const unsigned int FIRST_CENSUS_YEAR = first.getCensusYear();
    const unsigned int SECOND_CENSUS_YEAR = second.getCensusYear();

    const size_t FIRST_POPULATION = first.getPopulation();
    const size_t SECOND_POPULATION = second.getPopulation();

    if(FIRST_POPULATION >= SECOND_POPULATION)
    {
        _populationSign = '+';
        _populationDiff = FIRST_POPULATION - SECOND_POPULATION;
    }
    else
    {
        _populationSign = '-';
        _populationDiff = SECOND_POPULATION - FIRST_POPULATION;
    }

    _name = first.getName();
    _name.append(" (").append(std::to_string(FIRST_CENSUS_YEAR));

    if(first.getName() == second.getName())
    {
        _name.append(" vs. ")
             .append(std::to_string(SECOND_CENSUS_YEAR))
             .append(")");
    }
    else
    {
        _name.append(") vs. ")
             .append(second.getName())
             .append(" (")
             .append(std::to_string(SECOND_CENSUS_YEAR))
             .append(")");
    }
}

CityDiff::~CityDiff()
{

}

std::ostream & operator<<(std::ostream & stream, CityDiff & cityDiff)
{
    stream << cityDiff._name << std::endl << "populaton: "
           << cityDiff._populationSign
           << cityDiff._populationDiff << '\n';

    return stream;
}



