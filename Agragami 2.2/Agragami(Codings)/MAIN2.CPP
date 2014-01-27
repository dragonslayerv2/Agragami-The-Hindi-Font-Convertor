//*************************************************************************************************************************
//--------------------------------------HEADER FILES DECLARATION-----------------------------------------------------------
//*************************************************************************************************************************
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

void clean()
{
remove("i.tmp");
remove("o.tmp");
remove("stat.dat");
}
#pragma exit clean

//*************************************************************************************************************************
//--------------------------------------KEYS DEFINATIONS-------------------------------------------------------------------
//*************************************************************************************************************************
#define ESC 27
#define UP 72
#define DOWN 80
#define left 75
#define right 77
int lastmenuchoice=1;
//***************************************************************************
#define TXT "1"
#define HTML "4"
#define RTF "5"
#define DOC "9"
#define PDF "12"

//*************************************************************************************************************************
//--------------------------------------PRINT DATE IN FIRST WINDOW---------------------------------------------------------
//*************************************************************************************************************************
void date()
{
	textbackground(BLUE);
   time_t timer;
   struct tm *tblock;
   timer = time(NULL);
   tblock = localtime(&timer);
   gotoxy(28,3);
   textcolor(LIGHTGREEN);
   cprintf("%s", asctime(tblock));
}

//*************************************************************************************************************************
//-------------------------------------------CLASS DECLARATION-------------------------------------------------------------
//******************************************* CONVERTOR CLASS *************************************************************
class convertor
	{
	private:

		char previous;
		char pathi[_MAX_PATH];
		char patho[_MAX_PATH];
		char drive[_MAX_DRIVE];
		char dir[_MAX_DIR];
		char files[_MAX_FNAME];
		char ext[_MAX_EXT];
		char ival[10],oval[10];
		char extcommand[500];

		char serial_file_name[20];
		char serialno[30];
		char to[100],from[100];
		char infile[100],outfile[100];
		char fontname[100][100];
		int totalfonts;
		char file[20];
		char ic,oc;
		int time;
		int charac;
		char version[100];
		char temppath[100];
		float conversion_time;
	private:
		void printfirstscreen(int l);
		void changeinputfont();
		void changeoutputfont();
		void printfirstscreen();
		void welcome_screen();
		void box();
		void convertofile();
		void boxs(int x1,int y1,int x2,int y2);
		void serial();
		void getserial();
		int checkserial();
		void first();
		void input();
		void changeinputfile();
		void changeoutputfile();
		void getfonts();
		void changefont();
		void getdata();
		void putdata();
		void convert();
		void cleanup();
		void EXIT();
		void animate();
		void trial();
		void destroy();
		void message(int x,int y,int lines,char a[50],char b[50],char c[50],char d[50],char e[50],char f[10],int back,int fore,int bor);
		void fhelp();
		void credits();
		void stat();
		void printer(char a[],char b[],int x1,int y1,int x2,int y2,int background,int time);
		void convertifile();
	public:

		convertor()
			{
				textbackground(BLUE);
				clrscr();


				ic='1';
				oc='2';
				window(1,1,80,25);
				getfonts();
				strcpy(to,fontname[2]);
				strcpy(from, fontname[1]);
				strcpy(serial_file_name,"S78HBGF3.INF");
				strcpy(infile,"C:\\INPUT.DOC");
				strcpy(outfile,"C:\\OUTPUT.DOC");
				welcome_screen();
			}

	};

//*************************************************************************************************************************
//-------------------------------------------WELCOME SCREEN----------------------------------------------------------------
//*************************************************************************************************************************
void convertor::welcome_screen()
{
	box();
	_setcursortype(_NOCURSOR);
	message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,WHITE);
	gotoxy(30,15);
	textbackground(RED);
	cprintf("                       ");
	printer("Hindi Font Convertor","Agragami",30,14,36,12,RED,23);

	delay(200);
	serial();
}

//*************************************************************************************************************************
//-------------------------------------------CREATE BOXES------------------------------------------------------------------
//**********************************************BOX 1**********************************************************************
void convertor::boxs(int x1,int y1,int x2,int y2)
{
	gotoxy(x1,y1);
	cprintf("É");
	gotoxy(x2,y1);
	cprintf("»");
	gotoxy(x1,y2);
	cprintf("È");
	gotoxy(x2,y2);
	cprintf("¼");
	for(int i=x1+1;i<x2;++i)
	{
		gotoxy(i,y1);
		cprintf("Í");
		gotoxy(i,y2);
		cprintf("Í");
	}
	for(i=y1+1;i<y2;++i)
	{
		gotoxy(x1,i);
		cprintf("º");
		gotoxy(x2,i);
		cprintf("º");
	}
}

//*************************************BOX 2(BACKGROUND)*******************************************************************

void convertor :: box()
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
}


//*************************************************************************************************************************
//---------------------------------------------SERIAL CONSOLE--------------------------------------------------------------
//********************************************SERIAL    ROUTER*************************************************************

void convertor :: serial()
	{       _setcursortype(_NOCURSOR);
		ifstream serial_file(serial_file_name);
		ifstream trial_file("SIA759I6.INF");
			if(serial_file==0&&trial_file==0)
			{
				serial_file.close();
				getserial();
			}

			else if(trial_file==0&&serial_file!=0)
			{
				serial_file.read((char *)&serialno,sizeof(serialno));
				if(checkserial()==0)
				{
				box();
				gotoxy(21,11);
				textcolor(LIGHTRED);
				remove("trial.exe");
				cprintf("An attempt was made to distrupt the program");
				textcolor(YELLOW);
				gotoxy(24,14);
				cprintf("Program will now destroy itself");
				destroy();
				getch();
				exit(1);
				}
				else
				{
				strcpy(version,"FULL.");
				serial_file.close();
				first();
				}
			}
			else if(trial_file!=0&&serial_file==0)
			{       char b;
				trial_file.get(b);
				int a=b;
				if(a>=10)
				{
					box();
					gotoxy(30,12);
					textcolor(LIGHTRED);
					box();
				message(25,10,3," ",
		       " YOUR TRIAL VERSION ENDS ",
		       " ",
		       " ",
		       " "," OK ",RED,WHITE,YELLOW);

					destroy();
					rename("TRIAL.exe","MAIN.exe");
					getch();
					exit(1);
				}
				box();
				time=a+1;
				ofstream trial("SIA759I6.INF");
				trial.put(time);
				trial.close();
				textcolor(WHITE);
				boxs(24,10,50,16);
				gotoxy(30,12);

				if(10-a>=5)
				{
				message(24,10,5," ","    Trial Version    "," "," "," ","OK",GREEN,YELLOW,WHITE);
				textbackground(GREEN);
				}
				else
				{
				message(24,10,5," ","    Trial Version    "," "," "," ","OK",RED,YELLOW,WHITE);
				textbackground(RED);
				}
				gotoxy(28,15);
				textcolor(WHITE);


				cprintf("Hits Remaining : ");
					textcolor(YELLOW);
				cprintf ("%d",10-a);
				getch();
				strcpy(version,"TRIAL");

				trial_file.close();
				first();
			}
			else
				{
				box();
				gotoxy(21,11);
				textcolor(LIGHTRED);
				remove("trial.exe");
				cprintf("An attempt was made to distrupt program");
				textcolor(YELLOW);
				gotoxy(24,14);
				cprintf("Program will now destroy itself");
				destroy();
				getch();
				exit(1);
				}


	}
//***********************************GET SERIAL CODE FROM USER*************************************************************

void convertor::getserial()
	{
		box();
		_setcursortype(_NORMALCURSOR);
		message(18,8,7,"                                  ",
	       " ",
	       " ",
	       " ",
	       " "," OK ",RED,WHITE,YELLOW);
		textbackground(RED);
		textcolor(YELLOW);
		gotoxy(29,11);


		cprintf("Enter Serial Key\n");
		gotoxy(23,14);
		textcolor(WHITE);
		cprintf("_____________________________");


		gotoxy(23,14);
		char temp[30];
		for(int i=0;temp[i-1]!=13;i++)
		{
		temp[i]=getch();
		if(temp[i]==8)
			{
			if(i!=0)
				{
				cprintf("\b_\b");
				i-=1;
				}
			i--;
			}
		else if(temp[i]==27)
			exit(0);
		else
		cprintf("%c",temp[i]);

		}
		temp[i-1]=NULL;
		strcpy(serialno,temp);
		strupr(serialno);
		if(strcmp(serialno,"SFCTRIAL")==0)
			{
			trial();
			}
		else
		{
		int check = checkserial();
		if(check==0)
			{
			box();
			message(25,10,3," ",
	       " INVALID SERIAL KEY ",
	       " ",
	       " ",
	       " "," OK ",RED,WHITE,YELLOW);

			getch();
			cleanup();
			exit(0);
			}
		else
			{
			clrscr();
			ofstream serial_file(serial_file_name);
			serial_file.write((char *)&serialno,sizeof(serialno));
			system("attrib S78HBGF3.INF +a +h +s +r");
			serial_file.close();
			box();
			box();
			message(20,10,3," ",
	       " SERIAL KEY INSTALLED SUCCESSFULLY ",
	       " ",
	       " ",
	       " "," OK ",GREEN,WHITE,YELLOW);

			getch();
			serial();

			}
		}
	}
//**********************************CHECK SERIAL CODE ENTERED BY USER *****************************************************
int convertor::checkserial()
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
//****************************** CREATE TRIAL FILE ************************************************************************
void convertor::trial()
	{
	ofstream trial("SIA759I6.INF");
	system("attrib SIA759I6.INF +a +h +s");
	trial.put(1);
	serial();
	}
//*************************************************************************************************************************
//---------------------------------------------FIRST SCREEN----------------------------------------------------------------
//*************************************************************************************************************************

void convertor::first()
{
	strcpy(temppath,"");


	strupr(infile);
	strupr(outfile);
	box();
	textcolor(WHITE);
	boxs(68,2,76,4);
	gotoxy(70,3);
	textcolor(YELLOW);
	cprintf(version);
	gotoxy(35,5);
	textcolor(YELLOW);
	cprintf(" AGRAGAMI");

	gotoxy(30,7);
	textcolor(WHITE);
	cprintf("Hindi Font Convertor");

	gotoxy(2,9);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");

	gotoxy(4,11);
	textcolor(WHITE);
	cprintf("1 => Input file           =>        ");
	textcolor(YELLOW);
	cprintf(infile);

	gotoxy(4,13);
	textcolor(WHITE);
	cprintf("2 => Output file          =>        ");
	textcolor(YELLOW);
	cprintf(outfile);

	gotoxy(4,15);
	textcolor(WHITE);
	cprintf("3 => Current convertor    =>        ");
	textcolor(YELLOW);
	cprintf(from);
	textcolor(LIGHTRED);
	cprintf("  =>  ");
	textcolor(YELLOW);
	cprintf(to);

	gotoxy(4,17);
	textcolor(WHITE);
	cprintf("4 => Convert.");

	gotoxy(4,19);
	textcolor(WHITE);
	cprintf("5 => Exit.");

	gotoxy(2,21);
	textcolor(YELLOW);

	cprintf("-----------------------------------------------------------------------------");
	gotoxy(3,23);
	textcolor(WHITE);
	cprintf("=> ");
	textcolor(YELLOW);
	gotoxy(40,23);
	textcolor(YELLOW);
	cprintf("F1.");
	textcolor(WHITE);
	cprintf(" Wizard.   ");
	textcolor(YELLOW);

	textcolor(YELLOW);
	cprintf("F2. ");
	textcolor(WHITE);
	cprintf("Credits.  ");
	textcolor(YELLOW);
	cprintf("ESC. ");
	textcolor(WHITE);
	cprintf("QUIT.");


	input();
}
//*************************************************************************************************************************
//---------------------------------------------ROUTER----------------------------------------------------------------------
//********************GET INPUT FROM USER AND ROUTE THEM TO RESPECTIVE FUNCTION********************************************
void convertor::input()
{
	_setcursortype(_NORMALCURSOR);
       _setcursortype(_NOCURSOR);
	int l=lastmenuchoice;
	char i;
	do
	{
	while(!kbhit())
		printfirstscreen(l);
	i=getch();
	lastmenuchoice=l;
	if(i==UP&&l>1)
		{l--; continue;}

	else if(i==DOWN&&l<5)
		{l++; continue;}

	else
	{
	switch(i)
	{

		case 59 :
			  int result=spawnl(P_WAIT,"wizard.exe",NULL);

			  clrscr();
			  if(result==-1)
		  {		cprintf("UNABLE TO FIND WIZARD.EXE");getch();}
			  first();
			  break;


		case 60:   credits();break;

		case '1':
		case 'i':
		case 'I': changeinputfile();break;

		case '2':
		case 'o':
		case 'O': changeoutputfile();break;

		case '3':
		case 'f':
		case 'F': changefont();break;

		case '4':
		case 'c':
		case 'C': convert();break;

		case 27:
		case '5':
		case 'e':
		case 'E': EXIT();break;

	}
	}
	}while(i!=13&&i!=right);

		switch(l)
			{

		case 1: changeinputfile();break;

		case 2: changeoutputfile();break;

		case 3: changefont();break;

		case 4: convert();break;

		case 5: EXIT();break;

			}

}
//*************************************************************************************************************************
//----------------------------------------PRINT MENU OF FIRST SCREEN-------------------------------------------------------
//********************************************** PRINT MENU  **************************************************************

void convertor::printfirstscreen(int l)
{               _setcursortype(_NOCURSOR);
	char menu[10][100],menuh[10][100];

	strcpy(menu[1],"1 => Input file        ");
	strcpy(menuh[1],"Change Input File.    ");
	strcpy(menu[2],"2 => Output file       ");
	strcpy(menuh[2],"Change Output File.   ");
	strcpy(menu[3],"3 => Current convertor ");
	strcpy(menuh[3],"Change Convertor.     ");
	strcpy(menu[4],"4 => Convert.      ");
	strcpy(menuh[4],"Convert Data.         ");
	strcpy(menu[5],"5 => Exit.        ");
	strcpy(menuh[5],"Quit.                 ");

	for(int i=1;i<=5;i++)
		{
		date();
		textbackground(BLUE);

		textcolor(WHITE);

		lowvideo();
		if(i==l)
		       {
			highvideo();
			gotoxy(7,23);
			cprintf(menuh[i]);
		       }

		gotoxy(4,9+2*i);
		cprintf(menu[i]);
		}
		normvideo();
	}

//*************************************************************************************************************************
//----------------------------------------CHANGE INPUT FILE FUNCTION-------------------------------------------------------
//************************************ CHANGES INPUT FILE TO USER FILE ****************************************************

void convertor::changeinputfile()
{

	char temp[100];
	strcpy(temp,temppath);
	box();
	for(int i=strlen(temppath);temp[i-1]!=13;i++)
		{
gotoxy(28,7);	cprintf("%s",temp);
	char command[100]="dirb ";
		strcat(command,temp);
		system(command);

	_setcursortype(_NORMALCURSOR);
	gotoxy(17,23);
	textcolor(YELLOW);
	cprintf(" F2.");
	textcolor(WHITE);
	cprintf(" Preview.");
	textcolor(YELLOW);
	cprintf("   ENTER.");
	textcolor(WHITE);
	cprintf(" Continue.");
	textcolor(YELLOW);
	cprintf("   ESC.");
	textcolor(WHITE);
	cprintf(" BACK.");
	textbackground(BLUE);
	gotoxy(23,3);
	textcolor(YELLOW);
	cprintf("Current input file : ");
	textcolor(LIGHTRED);
	if(strlen(infile)<27)
	{
	cprintf(infile);
	}
	else
	{
	for(int i=0;i<27;i++)
	cprintf("%c",infile[i]);
	cprintf("...");
	}
	gotoxy(27,5);
	textcolor(WHITE);
	cprintf("Enter new input file path.");

	gotoxy(25,7);
	textcolor(YELLOW);
	cprintf("=> ");

		gotoxy(28+i,7);
		temp[i]=getch();
		gotoxy(1,1);
		box();

		if(temp[i]==8)
			{
			if(i!=0)
				{
				cprintf("\b \b");
				i-=1;
				}
			i--;
			}

		else if(temp[i]==27)
			first();

		else if (temp[i]==60)
			{
			temp[i]=NULL;
			char command[100]="startcd ";
			strcat(command,temp);
			int result=system(command);
			clrscr();
			if(result==-1)
				{box();gotoxy(2,2);perror("ERROR");getch();}
			strcpy(temppath,temp);
			changeinputfile();
			}

		/*else if(temp[i]==61)
			{
			system("edit C:\\input.txt");
			strcpy(infile,"C:\\input.txt");
			first();
			}*/

			temp[i+1]=NULL;		       {gotoxy(28,7);	cprintf("%s",temp);}

		strcpy(command,"dirb ");
		strcat(command,temp);
		system(command);

		}
	temp[i-1]=NULL;
	ifstream tempfile;
	tempfile.open(temp);
	if(strlen(temp)==0)
		{
			box();
			tempfile.close();
			message(20,8,4," ", " ","FILE FIELD CANNOT BE LEFT BLANK..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeinputfile();
		}
	else if(tempfile==0)
		{       box();
			strcpy(temppath,temp);
			tempfile.close();
			message(24,8,4," ", " ","     FILE NOT FOUND...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeinputfile();
		}
	else
		{
			tempfile.close();
			strcpy(infile,temp);
			first();
		}
}
//*************************************************************************************************************************
//----------------------------------------CHANGE OUTPUT FILE FUNCTION------------------------------------------------------
//************************************ CHANGES OUTPUT FILE TO USER FILE ***************************************************
void convertor::changeoutputfile()
{       _setcursortype(_NORMALCURSOR);
	box();
	gotoxy(23,23);
	textcolor(YELLOW);
	cprintf("   ENTER.");
	textcolor(WHITE);
	cprintf(" Continue.");
	textcolor(YELLOW);
	cprintf("   ESC.");
	textcolor(WHITE);
	cprintf(" BACK.");
	gotoxy(23,11);
	textcolor(YELLOW);
	cprintf("Current output file : ");
	textcolor(LIGHTRED);
	cprintf(outfile);
	gotoxy(27,14);
	textcolor(WHITE);
	cprintf("Enter new output file path.");
	char temp[100];
	gotoxy(25,16);
	textcolor(YELLOW);
	cprintf("=> ");
	for(int i=0;temp[i-1]!=13;i++)
		{
		temp[i]=getch();
		if(temp[i]==8)
			{
			if(i!=0)
				{
				cprintf("\b \b");
				i-=1;
				}
			i--;
			}
		else if(temp[i]==27)
			first();
		else
			cprintf("%c",temp[i]);

		}
	temp[i-1]=NULL;

	if(strlen(temp)==0)
		{
			box();
			message(20,8,4," ", " ","FILE FIELD CANNOT BE LEFT BLANK..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();

		}
		strupr(temp);
		if(strcmp(temp,infile)==0)
		 {
			box();
			message(22,8,4," ", " ","     SAME INPUT/OUTPUT FILE...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
		}
	ifstream tems(temp);
		if(tems!=0)
		{
			box();
			tems.close();
			message(22,8,4," ", " ","       FILE ALREADY EXIST...       "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
		}

	ofstream temps(temp);
	if(temps==0)
		{
			box();
			temps.close();
			message(24,8,4," ", " ","     INVALID FILE PATH...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
		}

	else
		{       remove(temp);
			strcpy(outfile,temp);
			first();
		}


}
//*************************************************************************************************************************
//----------------------------------------------FONT CONSOLE --------------------------------------------------------------
//************************************ Print First screen in Change Font ** ***********************************************
void convertor::printfirstscreen()
{

	strupr(infile);
	strupr(outfile);
	box();
	textcolor(WHITE);
	boxs(68,2,76,4);
	gotoxy(70,3);
	textcolor(YELLOW);
	cprintf(version);
	gotoxy(35,5);
	textcolor(YELLOW);
	cprintf(" AGRAGAMI");

	gotoxy(30,7);
	textcolor(WHITE);
	cprintf("Hindi Font Convertor");

	gotoxy(2,9);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");

	gotoxy(4,11);
	textcolor(WHITE);
	cprintf("1 => Input file           =>        ");
	textcolor(YELLOW);
	cprintf(infile);

	gotoxy(4,13);
	textcolor(WHITE);
	cprintf("2 => Output file          =>        ");
	textcolor(YELLOW);
	cprintf(outfile);

	gotoxy(4,15);
	textcolor(WHITE);
	cprintf("3 => Current convertor    =>        ");
	textcolor(YELLOW);
	cprintf(from);
	textcolor(LIGHTRED);
	cprintf("  =>  ");
	textcolor(YELLOW);
	cprintf(to);

	gotoxy(4,17);
	textcolor(WHITE);
	cprintf("4 => Convert.");

	gotoxy(4,19);
	textcolor(WHITE);
	cprintf("5 => Exit.");

	gotoxy(2,21);
	textcolor(YELLOW);

	cprintf("-----------------------------------------------------------------------------");
	gotoxy(3,23);
	textcolor(WHITE);
	cprintf("=> ");
	textcolor(YELLOW);
	gotoxy(29,23);
	textcolor(YELLOW);
	gotoxy(40,23);
	textcolor(YELLOW);
	cprintf("F1.");
	textcolor(WHITE);
	cprintf(" Wizard.   ");
	textcolor(YELLOW);
/*
	cprintf("F2.");
	textcolor(WHITE);
	cprintf(" Notepad.  ");*/

	textcolor(YELLOW);
	cprintf("F2. ");
	textcolor(WHITE);
	cprintf("Credits.  ");
	textcolor(YELLOW);
	cprintf("ESC. ");
	textcolor(WHITE);
	cprintf("QUIT.");
	date();
}
//*************************************************************************************************************************
//----------------------------------------------FONT CONSOLE --------------------------------------------------------------
//************************************ GET AVAILABLE FONTS FROM AVLFONT.DAT ***********************************************
void convertor::getfonts()
{       int e=0;
	ifstream font_file;
	font_file.open("AVLFONTS.DAT");
	if(font_file==0)
		{
		box();
		gotoxy(25,11);
			textcolor(LIGHTRED);
			cprintf("UNABLE TO FIND \"AVLFONTS.DAT\"...");
			cout<<endl;
			gotoxy(26,15);
			textcolor(YELLOW);
			cprintf("Program will now terminate...");
			getch();
			cleanup();
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

//*************************************************************************************************************************
//----------------------------------------CHANGE FONT FUNCTION-------------------------------------------------------------
//************************************ CHANGE FONT CONVERTOR FILE *********************************************************
void convertor::changefont()
{       changeinputfont();
	//OLDER MODULE!!!!!
	/*
	ffonts:
	box();
	gotoxy(14,3);
	textcolor(YELLOW);
	cprintf("Current Convertor : ");
	textcolor(LIGHTRED);
	cprintf(from);
	textcolor(YELLOW);
	cprintf(" => ");
	textcolor(LIGHTRED);
	cprintf(to);

	gotoxy(2,5);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");
	gotoxy(29,7);

	textcolor(WHITE);
	cprintf("AVAILABLE INPUT FONTS.");

	for(int i=1;fontname[i][0]!=NULL;i++)
	{
		gotoxy(3,10+2*(i-1));
		textcolor(YELLOW);
		cprintf("%d => ",i);
		textcolor(LIGHTGREEN);
		cprintf(fontname[i]);
	}
	gotoxy(2,21);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");
	gotoxy(3,23);
	textcolor(WHITE);
	cprintf("Enter input font number => ");
	char tempf[100],tempt[100];
	strcpy(tempf,from);
	strcpy(tempt,to);
	textcolor(YELLOW);
	int in=getche();
	if(in==27)
		first();
	in-=48;
	if(in>=1&&in<=totalfonts)
		{
		strcpy(from,fontname[in]);
		}
	else
		{
		message(24,8,4," ", " ","     INVALID FONT CODE...     "," "," ","OK",RED,YELLOW,WHITE);
		getch();
		goto ffonts;
		}
	ofonts:
	box();
	gotoxy(14,3);
	textcolor(YELLOW);
	cprintf("Current Convertor : ");
	textcolor(LIGHTRED);
	cprintf(from);
	textcolor(YELLOW);
	cprintf(" => ");
	textcolor(LIGHTRED);
	cprintf(to);

	gotoxy(2,5);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");
	gotoxy(29,7);

	textcolor(WHITE);
	cprintf("AVAILABLE OUTPUT FONTS.");

	for(i=1;fontname[i][0]!=NULL;i++)
	{
		gotoxy(3,10+2*(i-1));
		textcolor(YELLOW);
		cprintf("%d => ",i);
		textcolor(LIGHTGREEN);
		cprintf(fontname[i]);
	}
	gotoxy(2,21);
	textcolor(YELLOW);
	cprintf("-----------------------------------------------------------------------------");
	gotoxy(3,23);
	textcolor(WHITE);
	cprintf("Enter output font number => ");
	textcolor(YELLOW);
	gotoxy(3,33);
	int ins=getche();
	if(ins==27)
	 {	strcpy(from,tempf);
		strcpy(to,tempt);
		first();
	 }
	ins-=48;
	if(in==ins)
		{

		message(24,8,4," ", " ","SAME FONTS CANNOT BE SELECTED"," "," ","OK",RED,YELLOW,WHITE);
		getch();
		goto ofonts;
		}
	else if(ins>=1&&ins<=totalfonts&&in!=ins)
		{
		strcpy(to,fontname[ins]);
		ic=in+48;
		oc=ins+48;
		first();
		}
	else
		{
		gotoxy(3,23);

			message(24,8,4," ", " ","     INVALID FONT CODE...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			goto ofonts;

		}
	  */
}
//^OLDER MODULE ^
//***************************** CHANGE OUTPUT  FONT FUNCTION **************************************************
void convertor::changeinputfont()
{
printfirstscreen();
printfirstscreen(3);
	gotoxy(62,15);
	textcolor(WHITE);
	textbackground(BLUE);
	cprintf("                ");
	gotoxy(7,23);
	textcolor(WHITE);
	textbackground(BLUE);

	cprintf("Select Input Font.");
message(38,16,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);
	int l=ic-49;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)
					{
					gotoxy(40,15);
					textcolor(WHITE);
					textbackground(BLUE);
					cprintf(fontname[i+1]);
					textbackground(RED);
					}
		gotoxy(40,17+2*i);
		cprintf(fontname[i+1]);
		}
	gotoxy(1,1);
	while(!kbhit())
		date();
	b=getch();
	if (b==UP&&l>0)
		l--;
	if (b==DOWN&&l<totalfonts-1)
		l++;


	if(b==27)
		first();
	}
	while(b!=13&&b!=right);
		strcpy(from,fontname[l+1]);
		ic=l+49;
		changeoutputfont();

}
//***************************** CHANGE OUTPUT  FONT FUNCTION **************************************************
void convertor::changeoutputfont()
{
printfirstscreen();
printfirstscreen(3);
message(60,16,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);
	gotoxy(7,23);
	textcolor(WHITE);
	textbackground(BLUE);
	cprintf("Select Output Font.");
	int l=oc-49;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)
					{
					gotoxy(62,15);
					textcolor(WHITE);
					textbackground(BLUE);
					cprintf(fontname[i+1]);
					textbackground(RED);
					}
		gotoxy(62,17+2*i);
		cprintf(fontname[i+1]);
		}

	while(!kbhit())
		date();
	b=getch();
	if (b==UP&&l>0)
		 l--;

	if (b==DOWN&&l<totalfonts-1)
		 l++;

	if(b==left)
		{
		changeinputfont();
		}

	if(b==27)
		first();
	}
	while(b!=13);
		if(strcmp(from,fontname[l+1])==0)
			{
			message(24,8,4," ", " ","SAME FONTS CANNOT BE SELECTED"," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfont();
			}
		strcpy(to,fontname[l+1]);
		oc=l+49;
		first();

}
//*************************************************************************************************************************
//---------------------------------------- GET DATA FUNCTION --------------------------------------------------------------
//************************** GET DATA FROM USER INPUT FILE AND SAVE IT TO I.TMP FILE***************************************

void convertor::getdata()
{
	char indata[4096];
	ifstream getdata;
	getdata.open(infile);
	if(getdata==0)
		{
			getdata.close();
			message(24,8,4," ", " ","    INPUT FILE MISSING...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			first();
		}
	getdata.close();
	int flag=0;
	_splitpath(infile,drive,dir,files,ext);
	for(int z=0;z<=strlen(infile)-1;z++)
	{
	 if(infile[z]=='~')
		flag=1;
	}
	char tmp[100]="tempdoc";
	if(flag==1)
		{
		  char command[100]="copy ";
		  strcat(command,infile);
		  strcat(command," ");
		  strcat(tmp,ext);
		  strcat(command,tmp);
		  int res=system(command);
		  if(res==-1)
			{clrscr();cout<<"ERROR";getch();first();}
		  strcpy(infile,tmp);
		 }
	if(stricmp(ext,".txt")!=0)
		{
			convertifile();
		}
	else
		strcpy(pathi,infile);
	getdata.open(pathi);
	if(getdata==0)
		{       box();
			getdata.close();
			message(24,8,4," ", " ","    ERROR CONVERTING DATA.    "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			first();
		}
	for(int i=0;i<3000&&getdata!=0;i++)
		{
			getdata.get(indata[i]);
			if(i==2999)
			       {
				message(11,11,4," ", "    Input file contain more than 3000 characters    "," "," Convertor will convert only 3000 characters "," ","OK",RED,YELLOW,WHITE);
				getch();
				break;
			       }
		}
	indata[i-1]='\0';
	getdata.close();
	charac=i-1;
	if(charac==0)
	{	message(24,12,3," ", "    Input file is empty    "," "," "," ","OK",RED,YELLOW,WHITE);
		getch();

		cleanup();
		first();
	}


	ofstream outdata;
	outdata.open("i.tmp");
	if(outdata==0)
		{
			message(24,12,3," ", "    Error creating \"I.tmp\"    "," "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			first();
		}
	for(i=0;indata[i]!='\0';i++)
		{
			outdata.put(indata[i]);
		}

	outdata.close();
	if(stricmp(ext,".txt")!=0)
	       {remove(tmp);	remove(pathi);}
}
//*************************************************************************************************************************
//---------------------------------------- PUT DATA FUNCTION --------------------------------------------------------------
//************************** GET DATA FROM O.TMP AND SAVE IT TO USER OUTPUT FILE*******************************************
void convertor::putdata()
{
	char indata[4096];
	ifstream getdata;
	getdata.open("o.tmp");
	if(getdata==0)
		{
			message(27,12,3," ", "    \"O.tmp\" Missing     "," "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			first();
		}
	for(int i=0;getdata!=0;i++)
		{
			getdata.get(indata[i]);
		}

	indata[i-1]='\0';
	getdata.close();

	ofstream outdata;
	_splitpath(outfile,drive,dir,file,ext);
	_makepath(patho,drive,dir,file,".txt");
	outdata.open(patho);
	for(i=0;indata[i]!='\0';i++)
		{
			outdata.put(indata[i]);
		}
	outdata.close();
	if(stricmp(ext,".txt")!=0)
		{

		   convertofile();
		}
	if(stricmp(ext,".txt")!=0)
	{remove(patho);}
}
//*************************************************************************************************************************
//---------------------------------------- CONVERTOR MODULE ---------------------------------------------------------------
//********************************* OPEN RESPECTIVE FONT CONVERTOR FILE ***************************************************
//****** *************************CONTROLLED NOW SHIFTED TO ANTHR PROGRAM *************************************************

void convertor::convert()
{
		if(strcmp(outfile,infile)==0)
		 {
			message(20,8,4," ", " ","Same input and output file..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			first();

		}
	 clock_t start, end;


	file[0]=ic;
	file[1]=oc;
	file[2]=NULL;
	strcat(file,".exe");
	start = clock();
	getdata();
	int result = spawnl(P_WAIT,file,NULL);
	if (result==-1)
		{
		box();
		gotoxy(20,12);
		message(24,8,4," ", " ","    CONVERTOR FILE MISSING...     "," "," ","OK",RED,YELLOW,WHITE);
		cleanup();
		getch();
		exit(1);
		}
	putdata();
	end = clock();
	animate();
	cleanup();
	conversion_time = (end - start) / CLK_TCK;
	stat();
}
//*************************************************************************************************************************
//---------------------------------------- STATISTICS FUNCTION ------------------------------------------------------------
//************************************** SHOW THE PROGRESS REPORT *********************************************************
void convertor::stat()
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

message(18,8,6,"REPORT",
	       "\nTotal Characters       =>       ",
	       "\nErrors                 =>       ",
	       "\nAccuracy               =>       ",
	       "\nTime Taken             =>       ",
	       "OK",RED,WHITE,YELLOW);


gotoxy(47,11);
textcolor(YELLOW);
textbackground(RED);
cprintf("%d", charac);
gotoxy(47,12);
cprintf("%d", s.wrong);
if(charac==0)
charac++;
float p=(float)(s.wrong * 100) /charac;
gotoxy(47,13);
cout<<setprecision(2)<<float(100-p)<<" %";
gotoxy(47,14);
textcolor(YELLOW);
cout<<setprecision(2)<<conversion_time<<" sec";
gotoxy(37,16);
while(!kbhit())
	date();
getch();
char open[100];
strcpy(open,"startcd ");
strcat(open,outfile);
system(open);

first();
}
//*************************************************************************************************************************
//---------------------------------------- ANIMATION FUNCTION -------------------------------------------------------------
//************************** ANIMATE USER SCREEN WHILE CONVERSION IS IN PROGRESS*******************************************
void convertor:: animate()
{
	message(16,6,12,"                                      ",
	       "                                   ",
	       "                             ",
	       "                               ",
	       "                           ","  ",RED,WHITE,WHITE);
	textbackground(RED);
	gotoxy(28,20);
	cprintf("                           ");
	textcolor(YELLOW);
	boxs(21,8,52,17);
	gotoxy(25,10);
	cprintf("{                      }");

	for(int i=1;i<=20;i++)
		{
		gotoxy(i+26,10);
		textcolor(LIGHTGREEN);
		cprintf("-");
		gotoxy(1,1);
		delay(50);
		}
	char a[]={"STATUS"};
	char b[]={"Converting data."};
	char c[]={"DATA CONVERTED."};
	char d[]={"                        "};
	gotoxy(34,10);
	textcolor(YELLOW);

	for(i=0;a[i]!=NULL;i++)
		{
		gotoxy(34+i,10);
		cprintf("%c",a[i]);
		gotoxy(1,1);
		delay(60);
		}

	gotoxy(25,15);
	textcolor(YELLOW);
	cprintf("{                      }");

	for( i=1;i<=20;i++)
		{
		textcolor(LIGHTRED);
		gotoxy(i+26,15);
		cprintf("-");
		gotoxy(1,1);
		delay(80);
		}

	gotoxy(29,12);
	textcolor(LIGHTGREEN);
	for(i=0;b[i]!=NULL;i++)
		{
		gotoxy(29+i,12);
		cprintf("%c",b[i]);
		gotoxy(1,1);
		delay(60);
		}

	for(i=1;i<=100;i++)
	{
		gotoxy(30,15);
		textcolor(YELLOW);
		cprintf("%d %c complete",i,'%');
		gotoxy(1,1);
		delay(10);
	}


	gotoxy(29,12);
	cprintf("                ");
	gotoxy(30,12);
	for(i=0;c[i]!=NULL;i++)
	{
		delay(80);
		gotoxy(30+i,12);
		textcolor(LIGHTRED);
		cprintf("%c",c[i]);
		gotoxy(1,1);
	}
	gotoxy(25,19);
		textcolor(WHITE);
	for(i=0;d[i]!=NULL;i++)
	{
		delay(20);
		gotoxy(25,19);
		cprintf("%c",d[i]);
		gotoxy(1,1);

	}

}

//*************************************************************************************************************************
//---------------------------------------- EXIT  FUNCTION -----------------------------------------------------------------
//************************************** CONFIRMS USER EXIT ***************************************************************

void convertor::EXIT()

{
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(7,23);
	cprintf("Quit.               ");

	char a;
	message(20,8,5," ", " ","ARE YOU SURE YOU WANT TO EXIT?"," "," ","OK",RED,WHITE,YELLOW);
	gotoxy(30,15);
	textbackground(RED);
	cprintf("              ");
	gotoxy(28,14);
	textcolor(YELLOW);
	cprintf(" YES ");
	gotoxy(1,1);
	gotoxy(42,14);
	textcolor(WHITE);
	textbackground(BLACK);
	cprintf(" NO ");
	gotoxy(1,1);
	int x;
	do
	{
	x=getch();
	if (x==27)
		first();
	if(x==left||x=='y')
		{
		gotoxy(42,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" NO ");
		gotoxy(1,1);
		gotoxy(28,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" YES ");
		gotoxy(1,1);
		a='y';
		}

	if(x==right||x=='n')
		{
		a='n';
		gotoxy(28,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" YES ");
		gotoxy(1,1);
		gotoxy(42,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" NO ");
		gotoxy(1,1);
		}
	} while(x!=13);

	if (a=='y'||a=='Y')
		{
		cleanup();
		exit(0);
		}
	else
		first();
}

//*************************************************************************************************************************
//---------------------------------------- CLEANUP  FUNCTION --------------------------------------------------------------
//**************************************** DESTROY TEMP FILES *************************************************************
void convertor::cleanup()
{

	remove("i.tmp");
	remove("o.tmp");
	fcloseall();
}
//*************************************************************************************************************************
//---------------------------------------- DESTROY  FUNCTION --------------------------------------------------------------
//**************************************** DESTROY ALL FILES **************************************************************


void convertor::destroy()
{       char del[10];
	for(int i=1;i<=totalfonts;i++)
		{
		for(int j=1;j<=totalfonts;j++)
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

	remove("startcd.exe");
	remove("Agragami.pif");
	remove("setup.exe");
	remove("Repair.exe");
	remove("Send.dat");
	remove("temp.dat");
	remove("wizard.exe");
	remove("dirb.exe");
	remove("icon.ico");
	remove("MAIN.exe");
	remove("avlfonts.dat");
	remove("Conver~1.exe");
	remove("GETWOR~1.EXE");

}
//*************************************************************************************************************************
//---------------------------------------- HELP CONSOLE -------------------------------------------------------------------
//************************************* PRINTING FUNCTION *****************************************************************

void convertor::message(int x,int y,int lines,char a[50],char b[50],char c[50],
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
//*************************************************************************************************************************
//------------------------------------FIRST HELP FUNCTION------------------------------------------------------------------
//*******************************PROVIDES HELP IN FIRST SCREEN*************************************************************

/*void convertor::fhelp()
{
	message(18,8,7,"Press 1 or I to Change Input File.",
	       "Press 2 or O to Change Output File.",
	       "Press 3 or F to Change Fonts.",
	       "\nPress 4 or C to Convert Data.",
	       "\n\nPress 5 or ESC to exit.","OK",RED,WHITE,YELLOW);

	getch();
	first();
} */

//*************************************************************************************************************************
//--------------------------------------- CREDITS --------------------------------------------------------------------------
//***********************************PRINTING MODULE***********************************************************************
void convertor::printer(char a[],char b[],int x1,int y1,int x2,int y2,int background,int time)
{       gotoxy(x2,y2+1);
	textbackground(background);

	cprintf("                ");
	gotoxy(x1,y1);

	textcolor(YELLOW);
	cprintf(a);
	for(int k=0;k<2;k++)
	{
	for(int i=0;b[i]!=NULL;i++)
		{
		gotoxy(x2,y2);
		for(int j=0;b[j]!=NULL;j++)
			{

			if(i==j)
			{textcolor(YELLOW);
			gotoxy(x2+j,y2);
			cprintf("%c",b[j]);
			gotoxy(1,1);
			delay(time);}
			else
			{
			gotoxy(x2+j,y2);
			textcolor(LIGHTGREEN);
			cprintf("%c",b[j]);
			gotoxy(1,1);
			delay(time);
			}
			}
		}
	}
}
//*************************************************************************************************************************
//--------------------------------------- Convert input file to txt----------------------------------------------------------------------------------------------
//*************************************************************************************************************************

void convertor::convertifile()
{
char x[10];
if(stricmp(ext,".txt")==0)
strcpy(x,TXT);
else if(stricmp(ext,".htm")==0)
strcpy(x,HTML);
else if(stricmp(ext,".rtf")==0)
strcpy(x,RTF);
else if(stricmp(ext,".doc")==0)
strcpy(x,DOC);
else if(stricmp(ext,".pdf")==0)
strcpy(x,PDF);
else
{
box();
message(24,8,4," ", " "," UNRECOGNISED INPUT FILE FORMAT.  "," "," ","OK",RED,YELLOW,WHITE);
getch();
first();
}
ifstream conv("Conver~1.exe");
if(conv==0)
{box();message(24,8,4," ", " ","    CONVERTDOC.EXE  MISSING...     "," "," ","OK",RED,YELLOW,WHITE);getch();first();}
message(24,11,3," ","   PROCESSING FILE    "," "," "," ","WAIT",GREEN,YELLOW,WHITE);

_makepath(pathi,drive,dir,files,".txt");
strcpy(extcommand,"Conver~1 /S");
strcat(extcommand,infile);
strcat(extcommand," /F");
strcat(extcommand,x);
strcat(extcommand," /T");
strcat(extcommand,pathi);
strcat(extcommand," /C");
strcat(extcommand,"1");
int res=system(extcommand);
if(res==-1)
{
box();message(24,8,4," ", " ","    ERROR CONVERTING DATA...     "," "," ","OK",RED,YELLOW,WHITE);getch();first();
}
}
//*************************************************************************************************************************
//--------------------------------------- Convert txt file to output----------------------------------------------------------------------------------------------
//*************************************************************************************************************************

void convertor::convertofile()
{
char x[10];
if(stricmp(ext,".txt")==0)
strcpy(x,TXT);
else if(stricmp(ext,".htm")==0)
strcpy(x,HTML);
else if(stricmp(ext,".rtf")==0)
strcpy(x,RTF);
else if(stricmp(ext,".doc")==0)
strcpy(x,DOC);
else if(stricmp(ext,".pdf")==0)
strcpy(x,PDF);
else
{
box();
message(24,8,4," ", " "," UNRECOGNISED OUTPUT FILE FORMAT. "," "," ","OK",RED,YELLOW,WHITE);
getch();
first();
}
ifstream conv("Conver~1.exe");
if(conv==0)
{box();message(24,8,4," ", " ","    CONVERTDOC.EXE  MISSING...     "," "," ","OK",RED,YELLOW,WHITE);getch();first();}
message(24,11,3," ","   PROCESSING FILE    "," "," "," ","WAIT",GREEN,YELLOW,WHITE);
strcpy(extcommand,"Conver~1 /S");
strcat(extcommand,patho);
strcat(extcommand," /F");
strcat(extcommand,"1");
strcat(extcommand," /T");
strcat(extcommand,outfile);
strcat(extcommand," /C");
strcat(extcommand,x);
int res=system(extcommand);
if(res==-1)
{
box();message(24,8,4," ", " ","    ERROR CONVERTING DATA...     "," "," ","OK",RED,YELLOW,WHITE);getch();first();
}
}
//*************************************************************************************************************************
//--------------------------------------- CREDITS --------------------------------------------------------------------------
//*************************************************************************************************************************
void convertor::credits()
{
message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,YELLOW);
printer("Created By","SHOBHIT SAXENA",35,12,33,14,RED,12);

message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,YELLOW);
printer("Special Thanks To","SWAPNIL SAXENA",32,12,33,14,RED,12);
message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,YELLOW);
printer("Dedicated To","SUSHMA SAXENA",33,12,33,14,RED,12);

message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,YELLOW);
printer("Dedicated To","KAUSHAL SAXENA",34,12,33,14,RED,12);


printer("Contact Us At","shobhitsaxena@live.com",34,12,29,14,RED,7);

delay(500);
first();
}
//*************************************************************************************************************************
//---------------------------------------- MAIN  FUNCTION -----------------------------------------------------------------
//************************************** CREATES AN OBJECT ****************************************************************
//**********************************CONTROLL PASSED TO CONSTRUCTOR ********************************************************
void main()
	{
		convertor ob;
	}
//*************************************************************************************************************************
//-------------------------------------------- THE END --------------------------------------------------------------------
//*************************************** BY SHOBHIT SAXENA****************************************************************