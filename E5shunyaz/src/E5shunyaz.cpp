//============================================================================
// Name        : E5shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Modificacion del E4, añadiendo los modulos como: edad_correcta, aleatorio
//				jugada, mostrar_casilla y pinta_caracter y su usabilidad en el programa principal
//============================================================================

#include <iostream>
#include <conio2.h>
#include <windows.h>

using namespace std;
#define MAX_CAR 10 //maximo de caracteres del nombre
#define INF 8
#define SUP 99
#define CASILLA_MAX 63

typedef char cadena [MAX_CAR+1]; //tipo de datos cadena, array de MAX_CAR+1 caracteres
int edad_correcta(int edad,int inf, int sup);
int aleatorio(int inf, int sup);
void jugada(cadena nom_jug, int dado, int num, int &turno, int &t, bool &mover);
void mostrar_casilla(int num);
void pinta_caracter(int veces, char c, int color, int x , int y);


int main() {
	srand(time(NULL));
	cadena nom_jug1, nom_jug2;
	char resp;
	int edad1, edad2,num1, num2,dado, num, t1, t2, turno,valor1,valor2;
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
		puedejugar=false;
		valor1=edad_correcta(edad1,8,99);
		valor2=edad_correcta(edad2,8,99);

		if (valor1==0 && valor2==0){
			puedejugar=true;
		}

		if(puedejugar){
			cout<<"Estupendo, teneis la edad correcta, comenzamos a jugar"<<endl;
			cout<<"Introduzca el nombre del primer jugador (sin espacio):"<<endl;
			cin>>nom_jug1;
			cout<<"Introduzca el nombre del segundo jugador (sin espacio):"<<endl;
			cin>>nom_jug2;

			clrscr();
			cout<<"*************************************************************"<<endl;
			cout<<"REGLAS DEL JUEGO DE LA OCA"<<endl<<endl;
			cout<<"Cada jugador lanzara un dado por turnos"<<endl;
			cout<<"Comenzara a jugar el que obtenga la puntuacion mas alta"<<endl;
			cout<<"*************************************************************"<<endl<<endl;

			num1=aleatorio(1,6);
			cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
			num2=aleatorio(1,6);
			cout<<nom_jug2<<" ha sacado un "<<num2<<endl;

			while(num1==num2){
				cout<<"Se ha producido un empate, hay que volver a tirar los dados"<<endl;
				num1 =aleatorio(1,6);
				cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
				num2 =aleatorio(1,6);
				cout<<nom_jug2<<" ha sacado un "<<num2<<endl;
			}

			if(num1>num2){
				cout<<"Comenzara la partida "<<nom_jug1<<" que ha obtenido un "<<num1<<endl;
				turno=1;

			}else{
				cout<<"Comenzara la partida "<<nom_jug2<<" que ha obtenido un "<<num2<<endl;
				turno=2;
			}

			clrscr();
			cout<<"Apartir de aqui, se desarrolla la partida"<<endl;
			cout<<"Simulamos la partida"<<endl;
			Sleep(5000);

			t1=0;
			t2=0;

			while(t1!=63 && t2!=63){
				pasado=false;
				dado =aleatorio(1,6);
				if(turno==1){
					jugada(nom_jug1,dado,63,turno,t1,pasado);
				}else{
					jugada(nom_jug2,dado,63,turno,t2,pasado);
				}

				if(pasado==false){
					num=aleatorio(0,8);
					mostrar_casilla(num);
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
	Sleep(2000);

	clrscr();
	pinta_caracter(2,'M',2, 20,10);

	Sleep(3000);

	return 0;
}


int edad_correcta(int edad,int inf, int sup){
	int num;
	if (edad<inf ){
		cout<<"Eres demasiado pequeño para jugar a la OCA"<<endl;
		num= -1;
	}else if (edad>sup){
		cout<<"Ya no estás para estos juegos"<<endl;
		num= 1;
	}else{
		num=0;
	}
	return num;
}

int aleatorio(int inf, int sup){
	int resul, n;
	if(inf>sup){
		n=inf;
		inf=sup;
		sup=n;
	}
	resul=rand()%(sup-inf+1)+inf;
	return resul;
}

void jugada(cadena nom_jug, int dado, int num, int &turno, int &t, bool &mover){

	mover=false;
	cout<<"Tirada "<<nom_jug<<endl;
	if(t+dado>num){
		mover=true;
		cout<<nom_jug<<" no puede mover "<<dado<<", se ha pasado"<<endl;
	}else{
		t=t+dado;
		cout<<nom_jug<<" ha sacado un "<<dado<<" Total:"<<t<<" puntos"<<endl;
	}
	if(turno==1){
		turno=2;
	}else{
		turno=1;
	}

}

void mostrar_casilla(int num){
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

void pinta_caracter(int veces, char c, int color, int x , int y){
	color=toupper(color);
	gotoxy(x,y);
	for(int i=0; i<veces; i++){
		textcolor(color);
		cout<<c;
		Sleep(1000);
	}
	textcolor(WHITE);//para volver a color blanco
}


