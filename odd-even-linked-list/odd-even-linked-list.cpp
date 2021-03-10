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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *ansOdd=NULL,*ansEven=NULL,*oddTail=NULL,*evenTail=NULL,*curr=head;
        int counter=1;
        while(curr){
            if(counter%2){
                if(oddTail)
                    oddTail->next=curr,oddTail=oddTail->next;
                else
                    ansOdd=curr,oddTail=curr;
                
            }else{
                if(evenTail)
                    evenTail->next=curr,evenTail=evenTail->next;
                else
                    ansEven=curr,evenTail=curr;
                
            };
            curr=curr->next;
            counter++;
        };
        if(oddTail)oddTail->next=NULL;
        if(evenTail)evenTail->next=NULL;
        if(ansOdd)
            oddTail->next=ansEven;
        else
            return ansEven;
        return ansOdd;
    }
};