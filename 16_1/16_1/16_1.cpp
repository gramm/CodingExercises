/* 
Solution for "Cracking the coding interview"
Exercise 16_1

Notes:
Brute testing by verifying all possible combination when swapping two int8. Boundary checking would have be enough.
*/

#include <string>
#include <iostream>
#include "stdint.h"

using namespace std;

void swapNumber(int8_t& a, int8_t& b) {
	/* dif = b - a -> b = dif */
	b = b - a;
	a = b + a;
	b = a - b;
}

int main() {

	cout << "swapNumber" << endl;

	int errorCtr = 0;
	int successCtr = 0;
	for (int8_t i = INT8_MIN; i < INT8_MAX; i++) {
		for (int8_t j = INT8_MIN; j < INT8_MAX; j++) {
			int8_t a = i;
			int8_t b = j;
			swapNumber(a, b);

			if ((a != j) || (b != i)) {
				errorCtr++;
			}
			else {
				successCtr++;
			}
		}
	}
	cout << "Errors: " << errorCtr << endl;
	cout << "Success: " << successCtr << endl;
	cout << "Target success: " << (INT8_MAX - INT8_MIN) * (INT8_MAX - INT8_MIN) << endl;
}

