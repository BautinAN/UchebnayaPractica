#include <iostream>
#include <locale.h>
#include "plant.h"
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;

void vvod (int &M, int &N, int &N1)
{
    setlocale (0, "RUSSIAN");
    cout << "Введите номер опрашиваемого датчика M:\n";
    cin >> M;
    cout << "Число усредняемых измерений N:\n";
    cin >> N;
    cout << "Общее число измерений N1:\n";
    cin >> N1;
    cout << "\n";
}

void schet (int  &M, int &N, int &N1)
{
    Plant plant;
    plant_init(plant);
    int i,t=0;
    double Xcp, sum=0;
    vector <double> X(500);
    for(i=0; i<N1; i++) {
      if (i < N-1)
      {
        X[i]=plant_measure(M, plant);
        sum=sum+X[i];
        cout << i+1 << "\t";
        if(N1>9)
        {cout << " ";}
        if(N1>99)
        {cout << " ";}
        cout << "X=" << X[i] << "\n";
      }
      else
      { if (i == N-1) {
        X[i]=plant_measure(M, plant);
        sum=sum+X[i];
        Xcp=sum/N;
        cout << i+1 << "\t";
        if(N1>9)
        {cout << " ";}
        if(N1>99)
        {cout << " ";}
        cout << "X=" << X[i] << "\t" << "Xcp=" << Xcp << "\n"; }
        if (i > N-1)
        {
            X[i]=plant_measure(M, plant);
            sum=sum-X[t]+X[i];
            t++;
            Xcp=sum/N;
            cout << i+1 << "\t";
            if(N1>9)
            {cout << " ";}
            if(N1>99)
            {cout << " ";}
            cout << "X=" << X[i] << "\t" << "Xcp=" << Xcp << "\n";
        }
      }
    }
}

int main()
{
    int M,N,N1;
    vvod(M,N,N1);
    schet(M,N,N1);
    return 0;
}
