#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
/*
测试const 对于&num的作用
*/ 
int main(){
	vector<int> vt={1,2,3};
//	for (const auto num:vt){
//		num+=3;
//		//8	6	C:\Users\hx\leetcode\test_syntax.cpp	[Error] assignment of read-only variable 'num'
//	}
	
	for (const auto &num:vt){
		num+=3;
		//13	6	C:\Users\hx\leetcode\test_syntax.cpp	[Error] assignment of read-only reference 'num'
	}

}
