#include <iostream>
#include<vector>
#include<sstream>
#include<string>
int main()
{
    std::vector<std::pair<int, int>> range;
    std::vector<int> toCompare;
    std::pair<int, int> fromTo;
    int from = 0;
    int to = 0;
    std::string input;
    int number = 0;
    while (std::getline(std::cin,input) and input !=".")
    {
        std::stringstream str(input);
        str >> fromTo.first, str >> fromTo.second;
        range.emplace_back(fromTo.first, fromTo.second);
    }
    
    while (std::getline(std::cin, input) and input != ".")
    {
        std::stringstream strm(input);
        strm >> number;
        toCompare.push_back(number);
    }
    int k = 0;
    int end = toCompare.size()-1;
    for (size_t i = 0; i < range.size(); i++)
    {
        for (size_t j = 0; j < range.size(); j++)
        if (range[i].first <= toCompare[k] and toCompare[k] <= range[i].second) {
            std::cout << "in" << std::endl;
            if (k == end)
                break;
            k++;
        }
        else
        {
            std::cout << "out" << std::endl;
            if (k == end)
                break;
            k++;
        }
        
  
    }
}

