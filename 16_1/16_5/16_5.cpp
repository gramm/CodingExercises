/*
Solution for "Cracking the coding interview"
Exercise 16_5

Notes:
*/

#include <string>
#include <iostream>
#include "stdint.h"

using namespace std;

/* calculate number of trailing zeroes 
* zeroes happen at 5 (2*5 = 10), all multiples of 10 (10,20,100...)
* 14 * 15 = 7*2*3*5 = 21*10
* 10 = 2*5 20=2*2*5
*/

int powerOf5(int n) {
	int power = 0;
	int powerOf5 = 5;
	while (n >= powerOf5) {
		power++;
		powerOf5 = powerOf5 * 5;
	}

	powerOf5 = powerOf5 / 5;
	if (n == powerOf5) {
		return power;
	}
	else {
		return 1;
	}
}

int factorialZeroes(int n) {
	int zeroes = 0;
	
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			zeroes = zeroes + powerOf5(i);
		}
	}
	
	return zeroes;
}

int main() {
	for (int i = 0; i < 127; i++) {
		cout << "factorial " << i << " zeroes " << factorialZeroes(i)<<endl;
	}
}