/*

    Traverse the linked list and and elements in answer matrix in spiral order
    
    Abbreviation - 
    sr-Starting row
    sc-Starting col
    er-Ending row
    ec-Ending col

    */
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        int sr=0,er=m-1,sc=0,ec=n-1;
        int cnt=0;
        
        while(head!=NULL){
            
            for(int i=sc;i<=ec;i++){
                
               if(head!=NULL) {
                   ans[sr][i]=head->val;
                   head=head->next;
                   
               }
            }
            sr++;
             for(int i=sr;i<=er;i++){
                
               if(head!=NULL) {
                   ans[i][ec]=head->val;
                   head=head->next;
                   
             }
            }
            ec--;
             for(int i=ec;i>=sc;i--){
                
               if(head!=NULL) {
                   ans[er][i]=head->val;
                   head=head->next;
                   
               }
            }
            er--;
             for(int i=er;i>=sr;i--){
                
               if(head!=NULL) { 
                   ans[i][sc]=head->val;
                   head=head->next;
                  
               }
            }
            sc++;
            
            
        }
        
        return ans;
        
    }
