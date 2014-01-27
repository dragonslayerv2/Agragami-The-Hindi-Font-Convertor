void error(char module[],char filename[],int exitcode=FALSE)
{
	cout<<"\a";
	textbackground(BLACK);
	clrscr();
	_setcursortype(_NOCURSOR);
	char a;

	message(14,8,8,"","ERROR","------------------------","                                                ","","CLOSE",RED,WHITE,YELLOW);
	textbackground(RED);
	textcolor(WHITE);
	gotoxy(18,13);
	cprintf("ERROR NO  :");
	gotoxy(18,15);
	cprintf("FILE NAME :");
	gotoxy(18,14);
	cprintf("ERROR     :");
	gotoxy(18,16);
	cprintf("MODULE    :");

	gotoxy(30,13);

	textcolor(LIGHTGRAY);
	cprintf("%d",errno);
	gotoxy(30,14);
	textcolor(YELLOW);

	if(errno==EEXIST)
		cprintf("%s","File already exist");
	else
		cprintf("%s",strerror(errno));
	textcolor(LIGHTGRAY);
	gotoxy(30,15);
	cprintf("%.35s",filename);

	gotoxy(30,16);
	cprintf("%s",module);
	
	ofstream log("log.txt",ios::app);
   	log<<"\nERROR: "<<strerror(errno)<<"\nModule: "<<module<<"\nFile: "<<filename<<"\nTime:"<<getdate();
	log.close();
	getch();
		if(exitcode==TRUE)
		exit(1);
}
