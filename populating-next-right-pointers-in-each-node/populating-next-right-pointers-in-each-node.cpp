class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
       Node * par=root,*curr=NULL;
        while(par->left){
            curr=par;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next)curr->right->next=curr->next->left;
                curr=curr->next;
            };
            par=par->left;
        };
        return root;
    }
};