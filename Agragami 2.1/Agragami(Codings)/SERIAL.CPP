#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#define left 75
#define right 77
void EXIT();
void message(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back,int fore,int bor);
char serialno[100];
void patch()
{
			_setcursortype(_NOCURSOR);
			textbackground(WHITE);
			clrscr();
			remove("SIA759I6.INF");
			ofstream serial_file("S78HBGF3.INF");
			for(int i=0;i<29;i++)
			   {
			   if((i+1)%6==0&&i!=29)
			   serial_file.put('-');
			   else
			   serial_file.put(serialno[i]);
			   }
			serial_file.close();
			message(20,10,3," ",
		       " SERIAL KEY INSTALLED SUCCESSFULLY ",
		       " ",
		       " ",
		       " "," OK ",GREEN,WHITE,YELLOW);
			getch();
			textbackground(WHITE);
			clrscr();
			EXIT();
}
int checkserial()
	{
	char b[5][5];
	int sum=0;
	int col=0;
	int row=0;

	for(int i=0;i<=29;i++)
		{
		b[col][row]=serialno[i];
		row++;
		if(row==5)
			{
			row=0;
			col++;
			i++;
			}
		}

	for(i=0;i<5;i++)
		sum=sum+ ((b[i][0]+b[i][4]+(b[i][2]/10))-(b[i][1]+b[i][3]+(b[i][2]%10)));

	if(sum==31)
		return 1;
	else
		return 0;
	}
//***************************************************************************************************************************
void message(int x,int y,int lines,char a[50],char b[50],char c[50],
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

void printkey()
{       _setcursortype(_NOCURSOR);
	int j=0;
	textcolor(WHITE);
   textbackground(RED);
   randomize();
   for(int i=0;i<=29;i++)
   serialno[i]=NULL;
   while(checkserial()!=1)
   {
   j++;
   for(int i=0;i<=29;i++)
   {
   serialno[i]= 65+random (26);
   }
   }
   for(i=0;i<29;i++)
   {
   if((i+1)%6==0&&i!=29)
   cprintf("-");
   else
   cprintf("%c",serialno[i]);
   }
}


//**************************************************************************************************************************
void EXIT()
{        _setcursortype(_NOCURSOR);
	char a;
	message(20,8,5," ", " ","                              "," "," ","OK",RED,WHITE,YELLOW);
	gotoxy(30,15);
	textbackground(RED);
	cprintf("              ");
	gotoxy(25,14);
	textcolor(YELLOW);
	cprintf(" EXIT ");
	gotoxy(1,1);
	gotoxy(39,14);
	textcolor(WHITE);
	textbackground(BLACK);
	cprintf(" GENERATE ");
	gotoxy(23,10);
	printkey();

	textcolor(LIGHTGREEN);
	gotoxy(25,12);
	cprintf("AGRAGAMI - Shobhit Saxena");

	gotoxy(1,1);
	int x;
	do
	{
	x=getch();
	if (x==27)
		exit(0);
	if(x==left||x=='e')
		{
		gotoxy(39,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" GENERATE ");
		gotoxy(1,1);
		gotoxy(25,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" EXIT ");
		gotoxy(1,1);
		a='e';
		}

	if(x==right||x=='g')
		{
		a='g';
		gotoxy(25,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" EXIT ");
		gotoxy(1,1);
		gotoxy(39,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" GENERATE ");
		gotoxy(1,1);
		}
		 if(x==60)
		 patch();
	} while(x!=13);

	if (a=='e')
		{
		exit(0);
		}
	else    {
		EXIT();
		}

}
//**************************************************************************
void main()
{
_setcursortype(_NOCURSOR);
textbackground(WHITE);
clrscr();
EXIT();
}