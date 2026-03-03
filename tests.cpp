#include <iostream>
#include <string>

#include <HolyRandom.h>

int main()
{

	for (int i = 0; i <= 20; i++) {
		std::string HolyRandom_S = HolyRandom::getHolyRandom_S(20);
		std::cout << "Sample " << i << " " << HolyRandom_S << "\n";
	}

}
