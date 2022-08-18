/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode *dummy=new ListNode(-1);
        /*
        这道题理论上是很简单的一道题，但是一开始竟然有点懵
        总结，这种翻转型的肯定有一个pre
        */
        ListNode *p=head;
        ListNode *pre=nullptr;
        while (p){
            // ListNode *next=p->next;
            // ListNode *nextNext=next->next;
            // next->next=p;
            // p=
            ListNode *nextNode=p->next;
            p->next=pre;
            pre=p;
            p=nextNode;
        }
        return pre;
    }
};
