//2022.07.26 
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
    ListNode* needReverse(ListNode *p, int k){
        for (int i=0; i<k; i++){
            if (!p) break;
            p=p->next;
        }
        return p;
    }

    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail){
        ListNode *pre=tail->next;
        ListNode *p=head;
        while (pre!=tail){
            ListNode *nextP=p->next;
            p->next=pre;
            pre=p;
            p=nextP;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // // solution1：
        // ListNode *dummy=new ListNode(-1, head);
        // ListNode *pre=dummy;
        // ListNode *p=pre->next;
        // while (needReverse(pre, k)){
        //     ListNode *nowPre=pre;
        //     for (int i=0; i<k; i++){
        //         ListNode *nextP=p->next;
        //         p->next=pre;
        //         pre=p;
        //         p=nextP;
        //     }
        //     nowPre->next->next=p;
        //     swap(pre, nowPre->next);
        // }
        // return dummy->next;


        // //solution2:
        // ListNode *dummy=new ListNode(-1 ,head);
        // ListNode *pre=dummy;
        // ListNode *p=pre->next;
        // ListNode *tail;
        // while (tail=needReverse(pre, k)){
        //     ListNode *lastPre=pre->next;
        //     pre->next=tail;
        //     pre=tail->next;
        //     while (pre!=tail){
        //         ListNode *nextP=p->next;
        //         p->next=pre;
        //         pre=p;
        //         p=nextP;
        //     }
        //     pre=lastPre;
        // }
        // return dummy->next;

        //solution3:
        ListNode *dummy=new ListNode(-1, head);
        ListNode *pre=dummy;
        ListNode *p=pre->next;
        ListNode *tail;
        /**
        语法检查好神奇，下面这个!=nullptr有时候不写能通过，有时候不写通过不了
        */
        while ((tail=needReverse(pre, k))!=nullptr){
            auto pairs=reverse(pre->next, tail);
            pre->next=pairs.first;
            pre=pairs.second;
        }
        return dummy->next;

    }
};
