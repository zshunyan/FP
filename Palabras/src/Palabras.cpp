//============================================================================
// Name        : Palabras.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Lectura de fichero Palabra
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#define MAXLET 5
typedef char palabra [MAXLET+1];

int main()
{
	ifstream in;
	palabra pal;
	int num_pal=0;
	in.open ("Palabras.txt");
	if(in.fail())//comprobar que no hay fallos en la apertura de fichero
	{
		cout<<"Fichero de palabras no encontrado"<<endl;
	}
	else
	{
		in>>pal;//lectura de pantalla
		while (!in.eof())//mientras no sea fin de fichero
		{
			cout<<pal<<endl;
			num_pal++;
			in>>pal;
		}
	}
	in.close();//cerrar fichero
	cout<<"Ha leido "<<num_pal<<" palabras";

	return 0;
}
