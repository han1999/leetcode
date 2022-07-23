#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;
int main(){
	unordered_set<int> st1={1,3,2};
	unordered_set<int> st2={1,2,3};
	for (auto num:st1){
		cout<<num<<" ";
	}
	cout<<endl;
	for (auto num:st2){
		cout<<num<<" ";
	}
	cout<<endl;
	cout<<(st1==st2)<<endl;
	
	// 不管是 unordered_set还是set， 这两个都相等！ 
} 
