#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"Company.h"
#include<map>
#include<algorithm>


/*acme 424242420
softuni_foundation 20140414
itjoro 878968302
end
id
*/

std::vector<Company> companyData() {
	std::vector<Company> companies;
	int id=0;
	std::string line;
	std::string name;
	while (std::getline(std::cin, line) and (line != "end"))
	{
		std::stringstream stream(line);
		stream >> name >> id;
		companies.emplace_back(id, name);
	}
	return companies;
}

bool sortByName(const Company& left, const Company& right) {
	return left.getName() < right.getName();
}
bool sortById(const Company& left, const Company& right) {
	return left.getId() < right.getId();
}

int main()
{
	std::vector<Company> companies = companyData();
	std::string key;
	std::getline(std::cin, key);
	if (key == "id") {
		std::sort(companies.begin(), companies.end(), sortById);
	}
	else
	{
		std::sort(companies.begin(), companies.end(), sortByName);
	}
	for (Company& company : companies) {
		std::cout << company.toString() << std::endl;
	}
	
	return 0;
}