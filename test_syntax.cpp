#include <cstdio>
#include <vector>
#include <iostream>
#include <set> 
#include <unordered_set>
using namespace std;
///*
//����const ����&num������
//*/ 
//int main(){
//	vector<int> vt={1,2,3};
////	for (const auto num:vt){
////		num+=3;
////		//8	6	C:\Users\hx\leetcode\test_syntax.cpp	[Error] assignment of read-only variable 'num'
////	}
//	
//	for (const auto &num:vt){
//		num+=3;
//		//13	6	C:\Users\hx\leetcode\test_syntax.cpp	[Error] assignment of read-only reference 'num'
//	}
//
//}

////
///*
//���Ծֲ�������������
//while����ľֲ�����������һ��ѭ�����滹����֮ǰ��ֵ 
//*/
//int main(){
//	int cnt=0;
//	while (1){
//		int a,b,c;
//		cout<<a<<" "<<b<<" "<<c<<endl;
//		a=100;
//		b=200;
//		c=300;
//		if (cnt++==3) break;
//		//��� 
////1 0 0
////100 200 300
////100 200 300
////100 200 300
//	}
//} 

/**
mod�Ľ���ͱ�����һ��
*/ 
//int main(){
//	cout<<7%-3<<endl;//1
//	cout<<-7%3<<endl;//-1
//}


///**
//��Ȼa,b,c��while����һֱ���ڣ�����ÿ�ξ���int a=1;��ʱ��ֵ���ֱ����¸�ֵΪ1��
//*/ 
//int main(){
//	int cnt=0;
//	while (1){
//		int a=1;
//		int b=2; 
//		int c=3;
//		cout<<a<<b<<c<<endl;
//		a=100;
//		b=200;
//		c=300;
//		if (cnt++==3) break;
//		//�����  
////		123
////		123
////		123
////		123
//	}
//}

int main(){
	int cnt=0;
	while (cnt++!=4){
		unordered_set<int> st;
		int a;
		cout<<"&a:"<<&a<<endl;
		cout<<"&st:"<<&st<<endl;
		for (const auto &num:st){
			cout<<num;
		}
		cout<<endl;
		st.insert(1);
		a=100;
	//����ǣ� ÿһ��whileѭ�����棬��ʵ�������´���һ���������������ǵı�����ַ��֮ǰ��һ����
	//���ڻ����������ͣ�int �ȣ���Ȼ����֮ǰ��ֵ������stl������ȫ��ɿ��� 
//		a=37
//		
//		a=100
//		
//		a=100
//		
//		a=100

	}
}


