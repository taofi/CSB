#pragma once

#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

void progerday(char saction[]);
int strtoi(char arr[]);
bool IsVis(int);
int NumberOfDay(int, int, bool);
int findDay(char*);
int findMonth(char*);
int findYear(char*);
int dayBeforeBr(int, int);
void coutInfo(bool, int, int, int, int);
bool inData(int& day, int& month, int& year);
bool checkData(int* day, int* month, int* year);