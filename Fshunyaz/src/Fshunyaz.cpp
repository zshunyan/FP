//============================================================================
// Name        : Fshunyaz.cpp
// Author      : Shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Programa que se calcula factorial de un numero
//============================================================================

#include <iostream>
#include <float.h>

using namespace std;


//prototipos de funciones y procedimientos

//prototipo de la funcion factorial para enteros entre 0 y 12
int factorial (int n);

//prototipo de la funcion factorial para enteros entre 0 y 34
float factorial_float (int n);

//prototipo de la funcion factorial para enteros entre 0 y 170
double factorial_double (int n);

//prototipo de la funcion factorial para enteros entre 0 y 1754
long double factorial_l_double (int n);

int main()
{
	int num,fact;
	float fact_float;
	double fact_double;
	long double fact_l_double;
	cout<<"Valor maximo que puede almacenar un tipo de datos int:"<<INT_MAX<<endl;
	cout<<"Valor maximo que puede almacenar un tipo de datos float:"<<FLT_MAX<<endl;
	cout<<"Valor maximo que puede almacenar un tipo de datos double:"<<DBL_MAX<<endl;
	cout<<"Valor maximo que puede almacenar un tipo de datos long double:"<<LDBL_MAX<<endl<<endl;

	cout<<"Calculo del factorial de un numero entero "<<endl;
	cout<<"Vamos a calcular el factorial con distintas funciones"<<endl;
	cout<<"que realizan lo mismo pero trabajan con diferentes tipos de datos"<<endl<<endl;

	cout<<"Recuerde que debe introducir un numero >=0 y <=1754"<<endl;
	cout<<"Introduzca el numero para calcular su factorial:";
	cin>>num;
	while (num<0 || num>1754)
	{
		cout<<"Con este programa no podemos calcular el factorial de "<<num<<endl;
		cout<<"Introduzca un numero entre 0 y 1754:";
		cin>>num;
	}

	//A partir de aqui, y en funcion del numero entero que se introduzca
	//se podria llamar a una funcion u otra
	//si el numero esta entre 0 y 12 llamar a funcion de enteros
	//si el numero esta entre 13 y 34 llamar a funcion de float
	//...

	cout<<endl;
	//llamada a la funcion factorial entero
	fact = factorial(num);
	if (fact!=-1)
	{
		cout<<"El int factorial de "<<num<<" es "<<fact<<endl;
	}
	else
	{
		cout<<"No hemos podido calcular el factorial, usando de retorno un int"<<endl;
	}

	//llamada a la funcion factorial float
	fact_float = factorial_float(num);
	if (fact_float!=-1)
	{
		cout<<"El float factorial de "<<num<<" es "<<fact_float<<endl;
	}
	else
	{
		cout<<"No hemos podido calcular el factorial, usando de retorno un float"<<endl;
	}

	//llamada a la funcion factorial double
	fact_double = factorial_double(num);
	if (fact_double!=-1)
	{
		cout<<"El double factorial de "<<num<<" es "<<fact_double<<endl;
	}
	else
	{
		cout<<"No hemos podido calcular el factorial, usando de retorno un double"<<endl;
	}

	//llamada a la funcion factorial long double
	fact_l_double = factorial_l_double(num);
	if (fact_l_double!=-1)
	{
		cout<<"El long double factorial de "<<num<<" es "<<fact_l_double<<endl;
	}
	else
	{
		cout<<"No hemos podido calcular el factorial, usando de retorno un long double"<<endl;
	}
	return 0;
}

//Funcion factorial
//Calculara y devolvera el factorial de un numero n >=0 y menor o igual que 12
//si se introduce un numero no valido devolvera -1
int factorial (int n)
{
	int fact;
	//2.147.483.647 max entero
	//6.227.020.800 factorial de 13 es mayor que max entero
	//factorial de 12: 479.001.600

	fact =1;
	if (n<0 || n>12)
	{
		fact=-1;
	}
	else
	{
		for (int i=2;i<=n;i++)
		{
			fact = fact*i;

		}
	}
	return fact;
}

//factoriales <35
//si se introduce un numero no valido devolvera -1
float factorial_float (int n)
{
	float fact;
	fact =1;
	if (n<0 || n>=35)
	{
		fact=-1;
	}
	else
	{
		for (int i=2;i<=n;i++)
		{
			fact = fact*i;

		}
	}
	return fact;
}

//factoriales <=170
//mayor double 1.79769313486232e308
//si se introduce un numero no valido devolvera -1
double factorial_double (int n)
{
	double fact;
	fact =1;
	if (n<0 || n>170)
	{
		fact=-1;
	}
	else
	{
		for (int i=2;i<=n;i++)
		{
			fact = fact*i;

		}
	}
	return fact;
}

//factoriales <=1754
//si se introduce un numero no valido devolvera -1
long double factorial_l_double (int n)
{
	long double fact;
	fact =1;
	if (n<0 || n>1754)
	{
		fact=-1;
	}
	else
	{
		for (int i=2;i<=n;i++)
		{
			fact = fact*i;

		}
	}
	return fact;
}
