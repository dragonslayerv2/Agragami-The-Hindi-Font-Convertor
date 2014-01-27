#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<dos.h>


class uninstaller
{
		char file[50][_MAX_PATH];
		int total;
		char set_file[_MAX_PATH];
	public:
		uninstaller(char f[]){total=0;strcpy(set_file,f);}
		void getfiles();
		void uninstall();
};

void uninstaller::getfiles()
	{
	ifstream in;
	in.open(set_file);
	if(!in)
		error("Uninstaller",set_file,TRUE);

	for(int i=1;in;i++)
		{
			in.getline(file[i],_MAX_PATH);
		}
	total=i-2;
}
void uninstaller::uninstall()
{
	for(int i=1;i<=total;i++)
	{
		cprintf("Deleting %s...",file[i]);
		delay(20);
		if(remove(file[i])==-1)
		{
			cprintf("    ERROR: %s",strerror(errno));
		}
		else
			cprintf("      Deleted.");
		cprintf("\n\r");
	}
}
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		usage();
	}
	if(strcmp(argv[2],"+y")==0)
	{
		uninstaller ob(argv[1]);
		ob.getfiles();
		ob.uninstall();
	}
}