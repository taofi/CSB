int NumberOfDay(int day, int month, bool isVis) {
	int number = day;
	int mas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isVis)
		mas[1] ++;
	for (int i = 0; i < month - 1; i++)
		number += mas[i];
	return number;
}