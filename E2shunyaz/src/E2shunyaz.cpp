//============================================================================
// Name        : E2shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 09/10/2023
// Copyright   :
// Description : Sesion 2, implementacion con las estructuras de control de flujo repetitivas, iterativa o bucles.
//				Simulacion del juego OCA (controla edad, si empate y tirada)
//============================================================================

#include <iostream>
#define MAX_CAR 10 //maximo de caracteres del nombre


typedef char cadena [MAX_CAR+1]; //tipo de datos cadena, array de MAX_CAR+1 caracteres

using namespace std;
int main()
{
	srand(time(NULL));
	cadena nom_jug1, nom_jug2;
	char resp;
	int edad1, edad2,num1, num2, i, num;
	bool puedejugar;
	cout<<"Desea jugar al juego de la OCA s/n:";
	cin>>resp;
	while (	resp!='s' && resp!='S' && resp!='n' &&resp!='N')//para que el usuario solo introduzca s,S,n,N
	{
		cout<<"Ha introducido una respuesta incorrecta, responda s/n:";
		cin>>resp;
	}
	puedejugar=true;
	while ((resp =='s' || resp=='S') && puedejugar==true)
	{
		cout<<"Comencemos a jugar"<<endl;
		//Codigo del juego
		cout<<"Introduzca la edad del jugador 1: "<<endl;
		cin>>edad1;
		cout<<"Introduzca la edad del jugador 2: "<<endl;
		cin>>edad2;
		if (edad1<8 || edad2<8){
			cout<<"Eres demasiado pequeño para jugar a la OCA"<<endl;
			puedejugar=false;
		}else if (edad1>99 ||edad2>99){
			cout<<"Ya no estás para estos juegos"<<endl;
			puedejugar=false;
		}

		if(puedejugar){
			cout<<"Estupendo, teneis la edad correcta, comenzamos a jugar"<<endl;
			cout<<"Introduzca el nombre del primer jugador (sin espacio):"<<endl;
			cin>>nom_jug1;
			cout<<"Introduzca el nombre del segundo jugador (sin espacio):"<<endl;
			cin>>nom_jug2;

			num1 =rand()%6+1;
			cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
			num2 =rand()%6+1;
			cout<<nom_jug2<<" ha sacado un "<<num2<<endl;

			while(num1==num2){
				num1 =rand()%6+1;
				cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
				num2 =rand()%6+1;
				cout<<nom_jug2<<" ha sacado un "<<num2<<endl;
				cout<<"Se ha producido un empate, hay que volver a tirar los dados"<<endl;
			}
			if(num1>num2){
				cout<<"Comenzara la partida "<<nom_jug1<<" que ha obtenido un "<<num1<<endl;
			}else{
				cout<<"Comenzara la partida "<<nom_jug2<<" que ha obtenido un "<<num2<<endl;
			}

			cout<<"Apartir de aqui, se desarrolla la partida"<<endl;
			cout<<"Simulamos la partida"<<endl;

			i=0;
			while(i<5){
				cout<<"Tirada "<<i+1<<endl;
				num=rand()%9;
				switch(num){
				case 0:
					cout<<"Nada"<<endl;
					break;
				case 1:
					cout<<"Has caido en Oca"<<endl;
					break;
				case 2:
					cout<<"Has caido en Puente"<<endl;
					break;
				case 3:
					cout<<"Has caido en Posada"<<endl;
					break;
				case 4:
					cout<<"Has caido en Dados"<<endl;
					break;
				case 5:
					cout<<"Has caido en Calavera"<<endl;
					break;
				case 6:
					cout<<"Has caido en Carcel"<<endl;
					break;
				case 7:
					cout<<"Has caido en Pozo"<<endl;
					break;
				case 8:
					cout<<"Has caido en Laberinto"<<endl;
					break;
				}

				i++;
			}


			cout<<"¡¡¡FELICIDADES ha ganado ......!!!"<<endl;
			cout<<"Una vez que acabe la partida, los jugadores pueden volver a jugar"<<endl;
			cout<<"Desea volver a jugar al juego de la OCA s/n:";
			cin>>resp;
			while (	resp!='s' && resp!='S' && resp!='n' &&resp!='N')//para que el usuario solo introduzca s,S,n,N
			{
				cout<<"Ha introducido una respuesta incorrecta, responda s/n:";
				cin>>resp;
			}

		}else{
			cout<<"Lo sentimos, no tiene edad para jugar a este juego"<<endl;
		}

	}
	cout << "!!!Puede jugar cuando quiera!!" << endl;
	cout << "!!!Vuelva pronto!!" << endl;
	return 0;
}
