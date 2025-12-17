//============================================================================
// Name        : Tema1_1.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Calculo de a=b cubo +2
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int a,b;
	b=0;
	a= b*b*b+2;
	cout<<"Si b="<<b<<", entonces a="<<a<<endl;
	b=3;
	a= b*b*b+2;
	cout<<"Si b="<<b<<", entonces a="<<a<<endl;
	b=-3;
	a= b*b*b+2;
	cout<<"Si b="<<b<<", entonces a="<<a<<endl;

	return 0;
}
