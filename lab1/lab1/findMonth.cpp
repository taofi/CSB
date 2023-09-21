int findMonth(char* s) {
	int month;
	s += 2;
	month = int(*s - '0') * 10;
	month += *(s + 1) - '0';
	return month;
}