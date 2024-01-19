 int maxRotateFunction(vector<int>& nums) {
        
 // Intuition -       
/*

        From example 1 it is clear that we have to rotate array every time by k where k can be from 0 to n-1 since after n rotation rotated array becomes original array, so somehow we have to do rotaation n times and for every rotation we have to calculate i*nums[i] which will again take O(n) time so T.C would be O(n^2) which would give TLE

        So somehow we have to either find a possible k which will give optimal  product(i*nums[i]) without taking O(n) time or optimise this operation (i*nums[i]+((i+1)*nums[i+1])+...) so that we dont have to do thisa opertaiion again and again

        For finding optimal k direct thought of  - Binary Search on answer which after some dry run realise not work here ,soritng not work so only solution  left  is finding relation between F(k) and F(K-1) 


        Let the array elements be: [a b c d e].

    Length of array represented by N = 5
    Sum of elements of array represented by SUM = a + b + c + d + e

    Now, as per the question :

    F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d) + (4 * e) = 0 + b + 2c + 3d + 4e
    F(1) = (1 * a) + (2 * b) + (3 * c) + (4 * d) + (0 * e) = a + 2b + 3c + 4d + 0
    F(2) = (2 * a) + (3 * b) + (4 * c) + (0 * d) + (1 * e) = 2a + 3b + 4c + 0 + e

    Now subtracting 2 equations,

    F(1) - F(0) = a + b + c + d - 4e = a + b + c + d + e - 5e
    Therefore, F(1) = F(0) + a + b + c + d + e - 5e = F(0) + SUM - N*e

    F(2) - F(1) = a + b + c + e - 4d = a + b + c + d + e - 5d
    Therefore, F(2) = F(1) + a + b + c + d + e - 5d = F(1) + SUM - N*d

    Generalizing it, we get the following relation:

    F(K) = F(K-1) + SUM - N * (( K-1)th element from end of array)
    i.e. F(K) = F(K-1) + SUM - N * (array [N - 1 - (K-1)]) = F(K-1) + SUM - N * (array [N - K])

*/

        int n=nums.size();
        int sumOfProd=0,sum=0;
        

        //Calculating F(0) 
        for(int i=0;i<n;i++){

            sumOfProd +=(i*nums[i]);
            sum+=nums[i];
        }
        //F(0) can also be one of the answer
        int ans=sumOfProd;
        int lastValue=sumOfProd;

        //calulating all F(k) using previous F(k-1)
        for(int k=1;k<n;k++){

            int currValue= lastValue + sum -(n*nums[n-k]);
            lastValue=currValue;
            ans=max(ans,currValue);

        }
        return ans;
        

    }
