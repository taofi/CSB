#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>


#define strsize 18

using namespace std;
struct DATE
{
    unsigned month : 4;
    unsigned day : 6;
    unsigned years : 16;

};
struct product
{
    char type[strsize];
    char name[strsize];
    char number[255];
    unsigned int amount;
	double price;
    char producer[strsize];
    DATE date;
}listOfProduct[255];
short structSize = 0;

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

void coutHead() {
	cout << "| номер |";
	cout << "|" << setw(strsize + 1) << "тип |";
	cout << "|" << setw(strsize + 1) << "произвоитель |";
	cout << "|" << setw(strsize + 1) << "инв. номер |";
	cout << "| количество |";
	cout << "|  цена  |";
	cout << "| производитель |";
	cout << "|срок годности|" << endl;
}
void coutPr(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(strsize) << listOfProduct[index].type << "|";
	cout << "|" << setw(strsize) << listOfProduct[index].name << "|";
	cout << "|" << setw(strsize) << listOfProduct[index].number << "|";
	cout << "|" << setw(12) << listOfProduct[index].amount << "|";
	cout << "|" << setw(8) << fixed << setprecision(2) << listOfProduct[index].price << "|";
	cout << "|" << setw(15) << listOfProduct[index].producer << "|";
	cout << "|  " << listOfProduct[index].date.day << " " << listOfProduct[index].date.month << " " << listOfProduct[index].date.years << "  |" << endl;
	
}

bool operator < (product &pr1, product &pr2) {
	return double(pr1.price * pr1.amount) < double(pr2.amount* pr2.price);
}

bool operator > (product& pr1, product& pr2) {
	return double(pr1.price * pr1.amount) > double(pr2.amount * pr2.price);
}


bool operator == (product& pr1, product& pr2) {
	return double(pr1.price * pr1.amount) == double(pr2.amount * pr2.price);
}

void input() {
	cout << "введите тип" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listOfProduct[structSize].type);
	cout << "введите название" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listOfProduct[structSize].name);
	cout << "введите инвентарный_номер" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listOfProduct[structSize].number);
	cout << "введите количество" << endl;
	cin >> listOfProduct[structSize].amount;
	cout << "введите цену" << endl;
	cin >> listOfProduct[structSize].price;
	cout << "введите производителя" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listOfProduct[structSize].producer);
	cout << "введите дату: день месяц год" << endl;
	int n;
	cin >> n;
	if (n < 31)
		listOfProduct[structSize].date.day = n;
	cin >> n;
	if (n < 12)
		listOfProduct[structSize].date.month = n;
	cin >> n;
	if (n < 9999)
		listOfProduct[structSize].date.years = n;
	structSize++;
}

void output(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (structSize == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutHead();
			for (int i = 0; i < structSize; i++)
				coutPr(i);
		}
	}
	else
	{
		char arr[strsize] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr); 
		if (index == -1)
		{
			cout << "введён неправельный номер продукта" << endl;
		}
		else
		{
			if (index >= structSize)
			{
				cout << "максимальный индекс продукта в струтуре: " << structSize << endl;
			}
			else {
				coutHead();
				coutPr(index);
			}
		}
	}
}

void comp() {
	int d, index1, index2;
	cout << " < - 1, > - 2,  == - 3" << endl;
	cin >> d;
	cout << "index1 = ";
	cin >> index1;
	cout << "index2 = ";
	cin >> index2;
	switch (d) {
	case 1:
		if (listOfProduct[index1] < listOfProduct[index2])
			cout << "listOfProduct[" << index1 << "] < listOfProduct[" << index2 << "] - true" << endl;
		else
			cout << "listOfProduct[" << index1 << "] < listOfProduct[" << index2 << "] - false" << endl;
		break;
	case 2:
		if (listOfProduct[index1] > listOfProduct[index2])
			cout << "listOfProduct[" << index1 << "] > listOfProduct[" << index2 << "] - true" << endl;
		else
			cout << "listOfProduct[" << index1 << "] > listOfProduct[" << index2 << "] - false" << endl;
		break;
	case 3:
		if (listOfProduct[index1] == listOfProduct[index2])
			cout << "listOfProduct[" << index1 << "] == listOfProduct[" << index2 << "] - true" << endl;
		else
			cout << "listOfProduct[" << index1 << "] == listOfProduct[" << index2 << "] - false" << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	char buff[256];
	char* tmp_char;
	cout << "Для получения команд введите help" << endl;
	do {
		cout << "Введите команду" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "input" << endl;
			cout << "output" << endl;
			cout << "comp" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			output(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			input();
		else if (!strcmp(tmp_char, "comp"))
			comp();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}