#include <iostream>
#include <fstream>
#include <vector>

void day3(){
	std::ifstream input("input3.txt");
	char byte = 0;
	int SantaX = 500;
	int SantaY = 500;
	int RoboX = 500;
	int RoboY = 500;
	int houses_counter = 1;
	int switch_santa = 1; 
	std::vector<int> matrix(1000000, 0); // brute foooooorce
	matrix[100 * SantaY + SantaX] = 1;
	
	while (input.get(byte)) {
		if (switch_santa % 2) {
			if (byte == '<') SantaX--;
			if (byte == '>') SantaX++;
			if (byte == '^') SantaY++;
			if (byte == 'v') SantaY--;
			if (matrix[100 * SantaY + SantaX] == 0) {
				matrix[100 * SantaY + SantaX] = 1;
				houses_counter++;
			}
			switch_santa++;
			continue;
		}
		if (byte == '<') RoboX--;
		if (byte == '>') RoboX++;
		if (byte == '^') RoboY++;
		if (byte == 'v') RoboY--;
		if (matrix[100 * RoboY + RoboX] == 0) {
			matrix[100 * RoboY + RoboX] = 1;
			houses_counter++;
		}
		switch_santa++;
		
	}
	std::cout << "count: " << houses_counter << std::endl;
}