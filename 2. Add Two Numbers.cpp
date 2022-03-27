/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *l3=nullptr;
        ListNode*l3=new ListNode();
        ListNode *pre=l3;
        int carry=0;
        while (l1!=nullptr || l2!=nullptr){
            int val1=l1==nullptr?0:l1->val;
            int val2=l2==nullptr?0:l2->val;//all empty ones are 0
            int temp=val1+val2+carry;//first add carry,then %. not first % then add carry.
            //notice: 999999, 99
            int nowVal=temp%10;
            ListNode *last=new ListNode(nowVal);
            //because l3's head's val is not null, we have to discuss 2 cases
            //however, we can let l3's headnode's val be null, and return the headnode's next
            // if (pre==nullptr){
            //     pre=last;
            //     l3=last;
            // }else{
                pre->next=last;
                pre=last;
            // }
            carry=temp/10;
            //add a judge, because l1 or l2 may get to the end, but the while will not end.
            if (l1!=nullptr) l1=l1->next;
            if (l2!=nullptr) l2=l2->next;
        }
        if (carry){
            pre->next=new ListNode(carry);
        }
        return l3->next;
    }
};
