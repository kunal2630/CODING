/*

     //Bruteforce approache can be to find all subsequence of string s and then find the greatest length subsequence whose decimal value is <=k , but we know that find all subsequence of lenght n array or string takes 2^n time and n here is 1 <= s.length <= 1000 and 2^1000 is very large than 10^8 hence we will get TLE so we have to think of some bteer approach

     So we need longest subsequence with less total decimal value and in a binary substring value can be 0 and if we include 0 in our subsequence than its decimal value will be 0 and we can include  as many 0 in our answer as can , ex - if our s="00000000" its decmimal value will be 2^0*0+2^1*0+2^0*0.... = 0

     Whereas in case of 1 the more we move towards left the more value it will give in decimal value 
     Ex - 01010 - 2^4*0+2^3*1+2^2*0+2^1*1+0 

     So to get maximum value we should take 0 and take 1 from rightmost of s string and the moment our subsequence decimal value exceeds k , we stop taking 1 and only take 0 if present 

    */

    int longestSubsequence(string s, int k) {
        
        int cnt=0;
        int n=s.size();

        int digitSum=0;

        //Take this way as pow(2,n) if n is large will give out of bound error
        long long int powerOfTwo=1;

        for(int i=n-1;i>=0;i--){

            //take 0
            if(s[i]=='0') cnt++;

            //take 1 only if digitsum is <=k
            else if(s[i]=='1' && digitSum<=k){

                digitSum +=powerOfTwo;
                if(digitSum<=k) cnt++;

            }

            //for every index update power of two so that we can use it in future whereever required
            if(powerOfTwo *2<INT_MAX) powerOfTwo *=2;

        }

        return cnt;
    }
