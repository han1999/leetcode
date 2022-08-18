class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        以下算法不对，是我肤浅了
        */
        // vector<pair<int, int>> vt;
        // for (int i=0; i<prices.size(); i++){
        //     vt.push_back({prices[i], i});
        // }
        // sort(vt.begin(), vt.end());
        // int l=0, r=vt.size()-1;
        // while (l<=r){
        //     if (vt[l].second<vt[r].second){
        //         return vt[r].first-vt[l].first;
        //     }else {
        //         r--;
        //     }
        // }
        // return 0;

        //一次遍历：
        int minPrice=INT_MAX;
        // int ans=INT_MIN;
        int ans=0;
        /*
        假设我今天卖， 能赚多少钱
        */
        for (const auto &price:prices){
            ans=max(ans, price-minPrice);
            minPrice=min(minPrice, price);
        }
        // return ans<0?0:ans;
        /*
        这里也是技巧，如果price-minPrice小于0，在max的时候就可以直接忽略了
        */
        return ans;
    }
};
