#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &vt, int l1, int r1, int l2, int r2){
	vector<int> temp(vt.size());
	int pos=l1;
	int i=l1, j=l2;
	while (i<=r1 && j<=r2){
		if (vt[i]<=vt[j]){
			temp[pos++]=vt[i++];
		}else {
			temp[pos++]=vt[j++];
		}
	}
	while (i<=r1) temp[pos++]=vt[i++];
	while (j<=r2) temp[pos++]=vt[j++];
	for (int i=l1; i<=r2; i++){
		cout<<temp[i]<<" ";
		vt[i]=temp[i];
	}
	cout<<endl;
}
void mergeSort(vector<int> &vt, int l, int r){
	if (l>=r) return;
	int mid=(l+r)/2;
	mergeSort(vt, l, mid);
	mergeSort(vt, mid+1, r);
	merge(vt, l, mid, mid+1, r);
}

void mergeSort2(vector<int> &vt, int l, int r){
	int n=vt.size();
	for (int gap=1; gap<n; gap*=2){
		for (int i=0; i+gap-1<n-1; i+=2*gap){
			merge(vt, i, i+gap-1, i+gap, min(i+2*gap-1, n-1));
		}
	}
}
int main(){
	vector<int> vt;
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int num;
		cin>>num;
		vt.push_back(num);
	}
//	mergeSort(vt, 0, vt.size()-1);
	mergeSort2(vt, 0, vt.size()-1);
	for (const auto &num:vt){
		cout<<num<<" ";
	}
	cout<<endl;
}
