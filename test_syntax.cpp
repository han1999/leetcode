#include <cstdio>
#include <vector>
#include <iostream>
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

//
///*
//测试局部变量生命周期
//while里面的局部变量，在下一个循环里面还保持之前的值 
//*/
//int main(){
//	int cnt=0;
//	while (1){
//		int a,b,c;
//		cout<<a<<" "<<b<<" "<<c<<endl;
//		if (cnt==1) break;
//		a=100;
//		b=200;
//		c=300;
//		cnt++;
//		//结果
////		1 0 0
////		100 200 300 
//	}
//} 

int main(){
	cout<<7%-3<<endl;//1
	cout<<-7%3<<endl;//-1
}


