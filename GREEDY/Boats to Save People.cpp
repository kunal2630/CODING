
/*

INTUITION -

Same logic as used in question  Leetcode 1877. Minimize Maximum Pair Sum in Array
If two person weight is <=limit thne take both the person at once else take a person 
whose weight was greater as person with less weight may be taken in future with people having more weight

*/

    int numRescueBoats(vector<int>& people, int limit) {
        

        int n=people.size();
        sort(people.begin(),people.end());
        int i=0,j=n-1;
        int cnt=0;
        while(i<=j){

            if(people[i]+people[j]>limit){

                
                j--;
            }
            else{

                i++;
                j--;
                
            }
            cnt++;

        }

        return cnt;
    }
