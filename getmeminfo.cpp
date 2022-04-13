#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
 
int main(){
	
	fstream meminf;
	meminf.open("/proc/meminfo", ios::in);
	string s;
	long long total=0;
	for (int i=0;i<100;i++){
		meminf>>s;
		if(i==1){
			cout<<"Total memory :"<<s<<" Kb"<<endl;
			total=stoi(s);
		}
		if(i==4){
			cout<<"Free memory :"<<s<<" Kb\n";
			cout<<"used memory :"<<total-stoi(s)<<" Kb\n";
		}
	}
	meminf.close();
}
