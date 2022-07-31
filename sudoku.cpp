#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
bool valid=false;
//resize(n, val)， val默认是0
//vector(n) 就是 n个0
//resize(n)多出来的都是0 
vector<vector<int>> row;
vector<vector<int>> col;
vector<int> box;

void dfs(int index, vector<vector<int>> &vt){
	if (index==n*n){
		vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);
	
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				int num=vt[i][j];
				rowSum[i]+=num;
				colSum[j]+=num;
			}
		}
		for (int i=1; i<n; i++){
			if (rowSum[i]!=rowSum[i-1]  || colSum[i]!=colSum[i-1]){
				valid=false;
				return;
			}
		}
		valid=true;
		cout<<"rowSum:"<<rowSum[0]<<endl;
		cout<<"colSum:"<<colSum[0]<<endl;
		for (const auto &nums:vt){
			for (const auto &num:nums){
				cout<<num<<" ";
			}
			cout<<endl;
		}		
		return;
	}
	int i=index/n;
	int j=index%n;
//	cout<<"first i:"<<i<<" j:"<<j<<endl;
	/*
	这个n*n终点， 排查了好久
	*/ 
	for (int num=1; num<=n*n; num++){
//		cout<<"num:"<<num<<endl;
//		cout<<row[i][num]<<"   "<<col[j][num]<<"   "<<box[num]<<endl;
		if (row[i][num]==0 && col[j][num]==0 && box[num]==0){
//			cout<<"now we get here"<<endl; 
			vt[i][j]=num;
//			cout<<"i:"<<i<<" j:"<<j<<endl;
			row[i][num]=col[j][num]=box[num]=1;
			dfs(index+1, vt);
//			if (valid) return;
			row[i][num]=col[j][num]=box[num]=0;
			vt[i][j]=0;
		}
	}
}
int main(){
	while (1){
		cin>>n;
		box.clear();
		row.clear();
		col.clear();
		box.resize(n*n+1, 0);
		row.resize(n, vector<int>(n*n+1, 0));
		col.resize(n, vector<int>(n*n+1, 0));
		vector<vector<int>> vt(n, vector<int>(n, 0));
		dfs(0, vt);

	}
}
