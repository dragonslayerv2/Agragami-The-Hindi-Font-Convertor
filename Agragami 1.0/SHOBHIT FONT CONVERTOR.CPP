//*****************  HEADER FILES DECLARATION ***********************

#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>

//*******************************************************************

//********************** CREATE BOX GLOBAL FUNCTION******************
void createbox()
{       textcolor(LIGHTRED);
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
	for(i=0;i<=10;i++)
	{       textcolor(YELLOW);
		cout<<endl;
		cprintf("|");
		for(int j=0;j<=76;j++)
		cout<<" ";
		cprintf("|");
		textcolor(LIGHTRED);
		cout<<endl;
		cprintf("*");
		for( j=0;j<=76;j++)
		cout<<" ";
		cprintf("*");
	}
	textcolor(YELLOW);
		cout<<endl;
		cprintf("|");
		for(int j=0;j<=76;j++)
		cout<<" ";
		cprintf("|");
		cout<<endl;

	for( i=0;i<=25;i++)
	{
		textcolor(LIGHTRED);
		cprintf("*");
		textcolor(YELLOW);
		cprintf("--");
	}
	textcolor(LIGHTRED);
	cprintf("*");
	gotoxy(30,10);
}
//********************CLASS DECLARATION********************************
class naidunia
{       int fntno;
	char in[100][5],out[100][5],infont[100],outfont[100];
	char input[100],output[100], ih[4096],fh[4096];
	ifstream inputfile;
	ofstream outputfile;
	ifstream fontfile;
	char fntfile[100];
	char inputfont[100];
	char outputfont[100];
	char avlfonts[50][50];
	int infontcode, outfontcode;
	int total;
public:

	//****  CONSTRUCTOR ***

	naidunia()
		{
			strcpy(input,"INPUT.DAT");
			strcpy(output,"OUTPUT.DAT");
			strcpy(fntfile,"10");
			strcpy(inputfont,"True-Type Fonts");
			strcpy(outputfont, "Webdunia Fonts");
			infontcode=1;
			outfontcode=2;
			inputfile.open(input);
			outputfile.close();
			getfonts();
			infontcode=1;outfontcode=0;
		}

	//**********************
	void serial();          //*****************CHECK SERIAL KEY ******************
	void first(); 		//******** FIRST SCREEN ******************************
	void convertor();	//**** CONVERTS FONT AND GIVES OUTPUT TO AN ARRAY ****
	void inputs(); 		//**** MANIPULATE USER INPUT IN FIRST SCREEN *********
	void changeinput();	//************ CHANGE INPUT FILE  ********************
	void changeoutput();	//************ CHANGE OUTUT FILE  ********************
	void convert();         //******* GET CONVERTED DATA FROM CONVERTOR FUNCTION AND SAVE IT TO OUTPUT FILE ***
	void confirmexit();     //****** CONFIRMS WHETER USER WANTS TO EXIT OR NOT ***
	void copycodes();	//***** COPY FONT CONVERSION VALUES FROM FILE ********
	void changefontfile();  //***** CHANGE FONT CONVERSION FILE ******************
	void getfonts();	//***  GET THE LIST OF AVAILABLE FONTS  FROM FILE  ***
	void printfonts();	//*******PRINT THE LIST OF AVAILABLE FONTS ***********
	void ttow();            //****************CONVERTS TRUE TYPE TO NAIDUNIA *****
	void wtot();            //****************CONVERTS NAIDUNIA TO TRUE TYPE *****
	/*void ttou();            //****************CONVERTS TRUE TYPE TO NAIDUNIA *****
	void wtou();            //****************CONVERTS NAIDUNIA TO UNICODE *****
	void utow();            //****************CONVERTS UNICODE TO NAIDUNIA *****
	void utot();            //****************CONVERTS UNICODE TO TRUE TYPE ******/
};

//*******************************************************************

//**************************** SERIAL CHECKER *************************
void naidunia::serial()
{
textbackground(BLUE);
clrscr();
createbox();
char b[]={"DONOT DELETE THIS FILE"};
ifstream serial;
ofstream serials;
serial.open("S734H92S.INF");
if(serial==0)
{
serial.close();
char a[100];

textcolor(LIGHTRED);

textcolor(YELLOW);
cprintf("ENTER SERIAL KEY");
cout<<"\n\n";
gotoxy(24,14);
textcolor(YELLOW);
cprintf("_____________________________");
gotoxy(24,14);
textcolor(YELLOW);
cin.getline(a,100);
if(strcmp(a,"VDDF2-JJWM3-X7P27-FRHRT-8BVHT")==0)
{
clrscr();
serials.open("S734H92S.INF");
for(int i=0;b[i]!=NULL;i++)
serials.put(b[i]);
textcolor(YELLOW);
createbox();
textcolor(YELLOW);
cprintf("Serial Key Installed...");
gotoxy(27,14);
textcolor(LIGHTRED);
cprintf("Please restart the software...");
getch();
}
else
{
clrscr();
createbox();
textcolor(LIGHTRED);
cprintf("\n\nINVALID SERIAL CODE");
getch();
exit(0);
}
}
else
first();
}
//**************************FIRST SCREEN*********************************
void naidunia:: first()
{
	inputfile.close();
	outputfile.close();
	fontfile.close();
		textcolor(WHITE);
		textbackground(BLUE);
	clrscr();
	window(1,1,80,25);
	createbox();
		textcolor(YELLOW);
	gotoxy(2,3);
	cprintf("                            FONT CONVERTOR                                " );
	textcolor(WHITE);
	gotoxy(28,5);
	cprintf("-By Shobhit Saxena");
	textcolor(WHITE);
	gotoxy(2,8);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	char a[100];

	textcolor(WHITE);

		strupr(input);
		strupr(output);
	gotoxy(4,11);

	cprintf("1. (I)nput File      ==>  ");
		textcolor(YELLOW);
	cprintf(input);
		textcolor(WHITE);
	gotoxy(4,13);
	cprintf("2. (O)utput File     ==>  ");
		textcolor(YELLOW);
	cprintf(output);
		textcolor(WHITE);
	gotoxy(4,15);
	cprintf("3. (F)ont Convertor  ==>  ");
		textcolor(YELLOW);
	cprintf(inputfont);
		textcolor(LIGHTRED);
	cprintf(" => ");
		textcolor(YELLOW);
	cprintf(outputfont);
		textcolor(WHITE);
	gotoxy(4,17);
	textcolor(WHITE);
	cprintf("4. (C)onvert ");
	gotoxy(4,19);
	textcolor(WHITE);
	cprintf("5. (E)xit ");
	gotoxy(4,22);
	textcolor(YELLOW);
	cprintf("==> ");
	inputs();
}

//************************************************************************************

//********************** MANIPULATE USER INPUT IN FIRST SCREEN ***********************
void naidunia:: inputs()
{       gotoxy(8,22);
	char in;
		textcolor(YELLOW);
	in=getche();
	switch(in)
		{
		case 13:inputs();break;
		case '1':
		case 'i':
		case 'I': changeinput();break;
		case '2':
		case 'o':
		case 'O': changeoutput();break;
		case '3':
		case 'F':
		case 'f': changefontfile();break;
		case '4':
		case 'c':
		case 'C': convert();break;
		case '5':
		case 'e':
		case 'E': confirmexit();break;
		default: textcolor(LIGHTRED);gotoxy(10,22);cprintf("INVALID COMMAND");cout<<endl;inputs();break;
		}
}
//********************************************************************************************

//*************************CHANGE INPUT FUNCTION***************************
void naidunia::changeinput()
{
	char i[100];
		inputfile.close();
			textbackground(BLUE);
			textcolor(WHITE);
	clrscr();
	createbox();
	gotoxy(25,10);
	cout<<"Current File  =  ";
			textcolor(YELLOW);
	cprintf(input);
			textcolor(WHITE);
	gotoxy(22,15);
	cprintf("Enter the new input file location ");

	gotoxy(22,18);
	textcolor(YELLOW);
	cprintf("=> ");
	cin.getline(i,100);
	if(strlen(i)==0)
		{
			clrscr();
			createbox();
			textcolor(LIGHTRED);
			gotoxy(23,10);
			cprintf("FILE FIELD CAN'T BE LEFT BLANK...");
			gotoxy(24,14);
			textcolor(YELLOW);
			cprintf("PRESS ANY KEY TO CONTINUE...");
			getch();
			first();
		}

	inputfile.open(i);

	if(inputfile==0)
		{
			clrscr();
			createbox();
				textcolor(LIGHTRED);
				gotoxy(30,10);
			cprintf("FILE NOT FOUND.");
			gotoxy(24,14);
			textcolor(YELLOW);
			cprintf("PRESS ANY KEY TO CONTINUE...");
			inputfile.close();
			getch();
			inputfile.open(input);
			first();
		}
	else
		{
			strcpy(input,i);
			first();
	}
}
//*************************************************************************

//*********************CHANGE OUTPUT FUNCTION **************************************
void naidunia::changeoutput()
	{
	char o[100];
			textbackground(BLUE);
			textcolor(WHITE);
	clrscr();
	createbox();
	gotoxy(25,10);
	cout<<"Current File  =  ";
			textcolor(YELLOW);
	cprintf(output);
			textcolor(WHITE);
	gotoxy(22,15);
	cprintf("Enter the new output file location ");

	gotoxy(22,18);
	textcolor(YELLOW);
	cprintf("=> ");
	cin.getline(o,100);
	if(strlen(o)==0)
	{
			clrscr();
			createbox();
			textcolor(LIGHTRED);
			gotoxy(23,10);
			cprintf("FILE FIELD CAN'T BE LEFT BLANK...");
			gotoxy(24,14);
			textcolor(YELLOW);
			cprintf("PRESS ANY KEY TO CONTINUE...");
			getch();
			first();
	}
	else  if (isalpha(o[0])!=0)
	{
		strcpy(output,o);
		first();
	}
	else
	{
		clrscr();
		createbox();
			textcolor(LIGHTRED);
			gotoxy(27,10);
			cprintf("UNABLE TO CREATE FILE.");
			gotoxy(24,14);
			textcolor(YELLOW);
			cprintf("PRESS ANY KEY TO CONTINUE...");
			getch();
			first();
	}
}
//****************************************************************************

//************************ CONFIRMS EXIT *************************************
void naidunia::confirmexit()
{
	char e;
	clrscr();
	createbox();
	gotoxy(22,13);
		textcolor(WHITE);
	cprintf(" Would you really like to Quit");
		textcolor(YELLOW);
	cprintf(" (Y/N). ");
	e=getche();
	if(e=='y'||e=='Y')
		{
			exit(0);
		}
	  else
		{
			first();
		}
}
//*********************************************************************


//************************   FONT CONSOLE ******************************
//*********************    CHANGE FONT FILE *******************************

void naidunia::changefontfile()
	{       char temp[100];
		strcpy(temp,inputfont);
		int i;
		fontfile.close();
			textbackground(BLUE);
			textcolor(WHITE);
		clrscr();
		createbox();
		gotoxy(9,4);

		cout<<"Current Font Convertor  =  ";
			textcolor(YELLOW);
		cprintf(inputfont);
			textcolor(LIGHTRED);
		cprintf(" => ");
			textcolor(YELLOW);
		cprintf(outputfont);
		textcolor(WHITE);
		gotoxy(2,7);
		textcolor(YELLOW);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

		textcolor(WHITE);
		gotoxy(28,9);
		cout<<" Available Input fonts: ";

		printfonts();

		textcolor(YELLOW);
		gotoxy(2,19);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

		textcolor(WHITE);
		gotoxy(3,22);
		textcolor(WHITE);
		cprintf("Enter font number => ");

		i=getche();
		if(i==13)
		{
		textcolor(LIGHTRED);
		gotoxy(3,22);
		cprintf("FONT FIELD CAN'T BE LEFT BLANK");
		getch();
		first();
		}
		i=i-48;
		if(i>=1&&i<=fntno
		)
			{ strcpy(inputfont,avlfonts[i-1]);infontcode=i-1;}
		else
		{
				textcolor(LIGHTRED);
				gotoxy(3,22);
			cprintf("INVALID FONT CODE                 ");
			getch();
			first();
		}

			textbackground(BLUE);
			textcolor(WHITE);
		clrscr();
		createbox();
		gotoxy(9,4);
		cout<<"Current Font Convertor  =  ";
			textcolor(YELLOW);
		cprintf(inputfont);
			textcolor(LIGHTRED);
		cprintf(" => ");
			textcolor(YELLOW);
		cprintf(outputfont);
			textcolor(WHITE);
			textcolor(YELLOW);
		gotoxy(2,7);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		textcolor(WHITE);
		gotoxy(28,9);
		cout<<"Available Ouput fonts:";
		printfonts();
		textcolor(YELLOW);
		gotoxy(2,19);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(3,22);
		textcolor(WHITE);
		cprintf("Enter font number =>");
		i=getche();
		if(i==13)
		{
		textcolor(LIGHTRED);
		gotoxy(3,22);
		cprintf("FONT FIELD CAN'T BE LEFT BLANK");
		getch();
		strcpy(inputfont,temp);
		first();
		}
		i=i-48;
		if((i-1)==infontcode)
		{
		textcolor(LIGHTRED);
		gotoxy(3,22);
		cprintf("Same font files can't be selected");
		getch();
		strcpy(inputfont,temp);
		first();
		}
		if(i>=1&&i<=fntno)
		{	strcpy(outputfont,avlfonts[i-1]);outfontcode=i-1;}
		else
		{
				textcolor(LIGHTRED);
				gotoxy(3,22);
			cprintf("INVALID FONT CODE.                ");
			strcpy(inputfont,temp);
			getch();
			first();
		}

		first();
}
//*****************************************************************************************

//************************PRINT LIST OF AVAILABLE FONTS***********************************
void naidunia::printfonts()
{
		for(int i=0;i<fntno;i++)
	{
		gotoxy(4,12+2*i);
			textcolor(YELLOW);
		cprintf("%d",i+1);
			textcolor(WHITE);
		cprintf("=>        ");
		cprintf(avlfonts[i]);
		cout<<endl<<endl;
	  }
}

//******************************************************************************************
//*****************************GET FONTS LIST *****************************
void naidunia::getfonts()
	{       clrscr();
		textbackground(BLUE);
		char a;
		ifstream availfonts;
		availfonts.open("avlfonts.dat");
		if(availfonts==0)
		{
		clrscr();

		createbox();
		textcolor(LIGHTRED);
		gotoxy(22,10);
		cprintf("Unable to open source code file...");
		cout<<endl<<endl;
		gotoxy(24,14);
			textcolor(YELLOW);
		cprintf("PROGRAM WILL NOW TERMINATE...");

		getch();
		exit(0);
		}

		for(int i=0;availfonts!=0;i++)
		{
			for(int j=0;j<=50;j++)
			{
			availfonts.get(a);
				if(a=='\n')
					{avlfonts[i][j]='\0';break;}
				else
					avlfonts[i][j]=a;
			}
		}
		fntno=i-1;
		availfonts.close();
}
//*********************************************************************

//***************************CONVERTOR MODULES ****************************
//************************** MAIN CONVERTOR MODULE **********************
void naidunia::convert()
{       fh[0]='\0';
	inputfile.open(input);
	outputfile.close();
	clrscr();
		for(int i=0;inputfile;i++)
		{
			inputfile.get(ih[i]);
		}
	ih[i]='\0';
	convertor();
	outputfile.open(output);
		for(i=0;ih[i]!='\0';i++)
		{
			outputfile.put(fh[i]);
		}
	outputfile.close();
		textbackground(BLUE);
		textcolor(WHITE);
	clrscr();
	createbox();
	cprintf("\nFile converted....\n\n");
	       textcolor(YELLOW);
	       gotoxy(24,14);
	cprintf(" PRESS ANY KEY TO CONTINUE...\n\n\n");
	getch();
	first();
}
//*****************************************************************************
//*********************************CONVERTOR ROUTER****************************
void naidunia::convertor()
{
if(infontcode==0&&outfontcode==1)
wtot();
if(infontcode==1&&outfontcode==0)
ttow();
/*else if(infontcode==1&&outfontcode==2)
ttou();
else if(infontcode==0&&outfontcode==2)
wtou();
else if(infontcode==2&&outfontcode==0)
utow();
else if(infontcode==2&&outfontcode==1)
utot();*/
}
//***********************************************************************************

//**************************TRUE TO NAI CONVERSION MODULE *********************
void naidunia::ttow()
{      	int i=0;
		for(int j=0;ih[j]!='\0';j++,i++)
		{
			switch(ih[j])
			{
			case 'q':fh[i]='w';break;
			case 'w':fh[i]='q';break;
			case 'e':fh[i]='b';break;
			case 'r':fh[i]=';';break;
			case 't':fh[i]='s';break;
			case 'y':fh[i]='˜';break;
			case 'u':fh[i]='l';break;
			case 'i':fh[i]='v';break;
			case 'o':fh[i]='J';break;
			case 'p':fh[i]='a';break;
			case '[':fh[i]='Ï';break;
			case ']':fh[i]=',';break;
			case 'a':fh[i]='k';break;
			case 's':fh[i]='u';break;
			case 'd':fh[i]='f';fh[i+1]='U';i++;break;
			case 'f':fh[i]='r';break;
			case 'g':fh[i]='n';break;
			case 'h':fh[i]='e';break;
			case 'j':fh[i]='h';break;
			case 'k':fh[i]='t';break;
			case 'l':fh[i]='m';break;
			case ';':fh[i]='g';break;
			case '\'':fh[i]='ë';break;
			case 'z':fh[i]='{';break;
			case 'x':fh[i]='d';break;
			case 'c':fh[i]='c';break;
			case 'v':fh[i]='y';break;
			case 'b':fh[i]='R';break;
			case 'n':fh[i]='=';break;
			case 'm':fh[i]='W';break;
			case ',':fh[i]='Y';break;
			case '.':fh[i]='ã';break;
			case '/':fh[i]='Æ';break;
			case '`':fh[i]=']';break;
			case '1':fh[i]='1';break;
			case '2':fh[i]='2';break;
			case '3':fh[i]='3';break;
			case '4':fh[i]='4';break;
			case '5':fh[i]='5';break;
			case '6':fh[i]='6';break;
			case '7':fh[i]='7';break;
			case '8':fh[i]='8';break;
			case '9':fh[i]='9';break;
			case '0':fh[i]='0';break;
			case '-':fh[i]='.';break;
			case '?':fh[i]='Î';break;
			case '=':fh[i]='º';fh[i+1]='t';i++;break;
			case '\\':fh[i]='?';break;
			case 'Q':fh[i]='V';break;
			case 'W':fh[i]='p';break;
			case 'E':fh[i]='ö';break;
			case 'R':fh[i]='À';break;
			case 'T':fh[i]='ß';break;
			case 'Y':fh[i]='Ö';break;
			case 'U':fh[i]='à';break;
			case 'I':fh[i]='Ë';break;
			case 'O':fh[i]='Ô';break;
			case 'P':fh[i]='å';break;
			case '{':fh[i]='Ì';break;
			case '}':fh[i]='Å';break;
			case 'A':fh[i]='>';break;
			case 'S':fh[i]='i';break;
			case 'D':fh[i]='¢';break;
			case 'F':fh[i]='Ú';break;
			case 'G':fh[i]='B';break;
			case 'H':fh[i]='Ç';break;
			case 'J':fh[i]='¶';break;
			case 'K':fh[i]='Ò';fh[i+1]='t';i++;break;
			case 'L':fh[i]='ô';break;
			case ':':fh[i]='Á';break;
			case '\"':fh[i]='í';break;
			case 'Z':fh[i]='o';break;
			case 'X':fh[i]='É';break;
			case 'C':fh[i]='ç';break;
			case 'V':fh[i]='x';break;
			case 'B':fh[i]='X';break;
			case 'N':fh[i]='A';break;
			case 'M':fh[i]='z';break;
			case '<':fh[i]='Z';break;
			case '>':fh[i]='S';break;
			case '~':fh[i]='T';break;
			case '!':fh[i]='!';break;
			case '@':fh[i]='\\';break;
			case '#':fh[i]='h';fh[i+1]='¥';i++;break;
			case '$':fh[i]='+';break;
			case '%':fh[i]='&';break;
			case '^':fh[i]='I';break;
			case '&':fh[i]='-';break;
			case '*':fh[i]='I';break;
			case '(':fh[i]='<';break;
			case ')':fh[i]='°';break;
			case '_':fh[i]='}';break;
			case '+':fh[i]='\\';break;
			case '|':fh[i]='‘';break;
			case ' ':fh[i]=' ';break;
			case 'Å':fh[i]='Q';break;
			case 10:fh[i]='\n';break;
			case '\t':fh[i]='\t';break;
			default: fh[i]='\t';break;

}
}
}
//*******************************************************************
void naidunia::wtot()
{      	int i=0;

		for(int j=0;ih[j]!='\0';j++,i++)
		{
			if(ih[j]=='f'&&ih[j+1]=='U')
				{fh[i]='d';j++;}
			else if(ih[j]=='Ò'&&ih[j+1]=='t')
				{fh[i]='K';j++;}
			else if(ih[j]=='º'&&ih[j+1]=='t')
				{fh[i]='=';j++;}
			else if(ih[j]=='h'&&ih[j+1]=='¥')
				{fh[i]='#';j++;}


			else
			{
			switch(ih[j])
			{
			case 'M':fh[i]='\"';fh[i+1]='k';i++;break;
			case 'V':fh[i]='V';break;
			case '\"':fh[i]='/';fh[i+1]='k';i++;break;
			case 'G':fh[i]='{';fh[i+1]='k';i++;break;
			case 'D':fh[i]='?';fh[i+1]='k';i++;break;
			case 'O':fh[i]='*';break;
			case 'E':fh[i]='M';fh[i+1]='+';i++;break;
			case 'Q':fh[i]='Å';break;
			case '/':fh[i]='@';break;
			case 'j':fh[i]='y';break;
			case 's':fh[i]='t';break;
			case '[':i--;break;
			case 'f':fh[i]='d';break;
			case 'U':i--;break;
			case 'K':fh[i]='.';fh[i+1]='k';i++;break;
			case 'F':fh[i]='[';fh[i+1]='k';i++;break;
			case 'C':fh[i]='H';fh[i+1]='k';i++;break;
			case ':':fh[i]='F';fh[i+1]='k';i++;break;
			case 'ü':fh[i]='s';fh[i+1]='a';i++;break;
			case 'N':fh[i]='\'';fh[i+1]='k';i++;break;
			case 'w':fh[i]='q';break;
			case 'q':fh[i]='w';break;
			case 'b':fh[i]='e';break;
			case ';':fh[i]='r';break;
			case '˜':fh[i]='y';break;
			case 'l':fh[i]='u';break;
			case 'v':fh[i]='i';break;
			case 'J':fh[i]='o';break;
			case 'a':fh[i]='p';break;
			case 'Ï':fh[i]='[';break;
			case ',':fh[i]=']';break;
			case 'k':fh[i]='a';break;
			case 'u':fh[i]='s';break;
			case 'r':fh[i]='f';break;
			case 'n':fh[i]='g';break;
			case 'e':fh[i]='h';break;
			case 'h':fh[i]='j';break;
			case 't':fh[i]='k';break;
			case 'm':fh[i]='l';break;
			case 'g':fh[i]=';';break;
			case 'ë':fh[i]='\'';break;
			case '{':fh[i]='z';break;
			case 'd':fh[i]='x';break;
			case 'c':fh[i]='c';break;
			case 'y':fh[i]='v';break;
			case 'R':fh[i]='b';break;
			case '=':fh[i]='n';break;
			case 'W':fh[i]='m';break;
			case 'Y':fh[i]=',';break;
			case 'ã':fh[i]='.';break;
			case 'Æ':fh[i]='/';break;
			case '¥':fh[i]='Q';break;
			case 'p':fh[i]='W';break;
			case 'ö':fh[i]='E';break;
			case 'À':fh[i]='R';break;
			case 'ß':fh[i]='T';break;
			case 'Ö':fh[i]='Y';break;
			case 'à':fh[i]='U';break;
			case 'Ë':fh[i]='I';break;
			case 'Ô':fh[i]='O';break;
			case 'å':fh[i]='P';break;
			case 'Ì':fh[i]='{';break;
			case 'Å':fh[i]='}';break;
			case '>':fh[i]='A';break;
			case 'i':fh[i]='S';break;
			case '¢':fh[i]='D';break;
			case 'Ú':fh[i]='F';break;
			case 'B':fh[i]='G';break;
			case 'Ç':fh[i]='H';break;
			case '¶':fh[i]='J';break;
			case 'ô':fh[i]='L';break;
			case 'Á':fh[i]=':';break;
			case 'í':fh[i]='\"';break;
			case 'o':fh[i]='Z';break;
			case 'É':fh[i]='X';break;
			case 'ç':fh[i]='C';break;
			case 'x':fh[i]='V';break;
			case 'X':fh[i]='B';break;
			case 'A':fh[i]='N';break;
			case 'z':fh[i]='M';break;
			case 'Z':fh[i]='<';break;
			case 'S':fh[i]='>';break;
			case 'Î':fh[i]='?';break;
			case ']':fh[i]='`';break;
			case '1':fh[i]='1';break;
			case '2':fh[i]='2';break;
			case '3':fh[i]='3';break;
			case '4':fh[i]='4';break;
			case '5':fh[i]='5';break;
			case '6':fh[i]='6';break;
			case '7':fh[i]='7';break;
			case '8':fh[i]='8';break;
			case '9':fh[i]='9';break;
			case '0':fh[i]='0';break;
			case '.':fh[i]='-';break;
			case '?':fh[i]='\\';break;
			case 'T':fh[i]='~';break;
			case '!':fh[i]='!';break;
			case '\\':fh[i]='+';break;
			case '+':fh[i]='$';break;
			case '&':fh[i]='%';break;
			case 'I':fh[i]='^';break;
			case '-':fh[i]='&';break;
			case '<':fh[i]='(';break;
			case '°':fh[i]=')';break;
			case '}':fh[i]='_';break;
			case '‘':fh[i]='|';break;
			case '\t':fh[i]='\t';break;
			case '\n':fh[i]='\n';break;
			case ' ':fh[i]=' ';break;

			default: fh[i]='\t';break;
			}
			}
		}
}

//*******************************************************************
//********************** CONVERTOR MODULE ***************************
/*void naidunia:: convertor()
{ outputfile.close();
	int i=0;
	for(int j=0;ih[j]!='\0';j++,i++)
		{

		    for(int k=0;k<total;k++)
		   {
			if(infontcode==0&&ih[j]=='f'&&ih[j+1]=='U')
			{strcat(fh,"d");j++;break;}
			if(infontcode==0&&ih[j]=='º'&&ih[j+1]=='t')
			{strcat(fh,"=");j++;break;}
			if(infontcode==0&&ih[j]=='Ò'&&ih[j+1]=='t')
			{strcat(fh,"K");j++;break;}
			if(infontcode==0&&ih[j]=='Î'&&ih[j+1]=='T')
			{strcat(fh,"?");j++;break;}
			if(infontcode==0&&ih[j]=='h'&&ih[j+1]=='¥')
			{strcat(fh,"#");j++;break;}
			if (ih[j]==' ')
			{strcat(fh," ");break;}
			else if (ih[j]==9)
			{
			int n=strlen(fh);
			fh[n]='\t';
			fh[n+1]='\0';
			break;
			}
			else if (ih[j]==10)
			{
			int n=strlen(fh);
			fh[n]='\n';
			fh[n+1]='\0';
			break;
			}
			else if(ih[j]==in[k][0])
			{
			for(int l=0;out[k][l]!='\0';l++)
			strcat(fh,out[k]);
			break;
			}

		      }
		 cout<<ih[i]<<" coverted "<<fh[i];

		 getch();clrscr();
		 cout<<"fh = "<<fh<<endl<<endl;

}
} */
//******************** COPY CONVERSION CODES FROM FILE *************************
/*void naidunia::copycodes()
{       char temp[10];
	temp[0]=infontcode+48;
	temp[1]=outfontcode+48;
	temp[2]='\0';
	strcpy(fntfile,temp);
	fontfile.close();
	int flag=0;
	char a;
	fontfile.open(fntfile);
	if(fontfile==0)
	{       clrscr();
		textcolor(LIGHTRED);
		cprintf("UNABLE TO OPEN FONT SOURCE CODES");
		cout<<"\n\n";
		textcolor(YELLOW);
		cprintf("PROGRAM WILL NOW TERMINATE");
		getch();
		exit(0);
	}
	for(int i=0;fontfile!=0;i++)
	{
		for(int j=0;j<=5;j++)
		{
		fontfile.get(a);
		if(a=='\t')
			{in[i][j]='\0';break;}
		else if (a=='\n')
			{in[i][j]='\0';flag=1;break;}
		else
			{in[i][j]=a;}
		}
	if (flag==1)
	break;
	}
	total=i-1;
	for(i=0;fontfile!=0;i++)
	{
		for(int j=0;j<=5;j++)
		{
		fontfile.get(a);
		if(a=='\t')
			{out[i][j]='\0';break;}
		else if (a=='\n')
			{out[i][j]='\0';break;}
		else
			{out[i][j]=a;}
		}
	}
} */
//*********************************************************************
//*************************************************************************
//************************ MAIN CONSOLE ************************************
void main()
{
clrscr();
naidunia ob;
ob.serial();
}