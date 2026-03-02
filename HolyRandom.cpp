#include <iostream>
#include <string>

#include "HolyRandom.h"

int main()
{
	std::cout << HolyRandom::getHolyRandom_S(20) << "\n";
	std::cout << HolyRandom::getHolyRandom(10) << "\n";
}
