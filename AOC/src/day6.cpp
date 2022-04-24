#pragma warning(disable:4996)
#include <iostream>
#include <regex>
#include <vector>
#include <fstream>

void day6_1() {
	std::ifstream input("input6.txt");
	std::string line;
	std::regex input_parse{ R"((off|on|toggle)\s([0-9]+),([0-9]+)\sthrough\s([0-9]+),([0-9]+))" };
	std::smatch matches;
	int rowInit = 0;
	int rowFinal = 0;
	int colInit = 0;
	int colFinal = 0;
	std::vector<std::vector<int>> grid(1000, std::vector<int>(1000));
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			grid[i][j] = 0;
		}
	}
	enum Mode {off, on, toggle};
	Mode mode = off;

	while (std::getline(input, line)) {
		std::regex_search(line, matches, input_parse);
		if (matches[1] == "on") mode = on;
		if (matches[1] == "off") mode = off;
		if (matches[1] == "toggle") mode = toggle;
		rowInit = std::stoi(matches[2]);
		colInit = std::stoi(matches[3]);
		rowFinal = std::stoi(matches[4]);
		colFinal = std::stoi(matches[5]);
		for (int i = rowInit; i < rowFinal + 1; i++) {
			for (int j = colInit; j < colFinal+1; j++) {
				// off(0) -> =0; on(1) -> =1; toggle(2) -> (+1)%toggle
				if (mode == toggle) grid[i][j] = (grid[i][j] + 1) % mode;
				else grid[i][j] = mode;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (grid[i][j] == 1) count++;
		}
	}

	std::cout << count << '\n';
}