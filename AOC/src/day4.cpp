#include "md5.h"
#include <string> 

void day4_1() {
	int i = 1;
	while (1) {
		auto s = std::to_string(i);
		std::string result = md5("bgvyzdsv" + s);
		auto initial5 = result.substr(0, 5);
		if (initial5 == "00000") break;
		i++;
	}
	std::cout << "num: " << i << std::endl;
}

void day4_2() {
	int i = 1;
	for (;;) {
		auto s = std::to_string(i);
		std::string result = md5("bgvyzdsv" + s);
		auto initial6 = result.substr(0, 6);
		if (initial6 == "000000") break;
		i++;
	}
	std::cout << "num: " << i << std::endl;
}