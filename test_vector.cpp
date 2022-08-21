#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

/*
vector初始化方式
*/ 
//int main(){
//	vector<int> vt={1,2,4};
//	for (auto num:vt){
//		printf("%d ", num);
//	}
//}

/*
测试find
*/ 
//int main(){
//	vector<int> vt={1,2,3};
//	auto it=find(vt.begin(), vt.end(),3);
//	int nums[]={1,7,8};
//	auto it2=find(nums, nums+3, 7);
//	cout<<"*it=="<<*it<<endl;
//	cout<<"*it2=="<<*it2<<endl;
//}

/*
这个就是vector和string不一样的地方了
*/ 
//int main(){
//	vector<int> ans;
//	ans.insert(0, 1);//error ，insert(iter, val) 
//}

int main(){
	vector<int> vt;
	set<int> st={1,6,3,4};
//	vt=st;//no match for 'operator=' (operand types are 'std::vector<int>' and 'std::set<int>')
//	for (const auto &num:vt){
//		cout<<num<<" ";
//	}
	
//	vector<int> vt1(st);//[Error] no matching function for call to 'std::vector<int>::vector(std::set<int>&)'
	
	deque<int> dq={1,3,5};
//	vector<int> vt2{dq};
	//[Error] no matching function for call to 'std::vector<int>::vector(<brace-enclosed initializer list>)'
	cout<<endl;
	
	stack<int> stk={1,4,2};//[Error] could not convert '{1, 4, 2}' from '<brace-enclosed initializer list>' to 'std::stack<int>'
}
