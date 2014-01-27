#include"..\\header\\header.h"
#include"..\\header\\dialog.h"
#include"..\\header\\error.h"
#include"..\\header\\boxes.h"
#include"fontcon.h"
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		usage();
		getch();
		exit(1);
	}
	char temp[_MAX_PATH];
	tmpnam(temp);
	if(spawnl(P_WAIT,"31.exe","",argv[1],temp,NULL)==-1)
			error("23.exe","31.exe",TRUE);
	if(ifstream(temp)==FALSE)
			error("23.exe",temp,TRUE);
	if(spawnl(P_WAIT,"12.exe","",temp,argv[2],NULL)==-1)
			error("23.exe","12.exe",TRUE);
}