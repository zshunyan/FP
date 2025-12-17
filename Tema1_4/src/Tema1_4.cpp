//============================================================================
// Name        : Tema1_4.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Calcular la ecuacion de ax^2+bx+c
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,x;
	cout<<"Introduzca tres numeros:";
	cin>>a>>b>>c;
	cout<<"Introduzca un numero para x:";
	cin>>x;
	d=a*x*x+b*x+c;
	cout<<"Tu resultado de la ecuacion es:"<<d;

	return 0;
}
