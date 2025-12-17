//============================================================================
// Name        : E4shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Modificacion del E3, termina el juego cuando uno de los jugadores consiga 63 puntos
//============================================================================

#include <iostream>
using namespace std;
#define MAX_CAR 10 //maximo de caracteres del nombre

typedef char cadena [MAX_CAR+1]; //tipo de datos cadena, array de MAX_CAR+1 caracteres


int main() {
	srand(time(NULL));
	cadena nom_jug1, nom_jug2;
	char resp;
	int edad1, edad2,num1, num2,dado, num, t1, t2, turno;
	bool puedejugar,pasado;
	cout<<"Desea jugar al juego de la OCA s/n:";
	cin>>resp;
	resp=tolower(resp);
	while (	resp!='s' && resp!='n')//para que el usuario solo introduzca s,S,n,N
	{
		cout<<"Ha introducido una respuesta incorrecta, responda s/n:";
		cin>>resp;
	}
	puedejugar=true;
	while (resp =='s'  && puedejugar==true)
	{
		cout<<"Comencemos a jugar"<<endl;
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

			cout<<"*************************************************************"<<endl;
			cout<<"REGLAS DEL JUEGO DE LA OCA"<<endl<<endl;
			cout<<"Cada jugador lanzara un dado por turnos"<<endl;
			cout<<"Comenzara a jugar el que obtenga la puntuacion mas alta"<<endl;
			cout<<"*************************************************************"<<endl<<endl;


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
				turno=1;

			}else{
				cout<<"Comenzara la partida "<<nom_jug2<<" que ha obtenido un "<<num2<<endl;
				turno=2;
			}

			cout<<"Apartir de aqui, se desarrolla la partida"<<endl;
			cout<<"Simulamos la partida"<<endl;

			t1=0;
			t2=0;

			while(t1!=63 && t2!=63){
				pasado=false;
				dado =rand()%6+1;
				if(turno==1 ){
					cout<<"Tirada "<<nom_jug1<<endl;
					if(t1+dado>63){
						pasado=true;
						cout<<nom_jug1<<" no puede mover "<<dado<<", se ha pasado"<<endl;
					}else{
						t1=t1+dado;
						cout<<nom_jug1<<" ha sacado un "<<dado<<" Total:"<<t1<<" puntos"<<endl;
					}
					turno=2;
				}else{
					cout<<"Tirada "<<nom_jug2<<endl;
					if(t2+dado>63){
						pasado=true;
						cout<<nom_jug2<<" no puede mover "<<dado<<", se ha pasado"<<endl;
					}else{
						t2=t2+dado;
						cout<<nom_jug2<<" ha sacado un "<<dado<<" Total:"<<t2<<" puntos"<<endl;
					}
					turno=1;
				}

				if(pasado==false){
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
				}
			}

			if(t1==63){
				cout<<"¡¡¡FELICIDADES ha ganado "<<nom_jug1<<"" <<"!!!"<<endl;
			}else{
				cout<<"¡¡¡FELICIDADES ha ganado "<<nom_jug2<<"" <<"!!!"<<endl;
			}

			cout<<"Desea volver a jugar al juego de la OCA s/n:";
			cin>>resp;
			resp=tolower(resp);
			while (	resp!='s' && resp!='n')//para que el usuario solo introduzca s,S,n,N
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


