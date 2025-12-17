//============================================================================
// Name        : E1shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 02/10/2023
// Copyright   :
// Description : El usuario decide si quiere ejecutar el programa, en el caso de que si, dependiendo
// de su edad, se va a poder jugar o no. Despues se saca un numero aleatotrio para el dado, y el
// usuario elija la letra especificada en la informacion mostrada.
// En esta entrega utilizo el concepto de if-else, random y switch.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <stdlib.h>
using namespace std;

int main() {
	srand(time(NULL));
	char resp, letra;
	int edad, num;
	cout<<"Desea ejecutar el programa s/n:";
	cin>>resp;
	if (resp == 's' || resp=='S')
	{
		cout<<"Ha decidido ejecutar el programa"<<endl;
		cout<<"Introduzca su edad: "<<endl;
		cin>>edad;
		if (edad<8){
			cout<<"Eres demasiado pequeño para jugar a la OCA"<<endl;
		}else if (edad>99){
			cout<<"Ya no estás para estos juegos"<<endl;
		}else{
			cout<<"Estupendo, comenzamos a jugar"<<endl;

			num =rand()%6+1;
			cout<<"El numero es: "<<num<<endl;
			if (num==5){
				cout<<"Que suerte de oca a oca"<<endl;
			}
			cout<<"Introduzca una letra por teclado: N:nada O:oca P:puente S:posada D:dados V:calavera C:carcel Z:pozo L:laberinto: "<<endl;
			cin>>letra;
			letra=toupper(letra);
			switch(letra){
			case 'N':
				cout<<"Esta casilla no es especial"<<endl;
				break;
			case 'O':
				cout<<"Has caido en una Oca"<<endl;
				break;
			case 'P':
				cout<<"Has caido en una Puente"<<endl;
				break;
			case 'S':
				cout<<"Has caido en una poSada"<<endl;
				break;
			case 'D':
				cout<<"Has caido en una Dados"<<endl;
				break;

			case 'V':
				cout<<"Has caido en una calaVera"<<endl;
				break;

			case 'C':
				cout<<"Has caido en una Carcel"<<endl;
				break;

			case 'Z':
				cout<<"Has caido en una poZo"<<endl;
				break;

			case 'L':
				cout<<"Has caido en una Laberinto"<<endl;
				break;

			default:
				cout<<"Has introducido una letra incorrecta"<<endl;
			}


		}

	}
	else
	{
		cout<<"Hasta pronto"<<endl;
	}
}
