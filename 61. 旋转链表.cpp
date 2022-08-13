/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {};
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // ListNode *ans=new ListNode(-101, nullptr)
        //以下方法行不通，无法形成环
        // if (!head) return nullptr;
        // ListNode *p=head;
        // int size=0;
        // while (p){
        //     p=p->next;
        //     size++;
        // }
        // ListNode *preNode=nullptr, *nowNode=head;
        // int preVal=nowNode->val;
        // while (1){
        //     for (int i=0; i<k%size; i++){
        //         nowNode=nowNode->next?nowNode->next:head;
        //     }
        //     cout<<nowNode->val<<endl;
        //     swap(nowNode->val, preVal);
        //     if (nowNode==head) break;
        // }
        // return head;


        // //solution1: 类似于双指针 好笨的方法
        // if (head==nullptr) return head;
        // ListNode *temp=head;
        // int size=0;
        // while(temp){
        //     temp=temp->next;
        //     size++;
        // }
        // ListNode *ans=new ListNode(-101);
        // ListNode *p=ans;
        // for (int i=0; i<size; i++){
        //     p->next=new ListNode(-101, nullptr);
        //     p=p->next;
        // }
        // p=ans->next;
        // for (int i=0; i<k%size; i++){
        //     p=p->next;
        // }
        // ListNode *nowNode=head;
        // while (nowNode){
        //     p->val=nowNode->val;
        //     nowNode=nowNode->next;
        //     p=p->next?p->next:ans->next;
        // }
        // return ans->next;

        //solution2:
        //理论上不难，我应该能想到的，但是为啥没想到呢
        //今天状态实在不行，对于链表，并不需要真正去
        if (k==0 || head==nullptr || head->next==nullptr) return head;
        int size=1;
        ListNode *p=head;
        while (p->next){
            p=p->next;
            size++;
        }
        p->next=head;
        for (int i=0; i<size-k%size; i++){
            p=p->next;
        }
        ListNode *ans=p->next;
        p->next=nullptr;
        return ans;



    }
};
