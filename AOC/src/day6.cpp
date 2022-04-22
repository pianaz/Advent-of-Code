#pragma warning(disable:4996)
#include <iostream>
#include <sstream>
#include <fstream>

void day6_1() {
	std::ifstream input("input6.txt");
	std::string line;
	enum Mode { toggle, on, off };
	while (std::getline(input, line))
	{
		Mode mode = toggle;
		int start = 0;
		if (line.find("toggle") != std::string::npos) {
			mode = toggle;
			start = 7;
		}
		if (line.find("turn off") != std::string::npos) {
			mode = off;
			start = 9;
		}
		if (line.find("turn on") != std::string::npos) {
			mode = on;
			start = 8;
		}

		std::istringstream tokenizer(line[start]);
		std::string x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		std::getline(tokenizer, x1, ',');
		std::cout << x1 << std::endl;

	}
}