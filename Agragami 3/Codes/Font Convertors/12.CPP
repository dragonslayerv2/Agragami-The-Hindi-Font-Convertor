#include"..\\header\\header.h"
#include"..\\header\\dialog.h"
#include"..\\header\\error.h"
#include"..\\header\\boxes.h"
#include"fontcon.h"
//-----------------------------------------------------------------------
void fontcon::convert()
{
	
       for(int i=0,j=0;indata[j]!='\0'&&i<29998&&j<24950;i++,j++)
		{

			switch(indata[j])
				{
				case '¨':outdata[i]='t';i++;outdata[i]='u';break;
				case '©':outdata[i]='t';i++;outdata[i]='i';break;
				case '±':outdata[i]='ø';break;
				case '¶':outdata[i]='Ü';break;
				case '¸':outdata[i]='©';break;
				case 'º':outdata[i]='ñ';break;
				case '¾':outdata[i]='|';break;
				case 'À':outdata[i]=')';break;
				case 'Á':outdata[i]='y';i++;outdata[i]='t';break;
				case '²':outdata[i]='›';break;
				case 'Ê':outdata[i]='Y';i++;outdata[i]='p';break;
				case 'í':outdata[i]='æ';break;
				case 'ê':outdata[i]='Õ';break;
				case 'ë':outdata[i]='è';break;
				case 'Ğ':outdata[i]='Ä';break;
				case 'Ñ':outdata[i]='y';i++;outdata[i]='t';i++;outdata[i]='i';break;
				case 'î':outdata[i]='Ó';break;
				case 'Ö':outdata[i]='Í';break;
				case 'Ø':outdata[i]='f';i++;outdata[i]='{';i++;outdata[i]='U';break;
				case 'İ':outdata[i]='V';i++;outdata[i]='{';break;
				case 'Ş':outdata[i]='O';i++;outdata[i]='O';break;
				case 'ß':outdata[i]='I';i++;outdata[i]='I';break;
				case 'á':outdata[i]='Ê';break;
				case 'â':outdata[i]='†';break;
				case 'ã':outdata[i]='Ñ';break;
				case 'ä':outdata[i]='ÿ';break;
				case 'å':outdata[i]='’';break;
				case 'è':outdata[i]='Æ';break;
				case 'é':outdata[i]='ª';i++;outdata[i]='t';break;
				case 'ì':outdata[i]='È';break;
				case 'ñ':outdata[i]='\'';break;
				case 'ò':outdata[i]='‹';i++;outdata[i]='t';break;
				case 'ó':outdata[i]='¯';i++;outdata[i]='t';break;
				case 'ô':outdata[i]='¬';break;

				case 'à':outdata[i]='£';break;
				case 'Ù':outdata[i]='ú';break;
				case 'æ':outdata[i]='Š';break;
				case '¿':outdata[i]='(';break;
				case 'ï':outdata[i]='Û';break;
				case 'Ã':outdata[i]='R';outdata[i+1]='o';i++;break;
				case '£':outdata[i]='L';break;
				case '¥':outdata[i]='O';break;
				/*case '¤':outdata[i]='±';break;*/
				case 'Â':outdata[i]='F';break;
				case '¤':outdata[i]='±';break;
				case '»':outdata[i]='^';break;
				case'¬':outdata[i]='`';break;
				case'Ò': outdata[i]='C';break;
				case'¼':outdata[i]='(';break;
				case'½':outdata[i]=')';break;
				case'•':outdata[i]='\'';break;
				case'¡':outdata[i]='â';break;
				case'Å':outdata[i]='Q';break;
				case '‘':outdata[i]=']';break;
				case '\'':outdata[i]='ë';break;
				case '’':outdata[i]='ë';break;
				case 'q':outdata[i]='w';break;
				case 'w':outdata[i]='q';break;
				case 'e':outdata[i]='b';break;
				case 'r':outdata[i]=';';break;
				case 't':outdata[i]='s';break;
				case 'y':outdata[i]='˜';break;
				case 'u':outdata[i]='l';break;
				case 'i':outdata[i]='v';break;
				case 'o':outdata[i]='J';break;
				case 'p':outdata[i]='a';break;
				case '[':outdata[i]='Ï';break;
				case ']':outdata[i]=',';break;
				case 'a':outdata[i]='k';break;
				case 's':outdata[i]='u';break;
				case 'd':outdata[i]='f';outdata[i+1]='U';i++;break;
				case 'f':outdata[i]='r';break;
				case 'g':outdata[i]='n';break;
				case 'h':outdata[i]='e';break;
				case 'j':outdata[i]='h';break;
				case 'k':outdata[i]='t';break;
				case 'l':outdata[i]='m';break;
				case ';':outdata[i]='g';break;
				case 'z': if(outdata[i-1]=='U')
						{
						outdata[i-1]='{';
						outdata[i]='U';
						 }
					else outdata[i]='{';
					break;
				case 'x':outdata[i]='d';break;
				case 'c':outdata[i]='c';break;
				case 'v':outdata[i]='y';break;
				case 'b':outdata[i]='R';break;
				case 'n':outdata[i]='=';break;
				case 'm':outdata[i]='W';break;
				case ',':outdata[i]='Y';break;
				case '.':outdata[i]='ã';break;
				case '/':outdata[i]='Æ';break;
				case 'Q':outdata[i]='V';break;
				case 'W':outdata[i]='p';break;
				case 'E':outdata[i]='ö';break;
				case 'R':outdata[i]='À';break;
				case 'T':outdata[i]='ß';break;
				case 'Y':outdata[i]='Ö';break;
				case 'U':outdata[i]='à';break;
				case 'I':outdata[i]='Ë';break;
				case 'O':outdata[i]='Ô';break;
				case 'P':outdata[i]='å';break;
				case '{':outdata[i]='Ì';break;
				case '}':outdata[i]='Å';break;
				case 'A':outdata[i]='>';break;
				case 'S':outdata[i]='i';break;
				case 'D':outdata[i]='¢';break;
				case 'F':outdata[i]='Ú';break;
				case 'G':outdata[i]='B';break;
				case 'H':outdata[i]='Ç';break;
				case 'J':outdata[i]='¶';break;
				case 'K':outdata[i]='Ò';outdata[i+1]='t';i++;break;
				case 'L':outdata[i]='ô';break;
				case ':':outdata[i]='Á';break;
				case '\"':outdata[i]='í';break;
				case 'Z':outdata[i]='o';break;
				case 'X':outdata[i]='É';break;
				case 'C':outdata[i]='ç';break;
				case 'V':outdata[i]='x';break;
				case 'B':outdata[i]='X';break;
				case 'N':outdata[i]='A';break;
				case 'M':outdata[i]='z';break;
				case '<':outdata[i]='Z';break;
				case '>':outdata[i]='S';break;
				case '?':outdata[i]='Î';break;
				case '`':outdata[i]=']';break;
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
				case '-':outdata[i]='.';break;
				case '=':outdata[i]='º;';outdata[i+1]='t';i++;break;
				case '\\':outdata[i]='?';break;
				case '~':outdata[i]='T';break;
				case '!':outdata[i]='!';break;
				case '@':outdata[i]='/';break;
				case '#':outdata[i]='Á';break;
				case '$':outdata[i]='+';break;
				case '%':outdata[i]='&';break;
				case '^':outdata[i]='I';break;
				case '&':outdata[i]='-';break;
				case '*':outdata[i]='I';break;
				case '(':outdata[i]='<';break;
				case ')':outdata[i]='°';break;
				case '_':outdata[i]='}';break;
				case '+':outdata[i]=outdata[i-1];outdata[i-1]='\\';break;
				case '|':outdata[i]='‘';break;
				case ' ':outdata[i]=' ';break;
				case 10 :outdata[i]='\n';break;
				case '\t':outdata[i]='\t';break;
				case 'ç':outdata[i]='Œ';break;
				case '×':outdata[i]='º';break;
				case 'ö':outdata[i]='Ø';break;
				case 'Û':outdata[i]='\'';break;
				case '³':outdata[i]='E';break;
				case 'Ä':outdata[i]='D';break;
				case 'Õ':outdata[i]='G';break;
				case 'Æ':outdata[i]='K';break;
				case 'É':outdata[i]=':';break;
				case 'Ì':outdata[i]='\"';break;
				case 'Ó':outdata[i]='N';break;
				case 'Ô':outdata[i]='M';break;
				case '´':outdata[i]='@';break;
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
		outdata[i]=NULL;

}

void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		usage();
		getch();
		exit(1);
	}
	fontcon convertor("True-Type Fonts to Web-Dunia Fonts",argv[1],argv[2]);
	convertor.getdata();
	convertor.convert();
	convertor.putdata();
	convertor.generate_log();
}