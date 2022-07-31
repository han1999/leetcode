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

    /*
    solution2: 
    标准的递归排序
    */
    ListNode *merge2Lists(ListNode* l1, ListNode *&l2){
        if (!l1) return l2;
        else if (!l2) return l1;
        else if (l1->val<l2->val){
            l1->next=merge2Lists(l1->next, l2);
            return l1;
        }else {
            l2->next=merge2Lists(l1, l2->next);
            return l2;
        }
    }

    ListNode *mergeSort(vector<ListNode *> &lists, int l, int r){
        if (l==r) return lists[l];
        if (l>r) return nullptr;
        int mid=(l+r)/2;
        auto l1=mergeSort(lists, l, mid);
        auto l2=mergeSort(lists, mid+1, r);
        return merge2Lists(l1, l2);
    }

    /**
    以后凡是涉及到，指针，int这些基本类型的参数，一律不用引用
    加快不了速度，而且容易 出错
    */
    struct cmp{
        bool operator () (const ListNode* l1, const ListNode *l2) const{
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // // solution1: 方法虽然笨，但是确实能通过
        // // if (lists.empty()) return {};
        // vector<int> ans;
        // for (auto & p:lists){
        //     while (p){
        //         ans.push_back(p->val);
        //         p=p->next;
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // ListNode *head=new ListNode(-1);
        // ListNode *p=head;
        // for (auto const &val:ans){
        //     p->next=new ListNode(val);
        //     p=p->next;
        // }
        // return head->next;


        // return mergeSort(lists, 0, lists.size()-1);


        //solution3:
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (const auto &l:lists){
            // 如果不判断是不是nullptr，是不是cmp就比较不了，因为有空指针呢
           if(l) pq.push(l);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *p=dummy;
        while (!pq.empty()){
            ListNode *minList=pq.top();
            p->next=new ListNode(minList->val);
            p=p->next;
            pq.pop();
            if (minList->next) pq.push(minList->next);
        }
        return dummy->next;
    }
};
