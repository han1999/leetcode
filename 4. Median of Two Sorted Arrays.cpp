//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int size1=nums1.size();
//        int size2=nums2.size();
//        int size=size1+size2;
//        double p1=0,p2=0;
//        int cnt=0;
//        int nums[size+10];
//        while (p1<size1 && p2<size2){
//            if (nums1[p1]<=nums2[p2]){
//                nums[cnt++]=nums1[p1++];
//            }else{
//                nums[cnt++]=nums2[p2++];
//            } 
//        }
//        while (p1<size1) nums[cnt++]=nums1[p1++];
//        while (p2<size2) nums[cnt++]=nums2[p2++];
//        if (size%2==0){
//            double mid1=nums[size/2-1];
//            double mid2=nums[size/2];
//            return (mid1+mid2)/2;
//        }else {
//            return nums[size/2];
//        }
//        return -1;
//    }
//};

//2022.07.21
/**
思路更第一次一样
但是第一次代码简洁很多 
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vt;
        int p1=0;
        int p2=0;
        while (p1<nums1.size() && p2<nums2.size()){
            int num1=nums1[p1];
            int num2=nums2[p2];
            if (num1<num2){
                vt.push_back(num1);
                p1++;
            }else{
                vt.push_back(num2);
                p2++;
            }
        }
        while (p1<nums1.size()){
            vt.push_back(nums1[p1++]);
        }
        while (p2<nums2.size()){
            vt.push_back(nums2[p2++]);
        }
        int size=vt.size();
        if (size%2==0){
            return (vt[size/2]+vt[size/2-1])/2.0;
        }
        return vt[size/2];
    }
}; 

/**
改进了一下
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1=0;
        int p2=0;
        int cnt=0;
        int size=nums1.size()+nums2.size();
        int nowVal, preVal;
        while (p1<nums1.size() || p2<nums2.size()){
            int num1=p1<nums1.size()?nums1[p1]:INT_MAX;
            int num2=p2<nums2.size()?nums2[p2]:INT_MAX;
            if (num1<num2){
                preVal=nowVal;
                nowVal=num1;
                p1++;
            }else {
                preVal=nowVal;
                nowVal=num2;
                p2++;
            }
            cnt++;
            // cnt==1 index==cnt-1==0
            if (cnt-1==size/2){
                if (size%2==0){
                    return (nowVal+preVal)/2.0;
                }
                return nowVal;
            }
        }
        return -1;
    }
}; 
