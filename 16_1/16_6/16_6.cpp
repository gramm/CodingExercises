/*
Solution for "Cracking the coding interview"
Exercise 16_6

Notes:
*/

#include <string>
#include <algorithm>
#include <iostream>
#include "stdint.h"

using namespace std;

int main() {
	cout << "smallest difference" << endl;

	int a1[] = { 1,3,15,11,2 };	/* 1 2 3 11 15*/
	int a2[] = { 23,127,235,19,8}; /* 8 19 23 127 235 */

	int size1 = sizeof(a1) / sizeof(a1[0]);
	int size2 = sizeof(a2) / sizeof(a2[0]);
	sort(a1, a1 + size1);
	sort(a2, a2 + size2);

	int index1 = 0;
	int index2 = 0;
	int diff = INT32_MAX;
	while (true) {
		diff = min(diff, abs(a1[index1] - a2[index2]));
		cout << diff << endl;
		
		if ((index1 + 1 < size1) && (a1[index1 + 1] < a2[index2])) {
			index1++;
			continue;
		}

		if ((index2 + 1 < size2) && (a2[index2 + 1] < a1[index1])) {
			index2++;
			continue;
		}

		if (index1 + 1 < size1)
		{
			index1++;
			continue;
		}

		if (index2 + 1 < size2)
		{
			index2++;
			continue;
		}

		/* if we get there, no reason to search anymore since diff will only increase */
		break;
	}

	cout << "smallesr difference: " << diff << endl;

}