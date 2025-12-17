//============================================================================
// Name        : E7_shunyaz.cpp
// Author      : shunya zhan
// Version     :
// Copyright   : Your copyright notice
// Description : practica 7
//============================================================================

#include <iostream>

#include <windows.h>
using namespace std;
//definimos CONSTANTES
#define filas 6
#define columnas 5
//definimos TIPOS DE DATOS
typedef char cadena[columnas+1];
//tipo de datos casilla. Es un registro formado por dos campos:
//letra de tipo char
//y acierto de tipo entero
typedef struct
{
	char letra;
	int acierto;
}casilla;
//tipo de datos matriz. Es una matriz de 6 filas por 5 columnas
//cada elemento de la matriz es de tipo casilla
typedef casilla matriz [filas][columnas];
//PROTOTIPOS de funciones y procedimientos
void inicializar_matriz (matriz m);
void mostrar_matriz (const matriz m);
//PROTOTIPOS DE MODULOS QUE DEBERAS IMPLEMENTAR, Y PROBAR SU CORRECTO FUNCIONAMIENTO
void leer_letra (matriz m, int fila,int columna);
void leer_fila (matriz m, int fila);
char que_letra (const matriz m, int fila,int columna);
int que_valor (const matriz m, int fila, int columna);
void compara_actualiza (const cadena padivina, matriz m, int fila);
bool iguales_a_uno (const matriz m, int fila);


int main()
{
	bool igual;
	matriz m;
	cadena padivina="bucle";
	inicializar_matriz(m);
	//leer_letra(m,0,4);
	//leer_fila(m,0);
	int fila;

	//Deberas leer cada fila de la matriz letra a letra
	//y compararla con la palabra padivina
	//si acierta la palabra en menos de 7 intentos,
	//muestra un mensaje "Has acertado la palabra en tantos intentos"
	//si no acierta la palabra en los 6 intentos,
	//mostrara el mensaje "En la siguiente partida lo conseguiras, la palabra era padivina"
	fila=0;
	igual=false;
	cout<<"Adivina la palabra de 5 letra, tienes 6 intentos: "<<endl;
	while(!igual && fila<filas)
	{
		cout<<"Introduce la palabra:"<<endl;
		leer_fila(m,fila);
		compara_actualiza(padivina, m, fila);
		igual=iguales_a_uno(m,fila);
		mostrar_matriz(m);

		/*for(int i=0; i<6; i++)
	{
		if(igual==true)
			{
				cout<<"Has acertado la palabra!"<<endl;
				cout<<"En "<<i<<" intentos"<<endl;
			}
		//while(i>=6 || igual==false)
		else
		{
			cout<<"En la siguiente partida lo conseguiras, la palabra era "<<padivina<<endl;
		}
	}*/

		fila++;
	}
	/*if (igual) {
		cout << "Has acertado la palabra!" << endl;
		cout << "En " << fila - 1 << " intentos" << endl;
		Sleep(3000);
		cout << "Fin del programa, hasta luego!!!" << endl;
		Sleep(2000);
	}
	else
	{
		cout << "En la siguiente partida lo conseguirás, la palabra era " << padivina << endl;
		Sleep(3000);
	}*/

	if (igual) {
		cout << "Has acertado la palabra!" << endl;
		cout << "En " << fila << " intentos" << endl;
		Sleep(3000);
	} else {
		cout << "En la siguiente partida lo conseguiras, la palabra era " << padivina << endl;
		Sleep(3000);
	}

	mostrar_matriz(m);
	Sleep(3000);
	cout << "Fin del programa, hasta luego!!!" << endl;
	Sleep(3000);

	/*cout<<que_letra(m,0,4);
cout<<que_valor(m,0,4);
compara_actualiza(padivina,m,0);
igual=iguales_a_uno (m,1);
cout<<igual;*/


	//dada una fila y una columna leidas por teclado
	//mostrar la letra y el valor de acierto en esa posicion de la matriz
	return 0;
}//fin main



//IMPLEMENTACION DE MODULOS ****************************************
//procedimiento para inicializar la matriz con blancos y ceros
void inicializar_matriz (matriz m)
{
	for (int i=0;i<filas;i++)
	{
		for (int j=0;j<columnas;j++)
		{
			m[i][j].letra =' ';
			m[i][j].acierto =0;
		}
	}
}
//procedimiento para mostrar la matriz por consola por filas
void mostrar_matriz (const matriz m)
{
	for (int i=0;i<filas;i++)
	{
		for (int j=0;j<columnas;j++)
		{
			cout<<m[i][j].letra<<" "<<m[i][j].acierto<<" ";
		}
		cout<<endl;
	}
}

//procedimiento que permite leer una letra de la matriz (paso por variable) colocada en una
//determinada fila y columna pasados por parametros por valor

void leer_letra (matriz m, int fila,int columna)
{
	cin>>m[fila][columna].letra;
}

//procedimiento para leer todas las letras de una determinada fila (paso por valor)
//de la matriz (pasada por variable)

void leer_fila (matriz m, int fila)
{
	for(int i=0; i<columnas;i++)
	{
		leer_letra(m,fila,i);
	}
}

//función que devolvera la letra que existe en la matriz en una determinada fila y columna
//pasadas por parametros
//RECUERDA QUE LA ULTIMA SENTENCIA DE UNA FUNCION DEBE SER UN RETURN CON EL VALOR QUE DEVUELVA

char que_letra (const matriz m, int fila,int columna)
{
	return m[fila][columna].letra;
}

//funcion que devolvera el valor de acierto en la matriz en una determinada fila y columna
//pasadas por parametros por valor

int que_valor (const matriz m, int fila, int columna)
{
	return m[fila][columna].acierto;
}

//procedimiento que compara las letras de una fila de la matriz con la palabra padivina
//actualizando los valores de acierto de cada letra

void compara_actualiza (const cadena padivina, matriz m, int fila)
{
	/*bool encontrado=false;
int j=0;
	for(int i=0; i<columnas; i++)
	{
		j=0;
		while(!encontrado && j<columnas)
		{
			if (m[fila][i].letra==padivina[i])
					{
						m[fila][i].acierto=1;
					}
					else
					{
						m[fila][i].acierto=0;
					}
			j++;
		}


	}*/
	for (int i = 0; i < columnas; i++) {
		if (m[fila][i].letra == padivina[i])
		{
			m[fila][i].acierto = 1;
		} else {
			m[fila][i].acierto = 0;
		}
	}

}

//funcion que devolvera verdadero o falso en función de los valores
//de acierto de una determinada fila en la matriz
//devuelve verdadero si todos los valores de acierto de esa fila son iguales a uno
//devuelve falso en caso contrario

bool iguales_a_uno (const matriz m, int fila)
{
	int i=0;
	bool iguales;
	iguales=true;
	while(i<columnas && iguales==true)
	{
		if (m[fila][i].acierto==1)
		{
			iguales=true;
		}
		else
		{
			iguales=false;
		}
		i++;
	}
	return iguales;
}

