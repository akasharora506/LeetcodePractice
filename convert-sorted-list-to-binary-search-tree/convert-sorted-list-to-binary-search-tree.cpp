class Solution {
public:
    TreeNode* help(ListNode* r,int s,int e){
        if(s>e)
            return NULL;
        ListNode* mid=r;
        int k=(e+s)/2;
        while(k--)mid=mid->next;
        TreeNode *root=new TreeNode(mid->val);
        if(root)root->left=help(r,s,(e+s)/2-1);
        if(root)root->right=help(r,(e+s)/2+1,e);
        return root;
    };
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        int n=0;
        ListNode *temp=head;
        while(temp)temp=temp->next,n++;
        
        return help(head,0,n-1);
    }
};