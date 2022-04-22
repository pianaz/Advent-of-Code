#include <iostream>

void day3();
void day4_1();
void day4_2();
void day5_1();
void day5_2();
void day6_1();
// fac(n) --> n*n-1*n-2*...*1 --> n*fac(n-1)
int factorial(int i) {
	if (i == 1) return 1;
	return i*factorial(i - 1);
}

int sum(int x, int y) {
	return x + y;
}

void sum(int* x, int* y, int* z) {
	*z = *x + *y;
}

int frequency(int num, int k) {
	// num/10 ->> ..2.2 --> num%10 = 2
	int count = 0;
	while (num>0) {
		if (num % 10 == k) count++;
		num /= 10;
	}
	return count;
}

bool palindrome(int num) {
	// 123454321%10
	int opposite = 0;
	int n = num;
	int dec = 0;
	while (n > 0) {
		opposite = opposite*10 + n%10;
		std::cout << opposite<< std::endl;
		n /= 10;
		dec++;
	}
	if (num == opposite) return true;
	return false;
}


int main(int argc, char** argv) {
	//day3();
	//day4_2();
	//day5_2();
	//day6_1();

	int a = 5;
	int b = 4;
	int* ptr = &a;
	std::cout << a << " is " << *ptr << std::endl;
	int c;
	sum(&a, &b, &c);
	std::cout << a << " + "<< b << " = " << ++c << std::endl;
	int num = 593338492;
	int k = 3;
	int t = frequency(num, k);
	std::cout << k << " is in " << num << " " << t << " times" << std::endl;
	int p = 123454321;
	int n = 245146;
	if (palindrome(p)) std::cout << "p is palindrome";
	if (palindrome(n)) std::cout << "n is palindrome";
}