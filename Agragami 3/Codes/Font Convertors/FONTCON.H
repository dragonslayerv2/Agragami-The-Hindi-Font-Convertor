//---------------------- Contain Font Converting Functions-------------------
class fontcon
{
	ofstream log;
	ifstream in;
	ofstream out;
	char name[100];
	char indata[25000];
	char outdata[30000];

	public:
	struct
	{
		int charac;
		int wrong;

	}stat;


		fontcon(char nm[],char inpath[], char outpath[])
		{
			_setcursortype(_NOCURSOR);
			strcpy(name,nm);
			in.open(inpath);
			if(in==0)
				{
					error("Font Convertor",inpath,TRUE);
				}

			out.open(outpath);
			if(out==0)
				{	error("Font Convertor",outpath,TRUE);
				}
			log.open("log.txt",ios::app);
			if(log==0)
			{
				error("Font Convertor","log.txt",TRUE);
			}
			stat.charac=0;
			stat.wrong=0;
		}

		~fontcon()
		{
			in.close();
			out.close();
			log.close();
		}
		void generate_log();
		void getdata();
		void putdata();
		void convert();
};
//---------------------------------------------------------------------------
void fontcon::generate_log()
{

			log<<"\n\rConversion Type: "<<name<<endl<<"Total Errors => ";

			if(stat.wrong==0)
				log<<"NO ERRORS!!!";
			else
				log<<stat.wrong;

			log<<"\nTotal Characters => "<<stat.charac;
			
}
//---------------------------------------------------------------------------
void fontcon::getdata()
{
	for(int i=0;in!=FALSE&&i<24950;i++)
	{
		in.get(indata[i]);
	}

       indata[i-1]='\0';
       stat.charac=i;
       in.close();
}
//---------------------------------------------------------------------------
void fontcon::putdata()
{
	for(int i=0;outdata[i]!='\0';i++)
		{
			out.put(outdata[i]);
		}
	out.close();
}
//--------------------------------------------------------------------------
