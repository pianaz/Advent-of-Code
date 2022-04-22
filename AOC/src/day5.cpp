#pragma warning(disable:4996)
#include <iostream>
#include <sstream>
#include <fstream>

void day5_1() {
	std::ifstream input("input5.txt");
	std::string line;
	int nice = 0;
	while (std::getline(input, line))
	{
		std::cout << line << std::endl;
		if (!(line.find("ab") == std::string::npos && line.find("cd") == std::string::npos && line.find("pq") == std::string::npos && line.find("xy") == std::string::npos))	continue;
		char prev = 0;
		bool doubles = false;
		int vowels = 0;
		for (char& c : line) {
			if (c == prev) doubles = true;
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels++;
			if (vowels > 2 && doubles) {
				nice++;
				std::cout << "nice" << std::endl;
				break;
			}
			prev = c;
		}
	}
	std::cout << "nice lines: " << nice<<std::endl;
}

void day5_2() {
	std::ifstream input("input5.txt");
	std::string line;
	int nice = 0;
	while (std::getline(input, line))
	{
		std::cout << line << std::endl;
		char prev = 0;
		char prevprev = 0;
		bool doubles_inbetween = false;
		bool double_doubles = false;
		std::string tofind;
		int counter = 0;
		for (char& c : line) {
			if (counter > 1) {
				if (c == prevprev) doubles_inbetween = true;
			}
			std::string previous{ prev };
			std::string current{ c };
			if (counter > 0) {
				tofind = previous + current;
				if (line.find(tofind, counter + 1) != std::string::npos) double_doubles = true;
			}
			if (double_doubles && doubles_inbetween) {
				nice++;
				std::cout << "nice" << std::endl;
				break;
			}
			counter++;
			prevprev = prev;
			prev = c;
		}
	}
	std::cout << "nice lines: " << nice << std::endl;
}