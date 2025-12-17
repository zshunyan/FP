//============================================================================
// Name        : E8_shunyaz.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : visualizar jugador
//============================================================================

#include <iostream>
#include <conio2.h>
#include <fstream> //LIBRERÍA PARA USAR FUNCIONES DE FICHEROS
#include <windows.h>
#include <time.h>
using namespace std;
//CONSTANTES------------------------------------------------------------------------
#define maxnombre 10 //maximo de caracteres para el nombre del participante
#define maxjug 100 //maximo de jugadores
#define maxseg 10
//TIPOS DE DATOS --------------------------------------------------------------------

typedef char maxcadena [maxnombre];
//del participante necesitamos los siguientes datos
//nombre
//numero de veces que ha jugado

typedef struct
{
	maxcadena nombre;
	int numvecesjug;
}jugador;

typedef jugador jugadores[maxjug]; //vector de jugadores

//PROTOTIPOS-------------------------------------------------------------------------------------
void volcar_jugadores (jugadores v_jug, int & totaljug);
void jugadores_fichero (jugadores v_jug, int totaljug);
int buscar_jugador(const maxcadena nombrejug, const jugadores v_jug, int totaljug);
void hidecursor(bool oculta);
char comprobar_respuesta(char resp);

void mostrar_jugadores();
//-------------------------------------------------------------------------------------------
int main()
{
	int totaljug,encontrado,vez,segundos;
	maxcadena nombrejug;
	jugador auxjug;
	char resp;
	jugadores v_jug;//vector que almacenara a los jugadores que existen
	//llama al modulo ___mostrar_jugadores (____________);
	mostrar_jugadores();
	//--------------------------------------------------------------------------------------------
	//leemos el fichero de jugadores y lo almacenamos en un vector


	//leemos el nombre del jugador


	//si existe visualizamos el numero de veces que ha jugado, mensaje


	//si no existe le daremos de alta, mensaje

	//bucle para repetir las veces que deseemos jugar
	vez =0;
	segundos =0;
	auxjug.numvecesjug=0;
	cout<<"WORDLE Juego para adivinar palabras"<<endl;
	cout<<"Desea jugar s/n:";
	cin>>resp;
	resp = tolower(resp);//comprobar
	resp= comprobar_respuesta(resp);
	while (resp=='s')
	{
		if (vez==0)
		{
			volcar_jugadores (v_jug,totaljug);
			//datos del jugador
			cout<<"Introduzca su nombre:";
			cin>>nombrejug;
			nombrejug[strlen(nombrejug)]='\0';
			encontrado = buscar_jugador(nombrejug, v_jug,totaljug);
			//encontrado tendra la posición del jugador en el vector
			if (encontrado!=-1)
			{
				cout<<"Hola de nuevo "<<nombrejug<<endl;
				auxjug=v_jug[encontrado];
			}
			else
			{
				cout<<"Bienvenido "<<nombrejug<<" este juego te enganchara"<<endl;
				//inicializar los datos del jugador
				strcpy(auxjug.nombre,nombrejug);
			}
			vez++;
		}
		auxjug.numvecesjug++;
		cout<<"Simulamos que esta jugando la partida de wordle, esperamos "<<maxseg<<"segundos"<<endl;
		while (segundos <maxseg)
		{
			segundos++;
			hidecursor(false);
			textcolor(LIGHTGREEN);
			gotoxy(10,8);
			printf("[ %.2d ]",segundos);
			Sleep(1000);
		}
		hidecursor(true);
		textcolor(WHITE);
		segundos =0;
		if (encontrado!=-1)//el jugador ya existia
		{
			v_jug[encontrado]= auxjug;
		}
		else //jugador nuevo
		{
			v_jug[totaljug]= auxjug;
		}
		clrscr();
		cout<<"Desea jugar de nuevo s/n:";
		cin>>resp;
		resp= tolower(resp);//comprobar
		resp= comprobar_respuesta(resp);
	}//fin while
	if (encontrado ==-1)
	{
		totaljug++;
	}
	//actualizar fichero de jugadores siempre que se haya jugado
	if (vez!=0)
	{
		jugadores_fichero (v_jug,totaljug);
	}
	if(resp=='n'){
		cout<<("Fin del programa, hasta luego!!!");
		Sleep(2000);
	}
	return 0;
}//fin int main


//PASAR EL FICHERO DE JUGADORES A VECTOR DE JUGADORES
void volcar_jugadores (jugadores v_jug, int & totaljug)
{
	ifstream fjug;//fichero de lectura
	jugador jug;
	totaljug=0;
	int j=0;
	fjug.open ("Jugadores.txt");
	if (fjug.fail()) //si no se puede abrir el fichero
	{
		cout<<"Fichero de jugadores no encontrado"<<endl;
	}
	else
	{
		fjug>>jug.nombre; //leer del fichero hasta el primer blanco que encuentre
		while (!fjug.eof()) //mientras no sea fin de fichero
		{
			strcpy(v_jug[j].nombre, jug.nombre);
			fjug>>v_jug[j].numvecesjug;
			j++;
			totaljug++;
			fjug>>jug.nombre;
		}
	}
	fjug.close();//cerrar el fichero
}
//ACTUALIZAR FICHERO JUGADORES
void jugadores_fichero (jugadores v_jug, int totaljug)
{
	ofstream outfjug;//fichero de salida o para escritura
	outfjug.open ("Jugadores.txt");
	if (outfjug.fail())
	{
		cout<<"Fichero de jugadores no encontrado"<<endl;
	}
	else
	{
		for (int i=0;i<totaljug;i++)
		{
			outfjug<<v_jug[i].nombre<<" ";
			outfjug<<v_jug[i].numvecesjug<<" "<<endl;

		}
	}
	outfjug.close();//cerrar el fichero
}
//BUSCAR JUGADOR EN EL VECTOR
int buscar_jugador(const maxcadena nombrejug, const jugadores v_jug, int totaljug)
{
	int encontrado = -1;
	int i =0;
	while (encontrado==-1 && i<totaljug)
	{
		if (strcmp(nombrejug,v_jug[i].nombre)==0)//comparamos cadenas
		{
			encontrado = i;
		}
		else
		{
			i++;
		}
	}
	return encontrado;
}
//procedimiento para visualizar u ocultar el cursor
void hidecursor(bool oculta)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 10;
	info.bVisible = oculta;
	SetConsoleCursorInfo(consoleHandle, &info);
}
char comprobar_respuesta(char resp)
{
	while (resp!='s' && resp!='n')
	{
		cout<<"Incorrecto, vuelve a introducir s o n:";
		cin>>resp;
		resp=tolower(resp);
	}
	return resp;
}

//mostrar jugador en el fichero
void mostrar_jugadores (void)
{
	ifstream ficjug;//fichero de lectura
	jugador jug;
	ficjug.open ("Jugadores.txt");
	if (ficjug.fail()) //si no se puede abrir el fichero
	{
		cout<<"Fichero de jugadores no encontrado"<<endl;
	}
	else
	{
		ficjug>>jug.nombre;
		while (!ficjug.eof())
		{
			cout<<jug.nombre<<endl;
			ficjug>>jug.nombre;
			ficjug>>jug.nombre;
		}
	}
	ficjug.close();//cerrar el fichero
}

//no lo entiendo por que no me hace nada mas despues de contestar 'si'
