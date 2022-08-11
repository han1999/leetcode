#include <cstdio>
#include <vector>
#include <iostream>
#include <set> 
#include <unordered_set>
using namespace std;
///*
//测试const 对于&num的作用
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
//测试局部变量生命周期
//while里面的局部变量，在下一个循环里面还保持之前的值 
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
//		//结果 
////1 0 0
////100 200 300
////100 200 300
////100 200 300
//	}
//} 

/**
mod的结果和被除数一样
*/ 
//int main(){
//	cout<<7%-3<<endl;//1
//	cout<<-7%3<<endl;//-1
//}


///**
//虽然a,b,c在while里面一直存在，但是每次经过int a=1;的时候，值就又被重新赋值为1了
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
//		//结果：  
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
//	//结果是： 每一次while循环里面，其实都是重新创建一个变量，但是他们的变量地址和之前是一样的
//	//对于基本数据类型，int 等，仍然保持之前的值，对于stl，则完全变成空了 
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
//测试数组在内存中存储形式，初始化方式
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
测试引用
*/ 
int main(){
//	int &b=3;//invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
	const int &k=3;//不能用常量赋值 引用类型的变量, 但是可以赋值给常量引用 
	int b=3;
	int &a=b;//引用写法 
	a=4;
	cout<<"a:"<<a<<" b:"<<b<<endl;//a:4 b:4
	
	int c=a;//c是普通变量，c改变，a不改变 
	c=5;
	cout<<"a:"<<a<<" c:"<<c<<endl;//a:4 c:5
	
}

