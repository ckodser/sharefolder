#include<iostream>
#include<fstream>
using namespace std;
 
int main(){
	fstream my_file;
	my_file.open("/proc/version", ios::in);
	fstream my_file2;
	my_file2.open("Linux Version.txt", ios::out);
	if(!my_file){
		cout<<"FAIL to read!";
		return 0;
	}
	else if(!my_file2){
		cout<<"FAIL to write!";		
		return 0;
	}else{
		char ch;
		while(1){
			my_file >>ch;
			if(my_file.eof()){
				break;
			}
			my_file2<<ch;
		}
	}
	my_file2.close();
	my_file.close();
	cout<<"Done\n";
	return 0;
}
