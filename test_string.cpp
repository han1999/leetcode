#include <string>
#include <iostream>
#include <vector>
using namespace std;
//int main(){
//	string s="123456";
//	string s1=to_string(123);
//	bool isdig=isdigit(s[0]);
//	/**
//	��Ȼ�е����ף�����s[0]ȷʵ��ֵ��Ӧ��������� 
//	*/ 
//	s="";
//	char c=s[0];
//	cout<<"c:"<<c<<endl;
//	isdig=isdigit(s[0]);
//	cout<<isdig<<endl;
//}

///**
//����s.replace�ĳ��Ȳ���
//*/ 
//int main(){
//	string s="123456789";
////	string s1=s.replace(s.find("4"), 0, "aaaa");//123aaaa456789
//	string s1=s.replace(s.find("4"), 10, "aaaa");//123aaaa
//	
//	cout<<s1<<endl;
//	
//	printf("%d", s.npos);
//}


///**
//���Գ����ַ���������ɶ���ܲ�����s.size()
//*/ 
//int main(){
//	string s;
//	printf("%d\n", s.size()); 
//	if (s=="") cout<<"s==\"\""<<endl; 
//	//0
//	//s==""
//}

/*
whileѭ�����棬string ÿ�ζ������˳�ֵ
*/ 
//int main(){
//	int cnt=0;
//	
//	while (cnt++!=4){
//		string now;
//		cout<<now<<endl;
//		//��������Ϊ��  
//		now+="1234 ";
//	}
//}


int main(){
	string s;
	if (s=="123") cout<<"s==\"123\""<<endl;//���Խ��бȽ�
	
	vector<string> vt;
	int cnt=0; 
	while (cnt++<5){
		string temp;
		temp.clear();
		
		vt.push_back(temp); //5���մ�����push_back��ȥ 
	}
	cout<<vt.size()<<endl;
}
