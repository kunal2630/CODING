vector<vector<int>> findMatrix(vector<int>& nums) {

      //We have to use as less row as possible so for that maximum element has to be put in same row  , use new row only when current el is being repeated that is present in some row

    //Approach 1

      vector<vector<int>> ans;
      int rowCnt=0;
      unordered_map<int,unordered_set<int>> mp;
      mp[rowCnt].insert(nums[0]);
      int n=nums.size();
      for(int i=1;i<n;i++){

          bool inserted=false;

          //for each element find a row where it wont become repeated if inserted , the moment we find that row insert the element in that row

          for(auto& it:mp){

              auto rowEl=it.second;
              if(rowEl.find(nums[i])==rowEl.end()){

                  rowEl.insert(nums[i]);
                  mp[it.first]=rowEl;
                  inserted=true;
                  break;
              }
          }

          //if current element is being repeated in all row , insert it in a new row
          if(!inserted){

              rowCnt++;
              mp[rowCnt].insert(nums[i]);
          }

      }  

      for(auto it:mp){

          vector<int> temp(it.second.begin(),it.second.end());
          ans.push_back(temp);
      }

      return ans;



    //Optimal 

    vector<vector<int>> ans;
    int n=nums.size();

    //since given in constraint 1 <= nums[i] <= nums.length
    vector<int> freq(201,0);

    
    for(int i=0;i<n;i++){

        if(freq[nums[i]]>=ans.size()){

            ans.push_back({});
        }

        ans[freq[nums[i]]].push_back(nums[i]);
        freq[nums[i]]++;
    }

    return ans;



    }
