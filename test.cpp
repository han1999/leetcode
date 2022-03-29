#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


////test vector 
//vector<int> returnVector(){
//	return {1,3,5};
//}
//void printVector(vector<int> &vt){
//	for (auto num:vt){
//		printf("%d ", num);
//	}
//}
//int main(){
//	vector<int> vt=returnVector();
//	printVector(vt);
//} 

//test string
int main(){
	string s="123456";
	for (auto ch:s){
		cout<<ch<<" ";
	} 
	cout<<endl;
	string s2="aaa";
	s.replace(1, 2, s2);
	cout<<s<<endl;
}
