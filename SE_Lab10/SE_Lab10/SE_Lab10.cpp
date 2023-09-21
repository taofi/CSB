
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	vector <int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);
	cout << "число: " << target1 << " количество: " << num_items1 << endl;
	int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "количество элементов, кратных 3: " << num_items3 << endl;
	cout << endl << "Лямбда, захват переменых" << endl;
	for (auto i : v) [i]() {if (i % 3 == 0) cout << i << " "; }();
	cout << endl << "Лямбда с параметром" << endl;
	for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << " "; }(i);
	cout << endl << "Лямбда без параметром" << endl;
	for (auto i : v) [i] {if (i % 3 == 0) cout << i << " "; }();

	cout << endl;
	auto isPlus = [](auto a) { return a > 0; };
	isPlus(5) ? cout << "Yes" << endl : cout << "No" << endl;
	isPlus(-2) ? cout << "Yes" << endl : cout << "No" << endl;
}