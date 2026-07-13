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
    struct CompareNodes{
        bool operator()(ListNode* a, ListNode* b){
            return a->val >b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*,std::vector<ListNode*>,CompareNodes> minpq;
        ListNode dummyNode(0);
        for(ListNode* list : lists){
            if(list)
                minpq.push(list);
        }
        ListNode* currNode = &dummyNode;
        while(!minpq.empty()){
            ListNode* node = minpq.top();
            minpq.pop();
            currNode->next = node;
            if(node->next)
                minpq.push(node->next);
            currNode = currNode->next;
        }
        return dummyNode.next;
    }
};
