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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> a,b;
        while(headA){
            a.push(headA);
            headA=headA->next;
        };
        while(headB){
            b.push(headB);
            headB=headB->next;
        };
        ListNode* ans=NULL;
        while(!a.empty()&&!b.empty()&&a.top()==b.top()){
            ans=a.top();
            a.pop();b.pop();
        };
        return ans;
    }
};