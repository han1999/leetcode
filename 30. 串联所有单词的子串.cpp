//2022.07.28 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //д��һ��ѣ�����
        // if (words.empty()) return {};
        // unordered_multiset<string> st1;
        // for (auto word:words) st1.insert(word);
        // unordered_multiset<string> st2;
        // int l=0, r=0, n=words[0].size();
        // vector<int> ans;
        // bool needReset=false;
        // while (r<s.size()){
        //     string nowStr=s.substr(r, n);
        //     if (!st1.count(nowStr)){
        //         r++;
        //         needReset=true;
        //         continue;
        //         // while (!st1.count())
        //     }
        //     if (needReset){
        //         st2.clear();
        //         l=r;
        //         needReset=false;
        //     }
        //     // string lStr=s.substr(l,n);
        //     //���һ��ʼst2Ϊ�գ� �� it == st2.end()
        //     // auto it=st2.find(s.substr(l,n));
        //     if (st2.count(nowStr)==st1.count(nowStr)){
        //         //ֱ��erase key
        //         //���ɾ���ǰ�����keyΪnowStr��ȫɾ������, ������
        //         // st2.erase(s.substr(l, n));
        //         st2.erase(st2.find(s.substr(l,n)));
        //         // st2.erase(it);
        //         l+=n;
        //         continue;
        //     }else {
        //         st2.insert(nowStr);
        //         r+=n;
        //         // continue;
        //     }
        //     cout<<l<<" "<<r<<" ";
        //     for (auto str:st2) cout<<str<<" ";
        //     cout<<endl;
        //     if (st2.size()==words.size()) {
        //         ans.push_back(l);
        //         st2.erase(st2.find(s.substr(l,n)));
        //         // l=r=l+1;
        //         // st2.erase(it);
        //         //����erase(it)����Ϊ����ǰ��st2�����Ѿ�����
        //         l+=n;
        //     }
        // }
        // return ans;

        // /**
        // �����صķ�����������û�õ��������� solution1:
        // */
        // if (s.empty() || words.empty()) return {};
        // // unordered_multiset<string> st1,st2;
        // // for (auto &word:words) st1.insert(word);
        // unordered_map<string, int> mp1, mp2;
        // for (auto &word:words){
        //     mp1[word]++;
        // }
        // int n=words[0].size(), m=words.size();
        // vector<int> ans;
        // for (int i=0; i+m*n-1<s.size(); i++){
        //     mp2.clear();
        //     // st2.clear();
        //     int j;
        //     /*
        //     ����j�Ľ�βͦ����˼��
        //     */
        //     for (j=i; j<=i+(m-1)*n; j+=n){
        //         string nowStr=s.substr(j, n);
        //         // if (!mp1[nowStr]) break;
        //         // if (st2.count(nowStr)==st1.count(nowStr)) break;
        //         /*
        //         ����mp1[nowStr]�����û��nowStr���������ô�ڴ��оͻᴴ��һ��nowStr��,��ֵΪ0
        //         */
        //         if (!mp1.count(nowStr)) break;
        //         if (mp1[nowStr]==mp2[nowStr]) break;
        //         // st2.insert(nowStr);
        //         mp2[nowStr]++;
        //     }
        //     // if (st1.size()==st2.size()) ans.push_back(i);
        //     // for (auto &[str, cnt]:mp2){
        //     //     cout<<str<<" "<<cnt<<"     ";
        //     // }
        //     // cout<<mp1.size()<<" "<<mp2.size()<<endl;
        //     if (/*mp1.size()==mp2.size()*/j==i+m*n){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        // //solution2: ���̶����ȵĴ���
        // if (s.empty() || words.empty()) return {};
        // if (s.size()<words[0].size()) return {};
        // unordered_map<string, int> mp1;
        // for (const auto &word:words){
        //     mp1[word]++;
        // }
        // vector<int> ans;
        // int n=words[0].size(), m=words.size();
        // // cout<<"m=="<<m<<" n=="<<n<<endl;
        // for (int i=0; i<n && i+m*n-1<s.size(); i++){
        //     int l=i,r=i;
        //     unordered_map<string, int> mp2;
        //     mp2.clear();
        //     while(l+m*n-1<s.size()){
        //         string nowStr=s.substr(r, n);
        //         // cout<<"l:"<<l<<"  r:"<<r<<"  nowStr:"<<nowStr<<endl;
        //         /*
        //         map������ӹ����뵽
        //         mp2[key]--, ���������mp[key]==0�ˣ����Ԫ����Ȼ��mp2���棬
        //         */
        //         if (!mp1.count(nowStr)){
        //             cout<<"no value"<<endl;
        //             r+=n;
        //             l=r;
        //             mp2.clear();
        //             continue;
        //         }
        //         if (mp1[nowStr]==mp2[nowStr]){
        //             // cout<<"r=="<<r<<"  nowStr=="<<nowStr<<"  mp2[nowStr]=="<<mp2[nowStr]<<"   s.substr(l,n)=="<<s.substr(l,n)<<"  mp2[s.substr(l,n)]=="<<mp2[s.substr(l,n)]<<endl;
        //             // l+=n;
        //             //���գ����ﲻ��--mp2[...] ���� --mp2[...]==0
        //             if (--mp2[s.substr(l, n)]==0) mp2.erase(s.substr(l,n));//
        //             l+=n;
        //         //     for (auto &[str, cnt]:mp2){
        //         //     cout<<str<<" "<<cnt<<"    ";
        //         //    }
        //         //    cout<<endl;
        //             continue;
        //         }
        //         mp2[nowStr]++;
        //         r+=n;
        //         // for (auto &[str, cnt]:mp2){
        //         //     cout<<str<<" "<<cnt<<"    ";
        //         // }
        //         // cout<<endl;
        //         // cout<<"l=="<<l<<" r=="<<r<<" "<<endl;
        //         // cout<<endl;
        //         if (r==l+m*n){
        //             ans.push_back(l);
        //             // l+=n;
        //             /**
        //             ���Ӳ������ˣ�˳�򶼸㷴�ˣ�������������������������
        //             */
        //             if (--mp2[s.substr(l, n)]==0) mp2.erase(s.substr(l,n));//
        //             l+=n;
                    
        //         }
        //         // cout<<"l+m*n-1=="<<l+m*n-1<<endl;
        //     }
        // }
        // return ans;

        //solution3: �̶����ȵĴ���
        if(words.empty()) return {};
        vector<int> ans;
        int m=words.size(), n=words[0].size();
        for (int i=0; i<n && i+m*n-1<s.size(); i++){
            unordered_map<string, int> mp;
            mp.clear(); //����Ҫ��Ҫд��
            for (int j=0; j<m; j++){//j=i; j<=i+(m-1)*n; j+=n
                string nowWord=s.substr(i+j*n, n);
                mp[nowWord]++;
            }
            for (const auto &word:words){
                if (--mp[word]==0) mp.erase(word);
            }

            int start=i;
            while (start+m*n-1<s.size()){
                // if (start!=i){
                //     string preWord=s.substr(start-n, n);
                //     if (--mp[preWord]==0){
                //         mp.erase(preWord);
                //     }
                //     /*
                //     ע����β���⣬ �ײ� start+0*n β������start+(m-1)*n
                //     */
                //     string newWord=s.substr(start+(m-1)*n, n);
                //     if (++mp[newWord]==0){
                //         mp.erase(newWord);
                //     }
                // }
                // if (mp.empty()){
                //     ans.push_back(start);
                // }
                // start+=n;

                //��ϰ������ôд��
                if (mp.empty()){
                    ans.push_back(start);
                }
                string preWord=s.substr(start, n);
                if (--mp[preWord]==0){
                    mp.erase(preWord);
                }
                //substr�����ϻ����
                string newWord=s.substr(start+m*n, n);
                if (++mp[newWord]==0){
                    mp.erase(newWord);
                }
                start+=n;
            }
        }
        return ans;
    }

    // void backtrack(int index, vector<string> &words, string &)
};
