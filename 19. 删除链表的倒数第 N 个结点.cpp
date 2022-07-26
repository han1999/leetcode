// 2022.07.26 00.00-00.07 几分钟就写完了，挺容易的 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /**
        solution1： 不带头结点
        */
        // ListNode *r=head;
        // for (int i=0; i<n; i++){
        //     r=r->next;
        // }   
        // ListNode *l=head;
        // if (!r){
        //     return head->next;
        // }
        // while (r->next){
        //     l=l->next;
        //     r=r->next;
        // }
        // l->next=l->next->next;
        // return head;

        /*
        solution2： 带头结点
        明显带头结点的普遍写法更具有普适性！！
        */
        ListNode *dummy=new ListNode(0, head);
        ListNode *r=dummy;
        for (int i=0; i<n; i++){
            r=r->next;
        }
        ListNode *l=dummy;
        while (r->next){
            l=l->next;
            r=r->next;
        }
        /**
        这个是真删除，虽然在oj的时候并没有什么用
        */
        ListNode *toDelte=l->next;
        l->next=toDelte->next;
        delete toDelte;
        return dummy->next;
    }
};
