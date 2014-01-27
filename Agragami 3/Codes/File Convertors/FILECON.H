//----------------------- Contain File Convertor Functions -------------------
class filecon
{
	char in[_MAX_PATH];
	char out[_MAX_PATH];
	char logfile[_MAX_PATH];
	char itype[5];
	char otype[5];
	public:

		filecon(char inpath[], char outpath[],char intype[],char outtype[])
		{

			if(ifstream("Conver~1.exe")==0)
			{error("CONVERT.EXE","ConvertDOc.exe",TRUE);}

			if(ifstream(inpath)==0)
				error("Convert.exe",inpath,TRUE);
			if(ifstream(outpath)!=0)
				{
					errno=EEXIST;
					error("Convert.exe",outpath,TRUE);
				}
			if(ofstream(outpath)==0)
			{
				error("Convert.exe",outpath,TRUE);
			}

			remove(outpath);

			strcpy(in,inpath);
			strcpy(out,outpath);

			strcpy(itype,intype);
			strcpy(otype,outtype);
		}

		void generate_log();
		void convert_file();
};
//---------------------------------------------------------------------------
void filecon::generate_log()
{
   ofstream log("log.txt",ios::app);
   log<<"Input File Name => "<<logfile<<"\nOutput FIle Name => "<<out;
   log<<"\nInput File Type => "<<itype<<"\nOutput FIle type=> "<<otype<<endl;
   log.close();
}
//---------------------------------------------------------------------------
void filecon::convert_file()
{
	char fileconvertor[]="Conver~1.exe";

	char inpath[_MAX_PATH]="/S";
	strcat(inpath,in);

	char intype[10]="/F";
	strcat(intype,itype);

	char outpath[_MAX_PATH]="/T";
	strcat(outpath,out);

	char outtype[10]="/C";
	strcat(outtype,otype);

	int res=spawnl(P_WAIT,fileconvertor,"",inpath,intype,outpath,outtype,NULL);	
	if(res==-1)
		{
			error("Convert.exe","ConvertDoc.exe",TRUE);
		}
}