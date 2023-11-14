 /*

    Intuition -

    First thought is of to use basic subsequence method of pick, not pick and form all 3 length subsequence and check whether it can form a palindrome or not .
    But due to high constraint this method will give TLE. So we have to think some other approach

    So we have three length subsequence , so we can observe that for 3 length subsequence firstCharacter and lastCharacter of the subsequence must be same middle
    character can be anything So if any character comes only once in s it can never from 3 length palindrome subsequence which start with this character

    Also we want unique subsequence For  ex - s="aaaaaa" then no of unique 3 length palindromic subsequence is 1 .

    So we can start iterating in s and for every unique character we find its first occurence and last ocuurence because all character present in s between 
    its firstoccurence an dlastoccurence can take part in forming panildrome subsequence 

    And to get unique palindrome subsequence we can iterate from firstIndex+1 to lastINdex-1 and then store all found character in a set and at last 
    whatever setsize is that is our noof uniqiue palindromic subsequence form this cahracter


*/

    int countPalindromicSubsequence(string s) {
        
        int n=s.length();
        int ans=0;

        /* To store first and last inde x of every character */

        // vector<int> firstIndex(26,-1);
        // vector<int> lastIndex(26,-1);

        
        vector<pair<int,int>> index(26,{-1,-1});

        // for(int i=0;i<n;i++){

        //     if(firstIndex[s[i]-'a']==-1){

        //         firstIndex[s[i]-'a']=i;
        //     }
        // }
        // for(int i=n-1;i>=0;i--){

        //     if(lastIndex[s[i]-'a']==-1){

        //         lastIndex[s[i]-'a']=i;
        //     }
        // }

        for(int i=0;i<n;i++){

            char ch=s[i];

            /* Means we are seeing this character for the first time */
            if(index[ch-'a'].first==-1){

                index[ch-'a'].first=i;
            }

            index[ch-'a'].second=i;
        }

        /* Get all the unique present in s and then find its first and last index , find how many unique charcater present between them*/

        // unordered_set<char> uniChar;
        // for(auto& it:s){

        //     uniChar.insert(it);

        // }

       //for(auto& it:uniChar){

       /*We can get our unique letters from index array only no need to store in it set*/
      
           for(int i=0;i<26;i++){

            int fIndex=index[i].first;
            int lIndex=index[i].second;

            if(fIndex!=-1 && lIndex!=-1){

               
               /*Finding how many unique charcater present between firstIndex and lastINdex*/
                unordered_set<char> uc;
                for(int i=fIndex+1;i<lIndex;i++){

                    uc.insert(s[i]);


                }

                ans +=uc.size();
            }

      
        }

          return ans; 


    }
