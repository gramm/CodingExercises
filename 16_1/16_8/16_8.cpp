/*
Solution for "Cracking the coding interview"
Exercise 16_8

Notes:
*/

#include <string>
#include <algorithm>
#include <iostream>
#include "stdint.h"

using namespace std;

string tenz[] = {
	"",
	"ten",
	"twenty",
	"thirty",
	"fourty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};
string numz[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

void printNumber(int digit, int power) {
	if (power == 0) {
		cout << numz[digit] << " ";
	}
}

void printEnglish(int n, int pow10) {
	if ((n == 0) && (pow10 >= 1)) {
		/* we reached the last power of 10 -> stop recursion*/
		return;
	}


	printEnglish(n / 10, pow10 + 1);

	/* get last digit */
	int digit = n % 10;

}
void printThousand(int n) {
	if (n / 1000 > 0) {
		cout << numz[n / 1000] << " thousand ";
	}
}

void printEnglish(int n) {

	while (true) {
		int chunk = n % 10000;
		if (chunk / 1000 > 0) {
			cout << numz[chunk / 1000] << " thousand ";
		}

		chunk = chunk % 1000;
		if (chunk / 100 > 0) {
			cout << numz[chunk / 100] << " hundred ";
		}

		chunk = chunk % 100;
		if ((chunk == 0) && (n > 0)) {
			break;
		}
		if (chunk < 20) {
			cout << numz[chunk] << " ";
		}
		else {
			cout << tenz[chunk / 10] << " ";
			if (chunk % 10 > 0) {
				cout << numz[chunk % 10] << " ";
			}
		}
		n = n / 10000;
		if (n == 0) {
			break;
		}
	}
	cout << endl;
}


int main() {
	cout << "print english " << endl;
	printEnglish(0);
	printEnglish(1);
	printEnglish(2);
	printEnglish(8);
	printEnglish(9);
	printEnglish(10);
	printEnglish(11);
	printEnglish(19);
	printEnglish(20);
	printEnglish(21);
	printEnglish(29);
	printEnglish(30);
	printEnglish(31);
	printEnglish(99);
	printEnglish(100);
	printEnglish(101);
	printEnglish(985);
	printEnglish(1234);
	/*
	printEnglish(5);
	printEnglish(10);
	printEnglish(15);
	printEnglish(123);
	printEnglish(1234);
	*/
}