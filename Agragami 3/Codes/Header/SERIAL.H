//---------------------------------SERIAL CLASS--------------------------------------
class serial
	{
		char serialno[30];
	public:

		int checkfiles();
		void getserial();
		int checkserial();
		void destroy();
	};
//-----------------------------------------------------------------------
int serial :: checkfiles()
	{
		_setcursortype(_NOCURSOR);
		ifstream serial_file;
		serial_file.open("S78HBGF3.INF");


		if(serial_file==0)
			{
			       return FALSE;
			}

		else if(serial_file!=0)
			{
				serial_file.read((char *)&serialno,sizeof(serialno));
				if(checkserial()==TRUE)
				{
					serial_file.close();
					return TRUE;
				}
				else
				{

					destroy();
					serial_file.close();
					return FALSE;
				}
			}

		return FALSE;
	}
//-----------------------------------GET SERIAL CODE FROM USER------------------------------------------------------------*

void serial::getserial()
	{

		if(ifstream("S78HBGF3.INF")!=0)
			return;

		box(GREEN);

		message(18,8,7,"                                  ","","","",""," OK ",RED,WHITE,YELLOW);

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
					_setcursortype(_NORMALCURSOR);
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
			else if(temp[i]==ESC)
				exit(1);
			else
				cprintf("%c",temp[i]);
		}
		temp[i-1]=NULL;
		strcpy(serialno,temp);
		strupr(serialno);
		_setcursortype(_NOCURSOR);

		if(checkserial()==TRUE)
			{
				clrscr();
				_setcursortype(_NOCURSOR);
				ofstream serial_file("S78HBGF3.INF",ios::binary);
				if(serial_file==0)
				{
					box(BLACK);
					message(20,10,3,"","   UNABLE TO INSTALL SERIAL CODE.     ","","",""," OK ",RED,WHITE,YELLOW);
					getch();
					exit(1);
				}
				else
				{
					_setcursortype(_NOCURSOR);
					serial_file.write((char *)&serialno,sizeof(serialno));
					system("attrib S78HBGF3.INF +a +h +s +r");
					serial_file.close();
					box(GREEN);
					message(20,10,3,""," SERIAL KEY INSTALLED SUCCESSFULLY "," "," "," "," OK ",GREEN,WHITE,YELLOW);
					getch();
					checkfiles();
					return;
				}
			}
		else
			{
			_setcursortype(_NOCURSOR);
			box(BLACK);
			message(25,10,3,""," INVALID SERIAL KEY ","","",""," OK ",RED,WHITE,YELLOW);
			getch();
			exit(1);
			}
	}
//----------------------------------CHECK SERIAL CODE ENTERED BY USER -----------------------------------------------------
int serial::checkserial()
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
		return TRUE;
	else
		return FALSE;
	}
//****************************** CREATE TRIAL FILE ************************************************************************
void serial::destroy()
	{
		spawnl(P_WAIT,"UNIST.EXE","","uninst00.inf","+Y",NULL);
		exit(1);
	}
void start()
{
	_setcursortype(_NOCURSOR);
	serial ob;
	ob.getserial();
	if(ob.checkfiles()==TRUE)
	{
	  return;
	}
	else
		exit(1);
}
#pragma startup start
