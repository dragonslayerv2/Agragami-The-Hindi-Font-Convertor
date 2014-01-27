int listbox(char *name[],int total,int x,int y,int width,int bcolour,int fcolour,int border,int btext,int ftext)
{
	_setcursortype(_NOCURSOR);
	char a[100]="";
	for(int i=1;i<width-1;i++)
	 strcat(a," ");
	message(x,y,2*total-3,a,"","","",""," OK ",bcolour,YELLOW,border);
	int l=0;
	char b;
	do
		{
			for(int i=0;i<total;i++)
				{
				textcolor(btext);
				textbackground(bcolour);
				if(i==l)
					{
					textcolor(ftext);
					textbackground(fcolour);
					}
		gotoxy(x+2,(y+1)+2*i);
		cprintf(name[i+1]);
		}
	b=getch();
	if (b==UP&&l>0)
		l--;
	if (b==DOWN&&l<total-1)
		l++;


	if(b==ESC)
		return -1;
	}
	while(b!=13);
		return l+1;
}