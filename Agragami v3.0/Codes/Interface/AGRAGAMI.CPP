#include"..\\header\\header.h"
#include"..\\header\\error.h"
#include"..\\header\\dialog.h"
#include"..\\header\\boxes.h"
#include"..\\header\\credits.h"
#include"..\\header\\listbox.h"

char *type[]={"","1. Text Document                   (.txt)",
		 "2. Microsoft Word 97-2003 Document (.doc)",
		 "3. Web Page                        (.htm)",
		 "4. Rich Text Format                (.rtf)",
		 "5. Adobe Acrobat Format            (.pdf)",
		 };

char *typecode[]={"","1","9","4","5","12",};
int use_con;
int total_types;

class interface
	{
	private:
		char temppath[_MAX_PATH];
		char to[50],from[50];
		char infile[_MAX_PATH],outfile[_MAX_PATH];
		char ifc[10],ofc[10];
		char fontname[20][50];
		int totalfonts;
		char ic,oc;
		int lastmenuchoice;
		char version[20];
	public:
		void odialog();
		void menu(int l);
		void changeinputfont();
		char * changetype();
		void idialog();
		void changeoutputfont();
		void router();
		void changeinputfile();
		void changefiletype(char *);
		void changeoutputfile();
		void getfonts();
		void EXIT();

		void convert();


		interface()
			{
				ifstream setting("usecon.ini");
				if(!setting)
				{
					error("INTERFACE.EXE","USECON.INI",TRUE);
				}
				else
					{
					setting>>use_con;
					setting.close();
					}

				if(use_con==0)
					{
					total_types=1;
					strcpy(infile,"C:\\INPUT.TXT");
					strcpy(outfile,"C:\\OUTPUT.TXT");
					strcpy(ifc,typecode[1]);
					strcpy(ofc,typecode[1]);
					}
				else
					{
					total_types=5;
					strcpy(infile,"C:\\INPUT.DOC");
					strcpy(outfile,"C:\\OUTPUT.DOC");
					strcpy(ifc,typecode[2]);
					strcpy(ofc,typecode[2]);
					}
				lastmenuchoice=1;
				strcpy(version,"BETA");
				getfonts();
				ic='1';
				oc='2';
				window(1,1,80,25);
				strcpy(to,fontname[2]);
				strcpy(from, fontname[1]);
			}

	};
//---------------------------------------------------------------------------
void interface::idialog()
{
	textbackground(GREEN);
	clrscr();
	message(13,8,7,"","","                                                    ","","","",RED,WHITE,WHITE);
	textbackground(RED);	gotoxy(19,17);	textcolor(YELLOW);	cprintf(" F2.");	textcolor(WHITE);	cprintf(" Preview.");	textcolor(YELLOW);	cprintf("   ENTER.");	textcolor(WHITE);	cprintf(" Continue.");	textcolor(YELLOW);	cprintf("   ESC.");	textcolor(WHITE);	cprintf(" BACK.");
	textcolor(YELLOW);	textbackground(RED);	gotoxy(16,10);cprintf("PATH   ");	textbackground(BLUE);
	cprintf("                                              ");
	gotoxy(16,12);

	textbackground(RED);	cprintf("STATUS ");	textbackground(RED);	textcolor(LIGHTGRAY);	cprintf("NOT FOUND.");	textcolor(YELLOW);	gotoxy(16,14);cprintf("FORMAT ");		textbackground(BLUE);	cprintf("                                              ");
	gotoxy(16,16);
	textbackground(RED);
	textcolor(WHITE);
	cprintf("----------------------------------------------------");
}
void interface::odialog()
{
	textbackground(GREEN);
	clrscr();
	message(13,8,7,"","","                                                    ","","","",RED,WHITE,WHITE);
	textbackground(RED);	gotoxy(25,17);	textcolor(YELLOW);	cprintf("   ENTER.");	textcolor(WHITE);	cprintf(" Continue.");	textcolor(YELLOW);	cprintf("   ESC.");	textcolor(WHITE);	cprintf(" BACK.");
	textcolor(YELLOW);	textbackground(RED);	gotoxy(16,10);cprintf("PATH   ");	textbackground(BLUE);
	cprintf("                                              ");
	gotoxy(16,12);

	textbackground(RED);	cprintf("STATUS ");	textbackground(RED);	textcolor(YELLOW);	gotoxy(16,14);cprintf("FORMAT ");		textbackground(BLUE);	cprintf("                                              ");
	gotoxy(16,16);
	textbackground(RED);
	textcolor(WHITE);
	cprintf("----------------------------------------------------");
}

//-------------------------------------------------------------------------
char * interface::changetype()
{
int format=listbox(type,total_types,23,14,42,BLUE,GREEN,WHITE,WHITE,YELLOW);
if(format==-1)
	return NULL;
else
	return typecode[format];
}
//-------------------------------------------------------------------------
void interface::changeinputfile()
{
	idialog();
	_setcursortype(_NORMALCURSOR);
	char temp[100];
	strcpy(temp,temppath);

	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(23,10);
	cprintf("%s",temp);

	for(int i=strlen(temppath);temp[i-1]!=13;i++)
		{

		gotoxy(23+i,10);
		temp[i]=getch();
		if(temp[i]==8)

			{
			if(i!=0)
				{
				textbackground(BLUE);
				cprintf("\b \b");
				i--;
				}
			i--;
			}

		else if(temp[i]==ESC)
			return;

		else if (temp[i]==60)
			{
			temp[i]=NULL;
			if(spawnl(P_WAIT,"startcd.exe","",temp,NULL)==-1)
				error("Interface.exe","StartCD.exe",FALSE);
				strcpy(temppath,temp);
				changeinputfile();
				return;
			}

		temp[i+1]=NULL;
		gotoxy(23,10);
		textcolor(WHITE);
		textbackground(BLUE);
		if(i>44)
			{temp[i-1]=NULL;
			i--;}

		cprintf("%s",temp);

		if(ifstream(temp)!=0)
		{       gotoxy(23,12);
			textbackground(RED);
			textcolor(LIGHTGREEN);
			cprintf("FILE FOUND.   ");
		}
		else
		{
			gotoxy(23,12);
			textcolor(LIGHTGRAY);
			textbackground(RED);
			cprintf("NOT FOUND.   ");
		}
		}
	temp[i-1]=NULL;
	if(ifstream(temp)!=0)
		{       gotoxy(23,12);
			textbackground(RED);
			textcolor(LIGHTGREEN);
			cprintf("FILE FOUND.   ");
		}
	if(strlen(temp)==0)
		{
			textbackground(GREEN);
			clrscr();
			message(20,8,4," ", " ","FILE PATH CANNOT BE LEFT BLANK..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeinputfile();
			return;
		}
	else if(ifstream(temp)==FALSE)
		{
			textbackground(GREEN);
			clrscr();
			strcpy(temppath,temp);
			message(24,8,4," ", " ","     FILE NOT FOUND...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeinputfile();
			return;
		}
	else
		{
			char *t=changetype();
			if(t==NULL)
				return;
			else
		       {  strcpy(ifc,t);

			strcpy(infile,temp);
			return;
			}
		}
}
//------------------------------------------------------------------------
void interface::changeoutputfile()
{
	odialog();
	_setcursortype(_NORMALCURSOR);
	char temp[100];
	strcpy(temp,temppath);

	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(23,10);
	cprintf("%s",temp);

	for(int i=strlen(temppath);temp[i-1]!=13;i++)
		{

		gotoxy(23+i,10);
		temp[i]=getch();
		if(temp[i]==8)

			{
			if(i!=0)
				{
				textbackground(BLUE);
				cprintf("\b \b");
				i--;
				}
			i--;
			}

		else if(temp[i]==ESC)
			return;

		temp[i+1]=NULL;
		gotoxy(23,10);
		textcolor(WHITE);
		textbackground(BLUE);
		if(i>44)
			{temp[i-1]=NULL;
			i--;}

		cprintf("%s",temp);

		if(ifstream(temp)!=0)
		{       gotoxy(23,12);
			textbackground(RED);
			textcolor(YELLOW);
			cprintf("FILE ALREADY EXIST.");
		}

		else
		{
			gotoxy(23,12);
			textcolor(LIGHTGRAY);
			textbackground(RED);
			cprintf("                    ");
		}
		}
	temp[i-1]=NULL;
	if(stricmp(temp,infile)==0)
		 {
			textbackground(GREEN);
			clrscr();
			strcpy(temppath,temp);
			message(22,8,4," ", " ","     SAME INPUT/OUTPUT FILE...     "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
			return;
		}
	if(ifstream(temp)!=0)
		{       
            textbackground(GREEN);
			clrscr();
			strcpy(temppath,temp);
			message(22,8,4," ", " ","       FILE ALREADY EXIST...       "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
			return;
		}
	if(strlen(temp)==0)
		{
			textbackground(GREEN);
			clrscr();

			message(20,8,4," ", " ","FILE PATH CANNOT BE LEFT BLANK..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
			return;
		}
	else if(ofstream(temp)==0)
		{
			textbackground(GREEN);
			clrscr();
				strcpy(temppath,temp);
			message(20,8,4," ", " ","UNABLE TO CREATE OUTPUT FILE..."," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfile();
			return;
		}

	else
		{
			remove(temp);
			char *t=changetype();
			if(t==NULL)
				return;
			else
		       {  strcpy(ofc,t);

			strcpy(outfile,temp);
			return;
			}
		}
}

//------------------------------------------------------------------------
void interface::getfonts()
{
	ifstream font_file;
	font_file.open("AVLFONTS.INF");
	if(font_file==0)
		error("INTERFACE.EXE","AVLFONTS.INF",TRUE);

	for(int i=1;font_file!=0;i++)
		{
		font_file.getline(fontname[i],40);
		}
	totalfonts=i-2;
}
//--------------------------------------------------------------------------
void interface::menu(int l)
{
	_setcursortype(_NOCURSOR);
	box(GREEN);

	gotoxy(35,5); 	textcolor(YELLOW);	cprintf(" AGRAGAMI");

	gotoxy(30,7);   textcolor(WHITE); 	cprintf("Hindi Font Convertor");

	box2(68,2,76,4); gotoxy(70,3);	textcolor(YELLOW); cprintf(version);

	gotoxy(2,9);   textbackground(RED);	textcolor(YELLOW);	cprintf("-----------------------------------------------------------------------------");
	for(int i=0;i<=10;i++)
	{gotoxy(2,10+i);   textbackground(BLACK);	textcolor(YELLOW);	cprintf("                                                                             ");}

	textbackground(RED);gotoxy(2,21);	textcolor(YELLOW);	cprintf("-----------------------------------------------------------------------------");

	textbackground(GREEN);	gotoxy(29,23);

	textcolor(YELLOW);cprintf("F1.");	textcolor(WHITE);cprintf(" Wizard   ");
	textcolor(YELLOW); cprintf("F2. "); textcolor(WHITE);	cprintf("Settings  ");
	textcolor(YELLOW); cprintf("F3. "); textcolor(WHITE);	cprintf("Credits  ");
	textcolor(YELLOW); cprintf("ESC. "); textcolor(WHITE);	cprintf("QUIT");

	gotoxy(40,11);textbackground(BLACK);textcolor(YELLOW);	cprintf("%.38s",infile);
	gotoxy(40,13); textcolor(YELLOW);	cprintf("%.38s",outfile);
	textcolor(WHITE);
	gotoxy(30,11);cprintf("=>");
	gotoxy(30,13);cprintf("=>");
	gotoxy(30,15);cprintf("=>");
	gotoxy(40,15);
	textcolor(YELLOW);
	cprintf("%.16s",from);
	textcolor(LIGHTRED);
	cprintf("  =>  ");
	textcolor(YELLOW);
	cprintf("%.16s",to);

	char menu[10][100],menuh[10][100];


	strcpy(menu[1],"1 => Input file        ");
	strcpy(menuh[1],"Change Input File.    ");
	strcpy(menu[2],"2 => Output file       ");
	strcpy(menuh[2],"Change Output File.   ");
	strcpy(menu[3],"3 => Current convertor ");
	strcpy(menuh[3],"Change Convertor.     ");
	strcpy(menu[4],"4 => Convert.          ");
	strcpy(menuh[4],"Convert Data.         ");
	strcpy(menu[5],"5 => Exit.             ");
	strcpy(menuh[5],"Quit.                 ");
	for(i=1;i<=5;i++)
		{

		textbackground(BLACK);

		textcolor(WHITE);

		lowvideo();
		if(i==l)
		       {
			normvideo();
			gotoxy(4,23);
			textbackground(GREEN);
			cprintf(menuh[i]);
			textbackground(BLUE);
		       }

		gotoxy(4,9+2*i);
		cprintf(menu[i]);
		}
			normvideo();
	}
//--------------------------------------------------------------------------

void interface::router()
{
	start:
	strcpy(temppath,"");

	strupr(infile);
	strupr(outfile);

	_setcursortype(_NOCURSOR);
	int l=lastmenuchoice;
	char i;
	do
	{
	menu(l);
	  while(!kbhit())
	  {
		  gotoxy(28,3);
		  textbackground(GREEN);
		  textcolor(LIGHTGRAY);
		  cprintf("%s", getdate());
	  }

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

		case 59 : if(spawnl(P_WAIT,"wizard.exe","","+o",NULL)==-1)
				error("INTERFACE.EXE","WIZARD.EXE",FALSE);
			  goto start;


		case 60: if(spawnl(P_WAIT,"settings.exe",NULL)==-1)
				{error("INTERFACE.EXE","SETTINGS.EXE",FALSE);goto start;}
			if(spawnl(P_WAIT,"startcd.exe","","agragami.exe",NULL)==-1)
				error("INTERFACE.EXE","startcd.EXE",FALSE);
			exit(0);
				break;
		case '=':  credits();	goto start;

		case '1':
		case 'i':
		case 'I': changeinputfile();
			goto start;

		case '2':
		case 'o':
		case 'O': changeoutputfile();
			goto start;

		case '3':
		case 'f':
		case 'F': changeinputfont();
			goto start;


		case '4':
		case 'c':
		case 'C': convert();
			goto start;


		case ESC:
		case '5':
		case 'e':
		case 'E':EXIT();
			goto start;


	}
	}
	}while(i!=13&&i!=RIGHT);

		switch(l)
			{

		case 1: changeinputfile();  goto start;
		case 2: changeoutputfile();
			  goto start;

		case 3: changeinputfont();

			goto start;

		case 4: convert();
			  goto start;

		case 5: EXIT();
			  goto start;

			}
}


void interface::EXIT()

{
	textbackground(GREEN);
	clrscr();

	_setcursortype(_NOCURSOR);
	char a;
	message(20,8,5," ", " ","ARE YOU SURE YOU WANT TO EXIT?"," "," ","",RED,WHITE,YELLOW);
	gotoxy(30,15);
	textbackground(RED);
	cprintf("              ");

	gotoxy(28,14);
	textcolor(YELLOW);
	cprintf(" YES ");

	gotoxy(42,14);
	textcolor(WHITE);
	textbackground(BLACK);
	cprintf(" NO ");

	int x;
	do
	{
	x=getch();
	if (x==ESC)
		return;
	if(x==LEFT||x=='y')
		{
		gotoxy(42,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" NO ");

		gotoxy(28,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" YES ");
		a='y';
		}

	if(x==RIGHT||x=='n')
		{
		a='n';
		gotoxy(28,14);
		textbackground(RED);
		textcolor(YELLOW);
		cprintf(" YES ");

		gotoxy(42,14);
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf(" NO ");

		}
	} while(x!=13);

	if (a=='y'||a=='Y')
		{
		exit(0);
		}
	else
		return;
}


void interface::convert()
{
       char fntfile[10];
       if(ifstream(infile)==FALSE)
		{
			error("Interface.exe",infile,FALSE);
			return;
		}

       if(ic==oc)
		 {
			textbackground(GREEN);
			clrscr();

			cout<<"\a";
			message(25,8,4," ", " ","  SAME INPUT/OUTPUT FONT.  "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			return;
		 }
       if(strcmp(outfile,infile)==0)
		 {
			cout<<"\a";
			textbackground(GREEN);
			clrscr();
			message(25,8,4," ", " ","  SAME INPUT/OUTPUT FILE.  "," "," ","OK",RED,YELLOW,WHITE);
			getch();
			return;
		 }

	fntfile[0]=ic;
	fntfile[1]=oc;
	fntfile[2]=NULL;
	strcat(fntfile,".exe");

	if (spawnl(P_WAIT,"FontCon.exe","",infile,ifc,outfile,ofc,fntfile,NULL)==-1)
		{
			error("Interface.exe","FontCon.exe",FALSE);
			return;
		}
}
//-------------------------------------------------------------------------
void interface::changeinputfont()
{
	menu(3);

	gotoxy(62,15);
	textbackground(BLACK);
	cprintf("                ");

	gotoxy(4,23);
	textcolor(WHITE);
	textbackground(GREEN);

	cprintf("Select Input Font.");
	message(38,16,2*totalfonts-3,"              ","","","",""," OK ",RED,YELLOW,WHITE);
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
						textbackground(BLACK);
						cprintf(fontname[i+1]);
						textbackground(RED);
					}
		gotoxy(40,17+2*i);
		cprintf(fontname[i+1]);
		}

       while(!kbhit())
	  {
		  gotoxy(28,3);
		  textbackground(GREEN);
		  textcolor(LIGHTGRAY);
		  cprintf("%s", getdate());
	  }
	b=getch();
	if (b==UP&&l>0)
		l--;
	if (b==DOWN&&l<totalfonts-1)
		l++;


	if(b==ESC)
		{return;}
	}
	while(b!=13&&b!=RIGHT);
		strcpy(from,fontname[l+1]);
		ic=l+49;
	changeoutputfont();
}
//***************************** CHANGE OUTPUT  FONT FUNCTION **************************************************
void interface::changeoutputfont()
{
	menu(3);

	gotoxy(62,15);
	textbackground(BLACK);
	cprintf("                ");

	gotoxy(4,23);
	textcolor(WHITE);
	textbackground(GREEN);
	cprintf("Select Output Font.");
	message(60,16,2*totalfonts-3,"              ","","","",""," OK ",RED,YELLOW,WHITE);
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
					textbackground(BLACK);
					cprintf(fontname[i+1]);
					textbackground(RED);
					}
		gotoxy(62,17+2*i);
		cprintf(fontname[i+1]);
				}

	    while(!kbhit())
			  {
			  gotoxy(28,3);
			  textbackground(GREEN);
			  textcolor(LIGHTGRAY);
			  cprintf("%s", getdate());
			  }

	b=getch();
	if (b==UP&&l>0)
		 l--;

	if (b==DOWN&&l<totalfonts-1)
		 l++;

	if(b==LEFT)
		{
			changeinputfont();
			return;
		}

	if(b==ESC)
		return;
	} while(b!=13);

		if(strcmp(from,fontname[l+1])==0)
			{
			textbackground(GREEN);
			clrscr();
			message(24,8,4," ", " ","SAME FONTS CANNOT BE SELECTED"," "," ","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfont();
			return;
			}
		strcpy(to,fontname[l+1]);
		oc=l+49;
	}

//-------------------------------------------------------------------------
void printer(char a[],char b[],int x1,int y1,int x2,int y2,int background,int time)
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

void main()
{

		box(GREEN);
		_setcursortype(_NOCURSOR);
		message(24,10,3,"                         "," "," "," "," "," ",RED,YELLOW,WHITE);
		gotoxy(30,15);
		textbackground(RED);
		cprintf("                       ");
		printer("Hindi Font Convertor","Agragami",30,14,36,12,RED,23);
		delay(200);
		interface ob;
		ob.router();
}
//-------------------------------------------------------------------------
