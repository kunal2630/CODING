 string originalDigits(string s) {
        
                
             /*
             
               Problem in this question was to know that is f is coming then that f is for four or five because that f is for five and we have taken four then at last some character would be left in s , which we dont want so somehow we have uniquely identify each character that like if z is there it would be only for zero
               
               
              
                Unique & Single Characters

                one, two, three, four, five, six, seven, eight, nine
                z - zero
                w - two
                u - four
                x - six
                g - eight

                one, three, five, seven, nine
                o - one
                t - three
                f - five
                s - seven
                i - nine

             */
        
               string ans="";
                int fre[26];
                memset(fre,0,sizeof(fre));
        
                vector<pair<pair<char, char>, string>> v = 
                    
                                    {{{'z', '0'}, "zero"}, {{'w', '2'}, "two"}, {{'u', '4'}, "four"}, 
                                    {{'x', '6'}, "six"}, {{'g', '8'}, "eight"}, {{'o', '1'}, "one"}, 
                                    {{'t', '3'}, "three"}, {{'f', '5'}, "five"}, {{'s', '7'}, "seven"}, 
                                    {{'i', '9'}, "nine"}};
        
               for(auto& it:s){
                   
                   fre[it-'a']++;
               }
               for(auto& it:v){
                   
                   char digitChar=it.first.first;
                   char digit=it.first.second;
                  
                   string digitInWords=it.second;
                   int freOfDigit=fre[digitChar-'a'];
                   for(int i=1;i<=freOfDigit;i++){
                       

                       
                       ans +=digit;
                       for(auto& it:digitInWords){
                       
                          fre[it-'a']--;
                       }
                   }

                   
               }
               sort(ans.begin(),ans.end());
        return ans;
    }
