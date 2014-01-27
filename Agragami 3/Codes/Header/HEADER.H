//--------------------- Contain list of header files and keys definations-------------------------------------
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<time.h>
#include<iomanip.h>
#include<errno.h>
//-----------------------------------Boolean Values---------------------------------
#define TRUE 1
#define FALSE 0
//-----------------------------------------------------------------------------------
#define ESC 27
//-------------------------------- Arrow Keys Definitions -----------------------------
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
//------------------------------------FILE CODES---------------------------
#define TXT "1"
#define HTML "4"
#define RTF "5"
#define DOC "9"
#define PDF "12"
//----------------------------------Prototypes------------------------------
void box2(int x1,int y1,int x2,int y2);
void box(int back_colour);
void message(int x,int y,int lines,char a[50],char b[50],char c[50],	 char d[50],char e[50],char f[10],int back,int fore,int bor);
void error(char [],char[],int);
int listbox(char *name[],int total,int x,int y,int width,int bcolour,int fcolour,int border,int btext,int ftext);

//------------------------------return date----------------------------------
char * getdate()
{
   time_t timer;
   struct tm *tblock;
   timer = time(NULL);
   tblock = localtime(&timer);
   return asctime(tblock);
}
//-------------------------------------------------------------------------
void usage()
{
	
	void mes(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back,int fore,int bor);
	_setcursortype(_NOCURSOR);
	mes(16,4,13,"","            About Agragami              ","---------------------------------","","","OK",RED,WHITE,YELLOW);
	textbackground(RED);
	textcolor(WHITE);
	gotoxy(19,8);
	cprintf("Developer    : ");
	textcolor(YELLOW);
	cprintf("Shobhit Saxena");
	textcolor(WHITE);
	gotoxy(19,9);
	cprintf("Dedecated to : ");
	textcolor(YELLOW);
	cprintf("My Mom and Dad");
	textcolor(WHITE);
	gotoxy(22,10);
	cprintf("---------------------------------");
	gotoxy(19,11);
	cprintf("Version      : ");

	textcolor(YELLOW);
	cprintf("3.0 (Testing Phase)");
	textcolor(WHITE);

	gotoxy(22,12);

	cprintf("---------------------------------");

	gotoxy(19,13);
	cprintf("Home Page    : ");
	textcolor(YELLOW);
	cprintf("www.himvan.com");
	textcolor(WHITE);

	gotoxy(19,14);
	cprintf("E-mail       : ");
	textcolor(YELLOW);
	cprintf("shobhitsaxena@live.com");
	textcolor(WHITE);

	gotoxy(22,15);
	cprintf("---------------------------------");
	textcolor(WHITE);
	gotoxy(27,16);
	cprintf("Copyright (C) 2009-2010.");
	gotoxy(29,17);
	cprintf("All rights reserved.");
	gotoxy(22,18);

	cprintf("---------------------------------");
	getch();
	clrscr();
	exit(1);
}
//------------ This Header File Contains Functions for creating Dialog Box ---------------
void mes(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back,int fore,int bor)
	{
	_setcursortype(_NOCURSOR);
	int l,i,j;
	char f1[10];

	l=strlen(a);
	if(l<strlen(b))
		 l=strlen(b);
	if(l<strlen(c))
		 l=strlen(c);
	if(l<strlen(d))
		 l=strlen(d);
	if(l<strlen(e))
		 l=strlen(e);
	if(l<strlen(f))
		 l=strlen(f);
	l+=4;

	textbackground(back);
	for(i=1;i<l+2;i++)
		for(j=1;j<lines+4;j++)
			 {
			 gotoxy(i+x,j+y);
			 cputs(" ");
			 }
	textcolor(bor);
	gotoxy(x,y);
	cputs("É");
	for(i=x+1;i<l+x+1;i++)
		{
		 gotoxy(i,y);
		 cputs("Í");
		 gotoxy(i,y+lines+3);
		 cputs("Í");
		 }
	gotoxy(x+1+l,y);
	cputs("»");

	for(i=y+1;i<lines+4+y;i++)
		 {
		 gotoxy(x,i);
		 cputs("º");
		 gotoxy(x+l+1,i);
		 cputs("º");
		 }
	gotoxy(x,y+lines+3);
	cputs("È");
	gotoxy(x+l+1,y+lines+3);
	cputs("¼");
	textcolor(fore);
	j=l-strlen(a);
	j=j/2;
	gotoxy(j+x+1,++y);
	cputs(a);
	j=l-strlen(b);
	j=j/2;
	gotoxy(x+j+1,y+1);
	cputs(b);
	j=l-strlen(c);
	j=j/2;
	gotoxy(x+j+1,2+y);
	cputs(c);
	j=l-strlen(d);
	j=j/2;
	gotoxy(x+j+1,3+y);
	cputs(d);
	j=l-strlen(e);
	j=j/2;
	gotoxy(x+j+1,4+y);
	cputs(e);
	j=l-strlen(f)-3;
	j=j/2;
	gotoxy(x+j+1,y+lines+1);
	int xx=x+j+1+2;
	int yy=y+lines+1;
	strcpy(f1," ");
	strcat(f1,f);
	strcat(f1," ");
	textbackground(BLACK);
	cputs(f1);
	textcolor(BLACK);
	for(i=0;i<lines+3;i++)
		 {
		 gotoxy(x+l+2,i+y);
		 cputs("Û");
		 }
	for(i=1;i<l+3;i++)
		 {
		gotoxy(x+i,y+lines+3);
		 cputs("ß");
		 }
		gotoxy(xx,yy);
	}
//--------------------------------------------------------------------------
#include"..\\header\\serial.h"