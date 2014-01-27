#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
               printf("Error: Unsufficient arguments.\nUsage: startcd [path of file to open]");
               getch();
               exit(1);
               }
               
                system(argv[1]);
}
