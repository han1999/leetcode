class Solution {
public:
    /*
    made������д�����ԣ���һ��������ô���ֵ���Ŀ
    ����д���Եģ�ֻ����Ч�ʵ͵㣬����Ҳ���
    */
    vector<string> ans;
    vector<string> segs;
    void dfs(int index, string s, vector<string> &segs){
            //         for (const auto &seg:segs){
            //     cout<<seg<<" ";
            // }
            // cout<<endl;
        // cout<<index<<endl;
        if (segs.size()==4){
            // for (const auto &seg:segs){
            //     cout<<seg<<" ";
            // }
            // cout<<endl;
            if (index==s.size()){
                string temp;
                for (int i=0; i<3; i++){
                    temp+=segs[i]+".";
                }
                temp+=segs[3];
                ans.push_back(temp);
            }
            return;
        }
        /*
        ����ܹؼ���ӦΪindex����һ��һ�����ϼӣ� ����+1,+2,+3���п���
        */
        if (index>=s.size()) return;
        if (s[index]=='0'){
            segs.push_back("0");
            dfs(index+1, s, segs);
            segs.pop_back();
        }else {
            for (int i=0; i<3; i++){
                string tempS=s.substr(index, i+1);
                // cout<<"tempS:"<<tempS<<endl;
                /*
                stoi�����ô�
                */
                if (stoi(tempS)>255) break;
                segs.push_back(tempS);
                /*
                ����̫�ؼ��ˣ���
                */
                dfs(index+1+i, s, segs);
                segs.pop_back();
            }
        }

    }

    // vector<string> segs;
    // vector<string> ans;
    // dfs(int index, int segId, string s){
    //     if (index==s.size()){
    //         if (segId==4){
    //             string addr;
    //             for (int i=0; i<3; i++){
    //                 addr+=segs[i]+".";
    //             }
    //             addr+=segs[3];
    //             ans.push_back(addr);
    //         }
    //         return;
    //     }
    //     if (segId==4) return;
    //     if (s[index]=='0'){
    //         segs.push_back("0");
    //         dfs(index+1, segId+1, s);
    //     }
    //     for (int i=0; i<3; i++){
    //         string tempS=s.substr(index, )
    //     }
    // }
    vector<string> restoreIpAddresses(string s) {
        dfs(0, s, segs);
        return ans;
    }
};
