#include <iostream>

using namespace std;

int f() {
    return 1;
}

int main()
{
    int x = 17, y = 18, z = 19;
    double s = 9.0;
    bool bt = true; //01 
    bool bf = false; //00 
    char co = 'O'; //4f  - O кодировка ascii
    wchar_t wcv = L'V'; //56 00  - V utf-16
    wchar_t wcr = L'В'; //12 04  - B utf-16
   
    short sxm = -x, sxp = x; //-11 11 |||ef ff  11 00
    short smin = -0x7fff;//-32767
    short smax = 0x7fff;//32767
    unsigned short usmin = 0x0; //0

    int iym = -y; // ee ff ff ff
    int iyp = y;// 12 00 00 00
    int imin = -0x7fffffff;//-2147483647
    int imax = 0x7fffffff;//2147483647
    unsigned int uimin = 0x0;//0

    long lzm = -z; // ed ff ff ff
    long lzp = z; // 13 00 00 00
    long lmin = -0x7fffffff; // -2147483647
    long lmax = 0x7fffffff; // 2147483647
    unsigned long ulmin = 0x0; // 0

    float fsp = s; // 9.000 // 00 00 10 41
    float fsm = -s; // -9.000 //  00 00 10 c1
    double ap = 2.0, am = -2.0;
    double infm = ap / 0;
    double infp = am / 0;
    double n = sqrt(-2.0);

    char* pc = &co;
    wchar_t* pwc = &wcr; // c4 ef af d6 ce
    short* sp = &sxm;
    int* pi = &iyp;
    long* pl = &lzm;
    float* pf = &fsp;
    double* pd = &ap;

    char* pc1 = pc + 3;
    wchar_t* pwc1 = pwc + 3;
    short* sp1 = sp + 3;
    int* pi1 = pi + 3;
    long* pl1 = pl + 3;
    float* pf1 = pf + 3;
    double* pd1 = pd + 3;

    void(*fun);
    fun = f; // c0 13 88 4f f7 7f 00 00
}