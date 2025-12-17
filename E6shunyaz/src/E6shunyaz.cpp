//============================================================================
// Name : E6shunyaz.cpp
// Author : Shunya Zhan
// Version : 1.0
// Description : Trabajamos con tipos de datos
// definimos nuevos tipos de datos e implementamos funciones y
// procedimientos para tratarlos
/*
 * El tipo de datos estudiante contendrá los siguientes campos:
• nombre de tipo cadena de 20 caracteres.
• edad de tipo entero.
• nota de FP de tipo real.
El vector de estudiantes tendrá como máximo 60 estudiantes.*/
//============================================================================
#include <iostream>
//definicion de constantes
#define MAX_CAR 20
#define MAX_EST 60
//definicion de tipos de datos
typedef char cadena[MAX_CAR + 1];
//tipo de dato estudiante
typedef struct
{
	int expediente;
	cadena nombre;
	int edad;
	float notafp;
}estudiante;
//tipo de dato vector de estudiantes
typedef estudiante v_estudiante[MAX_EST];
//prototipos de modulos
//MODULOS QUE GESTIONAN EL TIPO DE DATOS estudiante **************
//modulo que creara y devolvera un estudiante, se leeran todos los datos por teclado
estudiante crear_estudiante (void);
//modulo que creara y devolvera un estudiante pasandole el expediente
//el expediente se asignara y el resto de datos se leeran por teclado
estudiante crear_estudiante (int exp);
//modulo que mostrara los datos de un estudiante pasado como parametro
void mostrar_estudiante (estudiante e);
//modulo que devolvera la edad del estudiante que se pase como parametro
int get_edad (estudiante e);
//modulo que devolvera la nota del estudiante que se pase como parametro
float get_nota (estudiante e);
//modulo que modifica la edad de un estudiante
estudiante set_edad (estudiante e, int edad);
//modulo que modifica la nota de un estudiante
estudiante set_nota (estudiante e, float nota);

//*************************************************************************
//MODULOS QUE GESTIONAN EL TIPO DE DATOS vector de estudiantes **************
//prototipos de los modulos
//modulo que creara el vector de estudiantes, el expediente coincidira con la
//posicion en el vector. Debes usar los módulos implementados del tipo de datos estudiante
void crear_vectorest (v_estudiante v);
//modulo que mostrara los datos del vector de estudiantes
void mostrar_vectorest (const v_estudiante v);
//modulo que devolvera el estudiante cuyo numero de expediente coincida con
//el pasado como parametro
estudiante get_estudiante (const v_estudiante v, int exp);
//modulo que muestre los estudiantes que tengan una nota >= que la nota que se
//pase por parámetro y devuelva cuantos estudiantes hay que cumplan dicha condición
int lista_notas (const v_estudiante v, float nota);
//modulo que devuelva el expediente del primer estudiante que encuentre cuya
//edad coincida con una edad que se pase por parámetro.
int primer_estudiante_edad (const v_estudiante v, int edad);


using namespace std;
int main() {
	//variables
	estudiante e;
	//estudiante e1;
	int edad_modif, expediente_a_buscar,edad_a_buscar;
	//int exped;
	float nota_modif,nota_a_comparar;
	//////////////
	v_estudiante vector_estudiantes;
	srand(time(NULL));
	cout<<"Usamos los modulos relacionados con el tipo de datos estudiante"<<endl;
	e=crear_estudiante();
	//cout<<"Introduzca expediente del estudiante a crear:";
	//cin>>exped;
	//e1=crear_estudiante(exped);
	//cout<<endl<<"Datos del estudiante con expediente"<<endl;
	//mostrar_estudiante (e1);
	cout<<endl<<"Datos del estudiante"<<endl;
	mostrar_estudiante (e);
	cout<<endl;
	cout<<"Mostramos los datos del estudiante usando las funciones get"<<endl;
	cout<<e.nombre<<" tiene "<<get_edad(e)<<" anios"<<endl;
	cout<<e.nombre<<" tiene un "<<get_nota(e)<<" en la asignatura de FP"<<endl;
	cout<<endl<<"Vamos a modificar la edad y la nota del estudiante con las funciones set"<<endl;
	cout<<"Introduzca la edad modificada del estudiante:";
	cin>>edad_modif;
	e=set_edad(e,edad_modif);
	cout<<"Introduzca la nota modificada del estudiante:";
	cin>>nota_modif;
	e=set_nota(e,nota_modif);
	cout<<endl<<"Mostramos los Datos Modificados del estudiante"<<endl;
	mostrar_estudiante (e);



	//******Pequeño main para utilizar los modulo implementada por estudiante******
	crear_vectorest(vector_estudiantes);
	cout << "Datos del vector de estudiantes:" << endl;
	mostrar_vectorest(vector_estudiantes);
	cout << endl;
	cout << "Introduce el expediente a buscar: ";
	cin >> expediente_a_buscar;
	estudiante estudiante_buscado = get_estudiante(vector_estudiantes, expediente_a_buscar);
	cout << "Estudiante encontrado:" << endl;
	cout << "Expediente: " << estudiante_buscado.expediente << endl;
	cout << "Nombre: " << estudiante_buscado.nombre << endl;
	cout << "Edad: " << estudiante_buscado.edad << endl;
	cout << "Nota FP: " << estudiante_buscado.notafp << endl;

	cout << "Introduce la nota a comparar: ";
	cin >> nota_a_comparar;
	int cantidad_estudiantes = lista_notas(vector_estudiantes, nota_a_comparar);
	cout << "Cantidad de estudiantes con nota mayor o igual a " << nota_a_comparar << ": " << cantidad_estudiantes << endl;
	cout << "Introduce la edad a buscar: ";
	cin >> edad_a_buscar;
	int expediente_primer_estudiante = primer_estudiante_edad(vector_estudiantes, edad_a_buscar);
	if (expediente_primer_estudiante != -1) {
		cout << "Expediente del primer estudiante con edad " << edad_a_buscar << ": " << expediente_primer_estudiante << endl;
	}


	return 0;
}
//Implementacion de modulos
//modulo que creara un estudiante, se leeran los datos por teclado
estudiante crear_estudiante (void)
{
	estudiante e;
	cout<<"Introduzca expediente:";
	cin>>e.expediente;
	cout<<"Introduzca nombre estudiante:";
	cin>>e.nombre;
	cout<<"Introduzca su edad:";
	cin>>e.edad;//comprobar
	cout<<"Introduzca su nota:";
	cin>>e.notafp;//comprobar
	return e;
}
//modulo que creara y devolvera un estudiante pasandole el expediente
estudiante crear_estudiante (int exp)
{
	estudiante e;
	e.expediente=exp;
	cout<<"Expediente:"<<e.expediente<<endl;
	cout<<"Introduzca nombre estudiante:";
	cin>>e.nombre;
	cout<<"Introduzca su edad:";
	cin>>e.edad;//comprobar
	cout<<"Introduzca su nota:";
	cin>>e.notafp;//comprobar
	return e;
}
//modulo que mostrara los datos de un estudiante pasado como parametro
void mostrar_estudiante (estudiante e)
{
	cout<<"Expediente:"<<e.expediente<<endl;
	cout<<"Nombre estudiante:"<<e.nombre<<endl;
	cout<<"Edad:"<<e.edad<<endl;
	cout<<"Nota:"<<e.notafp<<endl;
}
//modulo que devolvera la edad del estudiante que se pase como parametro
int get_edad (estudiante e)
{
	return e.edad;
}
//modulo que devolvera la nota del estudiante que se pase como parametro
float get_nota (estudiante e)
{
	return e.notafp;
}
//modulo que modifica la edad de un estudiante
estudiante set_edad (estudiante e, int edad)
{
	e.edad = edad;
	return e;
}
//modulo que modifica la nota de un estudiante
estudiante set_nota (estudiante e, float nota)
{
	e.notafp = nota;
	return e;
}

//modulo que creara el vector de estudiantes
void crear_vectorest (v_estudiante v){
	for(int i=0; i<MAX_EST;i++){
		v[i]=crear_estudiante(i);
	}
}
//modulo que mostrara los datos del vector de estudiantes
void mostrar_vectorest (const v_estudiante v){
	for(int i=0;i<MAX_EST;i++){
		mostrar_estudiante(v[i]);
	}

}
//modulo que devolvera el estudiante cuyo numero de expediente coincida con el pasado como parametro
estudiante get_estudiante (const v_estudiante v, int exp){
	estudiante e;
	e.expediente=-1;
	if(exp>=0 && exp<=MAX_EST){
			e=v[exp];
		}
	return e;
}
//modulo que muestre los estudiantes que tengan una nota >= que la nota que se
//pase por parámetro y devuelva cuantos estudiantes hay que cumplan dicha condición
int lista_notas (const v_estudiante v, float nota){
	int cont=0;
	for(int i=0; i<MAX_EST;i++){
		if(v[i].notafp>=nota){
			cout<<v[i].nombre<<endl;
			cont++;
		}
	}
	return cont;
}
//modulo que devuelva el expediente del primer estudiante que encuentre cuya
//edad coincida con una edad que se pase por parámetro.
int primer_estudiante_edad (const v_estudiante v, int edad){
	int exp=-1;
	bool enc=false;
	int i=0;
	while(i<MAX_EST && !enc){
		if(v[i].edad==edad){
			enc=true;
			exp=v[i].expediente;
		}else{
			i++;
		}
	}
	return exp;
}
