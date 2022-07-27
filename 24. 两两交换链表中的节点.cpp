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
    void print(ListNode *head){
        while (head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    ListNode* swapPairs(ListNode* head) {
        //solution1:
        // if (!head) return nullptr;
        // ListNode *dummy=new ListNode(-1, head);
        // ListNode *p=dummy;
        // while (p){
        //     ListNode *pre=p;
        //     /*
        //     l和r如果不给初值nullptr的话，会一直保持上次循环的值
        //     */
        //     ListNode *l=nullptr,*r=nullptr;
        //     if (p->next){
        //         p=p->next;
        //         l=p;
        //     }
        //     if (p->next){
        //         p=p->next;
        //         r=p;

        //     }
        //     if (!l || !r) return dummy->next;
        //     l->next=r->next;
        //     r->next=l;
        //     pre->next=r;
        //     p=l;
        //     // cout<<l->val<<" "<<r->val<<" "<<endl;
        //     // print(dummy->next);
        // }
        // return dummy->next;

        // // solution2:
        // // 其实很简单，solution1怎么想的那么复杂呢
        // ListNode *dummy=new ListNode(-1, head);
        // ListNode *p=dummy;
        // while (p->next && p->next->next){
        //     ListNode *l=p->next;
        //     ListNode *r=p->next->next;
        //     l->next=r->next;
        //     r->next=l;
        //     p->next=r;
        //     p=l;
        // }
        // return dummy->next;

        //solution3：
        if (!head || !head->next) return head;
        ListNode *newHead=head->next;
        head->next=swapPairs(head->next->next);
        newHead->next=head;
        return newHead;

    }
};
