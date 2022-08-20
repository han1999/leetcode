class Solution {
public:
    int partition(vector<int> &nums, int l, int r){
        int randPos=rand()%(r-l+1)+l;
        swap(nums[r], nums[randPos]);
        int pivot=l-1;
        for (int i=l; i<r; ++i){
            if (nums[i]<=nums[r]){
                swap(nums[i], nums[++pivot]);
            }
        }
        swap(nums[r], nums[++pivot]);
        return pivot;
    }

    void quickSort(vector<int> &nums, int l, int r){
        if (l<r){
            int pivot=partition(nums, l, r);
            /*
            这里竟然能写错，写成nums, 0 ,pivot-1了！！！
            头脑太不清楚了
            */
            quickSort(nums, l, pivot-1);
            quickSort(nums, pivot+1, r);
        }
    }

    // void merge(vector<int> &nums, vector<int> &temp, int l, int mid, int r){
    //     int i=l, j=mid+1, pos=l;
    //     while (i<=mid && j<=r){
    //         if (nums[i]<=nums[j]){
    //             temp[pos++]=nums[i++];
    //         }else {
    //             temp[pos++]=nums[j++];
    //         }
    //     }
    //     while (i<=mid) temp[pos++]=nums[i++];
    //     while (j<=r) temp[pos++]=nums[j++];
    //     copy(temp.begin()+l, temp.begin()+r+1, nums.begin()+l);
    // }

    // void mergeSort(vector<int> &nums, vector<int> &temp, int l, int r){
    //     if (l>=r) return;
    //     int mid=l+(r-l)/2;
    //     mergeSort(nums, temp, l, mid);
    //     mergeSort(nums, temp, mid+1, r);
    //     merge(nums, temp, l, mid, r);
    // }

    // void mergeSort2(vector<int> &nums, vector<int> &temp, int l, int r){
    //     int n=nums.size();
    //     for (int gap=1; gap<n; gap*=2){
    //         for (int i=l; i+gap-1<n-1; i+=2*gap){
    //             merge(nums, temp, i, i+gap-1, min(i+2*gap-1, n-1));
    //         }
    //     }
    // }
    vector<int> sortArray(vector<int>& nums) {
        // //solution1: 
        // sort(nums.begin(), nums.end());
        // return nums;

        //solution2: 快排：需要有随机pivot，否则会超时
        srand(time(0));
        quickSort(nums, 0, nums.size()-1);
        return nums;

        // //solution3: 归并排序
        // vector<int> temp(nums.size());
        // mergeSort(nums, temp, 0, nums.size()-1);
        // // mergeSort2(nums, temp, 0, nums.size()-1);
        // return nums;
    }
};
