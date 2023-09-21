#include "stdafx.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char saction[100];
	bool isVis;
	int day, month, year;
	int br_day,br_month, br_year;
	bool goodData;
	do {
		cout << "¬ведите действие:" << endl;
		cout << "1 - анализ даты" << endl;
		cout << "2 - найти на какую дату приходитьс€ день прогромиста в году" << endl;
		cout << "3- выход" << endl;
		gets_s(saction);
		cin.ignore(cin.rdbuf()->in_avail());
		if (saction[1] == '\0')
		{
			switch (saction[0])
			{
			case '1':
				goodData = true;
				do {
					cout << "¬ведите дату в формате ƒƒћћ√√√√" << endl;
					goodData = inData(day, month, year);
					if (goodData)
						goodData = checkData(&day, &month, &year);
					if(!goodData)
						cout << "неверный ввод, повторите попытку" << endl;
				} while (!goodData);
				isVis = IsVis(year);
				goodData = true;
				do {
					cout << "¬ведите день рождени€ в формате ƒƒћћ√√√√" << endl;
					goodData = inData(br_day, br_month, br_year);
					if (goodData)
						goodData = checkData(&br_day, &br_month, &br_year);
					if (!goodData)
						cout << "неверный ввод, повторите попытку" << endl;
				} while (!goodData);
				coutInfo(isVis, dayBeforeBr(NumberOfDay(day, month, isVis), NumberOfDay(br_day, br_month, isVis)), NumberOfDay(day, month, isVis), year, month);
				break;
			case'2':
				cout << "введите год" << endl;
				gets_s(saction);
				cin.ignore(cin.rdbuf()->in_avail());
				progerday(saction);
				break;

			case '3':
				cout << "¬ыход" << endl;
				break;
			default:
				cout << "неверный ввод" << endl;
				break;
			}
		}
		else
		{
			cout << "неверный ввод" << endl;
			saction[0] = '0';
		}
		
	} while (saction[0] != '3');
}



