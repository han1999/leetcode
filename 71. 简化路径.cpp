class Solution {
public:

    vector<string> split(string path){
        string temp;
        vector<string> ans;
        for (const auto &ch:path){
            if (ch=='/'){
                ans.push_back(temp);
                temp.clear();
            }else {
                temp+=ch;
            }
        }
        //if (temp) �Ƿ�ȼ��� if(temp!="") ��Ҳ �������temp.empty()���ж� ������ temp==""
        if (!temp.empty()) ans.push_back(temp);
        return ans;
    }
    string simplifyPath(string path) {
        // //ûд���� ������/...�������
        // //����д������
        // /*
        // ������path.size()���һֱ�ڱ仯�Ļ����Ͳ�Ҫ��n����path.size()��
        // */
        // /*
        // ע�������ַ��������û��../������..�൱�ڷ�����һ��
        // "/a//b////c/d//././/.."
        // */
        // if (path.back()!='/') path+="/";
        // for (int i=0; i<path.size(); i++){
        //     if (i!=0 && path[i]=='/' && path[i-1]=='/'){
        //         path.erase(i, 1);
        //         i--;//i--��Ϊ���´ε�i++�������λ��
        //         continue;
        //     }
        //     if (i+1<path.size() && path[i]=='.' && path[i+1]=='/'){
        //         path.erase(i,2);
        //         i--;
        //         continue;
        //     }
        //     if (i+2<path.size() && path[i]=='.' && path[i+1]=='.' && path[i+2]=='/'){
        //         path.erase(i-1,4);
        //         if (path.empty() || path[0]!='/'){
        //             path.insert(0, "/");
        //             continue;
        //         }
        //         i-=2;
        //         while (path[i]!='/'){
        //             path.erase(i, 1);
        //             i--;
        //         }
        //         continue;
        //     }
        // }
        // if (path.size()!=1 && path.back()=='/') {
        //     path.erase(path.end()-1);
        // } 
        // return path;
        stack<string> stk;
        vector<string> splits=split(path);
        for (const auto &s:splits){
            //��s.empty()ʱ�� s=="."�����ϲ��Ϸ��� �Ϸ������ԱȽ�
            if (!s.empty() && s!="."){
                if (s==".."){
                    if (!stk.empty()) stk.pop();
                }else {
                    stk.push(s);
                }
            }
        }
        string ans;
        while (!stk.empty()){
            ans.insert(0, "/"+stk.top());
            stk.pop();
        }
        //��˫��������Ը���һ��
        //��׼���õ���vector�����Ը���һ�㣬stack�����ģ�vector��������vector�����Ա���
        // reverse(ans.begin(), ans.end());
        return ans==""?"/":ans;
    }
};
