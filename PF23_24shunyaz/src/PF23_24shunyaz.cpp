//============================================================================
// Name        : PF23_24shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Juego de la Oca, en el cual tiene las edades extringido, y se juego que dos
//		jugadores se tiran el dado por turno, teniendo el tablero con casillas especificada,
//		se gana el primero que llega al final del tablero.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <fstream> 
#include <windows.h>
#include <time.h>


using namespace std;

#define MAX_CAR 10 //maximo de caracteres del nombre
#define INF 8
#define SUP 99
#define CASILLA_MAX 63
#define Tiempo 3000
#define FIL 7
#define COL 9
#define MAX_JUG 100 //maximo de jugadores

typedef char cadena [MAX_CAR+1]; //tipo de datos cadena, array de MAX_CAR+1 caracteres
typedef struct
{
	cadena nombre;
	int numvecesjug;
	int numvecesganado;
	int cero;
}jugador;
typedef jugador jugadores[MAX_JUG]; //vector de jugadores

int edad_correcta(int edad,int inf, int sup);
int aleatorio(int inf, int sup);
void jugada(cadena nom_jug, int dado, int num, int &turno, int &t, bool &mover, bool &pierdeturno);
void dibuja_tablero();
void salto_Oca(cadena nom_jug, int &t, int num, int &turno);
void actualiza_turno(int &turno);
void perderTurnos(int &turno, int turnosPerdidos);
void pozo(int &turno, int &turnosPozo);

int buscar_jugador(const cadena nombrejug, const jugadores v_jug, int totaljug);
void volcar_jugadores (jugadores v_jug, int & totaljug);
void jugadores_fichero (jugadores v_jug, int totaljug);

int main() {
	srand(time(NULL));
	cadena nom_jug1, nom_jug2;
	jugador auxjug1,auxjug2;
	jugadores v_jug;
	char resp;
	int edad1, edad2,num1, num2,dado, t1, t2, turno,valor1,valor2,totaljug,encontrado1,encontrado2,vez;
	bool puedejugar,pasado, pierdeturno;

	vez=0;
	auxjug1.numvecesganado=0;
	auxjug1.numvecesjug=0;

	auxjug2.numvecesganado=0;
	auxjug2.numvecesjug=0;

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
		valor1=edad_correcta(edad1,INF,SUP);
		valor2=edad_correcta(edad2,INF,SUP);

		if (valor1==0 && valor2==0){
			puedejugar=true;
		}

		clrscr();


		if(puedejugar){

			volcar_jugadores (v_jug,totaljug);

			cout<<"Estupendo, teneis la edad correcta, comenzamos a jugar"<<endl;
			cout<<"Introduzca el nombre del primer jugador (sin espacio):"<<endl;
			cin>>nom_jug1;
			nom_jug1[strlen(nom_jug1)]='\0';
			encontrado1=buscar_jugador(nom_jug1,v_jug,totaljug);
			if (encontrado1!=-1)
			{
				cout<<"Hola de nuevo "<<nom_jug1<<endl;
				auxjug1=v_jug[encontrado1];
				cout<<auxjug1.nombre<<endl;
				cout<<auxjug1.numvecesjug<<endl;
				cout<<auxjug1.numvecesganado<<endl;
			}
			else
			{
				cout<<"Bienvenido "<<nom_jug1<<", este juego te enganchara"<<endl;
				strcpy(auxjug1.nombre,nom_jug1);

			}
			cout<<"Introduzca el nombre del segundo jugador (sin espacio):"<<endl;
			cin>>nom_jug2;
			nom_jug2[strlen(nom_jug2)]='\0';
			encontrado2=buscar_jugador(nom_jug2,v_jug,totaljug);
			if (encontrado2!=-1)
			{
				cout<<"Hola de nuevo "<<nom_jug2<<endl;
				auxjug2=v_jug[encontrado2];
				cout<<auxjug2.nombre<<endl;
								cout<<auxjug2.numvecesjug<<endl;
								cout<<auxjug2.numvecesganado<<endl;
			}
			else
			{
				cout<<"Bienvenido "<<nom_jug2<<", este juego te enganchara"<<endl;
				strcpy(auxjug2.nombre,nom_jug1);
			}

			auxjug1.numvecesjug++;
			auxjug2.numvecesjug++;
			clrscr();
			cout<<"*************************************************************"<<endl;
			cout<<"REGLAS DEL JUEGO DE LA OCA"<<endl<<endl;
			cout<<"Cada jugador lanzara un dado por turnos"<<endl;
			cout<<"Comenzara a jugar el que obtenga la puntuacion mas alta"<<endl;
			cout<<"*************************************************************"<<endl<<endl;

			cout<<"Tirando el dado el jugador 1..."<<endl;
			Sleep(Tiempo);
			num1=aleatorio(1,6);
			cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
			cout<<"Tirando el dado el jugador 2..."<<endl;
			Sleep(Tiempo);
			num2=aleatorio(1,6);
			cout<<nom_jug2<<" ha sacado un "<<num2<<endl;

			while(num1==num2){
				cout<<"Se ha producido un empate, hay que volver a tirar los dados"<<endl;
				cout<<"Tirando el dado el jugador 1..."<<endl;
				Sleep(Tiempo);
				num1=aleatorio(1,6);
				cout<<nom_jug1<<" ha sacado un "<<num1<<endl;
				cout<<"Tirando el dado el jugador 2..."<<endl;
				Sleep(Tiempo);
				num2=aleatorio(1,6);
				cout<<nom_jug2<<" ha sacado un "<<num2<<endl;
			}

			if(num1>num2){
				cout<<"Comenzara la partida "<<nom_jug1<<" que ha obtenido un "<<num1<<endl;
				turno=1;

			}else{
				cout<<"Comenzara la partida "<<nom_jug2<<" que ha obtenido un "<<num2<<endl;
				turno=2;
			}


			Sleep(Tiempo);


			cout<<"Apartir de aqui, ya podemos empezar la partida"<<endl;
			Sleep(Tiempo);

			t1=0;
			t2=0;

			while(t1!=CASILLA_MAX && t2!=CASILLA_MAX){
				pasado=false;
				pierdeturno=false;
				dado =aleatorio(1,6);
				if(turno==1){
					jugada(nom_jug1,dado,CASILLA_MAX,turno,t1,pasado,pierdeturno);


				}else{
					jugada(nom_jug2,dado,CASILLA_MAX,turno,t2,pasado,pierdeturno);
				}

				if(pierdeturno){
					actualiza_turno(turno);
					pierdeturno=false;
				}

			}

			if(t1==CASILLA_MAX){
				cout<<"¡¡¡FELICIDADES ha ganado "<<nom_jug1<<"" <<"!!!"<<endl;
				auxjug1.numvecesganado++;
				v_jug[encontrado1]= auxjug1;
			}else{
				cout<<"¡¡¡FELICIDADES ha ganado "<<nom_jug2<<"" <<"!!!"<<endl;
				auxjug2.numvecesganado++;
				v_jug[encontrado2]= auxjug2;
			}

			Sleep(Tiempo);
			clrscr();

			cout<<"Desea volver a jugar al juego de la OCA s/n:";
			cout<<"OJO!! si vais a jugar contra alguien que no habia jugado ante, vuelva a ejecutar el programa!!"<<endl;
			//eso es debido a que si vuelve a jugar, si alguno de los jugadores no existen en el fichero, se produce error de escritura
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

		if (encontrado1!=-1)//el jugador ya existe
				{
					v_jug[encontrado1]= auxjug1;
				}
				else
				{
					v_jug[totaljug]= auxjug1;
				}
		if (encontrado2!=-1)//el jugador ya existe
						{
							v_jug[encontrado2]= auxjug2;
						}
						else
						{
							v_jug[totaljug]= auxjug2;
						}
		jugadores_fichero (v_jug,totaljug);

	}
	if (encontrado1 ==-1)
		{
			totaljug++;
		}
	if (encontrado2 ==-1)
			{
				totaljug++;
			}
	jugadores_fichero (v_jug,totaljug);
	clrscr();
	cout << "!!!Puede jugar cuando quiera!!" << endl;
	cout << "!!!Vuelva pronto!!" << endl;
	Sleep(Tiempo);



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

void jugada(cadena nom_jug, int dado, int num,int &turno, int &t, bool &mover, bool &pierdeturno){

	mover=false;
	int turnosPozoJugador1,turnosPozoJugador2,puntosExceso = 0;
	bool necesitaTirarDeNuevo,enCasillaDados = false;
	cout<<"Tirada "<<nom_jug<<endl;

	switch(t){
	/*case 0:
		cout<<"Nada"<<endl;
		break;*/
	case 5:
	case 9:
	case 14:
	case 18:
	case 23:
	case 27:
	case 32:
	case 36:
	case 41:
	case 45:
	case 50:
	case 54:
	case 59:
		cout<<"De oca a oca y tiro porque me toca"<<endl;
		salto_Oca(nom_jug, t,num, turno);
		break;
	case 6:
	case 12:
		cout<<"De puente a puente y tiro porque me lleva la corriente"<<endl;
		if(t==6){
			t=12;
		}else{
			t=6;
		}
		actualiza_turno(turno);
		break;
	case 19:
		cout<<"Posada: Pierdes un turno"<<endl;
		perderTurnos(turno,1);
		pierdeturno=true;
		break;
	case 26:
	case 53:
		cout<<"De dados a dados y tiro porque me da igual"<<endl;
		if(t==26){
			t=53;
		}else{
			t=26;
		}
		enCasillaDados=true;
		break;
	case 58:
		cout<<"Calavera: Vuelves a empezar"<<endl;
		t=0;
		break;
	case 56:
		cout<<"Cárcel: Pierdes dos turnos"<<endl;
		perderTurnos(turno,2);
		break;
	case 31:
		cout<<"Pozo: No puedes jugar hasta que otro jugador caiga o pasen tres turnos"<<endl;
		pozo(turno, (turno == 1) ? turnosPozoJugador1 : turnosPozoJugador2);
		break;
	case 42:
		cout<<"Laberinto: Retrocedes a la casilla 30"<<endl;
		t=30;
		break;

	}
	enCasillaDados = (t == 26 || t == 53);

	if (enCasillaDados) {
		necesitaTirarDeNuevo = true;
	}
	if (necesitaTirarDeNuevo && !enCasillaDados) {
		actualiza_turno(turno);
	}

	if(t+dado>num){
		mover=true;
		puntosExceso=t+dado-num;
		t=num-puntosExceso;
		cout<<nom_jug<<" ha sacado "<<dado<<", se ha pasado. Retrocede al "<<t<<endl;
	}else{
		t=t+dado;
		cout<<nom_jug<<" ha sacado un "<<dado<<" Total:"<<t<<" puntos"<<endl;
	}

	/*if(!pierdeturno){
		if (!necesitaTirarDeNuevo) {
		            actualiza_turno(turno);
		        }
	}*/
	if (pierdeturno) {
		actualiza_turno(turno);
		pierdeturno = false;
	} else {
		if (!necesitaTirarDeNuevo) {
			actualiza_turno(turno);
		}
	}

}


void dibuja_tablero(){
	int i=1;
	for (int f=0;f<FIL;f++)
	{
		for (int c=0;c<COL;c++)
		{
			if(i==6||i==12){
				textbackground(YELLOW);
			}else if(i==19){
				textbackground(MAGENTA);
			}else if(i==26||i==53){
				textbackground(BLUE);
			}else if(i==31){
				textbackground(BROWN);
			}else if(i==42){
				textbackground(CYAN);
			}else if(i==56){
				textbackground(DARKGRAY);
			}else if(i==58){
				textbackground(RED);
			}else if(c==4||c==8){
				textbackground(GREEN);
			}else{
				textbackground(WHITE);
			}
			i++;
		}
		cout<<endl;
	}
}

void salto_Oca(cadena nom_jug, int &t, int num, int &turno){
	//int d;
	if (t < 59) {
		if (t < 9) {
			t = 9;
		} else if (t < 14) {
			t = 14;
		} else if (t < 18) {
			t = 18;
		} else if (t < 23) {
			t = 23;
		} else if (t < 27) {
			t = 27;
		} else if (t < 32) {
			t = 32;
		} else if (t < 36) {
			t = 36;
		} else if (t < 41) {
			t = 41;
		} else if (t < 45) {
			t = 45;
		} else if (t < 50) {
			t = 50;
		} else if (t < 54) {
			t = 54;
		} else {
			t = 59;
		}
		cout << "Avanzaste a la casilla " << t << ". ¡Vuelve a tirar el dado!" << endl;
		actualiza_turno(turno);
	} else {
		t = 63;
		cout << "¡Avanzaste al final del juego!" << endl;
	}

}

void actualiza_turno(int &turno){
	if(turno==1){
		turno=2;
	}else{
		turno=1;
	}
}

void perderTurnos(int &turno, int turnosPerdidos) {
	cout << "Pierdes " << turnosPerdidos << " turnos" << endl;
	for (int i = 0; i < turnosPerdidos; i++) {
		actualiza_turno(turno);
	}
}

void pozo(int &turno, int &turnosPozo) {

	turnosPozo = 3;
	for (int i = 0; i < turnosPozo; i++) {
		actualiza_turno(turno);
	}
}

int buscar_jugador(const cadena nombrejug, const jugadores v_jug, int totaljug)
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
			fjug>>v_jug[j].numvecesganado;
			j++;
			totaljug++;
			fjug>>jug.nombre;
		}
	}
	fjug.close();
}

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
			outfjug<<v_jug[i].numvecesjug<<" ";
			outfjug<<v_jug[i].numvecesganado<<" ";
			outfjug<<endl;


		}
	}
	outfjug.close();//cerrar el fichero
}
