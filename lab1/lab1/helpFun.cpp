#include "stdafx.h"
using namespace std;


int strtoi(char arr[]) {
	char* p = arr;
	bool isd = true;
	int digit = -1;
	while (*p)
		if (!isdigit(*p++))
		{
			isd = false;
			break;
		}
	if (isd)
		return atoi(arr);
	else
		return -1;
}

bool IsVis(int Year) {
	return (Year % 4 == 0);
}

void whatmonth(int m) {
	switch (m)
	{
	case 1:
		cout << "€нварь";
		break;
	case 2:
		cout << "февраль";
		break;
	case 3:
		cout << "март";
		break;
	case 4:
		cout << "апрель";
		break;
	case 5:
		cout << "май";
		break;
	case 6:
		cout << "июнь";
		break;
	case 7:
		cout << "июль";
		break;
	case 8:
		cout << "август";
		break;
	case 9:
		cout << "сент€брь";
		break;
	case 10:
		cout << "окт€брь";
		break;
	case 11:
		cout << "но€брь";
		break;
	case 12:
		cout << "декабрь";
		break;
	default:
		break;
	}
	cout << endl;
}

void coutInfo(bool isVis, int dayBeforeBr, int numberOfDay, int year, int month) {
	cout << "------------------------------------" << endl;
	if (isVis)
		cout << "|год" << year << " €вл€етс€ высокосным" << endl;
	else
		cout << "|год " << year << " не €вл€етс€ высокосным" << endl;
	cout << "|номер дн€ в году " << numberOfDay << endl;
	cout << "|мес€ц: "; whatmonth(month); 
	cout << "|количество дней до вашего дн€ рождени€ " << dayBeforeBr << endl;
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