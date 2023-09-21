int findYear(char* s) {
	int year;
	s += 4;
	year = int(*s - '0') * 1000;
	year += (*(s + 1) - '0') * 100;
	year += (*(s + 2) - '0') * 10;
	year += *(s + 3) - '0';
	return year;
}