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
					outdata[i]='Ì';
					j++;
				}

					else if(indata[j]=='\"'&&indata[j+1]=='k')
				{
					outdata[i]='Ô';
					j++;
				}

				else if(indata[j]=='{'&&indata[j+1]=='k')
				{
					outdata[i]='Õ';
					j++;
				}
				else if(indata[j]=='g'&&indata[j+1]=='~'&&indata[j+2]=='o')
				{
					outdata[i]='à';
					j++;
					j++;
				}
				else if(indata[j]=='g'&&indata[j+1]=='z')
				{
					outdata[i]='Ğ';
					j++;
				}
				else if(indata[j]=='v'&&indata[j+1]=='k'&&indata[j+2]=='S')
				{
					outdata[i]='Ñ';
					j+=2;
				}
				else if(indata[j]=='n'&&indata[j+1]=='~'&&indata[j+2]=='x')
				{
					outdata[i]='å';
					j+=2;
				}
				else if(indata[j]==','&&indata[j+1]=='W')
				{
					outdata[i]='Ê';
					j++;
				}
				else if(indata[j]=='F'&&indata[j+1]=='k')
				{
					outdata[i]='É';
					j++;
				}



				else if(indata[j]=='.'&&indata[j+1]=='k')
				{
					outdata[i]='Æ';
					j++;
				}
				else if(indata[j]=='['&&indata[j+1]=='k')
				{
					outdata[i]='Â';
					j++;
				}
				else if(indata[j]=='v'&&indata[j+1]=='k')
				{
					outdata[i]='Á';
					j++;
				}
				else if(indata[j]=='­'&&indata[j+1]=='®')
				{
					outdata[i]='k';
					i++;
					outdata[i]='s';
					j++;
				}
				else if(indata[j]=='Å'&&indata[j+1]=='¡')
				{
					outdata[i]='¬';
					j++;
				}

				else
				{
			switch(indata[j])
				{
				case '®':outdata[i]='¨';break;
				case 'Ê':outdata[i]='h';i++;outdata[i]='Z';break;
				case 'Ï':outdata[i]='ì';break;
				case '÷':outdata[i]='Ö';break;
				case 'ø':outdata[i]='¿';break;
				case 'ù':outdata[i]='ö';break;
				case 'Œ':outdata[i]='0';break;
				case 'Š':outdata[i]='8';break;
				case 'Ÿ':outdata[i]='Ù';break;
				case 'ƒ':outdata[i]='1';break;
				case 'ˆ':outdata[i]='6';break;
				case '˜':outdata[i]='ö';break;
				case '–':outdata[i]='n';i++;outdata[i]='`';break;
				case '—':outdata[i]='d';i++;outdata[i]='`';break;
				case '‚':outdata[i]='k';i++;outdata[i]='W';break;
				case '„':outdata[i]='2';break;
				case '†':outdata[i]='4';break;
				case '‡':outdata[i]='5';break;
				case '…':outdata[i]='3';break;
				case '‰':outdata[i]='7';break;
				case '‹':outdata[i]='9';break;
				case '›':outdata[i]='S';i++;outdata[i]='Z';i++;outdata[i]='a';break;
				case '™':outdata[i]='U';i++;outdata[i]='U';break;
				case '“':outdata[i]='\'';break;
				case '”':outdata[i]='\'';break;
				case '‘':outdata[i]='\"';break;
				case '’':outdata[i]='\"';break;

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
				case '¡':outdata[i]='¡';break;
				case '¢':outdata[i]='s';break;
				case '£':outdata[i]='[';i++;outdata[i]='k';i++;outdata[i]='z';break;
				case 'Æ':outdata[i]='£';break;
				case '¤':outdata[i]='¤';break;
				case '¥':outdata[i]='´';break;

				case '§':outdata[i]='¤';break;
				case '¨':outdata[i]='¨';break;
				case '©':outdata[i]='©';break;
				case 'ª':outdata[i]='ª';break;
				case '«':outdata[i]='×';break;

				case '±':outdata[i]='±';break;
				case '³':outdata[i]='³';break;
				case '´':outdata[i]='´';break;

				case '¶':outdata[i]='¶';break;
				case '·':outdata[i]='·';break;
				case '¸':outdata[i]='¸';break;
				case 'º':outdata[i]='º';break;
				case '»':outdata[i]='»';break;
				case '¼':outdata[i]='¼';break;
				case '½':outdata[i]='½';break;
				case '¾':outdata[i]='¾';break;
				case '¿':outdata[i]='¿';break;
				case 'À':outdata[i]='À';break;
				case 'Á':outdata[i]='i';i++;outdata[i]='z';break;
				case 'Ã':outdata[i]='Ã';break;
				case 'Ä':outdata[i]='Ä';break;
				case 'Å':outdata[i]='Å';break;

				case 'Ç':outdata[i]='f';i++;outdata[i]='a';break;
				case 'È':outdata[i]='h';i++;outdata[i]='a';break;
				case 'É':outdata[i]='²';break;
				case 'Ê ':outdata[i]='h';i++;outdata[i]='Z';break;
				case 'Ë':outdata[i]='/';break;
				case 'Ì':outdata[i]='í';break;
				case 'Í':outdata[i]='ê';break;
				case 'Î':outdata[i]='ë';break;
				case 'Ñ':outdata[i]='d';i++;outdata[i]='`';break;
				case 'Ò':outdata[i]='Ò';break;
				case 'Ó':outdata[i]='î';break;
				case '\'k':outdata[i]='Ó';break;
				case 'Ô':outdata[i]='ï';break;
				case 'Ö':outdata[i]='Ö';break;

				case 'Ø':outdata[i]='Ø';break;
				case 'Ù':outdata[i]='Ù';break;
				case 'Ú':outdata[i]='Ú';break;
				case 'Û':outdata[i]='Û';break;
				case 'Ü':outdata[i]='Ü';break;
				case 'İ':outdata[i]='İ';break;
				case 'Ş':outdata[i]='Ş';break;
				case 'ß':outdata[i]='ß';break;
				case 'à':outdata[i]='g';i++;outdata[i]='~';i++;outdata[i]='u';break;
				case 'á':outdata[i]='á';break;
				case 'â':outdata[i]='â';break;
				case 'ã':outdata[i]='ã';break;
				case 'ä':outdata[i]='ä';break;
				case 'å':outdata[i]='0';break;
				case 'æ':outdata[i]='æ';break;
				case 'ç':outdata[i]='ç';break;
				case 'è':outdata[i]='è';break;
				case 'é':outdata[i]='é';break;
				case 'ê':outdata[i]='ê';break;
				case 'ë':outdata[i]='ë';break;
				case 'ì':outdata[i]='ì';break;
				case 'í':outdata[i]='í';break;
				case 'î':outdata[i]='î';break;
				case 'ï':outdata[i]='ï';break;
				case 'ğ':outdata[i]='B';i++;outdata[i]='~';i++;outdata[i]='B';break;

				case 'ñ':outdata[i]='ñ';break;
				case 'ò':outdata[i]='ò';break;
				case 'ó':outdata[i]='ó';break;
				case 'ô':outdata[i]='ô';break;
				case 'õ':outdata[i]='S';i++;outdata[i]='Z';i++;outdata[i]='a';break;

				case 'ö':outdata[i]='ö';break;
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