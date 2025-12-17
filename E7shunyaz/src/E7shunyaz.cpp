//============================================================================
// Name        : E7shunyaz.cpp
// Author      : shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Introduccion al fichero
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#define MAX_CASI 63
#define FIL 7
#define COL 9
typedef char tablero[MAX_CASI];
int main()
{
	tablero tab_Oca;
	int i;
	char letra;
	ofstream out;//out será para el fichero de salida
	//declaramos una variable in que es de tipo fichero de lectura
	ifstream in;
	//asociamos in al fichero fisico TableroOca.txt
	in.open("TableroOca.txt");
	//antes de empezar a leer hay que comprobar que la apertura ha sido correcta
	if (in.fail())
	{
		cout<<"Se ha producido un error en la apertura del fichero TableroOca.txt"<<endl;
	}
	else
	{
		cout<<"Apertura correcta, procedemos a la lectura"<<endl;
		i=0;
		//leemos el primer dato
		in>>letra;//lectura adelantada
		while (!in.eof()) //mientras no sea fin de fichero
		{
			tab_Oca[i]= letra;
			i++;
			in>>letra;//leer otra letra
		}
		//visualizamos el vector tab_Oca
		cout<<"Vector completo"<<endl;
		for (int j=0;j<MAX_CASI;j++)
		{
			cout<<tab_Oca[j]<<" ";
		}
		cout<<endl;
		//visualizamos el vector por filas y columnas
		cout<<endl<<"Mostramos el Vector 9 filas y 7 columnas"<<endl;
		i=0;
		for (int f=0;f<FIL;f++)
		{
			for (int c=0;c<COL;c++)
			{
				cout<<tab_Oca[i]<<" ";
				i++;
			}
			cout<<endl;
		}
		//escribimos el vector en un fichero de texto cambiando las letras a minusculas
		//si el fichero no existe lo crea y si existe borra todo lo que hay
		//asociamos out al fichero fisico TableroOcamin.txt
		out.open("TableroOcamin.txt");
		if(out.fail())
		{
			cout<<"No se ha podido crear el fichero"<<endl;
		}
		else
		{
			i=0;
			for (int f=0;f<FIL;f++)
			{
				for (int c=0;c<COL;c++)
				{
					letra=tolower(tab_Oca[i]);
					out<<letra<<" ";
					i++;
				}
				out<<endl;
			}
		}
	}//fin else si apertura correcta
	//siempre hay que cerrar los ficheros antes de terminar el programa
	in.close();
	out.close();
	return 0;
}
