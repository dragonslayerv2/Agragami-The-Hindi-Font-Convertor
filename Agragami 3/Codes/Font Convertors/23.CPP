#include"..\\header\\header.h"
#include"..\\header\\dialog.h"
#include"..\\header\\boxes.h"
#include"..\\header\\error.h"

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
	if(spawnl(P_WAIT,"21.exe","",argv[1],temp,NULL)==-1)
			error("23.exe","21.exe",TRUE);
	if(ifstream(temp)==FALSE)
			error("23.exe",temp,TRUE);
	if(spawnl(P_WAIT,"13.exe","",temp,argv[2],NULL)==-1)
			error("23.exe","13.exe",TRUE);
}