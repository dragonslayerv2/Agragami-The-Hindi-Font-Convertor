#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<iomanip.h>
#include<dos.h>
#include<time.h>

#define ESC 27
#define UP 72
#define DOWN 80
#define left 75
#define right 77

void remov()
{
remove("i.txt");
remove("i.tmp");
remove("stat.dat");
}
#pragma exit remov
//--------------------------------------------------------------------------------------
void menu(int);
void animate();
void stat();
void convert();
void select_font();
void changeoutputfont();
void changeinputfont();
void input();
void output();
void message(int x,int y,int lines,char a[50],char b[50],char c[50], char d[50],char e[50],char f[10],int back,int fore,int bor);
void getfonts();
void serial();
void stat();
int checkserial(char serialno[]);

//--------------------------------------------------------------------------------------
int totalfonts;
char fontname[100][100];
char to[100],from[100];
int charac;
char ic,oc;
float conversion_time;
//--------------------------------------------------------------------------------------
int checkserial(char serialno[])
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

void serial()
	{       _setcursortype(_NOCURSOR);
		ifstream serial_file("S78HBGF3.INF");
		ifstream trial_file("SIA759I6.INF");
			if(serial_file==0&&trial_file==0)
			{
				serial_file.close();
				exit(0);
			}

			else if(trial_file==0&&serial_file!=0)
			{       char serialno[100];
				serial_file.read((char *)&serialno,sizeof(serialno));
				if(checkserial(serialno)==0)
				{
				exit(1);
				}
				else
				{
					return;
				}
			}
			else if(trial_file!=0&&serial_file==0)
			{       char b;
				trial_file.get(b);
				int a=b;
				if(a>=10)
				{
					exit(1);
				}
				int time=a+1;
				ofstream trial("SIA759I6.INF");
				trial.put(time);
				trial.close();
				trial_file.close();
				return;
			}
			else
				{
				   exit(1);
				}
	}

void getfonts()
{       int e=0;
	ifstream font_file;
	font_file.open("AVLFONTS.DAT");
	if(font_file==0)
		{

		gotoxy(23,11);
			textcolor(LIGHTRED);
			cprintf("UNABLE TO FIND SOURCE CODE FILE...");
			cout<<endl;
			gotoxy(26,15);
			textcolor(YELLOW);
			cprintf("Program will now terminate...");
			getch();

			exit(1);
		}

		char temp[1000];

		for(int i=0;font_file!=0;i++)
			font_file.get(temp[i]);
		temp[i]=NULL;

		for(i=0;i<strlen(temp);i++)
		{
			if(temp[i]==10)
				e++;
		}

		int k=0;

		for(int j=1;j<=e;j++)
		{
			for(int i=0;temp[k]!=10;i++,k++)
				{ fontname[j][i]=temp[k]; }
			fontname[j][i]=NULL;
			k++;
		}
		fontname[j][0]=NULL;
		totalfonts=e;
}

void menu(int l)
{
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
textbackground(BLUE);
clrscr();
if(l==1)
{
normvideo();textbackground(BLUE);textcolor(YELLOW);cprintf("ษอออป                  ");textcolor(WHITE);lowvideo(); textbackground(BLUE);cprintf("ษอออป                    ษอออป                     ษอออป\n\r");
normvideo();textbackground(BLUE);textcolor(YELLOW);cprintf("บ 1 บ                  ");textcolor(WHITE);lowvideo(); textbackground(BLUE);cprintf("บ 2 บ                    บ 3 บ                     บ 4 บ\n\r");
normvideo();textbackground(BLUE);textcolor(YELLOW);cprintf("ฬอออผ                  ");textcolor(WHITE);lowvideo(); textbackground(BLUE);cprintf("ศอหอผ                    ศอหอผ                     ศอออน\n\r");
normvideo();textbackground(BLUE);textcolor(YELLOW);cprintf("บ                        ");textcolor(WHITE);lowvideo(); textbackground(BLUE);cprintf("บ                        บ                           บ\n\r");
normvideo();textbackground(BLUE);textcolor(YELLOW);cprintf("บ                        ");textcolor(WHITE);lowvideo(); textbackground(BLUE);cprintf("บ                        บ                           บ\n\r");
}
else if(l==2)
{
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ษอออป                  ");textcolor(YELLOW);normvideo(); textcolor(YELLOW);textbackground(BLUE);cprintf("ษอออป                    ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ษอออป                     ษอออป\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ 1 บ                  ");textcolor(YELLOW);normvideo(); textcolor(YELLOW);textbackground(BLUE);cprintf("บ 2 บ                    ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ 3 บ                     บ 4 บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ฬอออผ                  ");textcolor(YELLOW);normvideo(); textcolor(YELLOW);textbackground(BLUE);cprintf("ศอหอผ                    ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ศอหอผ                     ศอออน\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        ");textcolor(YELLOW);normvideo();textcolor(YELLOW); textbackground(BLUE);cprintf("บ                        ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                           บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        ");textcolor(YELLOW);normvideo();textcolor(YELLOW); textbackground(BLUE);cprintf("บ                        ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                           บ\n\r");
}
else if(l==3)
{
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ษอออป                  ษอออป                    ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ษอออป                     ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ษอออป\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ 1 บ                  บ 2 บ                    ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ 3 บ                     ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ 4 บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ฬอออผ                  ศอหอผ                    ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ศอหอผ                     ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ศอออน\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        บ                        ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ                           ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        บ                        ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ                           ");textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ\n\r");

}
else if(l==4)
{
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ษอออป                  ษอออป                    ษอออป                     ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ษอออป\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ 1 บ                  บ 2 บ                    บ 3 บ                     ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ 4 บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("ฬอออผ                  ศอหอผ                    ศอหอผ                     ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ศอออน\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        บ                        บ                           ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ\n\r");
textcolor(WHITE);lowvideo();textbackground(BLUE);cprintf("บ                        บ                        บ                           ");textcolor(YELLOW);normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("บ\n\r");
}

normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ฬออออออออออออออออออออออออสออออออออออออออออออออออออสอออออออออออออออออออออออออออน\n\r");
for(int i=1;i<=18;i++)
{normvideo();textcolor(YELLOW);textbackground(BLUE);;cprintf("บ                                                                             บ\n\r");}
normvideo();textcolor(YELLOW);textbackground(BLUE);cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

}
//-------------------------------------------------------------------------------------------------
void message(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back,int fore,int bor)
	{
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
	cputs("ษ");
	for(i=x+1;i<l+x+1;i++)
		{
		 gotoxy(i,y);
		 cputs("อ");
		 gotoxy(i,y+lines+3);
		 cputs("อ");
		 }
	gotoxy(x+1+l,y);
	cputs("ป");

	for(i=y+1;i<lines+4+y;i++)
		 {
		 gotoxy(x,i);
		 cputs("บ");
		 gotoxy(x+l+1,i);
		 cputs("บ");
		 }
	gotoxy(x,y+lines+3);
	cputs("ศ");
	gotoxy(x+l+1,y+lines+3);
	cputs("ผ");
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
		 cputs("฿");
		 }
		gotoxy(xx,yy);
	}
//----------------------------------------------------------------------------------------
void input()
{
	ofstream temp("i.txt");
	if (temp==0)
	    {
	    clrscr();
	    message(20,8,4," ", " ","     ERROR OPENING INPUT FILE...     "," "," ","OK",RED,YELLOW,WHITE);
	    getch();
	    exit(1);
	    }
	    temp<<"[Paste your data in this window]";
	    temp.close();

	int res=system("startcd i.txt");
	    if (res==-1)
	     {
	     clrscr();
	     message(20,8,4," ", " ","     ERROR OPENING INPUT FILE...     "," "," ","OK",RED,YELLOW,WHITE);
	     getch();
	     exit(1);
	     }

}
//-----------------------------------------------------------------------------------------

void output()
{
	system("startcd o.txt");
}
//------------------------------------------------------------------------------------------
void changeinputfont()
{       menu(2);
	gotoxy(18,15);
	textcolor(YELLOW);
	cprintf("Select Input File Font =>");

	message(44,16,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);
	int l=0;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)
					{
					gotoxy(46,15);
					textcolor(WHITE);
					textbackground(BLUE);
					cprintf(fontname[i+1]);
					textbackground(RED);
					}
		gotoxy(46,17+2*i);
		cprintf(fontname[i+1]);
		}
	b=getch();
	if(b==27)
		exit(0);
	if (b==UP&&l>0)
		l--;
	if (b==DOWN&&l<totalfonts-1)
		l++;
		}
	while(b!=13);
		strcpy(from,fontname[l+1]);
		ic=l+49;
}
//***************************** CHANGE OUTPUT  FONT FUNCTION **************************************************
void changeoutputfont()
{
	menu(3);
	gotoxy(18,15);
	textcolor(YELLOW);
	cprintf("Select Output File Font =>");


message(44,16,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);
	int l=0;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)
					{
					gotoxy(46,15);
					textcolor(WHITE);
					textbackground(BLUE);
					cprintf(fontname[i+1]);
					textbackground(RED);
					}
		gotoxy(46,17+2*i);
		cprintf(fontname[i+1]);
		}
	b=getch();
	if(b==27)
		exit(0);
	if (b==UP&&l>0)
		 l--;

	if (b==DOWN&&l<totalfonts-1)
		 l++;

	}
	while(b!=13);
		if(strcmp(from,fontname[l+1])==0)
			{
			message(24,8,4," ", " ","SAME FONTS CANNOT BE SELECTED"," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfont();
			return;
			}
		strcpy(to,fontname[l+1]);
		oc=l+49;
}
//----------------------------------------------------------------------------------------																																																																																		}
//----------------------------------------------------------------------------------------
void convert()
{
		
	clock_t start, end;
	start = clock();
	char file[10];
	file[0]=ic;
	file[1]=oc;
	file[2]=NULL;
	strcat(file,".exe");

	int result = spawnl(P_WAIT,file,NULL);

	if (result==-1)
		{
		clrscr();
		message(24,8,4," ", " ","    CONVERTOR FILE MISSING...     "," "," ","OK",RED,YELLOW,WHITE);
		getch();
		exit(1);
		}
	end = clock();
	conversion_time = (end - start) / CLK_TCK;
	animate();
	stat();
	
}

//---------------------------------------- ANIMATION FUNCTION -------------------------------------------------------------
//************************** ANIMATE USER SCREEN WHILE CONVERSION IS IN PROGRESS*******************************************
void animate()
{
	message(18,8,12,"                                      ",
	       "                        ",
	       "                        ",
	       "                        ",
	       "                        ","  ",RED,WHITE,WHITE);
	textbackground(RED);
	gotoxy(28,22);
	cprintf("                           ");
	textcolor(YELLOW);
	gotoxy(28,12);
	cprintf("{                      }");
	for(int i=1;i<=20;i++)
		{
		  gotoxy(i+29,12);
		  textcolor(LIGHTGREEN);
		  cprintf("-");
		  delay(50);
		}
	char a[]={"STATUS"};
	char b[]={"Converting data."};
	char c[]={"DATA CONVERTED."};
	char d[]={"                        "};
	gotoxy(34,12);
	textcolor(YELLOW);

	for(i=0;a[i]!=NULL;i++)
		{
			gotoxy(37+i,12);
			cprintf("%c",a[i]);
			delay(60);
		}
	gotoxy(28,19);
	textcolor(YELLOW);
	cprintf("{                      }");
	for( i=1;i<=20;i++)
	  {
		textcolor(LIGHTRED);
		gotoxy(i+29,19);
		cprintf("-");
		gotoxy(1,1);
		delay(80);
	  }
	gotoxy(29,12);
	textcolor(LIGHTGREEN);
	for(i=0;b[i]!=NULL;i++)
	  {
		gotoxy(32+i,15);
		cprintf("%c",b[i]);
		gotoxy(1,1);
		delay(60);
	  }
	  gotoxy(33,15);

	for(i=1;i<=100;i++)
	  {
		gotoxy(33,19);
		textcolor(YELLOW);
		cprintf("%d %c complete",i,'%');
		gotoxy(1,1);
		delay(10);
	  }gotoxy(32,15);
	   cprintf("                     ");
	for(i=0;c[i]!=NULL;i++)
	  {
		delay(80);
		gotoxy(33+i,15);
		textcolor(LIGHTRED);
		cprintf("%c",c[i]);
		gotoxy(1,1);
	  }
	gotoxy(25,19);
	textcolor(WHITE);
	for(i=0;d[i]!=NULL;i++)
	  {
		delay(20);
		gotoxy(25,16);
		cprintf("%c",d[i]);
		gotoxy(1,1);
	  }
}
//----------------------------------------------------------------------------------
void stat()
{
struct statistics
{
int charac;
int wrong;
};
statistics s;
ifstream stats("stat.dat");
stats.read((char *)&s,sizeof(s));
stats.close();
remove("stat.dat");

message(20,11,6,"REPORT",
	       "\nTotal Characters       =>       ",
	       "\nErrors                 =>       ",
	       "\nAccuracy               =>       ",
	       "\nTime Taken             =>       ",
	       "OK",RED,WHITE,YELLOW);


gotoxy(49,14);
textcolor(YELLOW);
textbackground(RED);
cprintf("%d", s.charac);
gotoxy(49,15);
cprintf("%d", s.wrong);
if(charac==0)
s.charac++;
float p=(float)(s.wrong * 100) /s.charac;
gotoxy(49,16);
cout<<setprecision(2)<<float(100-p)<<" %";
gotoxy(49,17);
textcolor(YELLOW);
cout<<setprecision(2)<<conversion_time<<" sec";
gotoxy(1,1);
getch();

}
//----------------------------------------------------------------------------------
void main()
{
serial();
_setcursortype(_NOCURSOR);
remove("i.txt");
remove("o.txt");
remove("i.tmp");
remove("o.tmp");
getfonts();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
textbackground(BLUE);
clrscr();
menu(1);
message(14,12,4," ", " ","     Paste the data in the opened window...     "," "," ","OK",RED,YELLOW,WHITE);
input();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
char b=getch();
if(b==27)
		exit(0);
changeinputfont();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
changeoutputfont();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
menu(4);
rename("i.txt", "i.tmp");
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
convert();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
rename("o.tmp", "o.txt");
output();
_setcursortype(_NORMALCURSOR);
_setcursortype(_NOCURSOR);
exit(0);

}