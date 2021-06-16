class Codec {
public:
    TreeNode* convert(vector<int> &tree,int &c){
        if(c>=tree.size()||tree[c]==INT_MAX){
            c++;
            return NULL;
        };
        TreeNode* root=new TreeNode(tree[c]);
        c++;
        root->left=convert(tree,c);
        root->right=convert(tree,c);
        return root;
    }
    string preorder(TreeNode* root){
        if(!root)
            return ",NULL";
        return ","+to_string(root->val)+
            preorder(root->left)+preorder(root->right);
    }
    string serialize(TreeNode* root) {
        return preorder(root);
    }

    TreeNode* deserialize(string data) {
        int i=0,j=1;
        vector<int> tree;
        cout<<data<<endl;
        while(j<data.length()){
            while(j<data.length()&&data[j]!=',')j++;
            string curr=data.substr(i+1,j-i-1);
            int temp=curr=="NULL"?INT_MAX:stoi(curr);
            tree.push_back(temp);
            i=j;
            j++;
        };
        int c=0;
        return convert(tree,c);
    }
};
