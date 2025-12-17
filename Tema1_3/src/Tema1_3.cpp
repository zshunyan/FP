//============================================================================
// Name        : Tema1_3.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Minuscula a mayuscula
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char letra, a;
	cout<<"Introduzca un letra minuscula:";
	cin>>letra;
	a=letra-32;
	cout<<"Su mayuscula es:"<<a<<endl;

	return 0;
}
