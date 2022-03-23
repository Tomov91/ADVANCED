#pragma once
#ifndef CompanyMemoryUtils_H
#define CompanyMemoryUtils_H
#include"Company.h"
#include<memory>
typedef unsigned char byte;
using namespace std;

std::vector<Company> readCompaniesFromMemory(byte* memory, int numOfCompanies) {
    vector<Company> allCompanies;

    for (size_t i = 0; i < numOfCompanies; i++) {
        int id;
        std::string name;
        unsigned char cId = (*memory);
        id = (int)cId;
        while (memory++)
        {
            if (*memory != '\0' and *memory != 0) {
                name += *memory;
            }
            else
            {
                break;
            }
        }
        ++memory;
        int numOfEmployees = (int)*memory;
        std::vector<std::pair<char, char> > employees;
        for (size_t i = 0; i < numOfEmployees; i++)
        {
            ++memory;
            char first = *memory;
            ++memory;
            char second = *memory;
            employees.push_back(std::pair<char, char>(first, second));
        }
        Company comp(id, name, employees);
        allCompanies.push_back(comp);
        ++memory;
    }
    return allCompanies;
}

#endif // !CompanyMemoryUtils_H
