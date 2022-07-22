///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        // ListNode *l3=nullptr;
//        ListNode*l3=new ListNode();
//        ListNode *pre=l3;
//        int carry=0;
//        while (l1!=nullptr || l2!=nullptr){
//            int val1=l1==nullptr?0:l1->val;
//            int val2=l2==nullptr?0:l2->val;//all empty ones are 0
//            int temp=val1+val2+carry;//first add carry,then %. not first % then add carry.
//            //notice: 999999, 99
//            int nowVal=temp%10;
//            ListNode *last=new ListNode(nowVal);
//            //because l3's head's val is not null, we have to discuss 2 cases
//            //however, we can let l3's headnode's val be null, and return the headnode's next
//            // if (pre==nullptr){
//            //     pre=last;
//            //     l3=last;
//            // }else{
//                pre->next=last;
//                pre=last;
//            // }
//            carry=temp/10;
//            //add a judge, because l1 or l2 may get to the end, but the while will not end.
//            if (l1!=nullptr) l1=l1->next;
//            if (l2!=nullptr) l2=l2->next;
//        }
//        if (carry){
//            pre->next=new ListNode(carry);
//        }
//        return l3->next;
//    }
//};


/*
以下写法不对，这道题第一次写的时候，还能写出来，现在就写不出来了，哎
*/ 

////  Definition for singly-linked list.
//#include <stdio.h>
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode *ans=new ListNode();
//        ListNode *p1=l1;
//        ListNode *p2=l2;
//        ListNode *p=ans;
//        int carry=0;
//        while (p1!=nullptr && p2!=nullptr){
//            int sum=p1->val+p2->val+carry;
//            carry=sum/10;
//            p->val=sum%10;
//            printf("%d",p->val);
//            // todo
//            p1=p1->next;
//            p2=p2->next;
////            if (p1!=nullptr && p2!=nullptr){
//                p->next=new ListNode();
//                p=p->next;
////            }
//        }
//        while (p1!=nullptr){
//            int sum=p1->val+carry;
//            p->val=sum%10;
//            carry=sum/10;
//            p1=p1->next;
//            if (p1!=nullptr){
//                p->next=new ListNode();
//                p=p->next;
//            }
//        }
//        while (p2!=nullptr){
//            int sum=p2->val+carry;
//            p->val=sum%10;
//            carry=sum/10;
//            p2=p2->next;
//            if (p2!=nullptr){
//                p->next=new ListNode();
//                p=p->next;
//            }
//        }
//        return ans;
//    }
//};
//
//int main(){
//	ListNode *l1=new ListNode(9);
//	ListNode *p=l1;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	
//	ListNode *l2=new ListNode(9);
//	p=l2;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	p->next=new ListNode(9);
//	p=p->next;
//	
//	Solution solution;
//	solution.addTwoNumbers(l1,l2);
//} 


/**
看了上次的思路，写出来的 我感觉也挺巧妙的
但是感觉上次的思路更好一点 
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode *p=ans;
        int carry=0;
        ListNode *pre=nullptr;
        while (l1!=nullptr || l2!=nullptr){
            int val1=l1==nullptr?0:l1->val;
            int val2=l2==nullptr?0:l2->val;
            int sum=val1+val2+carry;
            p->val=sum%10;
            carry=sum/10;
            p->next=new ListNode();
            pre=p;
            p=p->next;
            if (l1!=nullptr){
                l1=l1->next;
            }
            if (l2!=nullptr){
                l2=l2->next;
            }
        }
        if (carry){
            p->val=carry;
        }
        if (p->val==0) pre->next=nullptr;
        return ans;
    }
}; 
