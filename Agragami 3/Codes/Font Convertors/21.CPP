#include"..\\header\\header.h"
#include"..\\header\\dialog.h"
#include"..\\header\\error.h"
#include"..\\header\\boxes.h"
#include"fontcon.h"
//--------------------------------------------------------------------------
void fontcon::convert()
{      
	 for(int i=0,j=0;indata[j]!='\0'&&i<29998&&j<24950;i++,j++)
		{
			if (indata[j]=='h'&&indata[j+1]=='�')
				{outdata[i]='#';j++;}
			else if (indata[j]=='�'&&indata[j+1]=='t')
				{outdata[i]='�';j++;}
			else if (indata[j]=='�'&&indata[j+1]=='t')
				{outdata[i]='�';j++;}
			else	if (indata[j]=='�'&&indata[j+1]=='t')
				{outdata[i]='=';j++;}
			else	if (indata[j]=='�'&&indata[j+1]=='t')
				{outdata[i]='K';j++;}
			else if (indata[j]=='\\'&&indata[j+1]=='z' )
				{
				outdata[i]='M';outdata[i+1]='+';i++;j++;
				}
			else if (indata[j]=='\\'&&indata[j+1]=='Z' )
				{
				outdata[i]='<';outdata[i+1]='+';i++;j++;
				}

			else
				switch(indata[j])
				{
				case '%':outdata[i]='i';i++;outdata[i]='z';i++;outdata[i]='f';i++;outdata[i]='r';i++;outdata[i]='\'';i++;outdata[i]='k';i++;outdata[i]='r';break;
				case '*':outdata[i]='�';break;
				case 'H':outdata[i]='&';break;
				case 'P':outdata[i]='�';break;
				case '[':outdata[i]='�';break;
				case '_':outdata[i]='&';break;
				case '~':outdata[i]='�';break;	
				case '�':outdata[i]='q';break;
				case '�':outdata[i]='�';break;	
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='[';i++;outdata[i]='k';i++;outdata[i]='z';break;
				case '�':outdata[i]='Y';i++;outdata[i]='y';break;
				case '�':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='H';i++;outdata[i]='k';break;
				case '�':outdata[i]='�';i++;outdata[i]='�';break;
				case '�':outdata[i]='f';i++;outdata[i]='a';break;
				case '�':outdata[i]='L';i++;outdata[i]='�';break;	
				case '�':outdata[i]='\"';i++;outdata[i]='B';break;
				case '�':outdata[i]='\"';i++;outdata[i]='V';break;
				case '�':outdata[i]='~';i++;outdata[i]='x';break;
				case '�':outdata[i]='I';i++;outdata[i]='R';break;
				case '�':outdata[i]='+';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='f';break;
				case '�':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='c';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';i++;outdata[i]='z';break;
				case '�':outdata[i]='B';i++;outdata[i]='~';i++;outdata[i]='B';break;
				case '�':outdata[i]='z';break;
				case '�':outdata[i]='<';i++;outdata[i]='~';i++;outdata[i]='<';break;
				case '�':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='u';break;
				case '�':outdata[i]='L';i++;outdata[i]='U';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';i++;outdata[i]='y';break;
				case '�':outdata[i]=')';break;
				case '�':outdata[i]='~';i++;outdata[i]='e';break;
				case '�':outdata[i]='w';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='\'';break;

				case '�':outdata[i]='~';i++;outdata[i]='d';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='a';break;
				case '�':outdata[i]='n';i++;outdata[i]='z';break;
				case '� ':outdata[i]='~';i++;outdata[i]='o';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';i++;outdata[i]='.';i++;outdata[i]='k';break;
				case '�':outdata[i]='&';break;
				case '�':outdata[i]='L';i++;outdata[i]='�';break;
				case '�':outdata[i]='T';i++;outdata[i]='T';break;
				case '�':outdata[i]='�';break;

				case '�':outdata[i]='Z';i++;outdata[i]='a';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case'�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '|':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='\"';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='U';i++;outdata[i]='U';break;
				case 'G':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='/';break;
				case 'N':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='P';outdata[i+1]='P';i++;break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				
				case '�':outdata[i]='s';outdata[i+1]='a';i++;break;
				case '�':outdata[i]='S';outdata[i+1]='a';i++;break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='K';break;
				case '�':outdata[i]='�';break;
				case '�':outdata[i]='h';outdata[i+1]='a';i++;break;	
				case '�':outdata[i]='g';outdata[i+1]='q';i++;break;
				case '�':outdata[i]='g';outdata[i+1]='w';i++;break;
				case 'w':outdata[i]='q';break;
				case 'q':outdata[i]='w';break;
				case 'b':outdata[i]='e';break;
				case ';':outdata[i]='r';break;
				case 's':outdata[i]='t';break;
				case '�':outdata[i]='y';break;
				case 'l':outdata[i]='u';break;
				case 'v':outdata[i]='i';break;
				case 'J':outdata[i]='o';break;
				case 'a':outdata[i]='p';break;
				case '�':outdata[i]='[';break;
				case ',':outdata[i]=']';break;
				case 'k':outdata[i]='a';break;
				case 'u':outdata[i]='s';break;
				case 'f':outdata[i]='d';break;
				case 'r':outdata[i]='f';break;
				case 'n':outdata[i]='g';break;
				case 'e':outdata[i]='h';break;
				case 'h':outdata[i]='j';break;
				case 't':outdata[i]='k';break;
				case 'm':outdata[i]='l';break;
				case 'g':outdata[i]=';';break;
				case '�':outdata[i]='\'';break;
				case '{':outdata[i]='z';break;
				case 'd':outdata[i]='x';break;
				case 'c':outdata[i]='c';break;
				case 'y':outdata[i]='v';break;
				case 'R':outdata[i]='b';break;
				case '=':outdata[i]='n';break;
				case 'W':outdata[i]='m';break;
				case 'Y':outdata[i]=',';break;
				case '�':outdata[i]='.';break;
				case '�':outdata[i]='Q';break;
				case 'p':outdata[i]='W';break;
				case '�':outdata[i]='E';break;
				case '�':outdata[i]='R';break;
				case '�':outdata[i]='T';break;
				case '�':outdata[i]='Y';break;
				case '�':outdata[i]='U';break;
				case '�':outdata[i]='I';break;
				case '�':outdata[i]='O';break;
				case '�':outdata[i]='P';break;
				case '�':outdata[i]='{';break;
				case '�':outdata[i]='}';break;
				case '>':outdata[i]='A';break;
				case 'i':outdata[i]='S';break;
				case '�':outdata[i]='D';break;
				case '�':outdata[i]='F';break;
				case 'B':outdata[i]='G';break;
				case '�':outdata[i]='H';break;
				case '�':outdata[i]='J';break;
				case '�':outdata[i]='L';break;
				case '�':outdata[i]=':';break;
				case 'o':outdata[i]='Z';break;
				case '�':outdata[i]='X';break;
				case '�':outdata[i]='C';break;
				case 'x':outdata[i]='V';break;
				case 'X':outdata[i]='B';break;
				case 'A':outdata[i]='N';break;
				case 'z':outdata[i]='M';break;
				case 'Z':outdata[i]='<';break;
				case 'S':outdata[i]='>';break;
				case '�':outdata[i]='?';break;
				case ']':outdata[i]='`';break;
				case '1':outdata[i]='1';break;
				case '2':outdata[i]='2';break;
				case '3':outdata[i]='3';break;
				case '4':outdata[i]='4';break;
				case '5':outdata[i]='5';break;
				case '6':outdata[i]='6';break;
				case '7':outdata[i]='7';break;
				case '8':outdata[i]='8';break;
				case '9':outdata[i]='9';break;
				case '0':outdata[i]='0';break;
				case '.':outdata[i]='-';break;
				case '?':outdata[i]='\\';break;
				case 'T':outdata[i]='~';break;
				case '!':outdata[i]='!';break;
				case '+':outdata[i]='$';break;
				case '&':outdata[i]='%';break;
				case 'I':outdata[i]='^';break;
				case '-':outdata[i]='&';break;
				case '<':outdata[i]='(';break;
				case '�':outdata[i]=')';break;
				case '}':outdata[i]='_';break;
				case '\\':outdata[i]='+';break;
				case '�':outdata[i]='|';break;
				case 10:outdata[i]=10;break;
				case '\t':outdata[i]='\t';break;
				case ' ':outdata[i]=' ';break;
				case 'j':outdata[i]='y';break;
				case '\'':outdata[i]='�';break;
				case '/':outdata[i]='@';break;
				case 'Q':outdata[i]='�';break;
				case 'E':outdata[i]='�';break;
				case 'U':i--;break;
				case 'O':outdata[i]='*';break;
				case 'D':outdata[i]='�';break;
				case 'F':outdata[i]='�';break;
				case 'K':outdata[i]='�';break;
				case 'L':outdata[i]='�';break;
				case ':':outdata[i]='�';break;
				case '\"':outdata[i]='�';break;
				case 'C':outdata[i]='�';break;
				case 'V':outdata[i]='Q';break;

				case 'M':outdata[i]='�';break;
				case '`':outdata[i]='�';break;
				case '@':outdata[i]='�';break;
				case '#':outdata[i]='*';break;
				case '$':outdata[i]='&';break;
				case '^':outdata[i]='�';break;
				case '(':outdata[i]='�';break;
				case ')':outdata[i]='�';break;
				default: outdata[i]='\t';stat.wrong++;break;
				}
			{
				textcolor(LIGHTGRAY);
				gotoxy(39,17);
				cprintf("%d",stat.wrong);
				gotoxy(39,16);
				cprintf("%d",j+1);
				gotoxy(39,18);
				cprintf("%.2f %       ",float((100-(float(stat.wrong)/(j+1))*100)));
			}
		}
	outdata[i]='\0';
}
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		usage();
		getch();
		exit(1);
	}
	fontcon convertor("Web-Dunia Fonts to True Type Font",argv[1],argv[2]);
	convertor.getdata();
	convertor.convert();
	convertor.putdata();
	convertor.generate_log();
}