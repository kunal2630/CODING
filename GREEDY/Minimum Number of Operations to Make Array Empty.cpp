class Solution {
public:
    int minOperations(vector<int>& nums) {
        
       //Approach -1 


        unordered_map<int,int> mp;
        for(auto it:nums){

            mp[it]++;
        }
        int ans=0;
        for(auto& it:mp){

            int fr=it.second;
            
           // We try to make as much pair of 3 as possible 
           int maxDiv=fr/3;
           bool check=true;
           while(fr!=0 && maxDiv!=0){

               int rem=fr-(maxDiv*3);
               if(rem%2==0){

                   ans +=maxDiv;
                   fr=rem;
                   ans +=(fr/2);
                   fr=fr%2;
                   check=false;
                   break;
               }
               maxDiv--;
           }
           
           //if not possible for 3 , make it 2 
           if(check){

               if(fr%2==0){
                   ans +=(fr/2);
               }
               else{
                   return -1;
               }
           }
        }

        return ans;

        //Approach - 2 Optimal
 
        unordered_map<int,int> mp;
        for(auto it:nums){

            mp[it]++;
        }
        int ans=0;
        for(auto& [_,fr]:mp){

            if(fr==1) return -1;
                   
           // We try to make as much pair of 3 as possible 
            ans +=fr/3;

            if(fr%3) ans++;
        }

        return ans;

    }
};
