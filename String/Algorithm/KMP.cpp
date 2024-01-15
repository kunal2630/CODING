//we calculated lps so that if any time our character didnt match we dont have to start from index 0 we can start at lps[j-1]
        void generateLPS(string& pat,vector<int>& lps){
            
            //len is the len of lps from index 0 to curr index
            int len=0;
            
            //lps[0]=0
            int i=1;
            
            while(i<pat.size()){
                
                if(pat[i]==pat[len]){
                    
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    
                    //if current character didnt match for curr lps length , try for smaller lps length
                    if(len!=0){
                        
                        len=lps[len-1];
                    }
                    //if len becomes 0 means no lps possible at current index
                    else{
                        
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            
            vector <int> ans;
            int n=txt.size();
            int m=pat.size();
            vector<int> lps(m,0);
            generateLPS(pat,lps);
            
            int i=0,j=0;
            while(i<n){
                
                if(txt[i]==pat[j]){
                    
                    i++;
                    j++;
                }
                else if(i<n && txt[i]!=pat[j]) {
                    
                    if(j>0) j=lps[j-1];
                    else i++;
                }
                
                //means we have found 1 pattern
                if(j==m){
                    
                    //since we have pass index as 1 based indexing therefore we did +1 , else pattern match at i-j only 
                    ans.push_back(i-j+1);
                    
                    //for finding another pat instead of starting from 0 we placed  j at lps[j-1]
                    j=lps[j-1];
                }
                
            }
            
            return ans;
        }
