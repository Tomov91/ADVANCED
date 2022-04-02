#pragma once
#ifndef SORTBY_H
#define SORTBY_H
#include<algorithm>

bool (*globalComparator)(const Company& a, const Company& b) = nullptr;

bool internalSort(Company* begin, Company* end) {
	return globalComparator(*begin,*end);
}

void sortBy(Company** begin, Company** end, bool (*sortBy)(const Company& a, const Company& b)) {
	globalComparator = sortBy;
	std::sort(begin, end, internalSort);
}

#endif // !SORTBY_H
