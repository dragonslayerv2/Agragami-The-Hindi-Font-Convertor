#include<conio.h>
void main()
{
textbackground(BLUE);
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
	gotoxy(30,12);
	textcolor(LIGHTRED);
	cprintf("YOUR TRIAL VERSION ENDS...");
	getch();
}