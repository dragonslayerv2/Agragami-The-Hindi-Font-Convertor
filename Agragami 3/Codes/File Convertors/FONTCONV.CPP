#include"..\\header\\header.h"
#include"..\\header\\dialog.h"
#include"..\\header\\error.h"
#include"..\\header\\boxes.h"
#include"filecon.h"


char temp[5][100];
void status()
{
	_setcursortype(_NOCURSOR);
	message(16,6,12,"","           CONVERTING - DATA           ","---------------------------------","","","WAIT",RED,WHITE,YELLOW);
	textbackground(RED);

	textcolor(WHITE);
	gotoxy(19,10);
	cprintf("Input File  :               Type :");
	gotoxy(19,11);
	cprintf("Output File :               Type :");


	textcolor(WHITE);
	gotoxy(22,12);
	cprintf("---------------------------------");

	gotoxy(19,13);
	cprintf("Status            : ");
	gotoxy(19,14);
	cprintf("Time Elapsed      : ");
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
	if(argc!=6)
	{
		usage();

	}
	_setcursortype(_NOCURSOR);
	clock_t start, end;
	start = clock();

	for(int i=1;i<4;i++)
		tmpnam(temp[i]);

	//------------------Copy File to A temp location------------
	ofstream log("log.txt",ios::app);
	log<<"--------"<<getdate()<<endl<<"Input File : "<<argv[1]
		      <<endl<<"Type       : "<<argv[2]
		      <<endl<<"Output File: "<<argv[3]
		      <<endl<<"Type       : "<<argv[4]
		      <<endl;



		if(ifstream(argv[1])==0)
		{
		 error("Convert.exe",argv[1],TRUE);
		}

	status();
	char drive[_MAX_DRIVE],dir[_MAX_DIR],file[_MAX_FNAME],ext[_MAX_EXT];
	strupr(argv[1]);
	strupr(argv[3]);
	_splitpath(argv[1],drive,dir,file,ext);
	textcolor(LIGHTGRAY);
	gotoxy(33,10);
	cprintf(file);
	gotoxy(54,10);
	cprintf(ext);
	_splitpath(argv[3],drive,dir,file,ext);

	gotoxy(33,11);
	cprintf(file);
	gotoxy(54,11);
	cprintf(ext);
	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Processing File");


	filecon input(argv[1],temp[2],argv[2],"1");
	input.convert_file();

	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Converting Data");

	int res=spawnl(P_WAIT,argv[5],"",temp[2],temp[3],NULL);
	if(res==-1)
		{
			error("FileConv.exe",argv[5],TRUE);
		}


	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Creating Output File");

	filecon output(temp[3],argv[3],"1",argv[4]);
	output.convert_file();

	gotoxy(39,13);
	textcolor(LIGHTGREEN);
	cout<<"\a";
	cprintf("Data Converted.      ");
	end = clock();
	gotoxy(39,14);

	textcolor(LIGHTGRAY);
	cprintf("%.2f sec",(float)(end - start) / CLK_TCK);
	gotoxy(26,20);
	textcolor(YELLOW);
	textbackground(BLACK);
	cprintf(" Press Enter to Continue ");

	getch();
	res=spawnl(P_WAIT,"startcd.exe","",argv[3],NULL);
	if(res==-1)
		error("FileConv.exe","startcd.exe",TRUE);

}
void rem()
{
for(int i=1;i<4;i++)
remove(temp[i]);
ofstream log("log.txt",ios::app);
log<<"\n\r------\n\r";
log.close();
}
#pragma exit rem