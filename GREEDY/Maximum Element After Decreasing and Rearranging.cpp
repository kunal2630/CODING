/*

    INTUITION -

    Rearrange the elements of arr to be in any order,this line give hint that we can sort the array ,
    Also no need to change array values as we only need adjacent value we can use a varaible last to store last index arr value
    We can only decrease the value not increase it , and we need max number so compare two adjacent number if their absolute differenc is >1 
    then decrease the larger number till it is in range(ex if two adjacent number is 5 and 59 then definatly to make it  abs(arr[i] - arr[i - 1]) <= 1
    we cahnge 59 to 6 or update last value as last+1)   and if two adjacent number is 5 and 6 then just update last as 6

 */

    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
       
        sort(arr.begin(),arr.end());
        int last=1;

        for(int i=1;i<arr.size();i++){

            if(abs(arr[i]-last)>1){

                last=last+1;

            }
            else{

                last=arr[i];
            }
        }

        return last;

       
    }
