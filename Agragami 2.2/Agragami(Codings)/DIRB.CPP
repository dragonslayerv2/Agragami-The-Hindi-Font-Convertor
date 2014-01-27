#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void scandir(char *dirname)
{
  textcolor(LIGHTGRAY);
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(dirname)) == NULL)
  { textcolor(YELLOW);
    gotoxy(3,14);perror("Unable to open directory");
  }
  int i=13,j=1;
  while ((ent = readdir(dir)) != NULL&&i<22)
  {    gotoxy(2+j*15-12,i);{textcolor(YELLOW);cprintf("%s",ent->d_name);j++;if(j==6){i++;j=1;}}}
}

void main(int argc,char *argv[])
{
// **************If no arguments provided exit ***********
if(argc !=2)
{
	exit(0);
}

//******** Data Declarations *****************************
char path[_MAX_PATH];
char path2[_MAX_PATH];
char drive[_MAX_DRIVE];
char dir[_MAX_DIR];
char file[_MAX_FNAME];
char ext[_MAX_EXT];
char files[]="\0";
char exts[]="\0";
//**********Split THe path********************************
strcpy(path,argv[1]);
_splitpath(path,drive,dir,file,ext);

//************Check if file is present********************
ifstream temp(path);
gotoxy(2,10);
if(temp!=0)
	{

	textcolor(YELLOW);
	gotoxy(2,10);
cprintf("-----------------------------------------------------------------------------");
		textcolor(LIGHTGREEN);
	gotoxy(35,11);
	cprintf("File found");
	textcolor(YELLOW);
	gotoxy(2,12);
cprintf("-----------------------------------------------------------------------------");
	textcolor(WHITE);
	gotoxy(2,13);
	cprintf(" Drive: \"%s\"",drive);
	gotoxy(2,14);
	cprintf(" Directory: \"%s\"\n\r",dir);
	gotoxy(2,15);
	cprintf(" File name: \"%s%s\"",file,ext);
	gotoxy(65,15);
	cprintf(" Type: \"%s\"\n\r",ext);

	textcolor(YELLOW);
	gotoxy(2,16);
cprintf("-----------------------------------------------------------------------------");
	gotoxy(30,18);
	cprintf("Press Enter to continue");
	temp.close();
	exit(0);
	}
//****************************************************************************

	textcolor(YELLOW);
	gotoxy(2,8);
cprintf("-----------------------------------------------------------------------------");

	textcolor(WHITE);
	gotoxy(2,9);
	cprintf(" Drive: \"%s\"",drive);
	gotoxy(2,10);
	cprintf(" Directory: \"%s\"\n\r",dir);
	gotoxy(2,11);
	cprintf(" File name: \"%s%s\"\n\r",file,ext);
	textcolor(YELLOW);
	gotoxy(2,12);
cprintf("-----------------------------------------------------------------------------");

_makepath(path2,drive,dir,files,exts);
scandir(path2);
	gotoxy(2,21);
cprintf("-----------------------------------------------------------------------------");
exit(0);
}