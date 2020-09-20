/*
Solution for "Cracking the coding interview"
Exercise 16_7

Notes:
*/

#include <string>
#include <algorithm>
#include <iostream>
#include "stdint.h"

using namespace std;

int max(uint8_t a, uint8_t b) {
	int diff = a - b;
	int sign = diff & 0xF0000000;
	int k = sign >> 32;
	return k * a + ~k * b;

}

int main() {
	cout << "max " << endl;
	cout << max(0, 0) << endl;
	cout << max(1, 0) << endl;
	cout << max(0, 1) << endl;
	cout << max(1, 1) << endl;
	cout << max(2, 3) << endl;
	cout << max(5, 3) << endl;

}