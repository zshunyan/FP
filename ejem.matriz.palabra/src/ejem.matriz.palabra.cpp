//============================================================================
// Name        : palabra.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#define maxint 6//n max de intentos para acertarla
#define maxlet 5//max num de letra de la palabra
#define maxpal 100//maximo de palabra en el fichero
typedef char palabra [maxlet+1];//desde 0-99 (100 palabras)

typedef char palabras [maxpal][maxlet];
void volcar_palabras (palabras p, int&total_pal);

using namespace std;

int main() {
	palabras p;
	int total_pal;
	volcar_palabras(p,total_pal);

	for(int i=0;i<total_pal; i++)
	{
		for(int j=0;j<maxlet; j++)
		{
			cout<<p[i][j];
		}

		cout<<endl;
	}

	return 0;
}


void volcar_palabras (palabras p, int&total_pal)
{
	ifstream in;
	palabra pal;
	int j=0;
	in.open ("Palabras.txt");
	if (in.fail())
	{
	    cout<<"Fichero de palabras no encontrado"<<endl;
	}
	else
	{
		in>>pal;//lo mismo que cin num;
		cout<<"primera palabra leida "<<pal<<endl;

	while(!in.eof())
	{
		for (int i=0;i<maxlet;i++)
		{
			p[j][i]=pal[i];
		}
		j++;
		in>>pal;
	}
	}
	in.close();
	total_pal = j;
}
