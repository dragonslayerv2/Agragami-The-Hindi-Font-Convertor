#include"..\\header\\header.h"
#include"..\\header\\error.h"
#include"..\\header\\dialog.h"
#include"..\\header\\boxes.h"
#include"..\\header\\credits.h"
#include"..\\header\\listbox.h"
char *answers[]={"",
		 "YES (Can convert \'.doc\',\'.rtf\',etc.)   ",
		 "NO  (Cannot convert \'.doc\',\'.rtf\',etc.)"};
//-------------------------------------------------------------------------
class use_converdoc
	{
		public:
		char value;

		public:
			void set_value(char);
			void get_value();
			void put_value();
			use_converdoc()
				{
					get_value();
				}
	};

void use_converdoc::get_value()
{
	ifstream in("usecon.ini");
	if(in==FALSE)
	{
		in.close();
		ofstream out("usecon.ini");
		if(out==FALSE)
		{
		       error("SETTINGS.EXE","USECON.INI",TRUE);
		}
		out.put('1');
		value='1';
		out.close();
		return;
	}
	else
	{
		char temp;
		in.get(temp);
		if(temp=='0'||temp=='1')
			{
			value=temp;
			}
		else
			{
			 textbackground(BLUE);
			 clrscr();
			 message(20,8,4," ", " ","INVALID CHARACTER AT LINE 1#1.."," "," ","OK",RED,YELLOW,WHITE);
			 getch();
			 exit(1);
			}

	}
}
//-------0--------------------------------------------------------------------
void use_converdoc::set_value(char x)
{
	if(x=='0'||x=='1')
	    {	value=x;
		if(value=='0')
			{textbackground(BLUE);clrscr();message(20,8,4," ", " ","    ConverDoc disabled.    "," "," ","OK",RED,YELLOW,WHITE);delay(200);}
		else
			{textbackground(BLUE);clrscr();message(20,8,4," ", " ","    ConverDoc enabled.    "," "," ","OK",RED,YELLOW,WHITE);delay(200);}
	    }
	else
	       {textbackground(BLUE);clrscr();message(20,8,4," ", " ","UNABLE TO CHANGE THE VALUE."," "," ","OK",RED,YELLOW,WHITE);getch();exit(1);}
}
//---------------------------------------------------------------------------
void use_converdoc::put_value()
{
	ofstream out("usecon.ini");
		if(out==FALSE)
		{
		       error("SETTINGS.EXE","USECON.INI",TRUE);
		}
	out.put(value);
	out.close();
	return;
}
//--------------------------------------------------------------------------
void main()
{
	use_converdoc ob;

	textbackground(GREEN);
	clrscr();
	message(13,8,9,"","","                                                    ","","","",RED,WHITE,WHITE);

	textbackground(RED);	gotoxy(25,19);
	textcolor(YELLOW);	cprintf("   ENTER.");	textcolor(WHITE);	cprintf(" Continue.");
	textcolor(YELLOW);	cprintf("   ESC.");	textcolor(WHITE);	cprintf(" Back.");

	textcolor(YELLOW);	textbackground(RED);	gotoxy(16,10); cprintf("CURRENT SETTINGS:  ");
	textbackground(BLUE);textcolor(WHITE);
	if(ob.value=='1'){ cprintf(" ConverDoc Enabled.              ");}
	else 	       cprintf(" ConverDoc Disabled.             ");
	textbackground(RED);textcolor(YELLOW);	gotoxy(16,12);cprintf("USE CONVERDOC:");
	gotoxy(16,18);	textbackground(RED);	textcolor(WHITE);
	cprintf("----------------------------------------------------");
	setvalue(getanswer());
	putvalue();
	exit(0);
    }