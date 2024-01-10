 /*

    In a minute an infected node can infect all its neighbours, but in a tree based structure from a node we can can access only its left and right child not above two child , so used map based approach where i stored all the neighnours of a node in a map , then did a bfs traversal on that map to find the time in which all the node will get infected  
    */
    unordered_map<int,vector<int>> mp;

    void preorder(TreeNode* root){

        if(root==NULL) return;
        if(root->left!=NULL){

            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);

        }
        if(root->right!=NULL){

            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }

        preorder(root->left);
        preorder(root->right);


    }
    int amountOfTime(TreeNode* root, int start) {
        
        preorder(root);
        queue<int> q;
        unordered_map<int,int> infected;
        q.push(start);
        int ans=0;
        while(!q.empty()){

            int size=q.size();
            while(size--){
                int infectedNode=q.front();
                q.pop();
                infected[infectedNode]=1;

                for(auto it:mp[infectedNode]){

                    if(infected[it]!=1){

                        q.push(it);
                    }

                }
            }

            ans++;

        }  
        return ans-1;      
    }
