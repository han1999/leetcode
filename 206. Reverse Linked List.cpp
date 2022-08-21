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
    ListNode* reverseList(ListNode* head) {
        //solution1:
        // ListNode *pre=nullptr;
        // ListNode *p=head;
        // while (p){
        //     ListNode *nextNode=p->next;
        //     p->next=pre;
        //     pre=p;
        //     p=nextNode;
        // }
        // return pre;

        //solution2:
        if (head==nullptr) return nullptr;
        ListNode *dummy=new ListNode(-1, head);
        ListNode *pre=dummy;
        ListNode *p=dummy->next;
        while (p->next){
            ListNode *pNext=p->next;
            p->next=pNext->next;
            pNext->next=pre->next;
            pre->next=pNext;
        }
        return dummy->next;
    }
};
