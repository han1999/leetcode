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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vt;
        ListNode *p=head;
        while (p!=nullptr){
            vt.push_back(p->val);
            p=p->next;
        }
        sort(vt.begin(), vt.end());
        p=head;
        int cnt=0;
        while (p!=nullptr){
            p->val=vt[cnt++];
            p=p->next;
        }
        return head;
    }
};
