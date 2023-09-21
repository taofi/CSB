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
		Instance d1 = Create("Работники                    ", 5);
#elif defined(TEST_CREATE_02)
		Instance d1 = Create("Работники", 1000);
#else
		Instance d1 = Create("Работники", 7);
#endif

#if  defined(TEST_ADDENTRY_03)
		AddEntry(d1, { 8, "Масленников Павел Фёдорович" });
		AddEntry(d1, { 7, "Давыдова Фатима Ибрагимовна" });
#elif defined(TEST_ADDENTRY_04)
		AddEntry(d1, { 1, "Калугин Антон Михайлович" });
#else
		AddEntry(d1, { 7, "Давыдова Фатима Ибрагимовна" });
#endif
		AddEntry(d1, { 1, "Ульянов Арсений Георгиевич" });
		AddEntry(d1, { 2, "Власов Герман Мирославович" });
		AddEntry(d1, { 3, "Захарова Таисия Ивановна" });
		AddEntry(d1, { 4, "Алексеева Елизавета Артёмовна" });
		AddEntry(d1, { 5, "Богомолова Александра Данииловна" });
		AddEntry(d1, { 6, "Галкина София Ильинична" });
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
		UpdEntry(d1, 10, { 10, "Поздняков Арсений Николаевич" });
#elif defined(TEST_UPDENTRY_08)
		UpdEntry(d1, 2, { 3, "Поздняков Арсений Николаевич" });
#endif
		UpdEntry(d1, 2, { 10, "Поздняков Арсений Николаевич" });
		Print(d1);
		Delete(d1);
		Print(d1);
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 0;
}