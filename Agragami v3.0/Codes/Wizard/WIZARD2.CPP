#include"..\\header\\header.h"
#include"..\\header\\error.h"
#include"..\\header\\dialog.h"

#include"..\\header\\boxes.h"
void menu(int l)
{
	box(GREEN);

	_setcursortype(_NOCURSOR);

	gotoxy(37,3);textcolor(WHITE); cprintf("Wizard");
	gotoxy(35,5);
	textcolor(YELLOW);
	cprintf(" AGRAGAMI");

	gotoxy(30,7);
	textcolor(WHITE);
	cprintf("Hindi Font Convertor");
	gotoxy(2,9);   textbackground(RED);	textcolor(YELLOW);	cprintf("-----------------------------------------------------------------------------");
	for(int i=0;i<=10;i++)
	{gotoxy(2,10+i);   textbackground(BLACK);	textcolor(YELLOW);	cprintf("                                                                             ");}

	textbackground(RED);gotoxy(2,21);	textcolor(YELLOW);	cprintf("-----------------------------------------------------------------------------");

	textbackground(GREEN);	gotoxy(68,23);	textcolor(YELLOW); cprintf("ESC. ");
	textcolor(WHITE);  cprintf("Close");

	char menu[10][100],menuh[10][100];

	strcpy(menu[1],"1 => Retrieving Data.         ");
	strcpy(menuh[1],"Press [Enter] to continue...");
	strcpy(menu[2],"2 => Select Input File Font. ");
	strcpy(menuh[2],"Choose input file font.                                    ");
	strcpy(menu[3],"3 => Select Output File Font.");
	strcpy(menuh[3],"Choose output file font.                                   ");
	strcpy(menu[4],"4 => Convert Data.        ");
	strcpy(menuh[4],"Converting Data.                                           ");
	strcpy(menu[5],"5 => Show Converted Data.       ");
	strcpy(menuh[5],"                               ");
	for(i=1;i<=5;i++)
		{

		textbackground(BLACK);

		textcolor(WHITE);

		lowvideo();
		if(i==l)
		       {
			highvideo();
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

class wizard
{
	   public:
		int totalfonts;
		char fontname[50][50];
		char ic,oc;
		char to[50],from[50];

	public:
		void input();
		void getfonts();
		void convert();
		void changeoutputfont();
		void changeinputfont();

		wizard()
		{
			remove("Iagr.txt");
			remove("Oagr.txt");
			getfonts();
			ic='1';
			oc='2';
			strcpy(from, fontname[1]);
			strcpy(to,fontname[2]);
		}
};
//------------------------------------------------------------------------
void wizard::getfonts()
{
	ifstream font_file;

	font_file.open("AVLFONTS.INF");
	if(font_file==0)
		error("WIZARD.EXE","AVLFONTS.INF",TRUE);

	for(int i=1;font_file!=0;i++)
		{
		font_file.getline(fontname[i],40);
		}
	totalfonts=i-2;

	font_file.close();
}
//-------------------------------------------------------------------------
void wizard::input()
{
	ofstream in("iagr.txt");
	if (in==FALSE)
	    {
	    error("Wizard.exe","Iagr.txt",TRUE);
	    }

	in<<"1. Paste your data in this window.\n\n2. Save and close this file, after pasting your data.";
	in.close();


	    if (spawnl(P_WAIT,"startcd.exe","","iagr.txt",NULL)==-1)
	     {
		error("Wizard.exe","startcd.exe",TRUE);
	     }
}
//------------------------------------------------------------------------
void wizard::changeinputfont()
{


	message(59,12,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);
	int l=ic-49;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)textcolor(WHITE);

		gotoxy(61,13+2*i);
		cprintf(fontname[i+1]);
		}
	gotoxy(1,1);

	b=getch();
	if (b==UP&&l>0)
		l--;
	if (b==DOWN&&l<totalfonts-1)
		l++;


	if(b==27)
		exit(0);
	}
	while(b!=13);
		strcpy(from,fontname[l+1]);
		ic=l+49;
	return;

}
//-------------------------------------------------------------------------
void wizard::changeoutputfont()
{
	menu(3);

	message(59,12,2*totalfonts-3,"             ","","","",""," OK ",RED,YELLOW,WHITE);

	int l=oc-49;
	char b;
	do
		{
			for(int i=0;i<totalfonts;i++)
				{
				textcolor(YELLOW);
				textbackground(RED);
				if(i==l)
					textcolor(WHITE);

		gotoxy(61,13+2*i);
		cprintf(fontname[i+1]);
		}
	b=getch();

	if (b==UP&&l>0)
		 l--;

	if (b==DOWN&&l<totalfonts-1)
		 l++;


	if(b==ESC)
		exit(0);
	}
	while(b!=13);
		if(strcmp(from,fontname[l+1])==0)
			{
			menu(3);
			message(24,8,4,"", "","SAME FONTS CANNOT BE SELECTED","","","OK",RED,YELLOW,WHITE);
			getch();
			changeoutputfont();
			return;
			}
		strcpy(to,fontname[l+1]);
		oc=l+49;
		return;
}
//-----------------------------------------------------------------------
void wizard::convert()
{
	char fntfile[10];
	fntfile[0]=ic;
	fntfile[1]=oc;
	fntfile[2]=NULL;
	strcat(fntfile,".exe");
	int res=spawnl(P_WAIT,fntfile,"","IAGR.TXT","OAGR.TXT",NULL);
	if (res==-1)
		{
			error("Wizard.exe","Convert.exe",TRUE);
		}
	else
		{
		gotoxy(41,13);
		textcolor(YELLOW);
		cprintf("DATA CONVERTED.");
		gotoxy(26,20);
		textcolor(YELLOW);
		textbackground(BLACK);
		cprintf(" Press Enter to Continue ");
		getch();

		res=spawnl(P_WAIT,"startcd.exe","","OAGR.TXT",NULL);
		if(res==-1)
			error("FileConv.exe","startcd.exe",TRUE);
		}
}

//-----------------------------------------------------------------------
void createdialog()
{

		_setcursortype(_NOCURSOR);
		message(16,6,12,"","           CONVERTING - DATA           ","---------------------------------","","","WAIT",RED,WHITE,YELLOW);
		textbackground(RED);
		textcolor(WHITE);
		gotoxy(19,10);
		cprintf("Input File  :               Type :     ");
		textcolor(YELLOW);
		gotoxy(33,10);
		cprintf("DEFAULT FILE");
		gotoxy(54,10);
		cprintf(".txt");
		textcolor(WHITE);
		gotoxy(19,11);
		cprintf("Output File :               Type : .TXT");
			textcolor(YELLOW);
		gotoxy(33,11);
		cprintf("DEFAULT FILE");
		gotoxy(54,11);
		cprintf(".txt");
		textcolor(WHITE);
		gotoxy(22,12);
		cprintf("---------------------------------");
		gotoxy(19,13);
		cprintf("Status            : ");
		gotoxy(41,13);
		textcolor(YELLOW);
		cprintf("CONVERTING DATA");
		textcolor(WHITE);
		gotoxy(22,15);
		cprintf("---------------------------------");
		gotoxy(19,16);
		cprintf("Charac. Converted :");
		gotoxy(19,17);
		cprintf("Errors            :");
		gotoxy(19,18);
		cprintf("Accuracy          :");
		gotoxy(22,19);
		cprintf("---------------------------------");
}

void main(int argc,char *argv[])
{
	if((argc!=2)||strcmp(argv[1],"+o")!=0)
		{
			usage();
		}

	wizard wiz;
	menu(1);
	wiz.input();
	if(getch()==ESC)
	exit(0);
	menu(2);
	wiz.changeinputfont();

	wiz.changeoutputfont();
	menu(4);
	createdialog();
	wiz.convert();
	menu(5);
	delay(500);
	exit(0);
}

void cleanup()
{
remove("IAGR.TXT");
}
#pragma exit cleanup