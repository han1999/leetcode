class CQueue {
public:
    stack<int> stk1, stk2;
    CQueue() {
        /*
        �ҵ��죬stack��Ȼû��clear
        */
        // stk1.clear();
        // stk2.clear();
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        // //solution1: �������ţ�ʱ�临�Ӷȸ���
        // if (stk1.empty()) return -1;
        // while (stk1.size()!=1){
        //     stk2.push(stk1.top());
        //     stk1.pop();
        // }
        // int ans=stk1.top();
        // stk1.pop();
        // while (!stk2.empty()){
        //     stk1.push(stk2.top());
        //     stk2.pop();
        // }
        // return ans;

        //solution2:
        if (!stk2.empty()){
            int ans=stk2.top();
            stk2.pop();
            return ans;
        }else {
            if (stk1.empty()){
                return -1;
            }else {
                while (stk1.size()!=1){
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                int ans=stk1.top();
                stk1.pop();
                return ans;
            }
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
