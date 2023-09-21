#include "Dictionary.h"
#include "stdafx.h"
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
		if (inst.dictionary[i].id == ed.id)					//���������� ���� ��� �������� ��������� � ������� ��� ���������� ������� ���������� ������
		{
			throw THROW04;
			return;
		}
	}
	cnt >= inst.size ? throw  THROW03 : inst.dictionary[cnt] = ed, inst.cnt++;	//��������� ��� �� ������������ �� ���������� ��������� �������, ���� ��� ��������� �������
}

void  Dictionary::DelEntry(Instance& inst, int id) {
	bool isDel = false;
	for (int i = 1; i <= inst.cnt; i++) {
		if (inst.dictionary[i].id == id) {
			isDel = true;
			for (int j = i; j < inst.cnt; j++) //������������ ��� �������� �� ������� +1 �� ������� ���� �������
				inst.dictionary[j] = inst.dictionary[j + 1];
			inst.cnt--;
			break;
		}
	}
	if (!isDel)
		throw THROW06;
}

Entry* Dictionary::GetEntry(Instance& inst, int id) { // ����� �� id � ����� ����� ���������� ��������
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << "\n�������: " << inst.dictionary[i].name << "\n";
			return &inst.dictionary[i];
		}
	}
	throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) //�������� ������� ������� 
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
	for (int i = 0; i < inst.cnt; i++) //�������� �� ������������ id
	{
		if (new_ed.id == inst.dictionary[i].id)
			throw THROW08;
	}
	*upd = new_ed;       //������ �������
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