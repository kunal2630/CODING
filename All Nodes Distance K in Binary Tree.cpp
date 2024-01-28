//From target node we have to find all nodes at a distance k whether the node is below or up , so in a tree we can move down but cant move up , but in graph we can do that so just make a graph (adj) from tree , then do dfs from target and find all nodes at a distance k

    void dfs(int node,vector<int>& ans,int k,unordered_map<int,int>& vis,unordered_map<int,vector<int>>& adj){

        if(k==0){

            ans.push_back(node);
            return;
        }

        vis[node]=1;

        for(auto& it:adj[node]){

            if(!vis[it]){

                dfs(it,ans,k-1,vis,adj);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,vector<int>> adj;
        while(!q.empty()){

            int size=q.size();
            while(size--){

                TreeNode* node=q.front();
                q.pop();
                if(node->left){

                    q.push(node->left);
                    adj[node->val].push_back(node->left->val);
                    adj[node->left->val].push_back(node->val);
                }
                if(node->right){

                    q.push(node->right);
                    adj[node->val].push_back(node->right->val);
                    adj[node->right->val].push_back(node->val);
                }
            }
        }
        vector<int> ans;
        unordered_map<int,int> vis;

        //since all nodes are unique there is no issue in taking target->val but if tree could have duplicate value then we have to take target as node not its value 
        dfs(target->val,ans,k,vis,adj);
        return ans;
    }
