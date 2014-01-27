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
			if (indata[j]=='h'&&indata[j+1]=='¥')
				{outdata[i]='#';j++;}
			else if (indata[j]=='¯'&&indata[j+1]=='t')
				{outdata[i]='ó';j++;}
			else if (indata[j]=='‹'&&indata[j+1]=='t')
				{outdata[i]='ò';j++;}
			else	if (indata[j]=='º'&&indata[j+1]=='t')
				{outdata[i]='=';j++;}
			else	if (indata[j]=='Ò'&&indata[j+1]=='t')
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
				case '*':outdata[i]='¹';break;
				case 'H':outdata[i]='&';break;
				case 'P':outdata[i]='¹';break;
				case '[':outdata[i]='ª';break;
				case '_':outdata[i]='&';break;
				case '~':outdata[i]='·';break;	
				case '¡':outdata[i]='q';break;
				case '¤':outdata[i]='Œ';break;	
				case '¦':outdata[i]='Û';break;
				case '§':outdata[i]='[';i++;outdata[i]='k';i++;outdata[i]='z';break;
				case '¨':outdata[i]='Y';i++;outdata[i]='y';break;
				case '«':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='H';i++;outdata[i]='k';break;
				case '¬':outdata[i]='­';i++;outdata[i]='ô';break;
				case '®':outdata[i]='f';i++;outdata[i]='a';break;
				case '¯':outdata[i]='L';i++;outdata[i]='×';break;	
				case '²':outdata[i]='\"';i++;outdata[i]='B';break;
				case '³':outdata[i]='\"';i++;outdata[i]='V';break;
				case '¸':outdata[i]='~';i++;outdata[i]='x';break;
				case '¹':outdata[i]='I';i++;outdata[i]='R';break;
				case '»':outdata[i]='+';break;
				case '¾':outdata[i]='¤';break;
				case 'Â':outdata[i]='f';break;
				case 'Ã':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='c';break;
				case 'Ê':outdata[i]='á';break;
				case '×':outdata[i]='í';i++;outdata[i]='z';break;
				case 'Ù':outdata[i]='B';i++;outdata[i]='~';i++;outdata[i]='B';break;
				case 'Ş':outdata[i]='z';break;
				case 'ê':outdata[i]='<';i++;outdata[i]='~';i++;outdata[i]='<';break;
				case 'ì':outdata[i]='n';i++;outdata[i]='~';i++;outdata[i]='u';break;
				case 'ï':outdata[i]='L';i++;outdata[i]='U';break;
				case 'ğ':outdata[i]='å';break;
				case 'ò':outdata[i]='º';i++;outdata[i]='y';break;
				case 'õ':outdata[i]=')';break;
				case '÷':outdata[i]='~';i++;outdata[i]='e';break;
				case 'œ':outdata[i]='w';break;
				case 'Ÿ':outdata[i]='õ';break;
				case 'ˆ':outdata[i]='\'';break;

				case 'µ':outdata[i]='~';i++;outdata[i]='d';break;
				case '–':outdata[i]='ô';break;
				case '‚':outdata[i]='a';break;
				case '“':outdata[i]='n';i++;outdata[i]='z';break;
				case '„ ':outdata[i]='~';i++;outdata[i]='o';break;
				case '‡':outdata[i]='Ü';break;
				case '•':outdata[i]='º';i++;outdata[i]='.';i++;outdata[i]='k';break;
				case '‰':outdata[i]='&';break;
				case '‹':outdata[i]='L';i++;outdata[i]='×';break;
				case '™':outdata[i]='T';i++;outdata[i]='T';break;
				case '·':outdata[i]='¡';break;

				case 'ø':outdata[i]='Z';i++;outdata[i]='a';break;
				case 'Í':outdata[i]='Ö';break;
				case 'Õ':outdata[i]='ê';break;
				case 'æ':outdata[i]='í';break;
				case 'Ó':outdata[i]='î';break;
				case '±':outdata[i]='¤';break;
				case'â':outdata[i]='¡';break;
				case 'Ø':outdata[i]='ö';break;
				case '›':outdata[i]='²';break;
				case 'Ü':outdata[i]='¶';break;
				case '©':outdata[i]='¸';break;
				case 'ñ':outdata[i]='º';break;
				case '|':outdata[i]='¾';break;
				case 'Ä':outdata[i]='Ğ';break;
				case 'í':outdata[i]='\"';break;
				case '†':outdata[i]='â';break;
				case 'Ñ':outdata[i]='ã';break;
				case 'ÿ':outdata[i]='ä';break;
				case '’':outdata[i]='å';break;
				case 'ª':outdata[i]='U';i++;outdata[i]='U';break;
				case 'G':outdata[i]='Õ';break;
				case 'è':outdata[i]='ë';break;
				case 'È':outdata[i]='ì';break;
				case 'Æ':outdata[i]='/';break;
				case 'N':outdata[i]='Ó';break;
				case 'Û':outdata[i]='ï';break;
				case '”':outdata[i]='P';outdata[i+1]='P';i++;break;
				case 'ú':outdata[i]='Ù';break;
				case '£':outdata[i]='à';break;
				
				case 'ü':outdata[i]='s';outdata[i+1]='a';i++;break;
				case 'î':outdata[i]='S';outdata[i+1]='a';i++;break;
				case 'Š':outdata[i]='æ';break;
				case 'Œ':outdata[i]='ç';break;
				case 'Ò':outdata[i]='K';break;
				case 'º':outdata[i]='×';break;
				case 'é':outdata[i]='h';outdata[i+1]='a';i++;break;	
				case 'ı':outdata[i]='g';outdata[i+1]='q';i++;break;
				case 'ş':outdata[i]='g';outdata[i+1]='w';i++;break;
				case 'w':outdata[i]='q';break;
				case 'q':outdata[i]='w';break;
				case 'b':outdata[i]='e';break;
				case ';':outdata[i]='r';break;
				case 's':outdata[i]='t';break;
				case '˜':outdata[i]='y';break;
				case 'l':outdata[i]='u';break;
				case 'v':outdata[i]='i';break;
				case 'J':outdata[i]='o';break;
				case 'a':outdata[i]='p';break;
				case 'Ï':outdata[i]='[';break;
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
				case 'ë':outdata[i]='\'';break;
				case '{':outdata[i]='z';break;
				case 'd':outdata[i]='x';break;
				case 'c':outdata[i]='c';break;
				case 'y':outdata[i]='v';break;
				case 'R':outdata[i]='b';break;
				case '=':outdata[i]='n';break;
				case 'W':outdata[i]='m';break;
				case 'Y':outdata[i]=',';break;
				case 'ã':outdata[i]='.';break;
				case '¥':outdata[i]='Q';break;
				case 'p':outdata[i]='W';break;
				case 'ö':outdata[i]='E';break;
				case 'À':outdata[i]='R';break;
				case 'ß':outdata[i]='T';break;
				case 'Ö':outdata[i]='Y';break;
				case 'à':outdata[i]='U';break;
				case 'Ë':outdata[i]='I';break;
				case 'Ô':outdata[i]='O';break;
				case 'å':outdata[i]='P';break;
				case 'Ì':outdata[i]='{';break;
				case 'Å':outdata[i]='}';break;
				case '>':outdata[i]='A';break;
				case 'i':outdata[i]='S';break;
				case '¢':outdata[i]='D';break;
				case 'Ú':outdata[i]='F';break;
				case 'B':outdata[i]='G';break;
				case 'Ç':outdata[i]='H';break;
				case '¶':outdata[i]='J';break;
				case 'ô':outdata[i]='L';break;
				case 'Á':outdata[i]=':';break;
				case 'o':outdata[i]='Z';break;
				case 'É':outdata[i]='X';break;
				case 'ç':outdata[i]='C';break;
				case 'x':outdata[i]='V';break;
				case 'X':outdata[i]='B';break;
				case 'A':outdata[i]='N';break;
				case 'z':outdata[i]='M';break;
				case 'Z':outdata[i]='<';break;
				case 'S':outdata[i]='>';break;
				case 'Î':outdata[i]='?';break;
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
				case '°':outdata[i]=')';break;
				case '}':outdata[i]='_';break;
				case '\\':outdata[i]='+';break;
				case '‘':outdata[i]='|';break;
				case 10:outdata[i]=10;break;
				case '\t':outdata[i]='\t';break;
				case ' ':outdata[i]=' ';break;
				case 'j':outdata[i]='y';break;
				case '\'':outdata[i]='Û';break;
				case '/':outdata[i]='@';break;
				case 'Q':outdata[i]='Å';break;
				case 'E':outdata[i]='³';break;
				case 'U':i--;break;
				case 'O':outdata[i]='*';break;
				case 'D':outdata[i]='Ä';break;
				case 'F':outdata[i]='Â';break;
				case 'K':outdata[i]='Æ';break;
				case 'L':outdata[i]='£';break;
				case ':':outdata[i]='É';break;
				case '\"':outdata[i]='Ì';break;
				case 'C':outdata[i]='Ò';break;
				case 'V':outdata[i]='Q';break;

				case 'M':outdata[i]='Ô';break;
				case '`':outdata[i]='¬';break;
				case '@':outdata[i]='´';break;
				case '#':outdata[i]='*';break;
				case '$':outdata[i]='&';break;
				case '^':outdata[i]='»';break;
				case '(':outdata[i]='¼';break;
				case ')':outdata[i]='½';break;
				default: outdata[i]='\t';stat.wrong++;sa<<indata[j]<<'\t';break;
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
		if(stat.wrong==0)
		sa<<"NO ERRORS!!!";
sa.close();
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