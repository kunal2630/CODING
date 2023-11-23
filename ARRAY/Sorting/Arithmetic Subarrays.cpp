
    /*

    Intuition - Do as asked in the question , it is pretty simple and also since contraints are less O(n^2) solution is acceptable

    Traverse in l took starting index from l and ending index from r , form a array with element taken from nums between index l and r 

    sort it and compare two adjacent element difference , if same true included in the  answer else false 

    */
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        for(int i=0;i<l.size();i++){

            int j=l[i];
            int k=r[i];
            if(k-j+1<2){

                ans.push_back(false);
                break;
            }
            else{
            vector<int> temp;
            for(int l=j;l<=k;l++){

                temp.push_back(nums[l]);
            }

            sort(temp.begin(),temp.end());
            int firstDiff=temp[1]-temp[0];
            bool check=true;
            for(int z=1;z<temp.size();z++){

                if(temp[z]-temp[z-1]!=firstDiff){
                   ans.push_back(false);
                   check=false;
                   break;
                }
            }
            if(check)ans.push_back(true);

            }

        }

        return ans;
    }
