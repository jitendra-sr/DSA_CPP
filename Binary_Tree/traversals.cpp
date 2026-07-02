// Boilerplate Code for Iterative Traversals of Binary Tree
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

// Preorder: NLR
// Inorder: LNR
// Postorder: LRN

class Solution {
    // The problem is that a normal stack gives you Root first, so we use a trick: generate the reverse of postorder and then reverse it.
    // So we will create the opposite of postorder (LRN->NRL), and then reverse it.
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> res;
        stack<TreeNode*> st;

        while(true){
            while(root){
                res.push_back(root->val);
                st.push(root);
                root=root->right;
            }
            
            if(st.empty()) break;
            TreeNode* node=st.top(); st.pop();
            root=node->left;
        }

        reverse(res.begin(),res.end()); // It is only for postorder
        return res;
    }
};

// All traversals of a binary tree in a single traversal

class Solution1 {
    vector<int> pre, in, post;

    void fun(TreeNode* root){
        if(!root) return;
        
        pre.push_back(root->val);
        if(root->left) fun(root->left);

        in.push_back(root->val);
        if(root->right) fun(root->right);

        post.push_back(root->val);

        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        pre.resize(0);
        in.resize(0);
        post.resize(0);

        fun(root);

        return post;
    }
};


class Solution2 {
    // num==1 -> inorder, num==2 -> preorder, num==3 -> postorder
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> pre, in, post;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});

        while(!st.empty()){
            TreeNode* node=st.top().first;
            int num=st.top().second;
            st.pop();

            if(num==1){ // pre list, change 1 to 2, push left
                pre.push_back(node->val);
                st.push({node,++num});
                if(node->left) st.push({node->left,1});
            }
            else if(num==2){ // in list, change 2 to 3, push right
                in.push_back(node->val);
                st.push({node,++num});
                if(node->right) st.push({node->right,1});
            }
            else{ // post list, num==3
                post.push_back(node->val);
            }
        }

        return post;
    }
};