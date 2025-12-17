//============================================================================
// Name        : PRUEBA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Prueba basico
//============================================================================

#include <iostream>
#include <conio2.h>
#include <windows.h>
using namespace std;
#define FIL 7
#define COL 9

int main()
{
	int i=1;
	int ac,af=0;
	for (int f=0;f<FIL;f++)
	{
		for (int c=0;c<COL;c++)
		{
			if(i==6||i==12){
				gotoxy(ac, af);
				textcolor(YELLOW);
				printf("%c",char(219));
			}else if(i==19){
				gotoxy(ac, af);
				textbackground(MAGENTA);
				printf("%c",' ');
			}else if(i==26||i==53){
				gotoxy(ac, af);
				textbackground(BLUE);
				printf("%c",' ');
			}else if(i==31){
				gotoxy(ac, af);
				textbackground(BROWN);
				printf("%c",' ');
			}else if(i==42){
				gotoxy(ac, af);
				textbackground(CYAN);
				printf("%c",' ');
			}else if(i==56){
				gotoxy(ac, af);
				textbackground(DARKGRAY);
				printf("%c",' ');
			}else if(i==58){
				gotoxy(ac, af);
				textbackground(RED);
				printf("%c",' ');
			}else if(c==4||c==8){
				gotoxy(ac, af);
				textbackground(GREEN);
				printf("%c",' ');
			}else{
				gotoxy(ac, af);
				textbackground(WHITE);
				printf("%c",' ');
			}
			i++;
			ac=c+1;
		}
		ac=0;
		af=f+1;
		cout<<endl;
	}
	Sleep(2000000000);

	return 0;
}
