//============================================================================
// Name        : EE6shunyaz.cpp
// Author      : Shunya Zhan
// Version     : 1.0
// Copyright   :
// Description : Practica relacionada con vector, vector de 8 reales >=0
//============================================================================

#include <iostream>
using namespace std;

#define MAX_FLOAT 8
typedef float v_reales[MAX_FLOAT];
void crear_valeatorio(v_reales v);
void crear_vintroducido(v_reales v);
void mostrar_vinversa(const v_reales v);
float calcula_media( const v_reales v);
float valor_minimo(const v_reales v);
bool si_ordenado(const v_reales v);
int buscar_valor(const v_reales v, float valor);

int main() {
	float m_al,m_int,min_al,min_int,valor;
	bool ordenado;
	int pos;
	v_reales v_aleatorio,v_introducido;
	srand(time(NULL));

	//vector aleatotio al v1
	crear_valeatorio(v_aleatorio);
	//vector introducido al v2
	crear_vintroducido(v_introducido);
	//mostrar vector en orden inverso
	cout<<"Vector aleatorio: "<<endl;
	mostrar_vinversa(v_aleatorio);
	cout<<endl;
	cout<<"Vector introducido: "<<endl;
	mostrar_vinversa(v_introducido);
	cout<<endl;
	//calcular y mostrar media
	m_al=calcula_media(v_aleatorio);
	cout<<"Media del vector aleatorio: "<<m_al<<endl;
	m_int=calcula_media(v_introducido);
	cout<<"Media del vector introducido: "<<m_int<<endl;
	//calcular y mostrar valor minimo
	min_al=valor_minimo(v_aleatorio);
	cout<<"Valor minimo del vector aleatorio: "<<min_al<<endl;
	min_int=valor_minimo(v_introducido);
	cout<<"Valor minimo del vector introducido: "<<min_int<<endl;
	ordenado=si_ordenado(v_aleatorio);
	if(ordenado){
		cout<<"El vector aleatorio SI está ordenado ascendentemente"<<endl;
	}else{
		cout<<"El vector aleatorio NO está ordenado ascendentemente"<<endl;
	}
	ordenado=si_ordenado(v_introducido);
	if(ordenado){
		cout<<"El vector introducido SI está ordenado ascendentemente"<<endl;
	}else{
		cout<<"El vector introducido NO está ordenado ascendentemente"<<endl;
	}
	//comprobar si el valor introducido existe, y mostrar su posicion en el vector
	cout<<"Introduce un valor para buscar en el vector introducido: "<<endl;
	cin>>valor;
	pos=buscar_valor(v_introducido, valor);
	if (pos!=-1){
		cout<<"El valor "<<valor<<" se encuentra en la posición "<< pos<<" del vector introducido."<<endl;
	} else {
		cout<<"El valor "<<valor<<" no se encuentra en el vector introducido."<<endl;
	}
	return 0;
}
//1-crear vector aleatorio
void crear_valeatorio(v_reales v){
	float n;
	for(int i=0; i<MAX_FLOAT; i++){
		n=static_cast<float>(rand());
		v[i]=n;
	}
}
//2-crear vector con valor introducido
void crear_vintroducido(v_reales v){
	for(int i=0; i<MAX_FLOAT; i++){
		cout<<"Introduza un numero real: "<<endl;
		cin>>v[i];
	}
}
//3-mostrar vector desde la última posicioin a la primera
void mostrar_vinversa(const v_reales v){
	cout<<"Vector en orden inverso: "<<endl;
	for(int i=MAX_FLOAT-1; i>=0; i--){
		cout<<v[i]<<" ";
	}
}
//4-calcular, devolver la media
float calcula_media( const v_reales v){
	float m;
	m=0;
	for(int i=0; i<MAX_FLOAT; i++){
		m+=v[i];
	}
	m/=MAX_FLOAT;
	return m;
}
//5-devolver el valor minimo
float valor_minimo(const v_reales v){
	float min;
	min=v[0];
	for(int i=1; i<MAX_FLOAT;i++){
		if(v[i]<min){
			min=v[i];
		}
	}
	return min;
}
//6-devolver true si el vector está ordenado, false en caso contrario
bool si_ordenado(const v_reales v){
	bool ordenado=true;
	int i=0;
	while (i<MAX_FLOAT-1 && ordenado) {
		if (v[i]>v[i+1]){
			ordenado=false;
		}else
		{
			i++;
		}
	}
	return ordenado;
}
//7-comprobar si existe en el vector un valor determinado pasado como parametro y si existe, devolver su posicion
int buscar_valor(const v_reales v, float valor) {
	int pos=-1;
	int i=0;
	while (i<MAX_FLOAT) {
		if (v[i]==valor) {
			pos=i;
		}
		i++;
	}
	return pos;
}
