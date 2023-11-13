 /*

    ASCII value of 'A' is 65 
    ASCII value of 'a' is 97 

    So lexigraphically A comes before a , brute approach is simple just store vowel and consonant separately consonant at the same place as in the original string ,
    whereas vowel as you like , then sort it

    Then combine vowel and consonant together

    */

    //Bruteforce
    string sortVowels(string s) {

        int n=s.length();
        vector<char> temp(n,' ');
        vector<char> vowel;
        string ans="";

        for(int i=0;i<n;i++ ){

            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'  ){

                vowel.push_back(s[i]);
            }
            else{

                temp[i]=s[i];
            }
        }

        //sorted it in descending order so that for taking out element from the vowel array i dont have to manage index just take last element using back() and then do pop_back()
        sort(vowel.begin(),vowel.end(),greater<int>());

        for(int i=0;i<n;i++){

            if(temp[i]==' '){

                temp[i]=vowel.back();
                vowel.pop_back();
            }
        }
        
        for(auto it:temp){

            ans +=it;
        }
        return ans;
        
    }

  

    //OPTIMAL 

    /*

    Editorial explanation - The important point to observe here is that the string temp will only have ten different characters, as there are five vowels and their corresponding upper-case letters. In such scenarios, where the length is much greater than the number of distinct characters, it's much more efficient to use counting sort. This is because we will just have to count the frequencies for just ten characters instead of sorting all the characters in the string temp. We will store the frequencies of these vowels in a map count.

Since we know the ten characters we can have in the string temp, to get the ascending order of temp we can just iterate over the ten vowels in their ASCII order with their count. Hence, we will keep the string sortedVowels which will be equal to AEIOUaeiou which represents the ten vowels in ascending order of their ASCII values.

    */

    bool isVowel(char ch){

        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;

        return false;
    }
    
       string sortVowels(string s) {

       
        //To store frequency of each vowel 
        unordered_map<char,int> vowelCount;
        string ans="";

        for(auto it:s){

            if(isVowel(it)){

                vowelCount[it]++;
            }
            
        }


        string sortedVowel="AEIOUaeiou";
        int j=0;
        
        for(auto it:s){

            if(!isVowel(it)){

                ans +=it;

            }
            else{

                while(vowelCount[sortedVowel[j]]==0) j++;

                ans +=sortedVowel[j];
                vowelCount[sortedVowel[j]]--;
            }
        }
        return ans;
        
    }
