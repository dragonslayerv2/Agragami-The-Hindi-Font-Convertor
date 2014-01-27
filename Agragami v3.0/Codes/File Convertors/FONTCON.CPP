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
	//---------------Newly edited------------
	int use_con;
	ifstream setting("usecon.ini");
	if(!setting)
		{
			error("INTERFACE.EXE","USECON.INI",TRUE);
		}
	else
		{
			setting>>use_con;
			setting.close();
		}

	//---------------------------------------
	for(int i=1;i<6;i++)
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
		  error("FontCon.exe",argv[1],TRUE);
		}

		if(ofstream(argv[3],ios::noreplace)==0)
		{
		  error("FontCon.exe",argv[3],TRUE);

		}
		remove(argv[3]);
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


	if(use_con!=0)
	{
	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Processing File");
	filecon input(argv[1],temp[2],argv[2],"1");
	input.convert_file();
	}

	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Converting Data");
	//*------------NEW ADDITIONS-------
	char f1[10],f2[10];
	strcpy(f1,"11.exe");
	strcpy(f2,"11.exe");

	f1[0]=argv[5][0];
	f2[1]=argv[5][1];

	//---------------------------------
		if(strcmp(f1,"11.exe")==0)
		{


		ifstream f1(use_con?temp[2]:argv[1]);
		if(!f1)
		{
		  error("FontCon.exe",use_con?temp[2]:argv[1],TRUE);
		}
		ofstream f2(temp[3]);
		if(!f2)
		{
		  error("FontCon.exe",temp[3],TRUE);
		}
		 while(f1)
		 {
			char ch;
			f1.get(ch);
			if(f1.eof()==1)

			{break;}
			f2.put(ch);
		 }
		 f1.close();
		 f2.close();
		}
		else
		{

		if(spawnl(P_WAIT,f1,"",use_con?temp[2]:argv[1],temp[3],NULL)==-1)
			 error("FontCon.exe",f1,TRUE);
		}


		//----TESTED OK----------------------------
		if(strcmp(f2,"11.exe")==0)
		       {	if(rename(temp[3],use_con?temp[4]:argv[3])==-1)
				{error("FontCon.exe",use_con?temp[4]:argv[3],TRUE);}

		       }
		else
		{
		if(spawnl(P_WAIT,f2,"",temp[3],use_con?temp[4]:argv[3],NULL)==-1)
			 error("FontCon.exe",f2,TRUE);
		}

      /*	int res=spawnl(P_WAIT,argv[5],"",use_con?temp[2]:argv[1],use_con?temp[3]:argv[3],NULL);
	if(res==-1)
		{
			error("FontCon.exe",argv[5],TRUE);
		}
	*/


	if(use_con!=0)
	{
	gotoxy(39,13);
	textcolor(YELLOW);
	cprintf("Creating Output File");
	filecon output(temp[4],argv[3],"1",argv[4]);
	output.convert_file();
	}
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
	int res=spawnl(P_WAIT,"startcd.exe","",argv[3],NULL);
	if(res==-1)
		error("FileConv.exe","startcd.exe",TRUE);

}
void rem()
{
for(int i=1;i<6;i++)
remove(temp[i]);
ofstream log("log.txt",ios::app);
log<<"\n\r------\n\r";
log.close();
}
#pragma exit rem