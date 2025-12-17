//============================================================================
// Name        : E2_shunyaz.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
//¿que hacen las 3 lineas siguientes?
//definen color
#define maxfil 25
#define maxcol 80
#define maxcolor 16
int main()
{
//¿que signfica esta sentencia? y que pasa si no la ponemos?
	srand(time(NULL));
//tomamos la semilla en la funcion de la función de la hora del procesador. sigue funciona si lo quitamos.
//¿De que tipo son las variables y porque se han puesto esos tipos?
		//char son la del letra,int es de numeros enteros, y son lo que necesito//
//¿Es correcto?
//Si, letra es char, fila,columna y color son un entero//



char resp,letra;
//int fila,columna;
int color;
//¿que signfica esta sentencia?
	clrscr();
	//colocar el cursor en la esquina superior izquierda
	//¿Cual sera el valor de la variable color?
	color = rand()%maxcolor;
	/*textcolor(color);
	//color aleatorio 0-15
	//¿Cual sera el valor de la variable fila, es correcto?
	fila=rand()%maxfil;
	//un color aleatorio 25 en fila,es correcto
	//¿Cual sera el valor de la variable columna, es correcto?
	columna=rand()%maxcol;
	//un color aleatorio 80 en columna, es correcto
	//¿que signfica esta sentencia?
	gotoxy(columna,fila);
	//mueve el cursor a la posición dada en la ventana del texto actua
	//¿que signfica esta sentencia?
	printf("%c",letra);
	//cadena de formato
	//¿que signfica esta sentencia?
	Beep(1000,200);
	//sonido,hz
	//¿que signfica esta sentencia?
	Sleep(5000);
	// retarda la ejecución de una instancia durante un período de tiempo determinado
	*/
cout<<" ejecutar el programa s/n:";
cin>>resp;
if (resp=='s' || resp=='S')

{
	cout<<"Ha decidido ejecutar el programa"<<endl;
cout<<"Introduzca una letra:";
cin>>letra;
gotoxy(1,1);
//mueve el cursor a la posición dada en la ventana del texto actual
//¿que signfica esta sentencia?
textbackground(BROWN);
textcolor(WHITE);
printf("%c",letra);//reemplaza por el valor de la variable contador y se imprime la cadena resultante.
Sleep(3000);//retarda el tiempo de ejecutar

gotoxy(79,1);//se coloca el curso en posision (79,1)
textbackground(GREEN);//fondo de texto
textcolor(DARKGRAY);//color de texto
printf("%c",letra);//reemplaza por el valor de la variable contador y se imprime la cadena resultante.
Sleep(3000);//retarda el tiempo de ejecutar

gotoxy(1,24);//se coloca el curso en posision (1,24)
textbackground(BLUE);//fondo de texto
textcolor(WHITE);//color de texto blanco
printf("%c",letra);//introducimos un valor de variable chat(letra)
Sleep(3000);//retarda el tiempo de ejecutar

gotoxy(79,24);//se coloca el curso en posision (79,24)
textcolor(RED);//restauramos el color del texto
printf("%c",letra);//reemplaza por el valor de la variable contador y se imprime la cadena resultante.
Sleep(3000);//retarda el tiempo de ejecutar

gotoxy(40,12);//se coloca el curso en posision (40,12)
textbackground(YELLOW);//fondo de texto
printf("%c",letra);//reemplaza por el valor de la variable contador y se imprime la cadena resultante.
Sleep(3000);//retarda el tiempo de ejecutar

}
else
{
	cout<<"Hasta pronto";
	Sleep(3000);
}
return 0;
}
