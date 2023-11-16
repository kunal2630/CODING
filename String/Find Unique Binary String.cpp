/*
 
 Bruteforce Approach -

  Since we have to find binary String of length n missing in nums array we can find all possible binary string of length n 
  and then find which string is not present in nums

 */  
    //Recursive approach to find all possible string of length n 
    void generateAllString(int idx,string temp,vector<string>& allString,int n){

        if(idx>=n){

            allString.push_back(temp);
            return;
        }

        //Take 1 , not take 0
        generateAllString(idx+1,temp+='1',allString,n);
        
        //backtrack
        temp.pop_back();

        //Take 0 , not take 1
        generateAllString(idx+1,temp+='0',allString,n);

         //backtrack
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        vector<string> allString;
        string temp="";
        int n=nums.size();
        generateAllString(0,temp,allString,n);

        //used map to store all string of nums so that i can find it later easily
        unordered_map<string,int> mp;
        for(auto it:nums){

            mp[it]=1;
        }

        for(auto it:allString){

            //If not present in nums that is our answer
            if(mp.find(it)==mp.end()){

                return it;
            }
        }

        return "";
    }

   

/*

 //Optimised Approach 

   We have to find such a string which is not present in nums, so how can we ensure that the string we write is not present in nums

   Answer - we write a string which is different from all string present in nums 

   Take first string of nums and whatever is the first character of that string write its opposite so with this we can ensure that aleast our answer string will not be same as first string of nums since we have changed first character , similarly do it for all string of nums 

Ex-  nums = ["01","10"]
     nums[0][0]='0'  ==> ans[0][0]='1' ==> not equal to first string of nums
     nums[1][1]='0'  ==> ans[1][1]='1' => not equal to second string of nums
    ==> no teqaul to any string of nums

*/
   
    string findDifferentBinaryString(vector<string>& nums) {
        
        string ans="";
        int n=nums.size();
        for(int i=0;i<n;i++){

            ans += (nums[i][i]=='0'?'1':'0');

        }
        return ans;
        
    }
