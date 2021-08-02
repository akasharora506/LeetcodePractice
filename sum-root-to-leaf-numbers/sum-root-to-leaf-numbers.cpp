/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void help(TreeNode* root,unordered_multiset<string> &v,string s=""){
    //     if(!root)
    //         return;
    //     if(!root->left&&!root->right){
    //         v.insert(s+to_string(root->val));
    //         return;
    //     };
    //     help(root->left,v,s+to_string(root->val));
    //     help(root->right,v,s+to_string(root->val));
    // }
    // int sumNumbers(TreeNode* root) {
    //     unordered_multiset<string> v;
    //     help(root,v);
    //     int ans=0;
    //     for(auto i:v){
    //         ans+=stoi(i);
    //     };
    //     return ans;
    // }
    int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return 0;
		int sum = 0;
		auto trie = unordered_map<const TreeNode*, int>();
		auto dfs = vector<TreeNode*>(1, root);
		while (dfs.size()) {
			const TreeNode * n = dfs.back();
			dfs.pop_back();
			const int val = trie[n] * 10 + n->val;
			if (n->left == NULL && n->right == NULL)
				sum += val;	// Add val into sum if it's a leave
			else {
				if (n->left) {
					trie[n->left] = val;	// Save the val (from root to parent)
					dfs.emplace_back(n->left);
				}
				if (n->right) {
					trie[n->right] = val;
					dfs.emplace_back(n->right);
				}
			}
		}
		return sum;
	}
};