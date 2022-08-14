#include <stack>
#include <iostream>
using namespace std;
int main(){
	stack<int> stk;
	stk.push(5);
	stk.push(2);
	stk.push(0);
	stk.push(1);
	stk.push(3);
	stk.push(1);
	stk.push(4);
	stk.push(9);
	for (const auto &num:stk){
		//[Error] no matching function for call to 'begin(std::stack<int>&)'
		//stack不能遍历，用vector来代替stack更好一点 
		cout<<num<<" ";
	}
}
