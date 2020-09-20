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
	while ((n % 5) == 0) {
		n = n / 5;
		power++;
	}
	return power;
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

int factorialZeroesFast(int n) {
	int zeroes = 0;
	for (int i = 5; i <= n; i = i * 5) {
		zeroes += n / i;
	}
	return zeroes;
}
int main() {
	for (int i = 5; i < 3125; i += 5) {
		cout << "factorial " << i << " zeroes1 " << factorialZeroes(i) << " zeroes2 " << factorialZeroesFast(i) << endl;
	}
}