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
    /**
    很经典而有趣的一道题
    */
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //solution1:
        // ListNode *dummy=new ListNode();
        // ListNode *p=dummy;
        // ListNode *p1=list1;
        // ListNode *p2=list2;
        // while (p1 || p2){
        //     int val1=p1?p1->val:INT_MAX;
        //     int val2=p2?p2->val:INT_MAX;
        //     int nowVal=min(val1, val2);
        //     ListNode *tail=new ListNode(nowVal);
        //     p->next=tail;
        //     p=tail;
        //     if(val1<val2){
        //         p1=p1->next;
        //     }else {
        //         p2=p2->next;
        //     }
        // }
        // return dummy->next;

        // //solution2:
        // if (!list1){
        //     return list2;
        // }else if (!list2){
        //     return list1;
        // }else if (list1->val<list2->val){
        //     list1->next=mergeTwoLists(list1->next, list2);
        //     return list1;
        // }else {
        //     list2->next=mergeTwoLists(list1, list2->next);
        //     return list2;
        // }
        // return nullptr;
        // // 这里最后没有一个return 竟然不报错

        //solution3:
        ListNode *dummy=new ListNode(-1);
        ListNode *p=dummy;
        while (list1 && list2){
            if (list1->val<list2->val){
                p->next=list1;
                p=p->next;
                list1=list1->next;
            }else {
                p->next=list2;
                p=p->next;
                list2=list2->next;
            }
        }
        p->next=list1?list1:list2;
        return dummy->next;
    }
};
