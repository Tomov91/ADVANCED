/*
 * Range.cpp
 *
 *  Created on: Feb 20, 2020
 *      Author: zhivko
 */

#include "Range.h"
#include <cmath>

Range::Range()
    : rangeFirst(0), rangeLength(0),
      valueCounts(nullptr) {

}

Range::~Range() {
  if (valueCounts) {
    clear();
  }
}

Range::Range(const Range & other) : rangeFirst(0),
                                    rangeLength(0),
                                    valueCounts(nullptr)
{
    if(other.valueCounts)
    {
        valueCounts = Range::copyValues(other);
        rangeFirst  = other.rangeFirst;
        rangeLength = other.rangeLength;
    }
}

Range& Range::operator=(const Range &other) {
  if (this != &other) {
    if(valueCounts)
    {
        clear();
    }

    if(other.valueCounts)
    {
        valueCounts = Range::copyValues(other);
        rangeFirst  = other.rangeFirst;
        rangeLength = other.rangeLength;
    }
  }

  return *this;
}

void Range::add(T value) {
  if(empty()) {
      resize(value, value);
  }
  else if(value < rangeFirst) //value is lower that first
  {
      resize(value, rangeFirst + rangeLength);
  }
  else if(value >= rangeFirst + rangeLength)
  {
      resize(rangeFirst, value);
  }

  ++(valueCounts[getIndex(value)]);
}

size_t Range::getCount(T value) const {
  if(value >= rangeFirst + rangeLength ||
     value < rangeFirst)
  {
      return 0;
  }

  return valueCounts[getIndex(value)];
}

void Range::clear() {
  delete[] valueCounts;
  valueCounts = nullptr;
  rangeFirst = 0;
  rangeLength = 0;
}

void Range::resize(T first, T last) {
  const int NEW_RANGE = std::abs(last - first) + 1;
  size_t * newValues = new size_t[NEW_RANGE];
  for(int i = 0; i < NEW_RANGE; ++i)
  {
      newValues[i] = 0;
  }

  int offset = 0;
  if(first < rangeFirst)
  {
      offset = rangeFirst - first;
  }

  for(int i = 0; i < rangeLength; ++i)
  {
       newValues[i + offset] = valueCounts[i];
  }

  rangeFirst = first;
  rangeLength = NEW_RANGE;
  valueCounts = newValues;
}

bool Range::empty() const {
  return valueCounts == nullptr;
}

size_t Range::getIndex(T value) const {
  return static_cast<size_t>(value - rangeFirst);
}

