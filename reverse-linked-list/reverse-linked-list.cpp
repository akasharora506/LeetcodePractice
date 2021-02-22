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
        ListNode* prev=NULL;
        ListNode* ans = head;
        if(head)head = head->next;
        while(head){
            ans->next=prev;
            prev=ans;
            ans=head;
            head=head->next;
        };
        if(ans)ans->next=prev;
        return ans;
    }
};