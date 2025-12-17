//============================================================================
// Name        : E6_shunyaz.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Algoritmo para comparar dos palabras de 5 letras
//============================================================================

#include <iostream>
using namespace std;
#define maxletras 5
typedef char cadena [maxletras+1];
typedef int vector [maxletras];

int main()
{
	cadena pleida;
	cadena padivina = "bucle";
	vector v;
	bool encontrado;
	int j;
	//inicializamos el vector v a ceros
	for (int i=0;i<maxletras;i++)
	{
	v[i]=0;
	}
	cout<<"Introduzca palabra:";
	cin>>pleida;
	//Solo estamos comparando la posicion cero

	cout<<"El numero significa que la palabra es: 0-no acertado, 1-acertado, 2-contiene la letra"<<endl;

	//i=letra leida, j=posicion de la letra para adivinar
	for(int i=0; i<maxletras; i++)
	{
		j=0;
		encontrado=false;
		while(!encontrado && j<maxletras)
		{
			if (padivina[j]==pleida[i])
			{
				if (j==i)
				{
					v[i]=1;
				}
				else
				{
					v[i]=2;
				}
			encontrado=true;
			}

		j++;
		}
		/*if(!encontrado)
		{
			v[i]=0;
		}*/
	}




	//Mostrar las letras de las palabras y la informacion del vector v
	for (int i=0;i<maxletras;i++)
	{
	cout<<padivina[i]<<" "<<pleida[i]<<" ";
	cout<<v[i]<<endl;
	}

	return 0;
}
