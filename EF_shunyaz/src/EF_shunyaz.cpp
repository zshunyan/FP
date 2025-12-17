//============================================================================
// Name        : EF_shunyaz.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Juego WORDLE
//============================================================================

#include <iostream>
#include <conio2.h>
#include <fstream>
#include <windows.h>
#include <time.h>

using namespace std;

#define maxnombre 10 //maximo de caracteres para el nombre del participante
#define maxjug 100 //maximo de jugadores
#define maxseg 10
#define ESPERA 3000
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
#define maxletras 5
typedef char cadena [maxletras+1];
typedef int vector [maxletras];
typedef char maxcadena [maxnombre];

typedef struct
{
	maxcadena nombre;
	int numvecesjug;
	int dia;
		int mes;
		int anio;
		int numvecesacierto;
		int cero;
}jugador;
typedef jugador jugadores[maxjug]; //vector de jugadores


void volcar_jugadores (jugadores v_jug, int & totaljug);
void jugadores_fichero (jugadores v_jug, int totaljug);
int buscar_jugador(const maxcadena nombrejug, const jugadores v_jug, int totaljug);
int comprobar_valor(int valor, int max, int min );
void hidecursor(bool oculta);
char comprobar_respuesta(char resp);
void mostrar_jugadores(void);

//-------------------------------------------------------------------------------------------
int main()
{
	int totaljug,encontrado,vez,segundos, filaini,colini, distcol, distfila,c, auxcol, auxfil,p, dia, mes, anio,auxdia,auxmes,auxanio;
	char resp;
	bool encontrada, encon;
	cadena pleida;
	cadena padivina = "bucle";
	vector v;
	int j;
	maxcadena nombrejug;
	jugador auxjug;
	jugadores v_jug;
	mostrar_jugadores();
	vez =0;
	segundos=0;
	auxjug.dia=0;
	auxjug.mes=0;
	auxjug.anio=0;
	auxjug.numvecesacierto=0;
	auxjug.cero=0;

	auxdia=27;
	auxmes=6;
	auxanio=2005;

	auxjug.numvecesjug=0;
	encon=false;
	for (int i=0;i<maxletras;i++)
	{
		v[i]=0;
	}
	cout<<"WORDLE Juego para adivinar palabras"<<endl;
	cout<<"Desea jugar s/n:";
	cin>>resp;
	resp = tolower(resp);
	resp= comprobar_respuesta(resp);
	while (resp=='s')
	{
		if (vez==0)
		{
			volcar_jugadores (v_jug,totaljug);
			cout<<"Introduzca su nombre:";
			cin>>nombrejug;
			nombrejug[strlen(nombrejug)]='\0';
			encontrado = buscar_jugador(nombrejug, v_jug,totaljug);
			if (encontrado!=-1)
			{
				cout<<"Hola de nuevo "<<nombrejug<<endl;
				auxjug=v_jug[encontrado];
				cout<<"Fecha nacimiento:"<<dia<<"/"<<mes<<"/"<<anio<<endl;;
			}
			else
			{
				cout<<"Introduzca su fecha de nacimiento dia/mes/anio"<<endl;;
				cout<<"Introduzca dia:";
				cin>>auxjug.dia;
				while(auxjug.dia<1 || auxjug.dia>31){
					cout<<"Error, el dia >=1 y <=31:";
					cin>>auxjug.dia;
				}
				cout<<"Introduzca mes";
				cin>>auxjug.mes;
				while(auxjug.mes<1 || auxjug.mes>12){
					cout<<"Error, el mes >=1 y <=12:";
					cin>>auxjug.mes;
				}
				cout<<"Introduzca anio:";
				cin>>auxjug.anio;

				auxanio=2023-auxjug.anio;
				if(auxanio<18 && auxjug.mes>auxmes && auxjug.dia>auxdia){
					cout<<nombrejug<<" para jugar debes tener 18 anios"<<endl<<"Cuando seas mayor de edad, podras jugar"<<endl;
					break;
				}
				else{
				cout<<"Bienvenido "<<nombrejug<<"， este juego te enganchara"<<endl;
				strcpy(auxjug.nombre,nombrejug);
				}
			}
			vez++;
		}
		auxjug.numvecesjug++;
		cout<<"Vamos a pintar los cuadrito que necesitamos para el WORDLE. Espera 3 segundo...: ";
		Sleep(3000);
		clrscr();

		cout<<"Te recomendamos que no lo intruzca en (1,1)"<<endl;
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
		filaini=5;
		colini=5;
		distcol=2;
		distfila=2;

		textcolor(WHITE);
		textbackground(BLACK);
		clrscr();
		auxcol=colini;
		auxfil=filaini;
		c=15;
		for (int k=0; k<FILAS; k++)
		{
			textcolor(c);
			for(int j=0; j<COLUMNAS; j++)
			{
				gotoxy(auxcol, auxfil);
				printf("%c",char(219));
				//Sleep(ESPERA);
				auxcol=auxcol+distcol;
			}
			auxcol=colini;
			auxfil=auxfil+distfila;
		}
		gotoxy(1,1);
		cout<<"Introducen las letras de uno en uno:";

		auxcol=colini;
		auxfil=filaini;
		gotoxy(auxcol,auxfil);

		//auxfil=filaini;

		p=0;
		while  (p<FILAS)
		{
			auxcol=colini;

			for (int i=0; i<COLUMNAS; i++)
			{

				gotoxy(auxcol,auxfil);
				cin>>pleida[i];
				//textcolor(WHITE);
				//cout<<j;
				//getch(); visualizar lo que tiene el variable 'j'
				j=0;
				encontrada=false;
				while (j<COLUMNAS && !encontrada)
				{
					if (padivina[j]==pleida[i])
					{
						if (j==i)
						{
							v[i]=1;
							//cout<<" ddd";
							gotoxy(auxcol,auxfil);
							textbackground(BLUE);
							textcolor(WHITE);
							printf("%c",pleida[i]);

						}
						else
						{
							v[i]=2;
							//cout<<"kkk";
							gotoxy(auxcol,auxfil);
							textbackground(YELLOW);
							textcolor(BLACK);
							printf("%c",pleida[i]);
						}
						encontrada=true;
					}

					j++;
				}//fin while
				if(encontrada==false)
				{
					gotoxy(auxcol,auxfil);
					textbackground(DARKGRAY);
					printf("%c",pleida[i]);

				}
				auxcol=auxcol+distcol;

			}//fin for columna
			auxfil=auxfil+distfila;
			int i=0;
			bool iguales;
			iguales=true;
			while(i<COLUMNAS && iguales==true)
			{
				if (v[i]==1)
				{
					iguales=true;
				}
				else
				{
					iguales=false;
				}
				i++;
			}
			if(iguales==true)
			{
				Sleep(1000);
				textbackground(BLACK);
				textcolor(WHITE);
				clrscr();
				gotoxy(1,1);
				cout<<"Has adivinado la palabra! que es '"<<padivina<<"'"<<endl;
				Sleep(2000);
				encon=true;//si se ha adivinado la palabra, se actualiza este variable
				auxjug.numvecesacierto++;
				break;
			}

			p++;
		}//fin while fila






		Sleep(ESPERA);
		textcolor(WHITE);
		textbackground(BLACK);
		clrscr();

		if(encon==false){
		cout << "En la siguiente partida lo conseguiras, la palabra era " << padivina << endl;
		Sleep(5000);
		}//si no habia entrado al if de iguales, significa que no se ha encontrado la palabra
		//con lo que no se actualizado el encon, significa que no ha encontrado la palabra, muestra mensaje no encontrado



		hidecursor(true);
		textcolor(WHITE);
		segundos =0;
		if (encontrado!=-1)//el jugador ya existe
		{
			v_jug[encontrado]= auxjug;
		}
		else
		{
			v_jug[totaljug]= auxjug;
		}
		clrscr();
		cout<<"Desea jugar de nuevo s/n:";
		cin>>resp;
		resp= tolower(resp);
		resp= comprobar_respuesta(resp);
	}
	if (encontrado ==-1)
	{
		totaljug++;
	}
	//actualizar fichero de jugadores
	if (vez!=0)
	{
		jugadores_fichero (v_jug,totaljug);
	}
	cout<<"Has terminado el programas o has elegido 'N':"<<endl;
	Sleep(ESPERA);
	cout<<"Gracias por usar nuestro programa, estamos a su disposicion las 24 horas del dia"<<endl;
	Sleep(ESPERA);

	return 0;
}//fin int main
//-----------------------------------------------------------------------------------------------

//PASAR EL FICHERO DE JUGADORES A VECTOR DE JUGADORES
void volcar_jugadores (jugadores v_jug, int & totaljug)
{
	ifstream fjug;//fichero de lectura
	jugador jug;
	totaljug=0;
	int j=0;
	fjug.open ("Jugadores.txt");
	if (fjug.fail())
	{
		cout<<"Fichero de jugadores no encontrado"<<endl;
	}
	else
	{
		fjug>>jug.nombre;
		while (!fjug.eof())
		{
			strcpy(v_jug[j].nombre, jug.nombre);
			fjug>>v_jug[j].numvecesjug;
			j++;
			totaljug++;
			fjug>>jug.nombre;
		}
	}
	fjug.close();
}
//ACTUALIZAR FICHERO JUGADORES
void jugadores_fichero (jugadores v_jug, int totaljug)
{
	ofstream outfjug;
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
			outfjug<<v_jug[i].dia<<" ";
			outfjug<<v_jug[i].mes<<" ";
			outfjug<<v_jug[i].anio<<" ";
			outfjug<<v_jug[i].numvecesjug<<" ";
			outfjug<<v_jug[i].numvecesacierto<<" ";
			outfjug<<v_jug[i].cero<<" ";
			outfjug<<v_jug[i].cero<<" ";
			outfjug<<v_jug[i].cero<<" "<<endl;


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
		if (strcmp(nombrejug,v_jug[i].nombre)==0)
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
			cout<<"Nombre: "<<jug.nombre<<endl;
			ficjug>>jug.numvecesjug;
			cout<<"Numero de veces que ha jugado: "<<jug.numvecesjug<<endl;
			ficjug>>jug.nombre;
		}
	}
	ficjug.close();
}

int comprobar_valor(int valor, int max, int min )
{
	while (valor>max || valor<min)
	{
		cout<<"Incorrecto, vuelve a introducir:";
		cin>>valor;
	}
	return valor;
}
