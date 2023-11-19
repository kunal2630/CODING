class Solution {
public:

    /*

    INTUITION - Everytime we need two largest value in the array , whenever we need more than one maximum or minimum value think of sorting as it will give maximum or minimum adjacently

    Basically we have to change larger element into smaller as a result at last all last all the element will be changed to smallest element

    So we can have two cases if we start traversing from last - 1. two adjacent element are equal in this case do nothing 
    2.adjacent element are not equal , so in this case we have to change larger element into smaller one , but ensure that we have to change not only the current ith element , but also all the element to the right of it , then only we can make sure all the element are equal


    */
    int reductionOperations(vector<int>& nums) {
        
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int cnt=0;

      for(int i=n-1;i>0;i--){

          if(nums[i]!=nums[i-1]){
              
              //count of element we have to change to the right of current element
              cnt+=n-i;
          }

      }

      return cnt;
    }
};
