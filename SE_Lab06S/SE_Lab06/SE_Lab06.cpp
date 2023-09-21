#include "Dictionary.h"
#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;
using namespace Dictionary;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
#if  defined(TEST_CREATE_01) //test Instance
		Instance d1 = Create("���������                    ", 5);
#elif defined(TEST_CREATE_02)
		Instance d1 = Create("���������", 1000);
#else
		Instance d1 = Create("���������", 7);
#endif

#if  defined(TEST_ADDENTRY_03)
		AddEntry(d1, { 8, "����������� ����� Ը�������" });
		AddEntry(d1, { 7, "�������� ������ �����������" });
#elif defined(TEST_ADDENTRY_04)
		AddEntry(d1, { 1, "������� ����� ����������" });
#else
		AddEntry(d1, { 7, "�������� ������ �����������" });
#endif
		AddEntry(d1, { 1, "������� ������� ����������" });
		AddEntry(d1, { 2, "������ ������ ������������" });
		AddEntry(d1, { 3, "�������� ������ ��������" });
		AddEntry(d1, { 4, "��������� ��������� ��������" });
		AddEntry(d1, { 5, "���������� ���������� ����������" });
		AddEntry(d1, { 6, "������� ����� ���������" });
		Print(d1);
#if defined(TEST_GETENTRY_05)
		GetEntry(d1, 10);
#elif defined(TEST_DELENTRY_06)
		DelEntry(d1, 10);
#endif
		GetEntry(d1, 4);
		DelEntry(d1, 4);
		Print(d1);
#if defined(TEST_UPDENTRY_07)
		UpdEntry(d1, 10, { 10, "��������� ������� ����������" });
#elif defined(TEST_UPDENTRY_08)
		UpdEntry(d1, 2, { 3, "��������� ������� ����������" });
#endif
		UpdEntry(d1, 2, { 10, "��������� ������� ����������" });
		Print(d1);
		Delete(d1);
		Print(d1);
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 0;
}