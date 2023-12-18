class Solution {
public:
   
   /*

   We have to find the total number of papers (called as h index ) which have received at least h citation  and this h values should be max , for example if h valu is 3 then our array should have at least 3 paper whose citation value is atleast 3

   Clearly our answer would be between 0 to size of citations array as maximum value of h could be equal to total number of paper

   */
   
    int hIndex(vector<int>& citations) {
        
        int n=citations.size();
        sort(begin(citations),end(citations));

        //Start traversing from last so that the moment we got our answer it would be maximum  
        for(int i=n;i>=1;i--){

            //used lower bound to find the number of element of citation haveing index of atleast i 

            //lower bound return pointer , pointing to first element if duplicate target element is present, and points to immediate greater element than target if target element not present and  n-idx will give number of that element


            int idx=lower_bound(citations.begin(),citations.end(),i)-citations.begin();

            if((n-idx)>=i) return i;
        }
        return 0;
    }
};
