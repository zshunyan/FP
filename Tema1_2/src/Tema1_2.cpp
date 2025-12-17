//============================================================================
// Name        : Tema1_2.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Indice de masa corporal de una persona
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	float peso, altura, imc;
	cout<<"Introduzca peso";
	cin>>peso;
	cout<<"introduzca altura:";
	cin>>altura;
	imc=peso/(altura*altura);
	cout<<"Su IMC es: "<<imc<<endl;

	return 0;
}
