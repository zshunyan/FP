//============================================================================
// Name        : Jugador.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define maxnombre 10
typedef char maxcadena [maxnombre];
#define maxint 6
typedef int aciertos[maxint];
#define maxjug 100

typedef struct
{
	maxcadena nombre;
	int numvecesjug;
	aciertos numaciertos;
}jugador;

typedef jugador jugadores [maxjug];




using namespace std;

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	return 0;
}

