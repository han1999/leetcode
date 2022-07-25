#include <unordered_map> 
#include <map>
#include <iostream>
using namespace std;

int main(){
	multimap<int , int> mmp;
	mmp.insert(make_pair(100, 1));
	mmp.insert(make_pair(100, 2));
	mmp.insert(make_pair(200, 3));
	mmp.insert(make_pair(100, 1));
	for (auto pair:mmp){
		int key=pair.first;
		int value=pair.second;
		printf("%d %d\n", key, value);
	}
	
	// ½á¹û£º
//	100 1
//100 2
//100 1 

	auto it=mmp.find(100);
	int cnt=mmp.count(100);
	cout<<"key:100 count:"<<cnt<<endl;
	
	for (auto it=mmp.lower_bound(100); it!=mmp.upper_bound(100); it++){
		int key=it->first;
		int value=it->second;
		printf("%d %d\n",key,value);
	} 
	
} 
