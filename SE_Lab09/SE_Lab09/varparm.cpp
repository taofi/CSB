#include "varparm.h"

int ivarparm(int n, ...) {
	int pr = 1;
	int* p = &n;
	int k = 1;

	while (k <= p[0])
	{
		pr *= p[k];
		k++;
	}
	return pr;
}

short svarparm(short n ...) {
	int* p = (int*)(&n);
	int k = 1;
	int m = p[0];
	while (k <= p[0])
	{
		if (m < p[k])
			m = p[k];
		k++;
	}
	return m;
}


float fvarparm(float first, ...)
{
    double sum = first;
    va_list args;
    va_start(args, first);
    while (true)
    {
        float val = va_arg(args, double);
        if (val == FLT_MAX)
            break;
        sum += val;
    }

    va_end(args);
    return sum;
}

double dvarparm(double first, ...)
{
    double sum = first;
    va_list args;
    va_start(args, first);
    while (true)
    {
        double val = va_arg(args, double);
        if (val == DBL_MAX)
            break;
        sum += val;
    }

    va_end(args);
    return sum;
}