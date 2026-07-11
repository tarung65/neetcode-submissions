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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev_node = NULL;
        ListNode* curr_node = head;
        ListNode* next_node = head->next;
        while(next_node){
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
            next_node = next_node->next;
        }
        curr_node->next = prev_node;
        return curr_node;
    }
};
