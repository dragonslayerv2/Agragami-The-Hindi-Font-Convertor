
#include<fstream.h>
#include<string.h>
#include<process.h>
void main()
{
	ofstream sa("send.dat",ios::app);
	char a[]={"\n*************************** Kruti Dev to Webdunia ***********************\n"};
	sa<<a;
	sa.close();
	//*****************INPUT PHASE ************************************
	char indata[4096],outdata[4096];
	ifstream in;
	int j;
	spawnl(P_WAIT,"31.exe",NULL);

	in.open("o.tmp");

	for(int i=0;in!=0;i++)
		{
			in.get(indata[i]);
		}
	indata[i-1]='\0';
	in.close();

	ofstream out;
	out.open("i.tmp");
	for(i=0;indata[i]!='\0';i++)
		{
			out.put(indata[i]);
		}
	out.close();

	spawnl(P_WAIT,"12.exe",NULL);
	sa.open ("send.dat",ios::app);
	sa<<a;
	sa.close();
	//*****************************************************************************
}