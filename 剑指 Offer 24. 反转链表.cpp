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
        ������������Ǻܼ򵥵�һ���⣬����һ��ʼ��Ȼ�е���
        �ܽᣬ���ַ�ת�͵Ŀ϶���һ��pre
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
