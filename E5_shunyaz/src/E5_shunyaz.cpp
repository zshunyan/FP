//============================================================================
// Name        : E5_shunyaz.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Bucles For
//============================================================================

#include <iostream>
#include <conio2.h>
#include <windows.h>
using namespace std;

#define FILAS 6
#define COLUMNAS 5
#define MIN_FIL 1
#define MAX_FIL 10
#define MIN_COL 1
#define MAX_COL 10

#define DIST_MIN_FIL 1
#define DIST_MAX_FIL 4
#define DIST_MIN_COL 1
#define DIST_MAX_COL 4

#define ESPERA 2000


char comprobar_respuesta(char resp);

int comprobar_valor(int valor, int max, int min );

int main()
{
	/*
=============================================================
//INTRODUCCION:

 	int cont, num;
	cin>>num;
	while(num<0 || num>10)
	{
		cout<<"ERROR";
		cin>>num;
	}
		cont=0;
		while (cont<=10)
		{
			cout<<num<<"*"<<cont<<"="<<num*cont<<endl;
			cont++;
		}

		for (int contador=0; contador<=10; contador++)
	    {
	    cout<<"Tabla del "<<contador<<endl;
		for (cont=0; cont<=10; cont++)
		{
			cout<<contador<<"*"<<cont<<"="<<contador*cont<<endl;
		}
		}
=============================================================


//=============================================================
//PRIMERA PARTE:

	//declaracion de variables

	int inifila,inicol,distfila,distcol,auxfil,auxcol,c;
	char resp;

	cout<<"Mi primer programa con bucles FOR"<<endl<<endl;
	cout<<"Desea ejecutar el programa de bucles FOR? S o N:";
	cin>>resp;
	resp=toupper(resp);
	//toupper es una funcion, que en este caso realiza lo siguiente:
	//If resp is a lower-case letter, toupper returns the corresponding upper-case letter.
	//Otherwise resp is returned unchanged.
	while (resp!='S' && resp!='N')
	{
	cout<<"Incorrecto, vuelve a introducir S o N:";
	cin>>resp;
	resp=toupper(resp);
	}
	while (resp=='S')
    {
	cout<<"Ha elegido ejecutar el programa de bucles FOR"<<endl;
	//---------------------------------------------------------
	cout<<"Introduzca el numero de fila inicial entre [1,10]:";
	cin>>inifila;
	while (inifila>MAX_FIL || inifila<MIN_FIL)
	{
		cout<<"Error, introduzca otra vez:"<<endl;
		cin>>inifila;
	}

	cout<<"Introduzca el numero de columna inicial entre [1,10]:";
	cin>>inicol;
	while (inicol>MAX_COL || inicol<MIN_COL)
		{
			cout<<"Error, introduzca otra vez:"<<endl;
			cin>>inicol;
		}
	cout<<"Introduzca distancia entre columnas [1,4]:";
	cin>>distcol;

while (distcol>DIST_MAX_COL || distcol<DIST_MIN_COL)
{
	cout<<"Error, introduzca otra vez:"<<endl;
	cin>>distcol;
}

	cout<<"Introduzca distancia entre filas [1,4]:";
	cin>>distfila;

while (distfila>DIST_MAX_FIL || distfila<DIST_MIN_FIL)
	{
		cout<<"Error, introduzca otra vez:"<<endl;
		cin>>distfila;
	}
clrscr();
	 auxcol=inicol;
	 auxfil=inifila;
c=1;
for (int k=0; k<FILAS; k++)
{
	textcolor(c);
	for(int j=0; j<COLUMNAS; j++)
	{
	    gotoxy(auxcol, auxfil);
	    printf("%c",char(219));
	    Sleep(ESPERA);
	    auxcol=auxcol+distcol;
	}
	auxcol=inicol;
	auxfil=auxfil+distfila;
	c++;
}
Sleep(ESPERA);
clrscr();


	//---------------------------------------------------------
	cout<<"Desea ejecutar el programa de bucles FOR de nuevo? S o N:";
	cin>>resp;
	resp=toupper(resp);
	while (resp!='S' && resp!='N')
	{
	cout<<"Incorrecto, vuelve a introducir S o N:";
	cin>>resp;
	resp=toupper(resp);
	}
	}//fin del bucle while (resp=='S')
	cout<<"Has terminado el programas o has elegido 'N':"<<endl;
	Sleep(ESPERA);
	cout<<"Gracias por usar nuestro programa, estamos a su disposicion las 24 horas del dia"<<endl;
	Sleep(3000);

//=============================================================


//=============================================================
//SEGUNDA PARTE Y TERCERA PARTE:
	 */

	int filaini,colini, distcol, distfila,c, auxcol, auxfil;
	char resp, letra, letra_aux1, letra_aux2;

	cout<<"Mi primer programa con bucles FOR"<<endl<<endl;
	cout<<"Desea ejecutar el programa de bucles FOR? S o N:";
	cin>>resp;
	resp=toupper(resp);

	resp=comprobar_respuesta(resp);

	while (resp=='S')
	{
		cout<<"Introduzca el numero de fila inicial ["<<MIN_FIL<<","<<MAX_FIL<<"]:";

		cin>>filaini;

		filaini=comprobar_valor( filaini, MAX_FIL, MIN_FIL);

		cout<<"Introduzca el numero de columna inicial ["<<MIN_COL<<","<<MAX_COL<<"]:";
		cin>>colini;

		colini=comprobar_valor( colini, MAX_COL, MIN_COL);

		cout<<"Introduzca distancia entre columnas [1,4]:";
		cin>>distcol;

		distcol=comprobar_valor(distcol, DIST_MAX_COL, DIST_MIN_COL);

		cout<<"Introduzca distancia entre filas [1,4]:";
		cin>>distfila;

		distfila=comprobar_valor(distfila, DIST_MAX_FIL, DIST_MIN_FIL);

		textcolor(WHITE);
		textbackground(BLACK);
		clrscr();
		auxcol=colini;
		auxfil=filaini;
		//==========================================
		//PARTE 3:

		c=15;
		for (int k=0; k<FILAS; k++)
		{
			textcolor(c);
			for(int j=0; j<COLUMNAS; j++)
			{
				gotoxy(auxcol, auxfil);
				printf("%c",char(219));
				Sleep(ESPERA);
				auxcol=auxcol+distcol;
			}
			auxcol=colini;
			auxfil=auxfil+distfila;
		}
		gotoxy(1,1);
		cout<<"Introducen las letras:";
		letra_aux1='a';
		letra_aux2='e';

		auxfil=filaini;
		for (int k=0; k<FILAS; k++)
		{
			auxcol=colini;
			for (int i=0; i<COLUMNAS; i++)
			{
				gotoxy(auxcol,auxfil);
				cin>>letra;
				textcolor(WHITE);
				if (letra==letra_aux1)
				{
					gotoxy(auxcol,auxfil);
					textbackground(GREEN);
					printf("%c",letra);
				}
				else
				{

					if(letra==letra_aux2)
					{
						gotoxy(auxcol,auxfil);
						textbackground(BROWN);
						printf("%c",letra);
					}
					else
					{
						gotoxy(auxcol,auxfil);
						textbackground(DARKGRAY);
						printf("%c",letra);
					}

				}
				auxcol=auxcol+distcol;
			}
			auxfil=auxfil+distfila;
		}

		/*
	c=1;
	for (int k=0; k<FILAS; k++)
	{
		textcolor(c);
		for(int j=0; j<COLUMNAS; j++)
		{
		    gotoxy(auxcol, auxfil);
		    printf("%c",char(219));
		    Sleep(ESPERA);
		    auxcol=auxcol+distcol;
		}
		auxcol=colini;
		auxfil=auxfil+distfila;
		c++;
	}*/
		//===========================================
		Sleep(ESPERA);
		textcolor(WHITE);
		textbackground(BLACK);
		clrscr();
		cout<<"Desea ejecutar el programa de bucles FOR de nuevo? S o N:";
		cin>>resp;
		resp=toupper(resp);
		resp=comprobar_respuesta(resp);

	}//fin del bucle while (resp=='S')
	cout<<"Has terminado el programas o has elegido 'N':"<<endl;
	Sleep(ESPERA);
	cout<<"Gracias por usar nuestro programa, estamos a su disposicion las 24 horas del dia"<<endl;
	Sleep(3000);

	return 0;
}

char comprobar_respuesta(char resp)
{
	while (resp!='S' && resp!='N')
	{
		cout<<"Incorrecto, vuelve a introducir S o N:";
		cin>>resp;
		resp=toupper(resp);
	}
	return resp;
}


int comprobar_valor(int valor, int max, int min )
{

	//cin<<valor;
	while (valor>max || valor<min)
	{
		cout<<"Incorrecto, vuelve a introducir:";
		cin>>valor;
	}
	return valor;
}


