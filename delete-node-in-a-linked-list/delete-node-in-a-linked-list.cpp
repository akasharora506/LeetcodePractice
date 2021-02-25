/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=node;
        while(node->next){
            swap(node->val,node->next->val);
            prev=node;
            node=node->next;
        };
        prev->next=NULL;
        delete node;
    }
};