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
    ListNode* middleNode(ListNode* head) {
        //solution1:
        // int len=0;
        // ListNode *p=head;
        // while (p){
        //     len++;
        //     p=p->next;
        // }
        // p=head;
        // for (int i=0; i<len/2; i++){
        //     p=p->next;
        // }
        // return p;

        // //solution2: 链表题常用的一种方法，用vt来装，可随机读取
        // vector<ListNode *> vt;
        // ListNode *p=head;
        // while (p){
        //     vt.push_back(p);
        //     p=p->next;
        // }
        // return vt[vt.size()/2];

        //solution3: 快慢指针 想到用双指针，没想到怎么实施
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
