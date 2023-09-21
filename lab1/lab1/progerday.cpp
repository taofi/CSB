#include "stdafx.h";

void progerday(char saction[]) {
	int year = strtoi(saction);
	if (year  == -1)
	{
		cout << "неправельный ввод" << endl;
		return;
	}
	if (year % 4 == 0)
		cout << "1309" << year << endl;
	else
		cout << "1209" << year << endl;
}
