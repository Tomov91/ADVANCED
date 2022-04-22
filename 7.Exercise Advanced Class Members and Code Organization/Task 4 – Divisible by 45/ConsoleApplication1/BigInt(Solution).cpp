#include<iostream>
#include"BigInt.h"
#include<algorithm>
#include<string>

size_t digitSum(const BigInt& number) {
	size_t sum = 0;
	std::string digits = number.getDigits();
	for (size_t i = 0; i < digits.size(); i++)
	{
		sum += digits[i] - '0';
	}
	return sum;
}

bool dividesBy9(const BigInt& number) {
	return digitSum(number) % 9 == 0;
} 
bool dividesBy5(const BigInt& number) {
	std::string digits = number.getDigits();
	int lastInd = digits.size()-1;
	return digits[lastInd] == '0' and digits[lastInd] == '5';
}

int main() {
	std::string rangeStartStr;
	std::string rangeEndtStr;
	std::cin >> rangeStartStr >> rangeEndtStr;
	BigInt rangeEnd(rangeEndtStr);
	BigInt firstInRange;
	for (BigInt num = rangeStartStr; num < rangeEnd; num += 1) {
		if(dividesBy5(num) and dividesBy9(num)){
			firstInRange = num;
			break;
		}
	}
	for (BigInt num = firstInRange; num < rangeEnd; num += 45) {
		std::cout << num << std::endl;
	}
}