class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        �����㷨���ԣ����ҷ�ǳ��
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

        //һ�α�����
        int minPrice=INT_MAX;
        // int ans=INT_MIN;
        int ans=0;
        /*
        �����ҽ������� ��׬����Ǯ
        */
        for (const auto &price:prices){
            ans=max(ans, price-minPrice);
            minPrice=min(minPrice, price);
        }
        // return ans<0?0:ans;
        /*
        ����Ҳ�Ǽ��ɣ����price-minPriceС��0����max��ʱ��Ϳ���ֱ�Ӻ�����
        */
        return ans;
    }
};
