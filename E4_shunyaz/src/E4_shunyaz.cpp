//============================================================================
// Name        : E4_shunyaz.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Programa con bucles WHILE
//============================================================================

#include <iostream>
using namespace std;
int main()
{
//declarar todas las variables necesarias para resolver esta practica
char resp,letra;
int numero,num_par;
cout<<"Mi primer programa con bucles WHILE"<<endl<<endl;
cout<<"Desea ejecutar el programa s/S/n/N:";
cin>>resp;

while (	resp!='s' && resp!='S' && resp!='n' &&resp!='N')//completa para que el usuario solo introduzca s,S,n,N
    {
		cout<<"Incorrecto, vuelve a introducir s,S,n,N:";
	    cin>>resp;
    }
while (resp=='s' || resp=='S')
 {
    cout<<"Ha elegido ejecutar el programa"<<endl;
    cout<<"Introducir un numero >=0:";
    cin>>numero;

    while (numero<0)
    {
    	cout<<"Incorrecto, introduce un valor >=0:";
    	cin>>numero;
    }
    cout<<"Perfecto, has introducido "<<numero<<" que es un valor >=0"<<endl;


    cout<<"Introducir un valor par:";
    cin>>num_par;
    while(num_par%2!=0)
    {
    	cout<<"Incorrecto, introduce un valor par:";
    	cin>>num_par;
    }
    cout<<"Perfecto, has introducido "<<num_par<<" que es Par"<<endl;

    cout<<"Introducir una letra (a..z, A..Z):";
    cin>>letra;
    while ((letra<'a' || letra>'z') && (letra <'A' || letra>'Z'))
    {
    	cout<<"Incorrecto, introduce una letra (a..z, A..Z):";
    	cin>>letra;
    }
    cout<<"Perfecto, has introducido "<<letra<<" que es una letra"<<endl;

    cout<<"Desea ejecutar el programa de nuevo s/S/n/N:";
    cin>>resp;
 }

cout<<"Finalizamos el programa, has decidido terminar porque has introducido una n o N"<<endl;

return 0;
}
