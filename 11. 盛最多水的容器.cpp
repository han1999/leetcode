//2022.07.22 
class Solution {
public:
    /*
    INT_MAX是10^9数量级的
    */
    int maxArea(vector<int>& height) {
        /*
        暴力超时了
        */
        // auto getCap=[&](int i, int j)->int{
        //     return min(height[i], height[j])*(j-i);
        // };
        // int size=height.size();
        // int maxCap=0;
        // for (int i=0; i<size; i++){
        //     for (int j=i+1; j<size; j++){
        //         maxCap=max(maxCap, getCap(i, j));
        //     }
        // }
        // return maxCap;


        int maxCap=0;
        int l=0, r=height.size()-1;
        while (l<r){
            int nowCap=min(height[l], height[r])*(r-l);
            maxCap=max(maxCap, nowCap);
            if (height[l]<height[r]){
                l++;
            }else {
                r--;
            }
        }
        return maxCap;
    }
};
