#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void trackback(int index, int n, vector<vector<int>> &ans, vector<int> &temp, vector<int> &hashTable){
	if (index==n){
		ans.push_back(temp);
		return;
	}
	for (int i=1; i<=n; i++){
		if (hashTable[i]==0){
			temp.push_back(i);
			hashTable[i]=1;
			trackback(index+1, n, ans, temp, hashTable);
			temp.pop_back();
			hashTable[i]=0;
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>> ans;
	vector<int> temp;
	vector<int> hashTable(10, 0);
	trackback(0, n, ans, temp, hashTable);
	for (const auto &per:ans){
		for (const auto &num:per){
			cout<<num;
		}
		cout<<endl;
	}
}
