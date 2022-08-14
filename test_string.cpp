#include <string>
#include <iostream>
#include <vector>
using namespace std;
//int main(){
//	string s="123456";
//	string s1=to_string(123);
//	bool isdig=isdigit(s[0]);
//	/**
//	虽然有点离谱，但是s[0]确实有值，应该是随机的 
//	*/ 
//	s="";
//	char c=s[0];
//	cout<<"c:"<<c<<endl;
//	isdig=isdigit(s[0]);
//	cout<<isdig<<endl;
//}

///**
//测试s.replace的长度参数
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
//测试初试字符串到底是啥，能不能用s.size()
//*/ 
//int main(){
//	string s;
//	printf("%d\n", s.size()); 
//	if (s=="") cout<<"s==\"\""<<endl; 
//	//0
//	//s==""
//}

/*
while循环里面，string 每次都被赋了初值
*/ 
//int main(){
//	int cnt=0;
//	
//	while (cnt++!=4){
//		string now;
//		cout<<now<<endl;
//		//结果是输出为空  
//		now+="1234 ";
//	}
//}


int main(){
	string s;
	if (s=="123") cout<<"s==\"123\""<<endl;//可以进行比较
	
	vector<string> vt;
	int cnt=0; 
	while (cnt++<5){
		string temp;
		temp.clear();
		
		vt.push_back(temp); //5个空串可以push_back进去 
	}
	cout<<vt.size()<<endl;
}
