//============================================================================
// Name        : E3_shunyaz.cpp
// Author      : Shunya Zhan
// Version     :
// Copyright   : Your copyright notice
// Description : Calcular la hora de trabajo no presencial en un cuatrimestre
//============================================================================

#include <iostream>
using namespace std;
#define hcred 25
#define cuatrimestre 14
int main()
{

float ncred,hteoria,hpractica,htp,hresto;
cout<<"Introduce numero creditos";
cin>>ncred;
if(ncred!=6 && ncred!=4)
{
	cout<<"Error";
}
else
{
	cout<<"Horas Teoricas:";
	cin>>hteoria;
	if(hteoria<0 || hteoria>27.0)
	{
		cout<<"Error";
	}
	else
	{
		cout<<"Horas Practica:";
		cin>>hpractica;
		if(hpractica<0 || hpractica>33.0)
		{
			cout<<"Error";
		}
		else
		{
			cout<<"Horas TP:";
			cin>>htp;
			if(htp<0 || htp>3)
			{
				cout<<"Error";
			}
			else
			{
				hresto=(25*ncred-hteoria-hpractica-htp)/cuatrimestre;
				cout<<"Tu hora de trabajo no presencial semanal es:"<<hresto;
			}
		}
	}
}

 return 0;
}
