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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head = NULL;
        ListNode* l1p = list1;
        ListNode* l2p = list2;
        ListNode* curr_p = NULL;
        if(list1->val < list2->val){
            head = list1;
            l1p = list1->next;
        } else {
            head = list2;
            l2p = list2->next;
        }
        curr_p =head;
        while(l1p &&l2p){
            if(l1p->val < l2p->val){
                curr_p->next = l1p;
                l1p = l1p->next;
            } else {
                curr_p->next = l2p;
                l2p = l2p->next;
            }
            curr_p = curr_p->next;  
        }
        if(l1p)
            curr_p->next = l1p;
        else 
            curr_p->next = l2p;
        return head;
    }
};
