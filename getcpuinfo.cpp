#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
 
int main(){
	
	fstream cpuinf;
	cpuinf.open("/proc/cpuinfo", ios::in);
	string s;
	for (int i=0;i<100;i++){
		cpuinf>>s;
		if(i==5){
			cout<<"CPU model :"<<s<<endl;
		}
		if(i==21){
			cout<<"CPU freq :"<<s<<endl;
		}
		if(i==35){
			cout<<"cash size :"<<s<<" kb\n";
		}
	}
	cpuinf.close();
}
