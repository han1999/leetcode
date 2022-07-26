// 2022.07.26 00.00-00.07 �����Ӿ�д���ˣ�ͦ���׵� 
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
        solution1�� ����ͷ���
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
        solution2�� ��ͷ���
        ���Դ�ͷ�����ձ�д�������������ԣ���
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
        �������ɾ������Ȼ��oj��ʱ��û��ʲô��
        */
        ListNode *toDelte=l->next;
        l->next=toDelte->next;
        delete toDelte;
        return dummy->next;
    }
};
