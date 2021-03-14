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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *one=head,*two=head,*temp=head;
        int tot=0;
        while(temp){
            tot++;
            temp=temp->next;
        };
        int ahead=tot-k;
        while(ahead--&&two->next){
            two=two->next;
        };
        k--;
        while(k--&&one->next){
             one=one->next;
        };
        swap(one->val,two->val);
        return head;
    }
};