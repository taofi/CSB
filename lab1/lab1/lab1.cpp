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
		cout << "������� ��������:" << endl;
		cout << "1 - ������ ����" << endl;
		cout << "2 - ����� �� ����� ���� ����������� ���� ����������� � ����" << endl;
		cout << "3- �����" << endl;
		gets_s(saction);
		cin.ignore(cin.rdbuf()->in_avail());
		if (saction[1] == '\0')
		{
			switch (saction[0])
			{
			case '1':
				goodData = true;
				do {
					cout << "������� ���� � ������� ��������" << endl;
					goodData = inData(day, month, year);
					if (goodData)
						goodData = checkData(&day, &month, &year);
					if(!goodData)
						cout << "�������� ����, ��������� �������" << endl;
				} while (!goodData);
				isVis = IsVis(year);
				goodData = true;
				do {
					cout << "������� ���� �������� � ������� ��������" << endl;
					goodData = inData(br_day, br_month, br_year);
					if (goodData)
						goodData = checkData(&br_day, &br_month, &br_year);
					if (!goodData)
						cout << "�������� ����, ��������� �������" << endl;
				} while (!goodData);
				coutInfo(isVis, dayBeforeBr(NumberOfDay(day, month, isVis), NumberOfDay(br_day, br_month, isVis)), NumberOfDay(day, month, isVis), year, month);
				break;
			case'2':
				cout << "������� ���" << endl;
				gets_s(saction);
				cin.ignore(cin.rdbuf()->in_avail());
				progerday(saction);
				break;

			case '3':
				cout << "�����" << endl;
				break;
			default:
				cout << "�������� ����" << endl;
				break;
			}
		}
		else
		{
			cout << "�������� ����" << endl;
			saction[0] = '0';
		}
		
	} while (saction[0] != '3');
}



