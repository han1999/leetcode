#include <string>
#include <iostream>
using namespace std;
int main(){
	string s="123456";
	string s1=to_string(123);
	bool isdig=isdigit(s[0]);
	/**
	��Ȼ�е����ף�����s[0]ȷʵ��ֵ��Ӧ��������� 
	*/ 
	s="";
	char c=s[0];
	cout<<"c:"<<c<<endl;
	isdig=isdigit(s[0]);
	cout<<isdig<<endl;
}
