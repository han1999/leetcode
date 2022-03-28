class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        int size=size1+size2;
        double p1=0,p2=0;
        int cnt=0;
        int nums[size+10];
        while (p1<size1 && p2<size2){
            if (nums1[p1]<=nums2[p2]){
                nums[cnt++]=nums1[p1++];
            }else{
                nums[cnt++]=nums2[p2++];
            } 
        }
        while (p1<size1) nums[cnt++]=nums1[p1++];
        while (p2<size2) nums[cnt++]=nums2[p2++];
        if (size%2==0){
            double mid1=nums[size/2-1];
            double mid2=nums[size/2];
            return (mid1+mid2)/2;
        }else {
            return nums[size/2];
        }
        return -1;
    }
};
