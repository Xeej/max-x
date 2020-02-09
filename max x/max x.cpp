#include <iostream>
#include <math.h>
using namespace std;
int col = 0;
void RECtoBIN(int N,int &k ,int *&mass)
{
    if (N!=0)
    {
        k++;
        RECtoBIN(N / 2,k, mass);
        mass[k] = N % 2;
        //cout << mass[k];
        k--;
    }
    else
    {
        mass = new int[k+1];
        col = k;
    }
}

int BINtoDEC(int& k, int*& mass)
{
    int sum = 0;
    for (int i = k; i >= 1; i--)
        if (mass[i] == 1)
            sum += pow(2, i-1);
    return sum;
}

int main()
{
    //Для простоты N - натуральное число поскольку не указано
    /*Напиши на любом языке программирования метод, 
    который определяет "x" - наименьшую целую степень числа два, при котором два в степени "x" 
    больше чем N. Чем больше способов решения предложите, тем лучше. */
    setlocale(LC_ALL, "Russian");
    
    //Первый вариант

    cout << "Введите N\n";
    int N,k=0;
    cin >> N;
    int* mass=NULL;
    //mass - массив в двоичной не перевернутой
    //cout << "N в двоичной системе: ";
    RECtoBIN(N, k, mass);
    col++;
    mass[col] = 1;
    for (int i = 0; i < col; i++)
        mass[i] = 0;
    cout<<"2^"<<col-1<<"=" << BINtoDEC(col, mass)<<">"<<N << "   X=" << col-1;
    cout << "\n";
    system("pause");

    //Второй вариант 

    int l = N;
    k = 0;
    while (l)
    {
        l = l / 2;
        k++;
    }
    cout << "2^" << k << "=" << pow(2,k) << ">" << N<<"   X="<<k;
    cout << "\n";
    system("pause");
}