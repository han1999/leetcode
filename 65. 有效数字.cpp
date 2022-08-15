class Solution {
public:
    //solution1: 
    //��Ȼд�����ˣ���������ֳ��ֳ�
    bool isInteger(string s){
        if (s.empty()) return false;
        int digitCnt=0;
        for (const auto &ch:s){
            if (ch!='+' && ch!='-' && !isdigit(ch)) return false;
            if (isdigit(ch)) digitCnt++;
        }
        if (digitCnt==0) return false;
        if (s.find("+")!=s.npos && s.find_last_of("+")!=0) return false;
        if (s.find("-")!=s.npos && s.find_last_of("-")!=0) return false;
        cout<<"isInteger"<<endl;
        return true;
    }

    bool isDecimal(string s){
        if (s.empty()) return false;
        if (s.find("+")!=-1 && s.find_last_of("+")!=0) return false;
        /*
        if�����ж�����ʽ�Ļ�������if else
        */
        // else s.erase(s.begin());
        if (s.find("-")!=-1 && s.find_last_of("-")!=0) return false;
        // else s.erase(s.begin());
        int digitCnt=0;
        for (const auto &ch:s){
            if (ch!='+' && ch!='-' && ch!='.' && !isdigit(ch)) return false;
            if (isdigit(ch)) digitCnt++;
        } 
        if (!digitCnt) return false;
        if (count(s.begin(), s.end(), '.')!=1) return false;
        cout<<"isDecimal"<<endl;
        return true; 
    }


    bool isEValid(string s, int index){
        string lStr=s.substr(0, index);
        string rStr=s.substr(index+1);
        return (isDecimal(lStr) || isInteger(lStr)) && isInteger(rStr);
    }
    bool isNumber(string s) {
        int eIndex=s.find('e');
        int EIndex=s.find('E');
        /*
        ���ﾹȻ����һ���﷨����if else else �ǲ��Ϸ���
        */
        if (eIndex==s.npos && EIndex==s.npos){
            return isDecimal(s) || isInteger(s);
        }else if (eIndex!=s.npos) return isEValid(s, eIndex);
        else return isEValid(s, EIndex);
    }
};
