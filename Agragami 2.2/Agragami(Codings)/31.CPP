#include<fstream.h>
#include<string.h>
void main()
{
	ofstream sa("send.dat",ios::app);
	char a[]={"Kruti Dev to True Type\n"};
	sa<<a;
	//*****************INPUT PHASE ************************************
	char indata[4096],outdata[4096];
	ifstream in;
	int j;
	in.open("i.tmp");
	for(int i=0;in!=0;i++)
		{
			in.get(indata[i]);
		}
	indata[i-1]='\0';
	in.close();

	struct statistics
	{
		int charac;
		int wrong;
	};
	statistics s;
	s.wrong=0;
	//*****************CONVERTOR PHASE*********************************************
	for(i=0,j=0;indata[j]!='\0';i++,j++)
		{


				if(indata[j]=='/'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}

					else if(indata[j]=='\"'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}

				else if(indata[j]=='{'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='g'&&indata[j+1]=='~'&&indata[j+2]=='o')
				{
					outdata[i]='�';
					j++;
					j++;
				}
				else if(indata[j]=='g'&&indata[j+1]=='z')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='v'&&indata[j+1]=='k'&&indata[j+2]=='S')
				{
					outdata[i]='�';
					j+=2;
				}
				else if(indata[j]=='n'&&indata[j+1]=='~'&&indata[j+2]=='x')
				{
					outdata[i]='�';
					j+=2;
				}
				else if(indata[j]==','&&indata[j+1]=='W')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='F'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}



				else if(indata[j]=='.'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='['&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='v'&&indata[j+1]=='k')
				{
					outdata[i]='�';
					j++;
				}
				else if(indata[j]=='�'&&indata[j+1]=='�')
				{
					outdata[i]='k';
					i++;
					outdata[i]='s';
					j++;
				}
				else if(indata[j]=='�'&&indata[j+1]=='�')
				{
					outdata[i]='�';
					j++;
				}

				else
				{
			switch(indata[j])
				{
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='h';i++;outdata[i]='Z';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='0';break;
				case '�':outdata[i]='8';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='1';break;
				case '�':outdata[i]='6';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='n';i++;outdata[i]='`';break;
				case '�':outdata[i]='d';i++;outdata[i]='`';break;
				case '�':outdata[i]='k';i++;outdata[i]='W';break;
				case '�':outdata[i]='2';break;
				case '�':outdata[i]='4';break;
				case '�':outdata[i]='5';break;
				case '�':outdata[i]='3';break;
				case '�':outdata[i]='7';break;
				case '�':outdata[i]='9';break;
				case '�':outdata[i]='S';i++;outdata[i]='Z';i++;outdata[i]='a';break;
				case '�':outdata[i]='U';i++;outdata[i]='U';break;
				case '�':outdata[i]='\'';break;
				case '�':outdata[i]='\'';break;
				case '�':outdata[i]='\"';break;
				case '�':outdata[i]='\"';break;

				case '!':outdata[i]='!';break;
				case '\"':outdata[i]='\"';break;
				case '#':outdata[i]='#';break;
				case '$':outdata[i]='$';break;
				case '%':outdata[i]='%';break;
				case '&':outdata[i]='&';break;
				case '\'':outdata[i]='\'';break;
				case '(':outdata[i]='(';break;
				case ')':outdata[i]=')';break;
				case '*':outdata[i]='*';break;
				case '+':outdata[i]='+';break;
				case ',':outdata[i]=',';break;
				case '-':outdata[i]='-';break;
				case '.':outdata[i]='.';break;
				case '/':outdata[i]='/';break;
				case '0':outdata[i]='0';break;
				case '1':outdata[i]='1';break;
				case '2':outdata[i]='2';break;
				case '3':outdata[i]='3';break;
				case '4':outdata[i]='4';break;
				case '5':outdata[i]='5';break;
				case '6':outdata[i]='6';break;
				case '7':outdata[i]='7';break;
				case '8':outdata[i]='8';break;
				case '9':outdata[i]='9';break;
				case ':':outdata[i]=':';break;
				case ';':outdata[i]=';';break;
				case '<':outdata[i]='<';break;
				case '=':outdata[i]='=';break;
				case '>':outdata[i]='>';break;
				case '?':outdata[i]='?';break;
				case '@':outdata[i]='@';break;
				case 'A':outdata[i]='A';break;
				case 'B':outdata[i]='B';break;
				case 'C':outdata[i]='C';break;
				case 'D':outdata[i]='D';break;
				case 'E':outdata[i]='E';break;
				case 'F':outdata[i]='F';break;
				case 'G':outdata[i]='G';break;
				case 'H':outdata[i]='H';break;
				case 'I':outdata[i]='I';break;
				case 'J':outdata[i]='J';break;
				case 'K':outdata[i]='K';break;
				case 'L':outdata[i]='L';break;
				case 'M':outdata[i]='M';break;
				case 'N':outdata[i]='N';break;
				case 'O':outdata[i]='O';break;
				case 'P':outdata[i]='P';break;
				case 'Q':outdata[i]='Q';break;
				case 'R':outdata[i]='R';break;
				case 'S':outdata[i]='S';break;
				case 'T':outdata[i]='T';break;
				case 'U':outdata[i]='U';break;
				case 'V':outdata[i]='V';break;
				case 'W':outdata[i]='W';break;
				case 'X':outdata[i]='X';break;
				case 'Y':outdata[i]='Y';break;
				case 'Z':outdata[i]='Z';break;
				case '[':outdata[i]='[';break;
				case '\\':outdata[i]='\\';break;
				case ']':outdata[i]=']';break;
				case '^':outdata[i]='^';break;
				case '_':outdata[i]='_';break;
				case '`':outdata[i]='`';break;
				case 'a':outdata[i]='a';break;
				case 'b':outdata[i]='b';break;
				case 'c':outdata[i]='c';break;
				case 'd':outdata[i]='d';break;
				case 'e':outdata[i]='e';break;
				case 'f':outdata[i]='f';break;
				case 'g':outdata[i]='g';break;
				case 'h':outdata[i]='h';break;
				case 'i':outdata[i]='i';break;
				case 'j':outdata[i]='j';break;
				case 'k':outdata[i]='k';break;
				case 'l':outdata[i]='l';break;
				case 'm':outdata[i]='m';break;
				case 'n':outdata[i]='n';break;
				case 'o':outdata[i]='o';break;
				case 'p':outdata[i]='p';break;
				case 'q':outdata[i]='q';break;
				case 'r':outdata[i]='r';break;
				case 's':outdata[i]='s';break;
				case 't':outdata[i]='t';break;
				case 'u':outdata[i]='u';break;
				case 'v':outdata[i]='v';break;
				case 'w':outdata[i]='w';break;
				case 'x':outdata[i]='x';break;
				case 'y':outdata[i]='y';break;
				case 'z':outdata[i]='z';break;
				case '{':outdata[i]='{';break;
				case '|':outdata[i]='|';break;
				case '}':outdata[i]='}';break;
				case '~':outdata[i]='~';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='s';break;
				case '�':outdata[i]='[';i++;outdata[i]='k';i++;outdata[i]='z';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='i';i++;outdata[i]='z';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='f';i++;outdata[i]='a';break;
				case '�':outdata[i]='h';i++;outdata[i]='a';break;
				case '�':outdata[i]='�';break;
				case '� ':outdata[i]='h';i++;outdata[i]='Z';break;
				case '�':outdata[i]='/';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='d';i++;outdata[i]='`';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '\'k':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='g';i++;outdata[i]='~';i++;outdata[i]='u';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='0';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='B';i++;outdata[i]='~';i++;outdata[i]='B';break;

				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='S';i++;outdata[i]='Z';i++;outdata[i]='a';break;

				case '�':outdata[i]='�';break;
				case'\t':outdata[i]='\t';break;
				case 10:outdata[i]=10;break;
				case ' ':outdata[i]=' ';break;
				default: outdata[i]='\t';s.wrong++;sa<<indata[j]<<'\t';break;
				}}
		}
	if(s.wrong==0)
		sa<<"NO ERRORS!!!";
	s.charac=i;
	sa<<"\nTotal Characters: "<<s.charac;

	sa<<"\n-------------------------------------------------------------------------\n";
	ofstream stat("stat.dat");
	stat.write((char *)&s,sizeof(s));
	stat.close();
	outdata[i]='\0';
	//********************OUTPUT PHASE*********************************************
	ofstream out;
	out.open("o.tmp");
	for(i=0;outdata[i]!='\0';i++)
		{
			out.put(outdata[i]);
		}
	out.close();
	//*****************************************************************************
}