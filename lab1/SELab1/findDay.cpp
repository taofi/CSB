#include "stdafx.h"
int findDay(char* s) {
	int day;
	day = int(*s - '0') * 10;
	day += *(s + 1) - '0';
	return day;
}