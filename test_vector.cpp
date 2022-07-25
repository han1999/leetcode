#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int main(){
//	vector<int> vt={1,2,4};
//	for (auto num:vt){
//		printf("%d ", num);
//	}
//}

int main(){
	vector<int> vt={1,2,3};
	auto it=find(vt.begin(), vt.end(),3);
	int nums[]={1,7,8};
	auto it2=find(nums, nums+3, 7);
	cout<<"*it=="<<*it<<endl;
	cout<<"*it2=="<<*it2<<endl;
}
