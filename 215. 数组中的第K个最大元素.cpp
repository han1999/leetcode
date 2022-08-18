class Solution {
public:

    int partition(vector<int> &nums, int l, int r){
        int pivot=l-1;
        for (int i=l; i<=r; i++){
            if (nums[i]<=nums[r]){
                swap(nums[i], nums[++pivot]);
            }
            // swap(nums[r], nums)
        }
        return pivot;
    }

    int quickSelect(vector<int> &nums, int l, int r, int index){
        // if (l>=r) return;
        /*
        本质上来看，就是一个只有一个方向的快排
        */
        int pivot=partition(nums, l, r);
        // cout<<"pivot:"<<pivot<<" l:"<<l<<" r:"<<r<<endl;
        if (pivot==index) return nums[pivot];
        /*
        搞反了好家伙！！
        */
        // if (pivot<index) return quickSelect(nums, l, pivot-1, index);
        // return quickSelect(nums, pivot+1, r, index); 
        if(pivot<index) return quickSelect(nums, pivot+1, r, index);
        return quickSelect(nums, l, pivot-1, index);
    }
    int findKthLargest(vector<int>& nums, int k) {
        //solution1: 用stl
    //    priority_queue<int> pq;
    //    for (const auto &num:nums){
    //        pq.push(num);
    //    } 
    //    for (int i=0; i<k-1; i++){
    //        pq.pop();
    //    }
    //    return pq.top();
    return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    
    }
};
