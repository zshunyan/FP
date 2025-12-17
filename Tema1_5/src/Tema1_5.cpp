//============================================================================
// Name        : Tema1_5.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Comprueba de resultado 1,2,3 para a,b,c
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"Introduce tres numeros:";
	cin>>a>>b>>c;
	a=b; b=c; c=a;
	//despues de esta linea, se aparecera en el resulado en vez de a, aparece la b,el b se aparece como c, y la c se aparece como a. Si uqeremos que en el resultado aparezca en orden que introducimos, pues debe quitar la linea anterior.

	cout<<endl<<"El resultado es:"<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
