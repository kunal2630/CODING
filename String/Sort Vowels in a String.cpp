 /*

    ASCII value of 'A' is 65 
    ASCII value of 'a' is 97 

    So lexigraphically A comes before a , brute approach is simple just store vowel and consonant separately consonant at the same place as in the original string , whereas vowel as you like , then sort it

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
