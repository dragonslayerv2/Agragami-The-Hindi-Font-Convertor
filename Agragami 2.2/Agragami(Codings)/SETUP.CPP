#define ESC 27
#define UP 72
#define DOWN 80
#define left 75
#define right 77

#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>

void menu();

void box()
{       textbackground(BLUE);
	clrscr();
	for(int i=0;i<=25;i++)
	{
			textcolor(LIGHTRED);
		cprintf("*");
			textcolor(YELLOW);
		cprintf("--");
	}

		 textcolor(LIGHTRED);
	cprintf("*");
	for(i=0;i<=11;i++)
	{
		cprintf("\n\r");
			textcolor(YELLOW);
		cprintf("|                                                                             |");
		cprintf("\n\r");
		if(i==11)
			break;
			textcolor(LIGHTRED);
		cprintf("*                                                                             *");
	}

	for(i=0;i<=25;i++)
	{
			textcolor(LIGHTRED);
		cprintf("*");
			textcolor(YELLOW);
		cprintf("--");
	}
		 textcolor(LIGHTRED);
	cprintf("*");
	gotoxy(35,3);
	textcolor(YELLOW);
	cprintf(" AGRAGAMI");

	gotoxy(30,5);
	textcolor(WHITE);
	cprintf("Hindi Font Convertor");

	gotoxy(2,7);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");
}

void message(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back,int fore,int bor)
	{
	box();
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

void destroy()
{
	textbackground(LIGHTGRAY);
	clrscr();
	char a='n';
	message(20,11,5," ", " ","ARE YOU SURE YOU WANT TO UNINSTALL?"," "," ","OK",RED,WHITE,YELLOW);
	gotoxy(30,18);
	textbackground(RED);
	cprintf("              ");
	gotoxy(28,17);
	textcolor(YELLOW);
	cprintf(" YES ");
	gotoxy(1,1);
	gotoxy(45,17);
	textcolor(WHITE);
	textbackground(BLACK);
	cprintf(" NO ");
	gotoxy(1,1);
	int x;
	do
	{
	x=getch();
	if (x==27)
		menu();
	if(x==left||x=='y')
		{
		gotoxy(45,17);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" NO ");
		gotoxy(1,1);
		gotoxy(28,17);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" YES ");
		gotoxy(1,1);
		a='y';
		}

	if(x==right||x=='n')
		{
		a='n';
		gotoxy(28,17);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" YES ");
		gotoxy(1,1);
		gotoxy(45,17);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" NO ");
		gotoxy(1,1);
		}
	} while(x!=13);

	if (a=='n')
		{
		menu();
		exit(0);
		}
	else    {

	char del[10];
	for(int i=1;i<=3;i++)
		{
		for(int j=1;j<=3;j++)
			{
			del[0]=i+48;
			del[1]=j+48;
			del[2]='.';
			del[3]='e';
			del[4]='x';
			del[5]='e';
			del[6]=NULL;
			remove(del);
			}
		}
	remove("MAIN.exe");
	remove("S78HBGF3.INF");
	remove("avlfonts.dat");

	remove("trial.exe");
	remove("temp.exe");
	remove("repair.exe");
	remove("wizard.exe");
	remove("setup.exe");
	remove("i.tmp");
	remove("o.tmp");
	remove("stat.dat");
	remove("send.dat");
	}
}

void menu()
{       textbackground(WHITE);
	clrscr();
	char a='r';
	message(16,11,5," ", " ","         What do you want to do?            "," "," ","OK",GREEN,WHITE,YELLOW);
	gotoxy(30,18);
	textbackground(GREEN);
	cprintf("                         ");
	gotoxy(24,17);
	textcolor(YELLOW);
	cprintf(" Uninstall ");
	gotoxy(1,1);
	gotoxy(45,17);
	textcolor(BLACK);
	textbackground(LIGHTGRAY);
	cprintf(" Repair ");
	gotoxy(1,1);
	int x;
	do
	{
	x=getch();
	if (x==27)
		exit(0);
	if(x==left||x=='u')
		{
		message(16,11,5," ", " ","         What do you want to do?            "," "," ","OK",RED,WHITE,YELLOW);
			gotoxy(30,18);
		textbackground(RED);
		cprintf("                         ");

		gotoxy(45,17);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" Repair ");
		gotoxy(1,1);
		gotoxy(24,17);

		textcolor(BLACK);
		textbackground(LIGHTGRAY);

		cprintf(" Uninstall ");
		gotoxy(1,1);
		a='u';
		}

	if(x==right||x=='r')
		{
		message(16,11,5," ", " ","         What do you want to do?            "," "," ","OK",GREEN,WHITE,YELLOW);
		a='r';
			gotoxy(30,18);
		textbackground(GREEN);
		cprintf("                         ");

		gotoxy(24,17);
		textbackground(GREEN);
		textcolor(YELLOW);
		cprintf(" Uninstall ");
		gotoxy(1,1);
		gotoxy(45,17);
		textcolor(BLACK);
		textbackground(LIGHTGRAY);
		cprintf(" Repair ");
		gotoxy(1,1);
		}
	} while(x!=13);

	if (a=='r')
		{
		int result=spawnl(P_WAIT,"repair.exe",NULL);
		if(result==-1)
			{clrscr();
			 cprintf("ERROR: Repair file missing");
			 getch();
			}
		else
			{
			clrscr();
			message(20,11,5," ", " ","Agragami repaired successfully"," "," ","OK",GREEN,WHITE,YELLOW);
			remove("S78HBGF3.INF");
			getch();
			}
			exit(0);
		}
	else
		{
		  destroy();
		  message(6,11,7," ", " ","Agragami uninstalled successfully","Few files can't be deleted. You can manually delete them later.","\n\nThanks for using our software. ","OK",GREEN,WHITE,YELLOW);
		  getch();
		  exit(0);
		}
}

void main()
{
_setcursortype(_NOCURSOR);
menu();
}
