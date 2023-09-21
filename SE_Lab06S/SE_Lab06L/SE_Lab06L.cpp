#include "Dictionary.h"
#include <iostream>
#include <cstring>
#include <locale>



using namespace std;
using namespace Dictionary;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	strlen(name) > ENTRYNAMEMAXSIZE ? throw THROW01 : strcpy_s(NewDict.name, name);
	NewDict.maxsize < size ? throw THROW02 : NewDict.size = size;
	NewDict.dictionary = new Entry[size];
	return NewDict;

}

void Dictionary::AddEntry(Instance& inst, Entry ed) {

	int cnt = inst.cnt;
	for (int i = 0; i < cnt; i++) { 
		if (inst.dictionary[i].id == ed.id)					//сравниваем если имя элемента совпадает с другими уже имеющимися именами выкидываем ошибку
		{
			throw THROW04;
			return;
		}
	}
	cnt >= inst.size ? throw  THROW03 : inst.dictionary[cnt] = ed, inst.cnt++;	//проверяем нет ли переполнения по количеству элементов словоря, если нет добавляем элемент
}

void  Dictionary::DelEntry(Instance& inst, int id) {
	bool isDel = false;
	for (int i = 1; i <= inst.cnt; i++) {
		if (inst.dictionary[i].id == id) {
			isDel = true;
			for (int j = i; j < inst.cnt; j++) //переставляем все элементы на позицию +1 тк удалили один элемент
				inst.dictionary[j] = inst.dictionary[j + 1];
			inst.cnt--;
			break;
		}
	}
	if (!isDel)
		throw THROW06;
}

Entry* Dictionary::GetEntry(Instance& inst, int id) { // поиск по id и вывод имени найденного элемента
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << "\nНайдено: " << inst.dictionary[i].name << "\n";
			return &inst.dictionary[i];
		}
	}
	throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) //изменить элемент словаря 
{
	Entry* upd = inst.dictionary;
	bool isFind = false;
	for (int i = 0; i < inst.cnt; upd++, i++) {
		if (upd->id == id)
		{
			isFind = true;
			break;
		}
	}
	if (!isFind)
		throw THROW07;
	for (int i = 0; i < inst.cnt; i++) //проверка на уникальность id
	{
		if (new_ed.id == inst.dictionary[i].id)
			throw THROW08;
	}
	*upd = new_ed;       //меняем элемент
}

void Dictionary::Print(Instance d)
{
	cout << "\n\n";
	cout  << d.name << "\n";
	for (int i = 0; i < d.cnt; i++)
	{
		cout << d.dictionary[i].id << "\t" << d.dictionary[i].name << endl;
	}
	cout << "\n";
}
void Dictionary::Delete(Instance& inst)
{
	inst.cnt = 0;
	delete[] inst.dictionary;
}