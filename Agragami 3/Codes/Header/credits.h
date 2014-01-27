void credits()
{
_setcursortype(_NOCURSOR);
message(16,4,13,"","            About Agragami              ","---------------------------------","","","OK",RED,WHITE,YELLOW);
textbackground(RED);
	textcolor(WHITE);
	gotoxy(19,8);
	cprintf("Developer    : ");
	textcolor(YELLOW);
	cprintf("Shobhit Saxena");
	textcolor(WHITE);
	gotoxy(19,9);
	cprintf("Dedecated to : ");
	textcolor(YELLOW);
	cprintf("My Mom and Dad");
	textcolor(WHITE);
	gotoxy(22,10);
	cprintf("---------------------------------");
	gotoxy(19,11);
	cprintf("Version      : ");

	textcolor(YELLOW);
	cprintf("3.0 (Testing Phase)");
	textcolor(WHITE);

	gotoxy(22,12);

	cprintf("---------------------------------");

	gotoxy(19,13);
	cprintf("Home Page    : ");
	textcolor(YELLOW);
	cprintf("www.himvan.com");
	textcolor(WHITE);

	gotoxy(19,14);
	cprintf("E-mail       : ");
	textcolor(YELLOW);
	cprintf("shobhitsaxena@live.com");
	textcolor(WHITE);

	gotoxy(22,15);
	cprintf("---------------------------------");
	textcolor(WHITE);
	gotoxy(27,16);
	cprintf("Copyright (C) 2009-2010.");
	gotoxy(29,17);
	cprintf("All rights reserved.");
	gotoxy(22,18);

	cprintf("---------------------------------");
	getch();
}