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

        //solution1: 链表难点就是不知道下标，放到vt里面就知道下标了
        // vector<ListNode *> vt;
        // ListNode *p=head;
        // while (p){
        //     vt.push_back(p);
        //     p=p->next;
        // }
        // int l=0, r=vt.size()-1;
        // /*
        // 这个判断条件还是有意思的
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
        下面这个写法，容错性更好
        */
        // ListNode *l2=midNode->next;
        // midNode->next=nullptr;
        // l2=reverseList(l2);

        ListNode *l2=reverseList(midNode);
        /*
        说到底还是为了解决一个下标的问题,把后半部分翻转，就能实现从后到前遍历效果
        */
        /*
        注意是&&
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
        加上这个是为了保险，否则会出现循环的情况
        如果l2是从mid+1开始，就不会有问题
        */
        midNode->next=nullptr;
    }
};
