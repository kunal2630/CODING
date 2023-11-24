 /*

    INTUITION -

    We know everytime Alice will pick the maximum value coin and bob will pick least value coin , so I will always pick second most value coin , traverse from back in sorted array and start picking 2nd value

    */
    int maxCoins(vector<int>& piles) {

       sort(begin(piles),end(piles));
       int i=0;
       int j=piles.size()-2;
       int ans=0;
       while(i<j){

           ans +=piles[j];
           j -=2;
           i++;

       } 

       return ans;
    }
