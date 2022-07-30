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
	//结果是： 每一次while循环里面，其实都是重新创建一个变量，但是他们的变量地址和之前是一样的
	//对于基本数据类型，int 等，仍然保持之前的值，对于stl，则完全变成空了 
//		a=37
//		
//		a=100
//		
//		a=100
//		
//		a=100

	}
}


