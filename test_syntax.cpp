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

//int main(){
//	int cnt=0;
//	while (cnt++!=4){
//		unordered_set<int> st;
//		int a;
//		cout<<"&a:"<<&a<<endl;
//		cout<<"&st:"<<&st<<endl;
//		for (const auto &num:st){
//			cout<<num;
//		}
//		cout<<endl;
//		st.insert(1);
//		a=100;
//	//����ǣ� ÿһ��whileѭ�����棬��ʵ�������´���һ���������������ǵı�����ַ��֮ǰ��һ����
//	//���ڻ����������ͣ�int �ȣ���Ȼ����֮ǰ��ֵ������stl������ȫ��ɿ��� 
////		a=37
////		
////		a=100
////		
////		a=100
////		
////		a=100
//
//	}
//}

///*
//�����������ڴ��д洢��ʽ����ʼ����ʽ
//*/ 
//int main(){
//	int a[3][5]={0,1,2,3,4,5,6,7};
//	for (int i=0; i<3; i++){
//		for (int j=0; j<5; j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	
//	int b[3][5];
//	for (int i=0; i<3; i++){
//		for (int j=0; j<5; j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
////0 1 2 3 4
////5 6 7 0 0
////0 0 0 0 0
////4253632 0 37 0 1261011
////0 1 0 -1 -1
////4253733 0 1 0 4254665
//}

/*
��������
*/ 
int main(){
//	int &b=3;//invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
	const int &k=3;//�����ó�����ֵ �������͵ı���, ���ǿ��Ը�ֵ���������� 
	int b=3;
	int &a=b;//����д�� 
	a=4;
	cout<<"a:"<<a<<" b:"<<b<<endl;//a:4 b:4
	
	int c=a;//c����ͨ������c�ı䣬a���ı� 
	c=5;
	cout<<"a:"<<a<<" c:"<<c<<endl;//a:4 c:5
	
}

