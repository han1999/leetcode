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
        //if (temp) 是否等价于 if(temp!="") 非也 必须得用temp.empty()来判断 或者用 temp==""
        if (!temp.empty()) ans.push_back(temp);
        return ans;
    }
    string simplifyPath(string path) {
        // //没写出来 处理不了/...这种情况
        // //以下写法不对
        // /*
        // 像这里path.size()如果一直在变化的话，就不要用n接收path.size()了
        // */
        // /*
        // 注意以下字符串，最后没有../但是有..相当于返回上一级
        // "/a//b////c/d//././/.."
        // */
        // if (path.back()!='/') path+="/";
        // for (int i=0; i<path.size(); i++){
        //     if (i!=0 && path[i]=='/' && path[i-1]=='/'){
        //         path.erase(i, 1);
        //         i--;//i--是为了下次的i++后还在这个位置
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
            //当s.empty()时， s=="."操作合不合法？ 合法，可以比较
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
        //用双向队列明显更好一点
        //标准答案用的是vector，明显更好一点，stack能做的，vector都能做，vector还可以遍历
        // reverse(ans.begin(), ans.end());
        return ans==""?"/":ans;
    }
};
