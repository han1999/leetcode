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
    ListNode *getMidNode(ListNode *head){
        ListNode *slow=head, *fast=head;
        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head){
        ListNode *pre=nullptr;
        ListNode *p=head;
        while (p){
            ListNode *nextNode=p->next;
            p->next=pre;
            pre=p;
            p=nextNode;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        // ListNode *dummy=new ListNode(-1);
        // ListNode *p=dummy;
        // int len=0;
        // ListNode temp=head;
        // while (temp!=nullptr){
        //     len++;
        //     temp=temp->next;
        // }
        // for (int i=0; i<len; i++){
        //     p->next=
        // }

        //solution1: �����ѵ���ǲ�֪���±꣬�ŵ�vt�����֪���±���
        // vector<ListNode *> vt;
        // ListNode *p=head;
        // while (p){
        //     vt.push_back(p);
        //     p=p->next;
        // }
        // int l=0, r=vt.size()-1;
        // /*
        // ����ж�������������˼��
        // */
        // while (l<r){
        //     vt[l++]->next=vt[r];
        //     vt[r--]->next=vt[l];
        // }
        // vt[l]->next=nullptr;

        //solution2:
        ListNode *midNode=getMidNode(head);
        ListNode *l1=head;
        /*
        �������д�����ݴ��Ը���
        */
        // ListNode *l2=midNode->next;
        // midNode->next=nullptr;
        // l2=reverseList(l2);

        ListNode *l2=reverseList(midNode);
        /*
        ˵���׻���Ϊ�˽��һ���±������,�Ѻ�벿�ַ�ת������ʵ�ִӺ�ǰ����Ч��
        */
        /*
        ע����&&
        */
        while (l1!=midNode && l2){
            cout<<l1->val<<" "<<l2->val<<endl;
            ListNode *next1=l1->next;
            l1->next=l2;
            l1=next1;
            ListNode *next2=l2->next;
            l2->next=l1;
            l2=next2;
        }
        /*
        ���������Ϊ�˱��գ���������ѭ�������
        ���l2�Ǵ�mid+1��ʼ���Ͳ���������
        */
        midNode->next=nullptr;
    }
};
