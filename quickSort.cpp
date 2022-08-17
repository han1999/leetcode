#include <vector>
#include <iostream>
using namespace std;
int partition(vector<int> &nums, int l, int r){
	int pivot=l-1;
	for (int i=l; i<=r; i++){
		if (nums[i]<=nums[r]){
			swap(nums[i], nums[++pivot]);
		}
	}
//	swap(nums[r], nums[++pivot]);
	return pivot;	
}

void quickSort(vector<int> &nums, int l, int r){
	if (l>=r) return;
	int pivot=partition(nums, l, r);
	quickSort(nums, l, pivot-1);
	quickSort(nums, pivot+1, r);
}
int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for (int i=0; i<n; i++){
		int num;
		cin>>num;
		nums.emplace_back(num);
	}
	
	quickSort(nums, 0, nums.size()-1);
	for (const auto &num:nums){
		cout<<num<<" ";
	}
}
