class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // //solution1: 开一个新数组
        // // int m=nums1.size(), n=nums2.size();
        // vector<int> temp(m+n);
        // int i=0, j=0, pos=0;
        // while (i<m || j<n){
        //     int num1=i<m?nums1[i]:INT_MAX;
        //     int num2=j<n?nums2[j]:INT_MAX;
        //     if (num1<num2){
        //         temp[pos++]=nums1[i++];
        //     }else {
        //         temp[pos++]=nums2[j++];
        //     }
        // }
        // nums1=temp;

        // //solution2:原地操作
        // int i=0, j=0, len=m;
        // while (i<m || j<n){
        //     /*
        //     len改变，要及时更行， 这里容易错
        //     */
        //     int val1=i<len?nums1[i]:INT_MAX;
        //     int val2=j<n?nums2[j]:INT_MAX;
        //     if (val1<=val2){
        //         i++;
        //     }else {
        //         for (int k=len-1; k>=i; k--){
        //             nums1[k+1]=nums1[k];
        //         }
        //         nums1[i]=val2;
        //         j++;
        //         i++;
        //         len++;
        //     }
        // }

        //solution3:
        int pos=m+n-1;
        int i=m-1, j=n-1;
        while (i>=0 || j>=0){
            int val1=i>=0?nums1[i]:INT_MIN;
            int val2=j>=0?nums2[j]:INT_MIN;
            if (val1>val2){
                nums1[pos--]=nums1[i--];
            }else {
                nums1[pos--]=nums2[j--];
            }
        }
    }
};
