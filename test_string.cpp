#include <string>
#include <iostream>
using namespace std;
int main(){
	string s="123456";
	string s1=to_string(123);
	bool isdig=isdigit(s[0]);
	/**
	虽然有点离谱，但是s[0]确实有值，应该是随机的 
	*/ 
	s="";
	char c=s[0];
	cout<<"c:"<<c<<endl;
	isdig=isdigit(s[0]);
	cout<<isdig<<endl;
}
