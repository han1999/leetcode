class Solution {
public:
    /**
    hashKey�������У���Ϊ����̫���ˣ�����ͬ��hashKey
    */
    // long long  getHashKey(string str){
    //     long long hashKey=0;
    //     for (const auto &ch:str){
    //         hashKey+=ch*ch*ch-10000007*ch+ch*ch;
    //     }
    //     return hashKey;
    // }
    // unordered_map<long long , int> mp;
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //solution1:
        // vector<vector<string>> ans;
        //  unordered_map<string, int> mp;
        // for (const auto &str:strs){
        //     // int hashKey=getHashKey(str);
        //     string hashKey=str;
        //     sort(hashKey.begin(), hashKey.end());
        //     if (mp.count(hashKey)){
        //         ans[mp[hashKey]].emplace_back(str);
        //     }else {
        //         //vector��ʼ�������кö���:�������ֶ���
        //         // vector<string> temp;
        //         // temp.emplace_back(str);
        //         // ans.emplace_back(temp);

        //         // vector<string> temp={str};
        //         // ans.emplace_back(temp);

        //         // ans.push_back({str});

        //         // ans.emplace_back(vector<string>({str}));

        //         // ans.emplace_back({str})���У��Ժ�����push_back�ɣ������
        //         mp[hashKey]=ans.size()-1;
        //     }
        // }
        // return ans;

        //solution2��
        unordered_map<string, vector<string>> mp;
        for (const auto &str:strs){
            string hashKey=str;
            sort(hashKey.begin(), hashKey.end());
            // if (mp.count(hashKey)){
            //     mp[hashKey].push_back(str);
            // }else {

            // }

            mp[hashKey].push_back(str);//���û��hashKey�����Զ�����һ��hashKey�Ͷ�Ӧ��vt
        }
        vector<vector<string>> ans;
        for (const auto &[hashKey, vt]:mp){
            ans.push_back(vt);
        }
        return ans;
    }
};
