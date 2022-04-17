#include"Echo.h"

bool echoOn = false;
void echo(std::string line) {
	if (echoOn) {
		std::cout << line << std::endl;
	}
}