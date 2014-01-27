//-----------------------------------------------------------------------------------
void box2(int x1,int y1,int x2,int y2)
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
//-----------------------------------------------------------------------------------
void box(int back_colour)
{	
	_setcursortype(_NOCURSOR);
	textbackground(back_colour);
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
//-----------------------------------------------------------------------------------