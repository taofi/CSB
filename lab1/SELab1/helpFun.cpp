#include "stdafx.h"
using namespace std;

bool IsVis(int Year) {
	return (Year % 4 == 0);
}

void coutInfo(bool isVis, int dayBeforeBr, int numberOfDay, int year) {
	cout << "------------------------------------" << endl;
	if (isVis)
		cout << "|год" << year << " является высокосным" << endl;
	else
		cout << "|год " << year << " не является высокосным" << endl;
	cout << "|номер дня в году " << numberOfDay << endl;
	cout << "|количество дней до вашего дня рождения " << dayBeforeBr << endl;
	cout << "------------------------------------" << endl;
};
bool inData(int& day, int& month, int& year) {
	char inputData[100];
	gets_s(inputData);
	day = findDay(inputData);
	month = findMonth(inputData);
	year = findYear(inputData);
	return inputData[8] == '\0';
};

bool checkData(int* day, int* month, int* year) {
	int mas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	mas[1] += IsVis(*year);
	if (*month > 12)
		return false;
	if (*day > mas[*month - 1])
		return false;
	return true;
};