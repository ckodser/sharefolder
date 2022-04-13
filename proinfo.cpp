#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<unistd.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<cstring>

using namespace std;
 
int main(int argc, char *argv[]){
	string pid= (argv[1]);
	
	fstream mem;
	mem.open("/proc/"+pid+"/statm", ios::in);
	cout<<"total memory usage = ";
	string s;
	mem>>s;
	int memusage=stoi(s);
	cout<<memusage*4096<<" byte"<<endl;
	mem.close();

	fstream status;
	status.open("/proc/"+pid+"/status", ios::in);
	cout<<"proc name =  ";
	status>>s;
	status>>s;
	cout<<s<<endl;
	status.close();

	char buf[1000];
	char symlink[100];
	string link="/proc/"+pid+"/exe"; 	
	strcpy(symlink, link.c_str());
	ssize_t nbytes;	
	nbytes=readlink(symlink,buf, 1000);
	printf("exe link: '%.*s'\n", (int)nbytes, buf);


	fstream cmdl;
	cmdl.open("/proc/"+pid+"/cmdline", ios::in);
	cout<<"command =  ";
	while (1){
		cmdl>>s;		
		cout<<s<<' ';
		if(cmdl.eof()){
			cout<<endl;
			break;
		}
	}
	cmdl.close();
}











