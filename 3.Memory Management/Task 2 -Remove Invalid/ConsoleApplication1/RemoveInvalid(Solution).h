#pragma once
#ifndef RemoveInvalid_H
#define RemoveInvalid_H
#include<iostream>
#include<list>
#include<algorithm>
#include<string>

std::list<Company*> removeInvalid(std::list<Company*>& companies) {
	std::list<Company*>::iterator it;
	for (it = companies.begin(); it != companies.end(); it++) {
		if ((*it)->getId() < 0) {
			companies.remove(*it++);
		}
	}
	
	return companies;
}

#endif // !RemoveInvalid_H
