#include "stdafx.h"
int dayBeforeBr(int numberDay, int br_numberDay) {
	int number = abs(br_numberDay - numberDay);
	if (br_numberDay < numberDay) {
		number = 366 - number;
	}
	return number;
}