 string decodeString(string s) {

       //in case of parenthesis , or pattern we use stack
        stack<char> st;
        string ans="";
        for(auto& it:s){

            //if current character is not a closing bracket just put it in stack

            if(it!=']'){

                st.push(it);
            }

            //if current character is closing bracket 
            else{ 

                string num="";
                string word="";

                //find all letter in the current [] that is till we dont get '['
                while(!st.empty() && st.top()>='a' && st.top()<='z' ){

                    word+=st.top();
                    st.pop();
                }

                //remove '['
                 st.pop();

                //store digits 

                while(!st.empty() && st.top()>='0' && st.top()<='9'){

                    num+=st.top();
                    st.pop();
                }
                //since we traversing stack,reverse word and num to find current pattern
                reverse(num.begin(),num.end());

                int repeat=stoi(num);
                string wordToRepeat=word;
                while(repeat>1){

                    word+=wordToRepeat;
                    repeat--;
                }

                reverse(word.begin(),word.end());

                //again pushed in stack , so if nested bracket is present in s we can deal with it
                for (int k = 0; k < word.size(); k++) {
                    st.push(word[k]);
                }
            }
  
        }

        while(!st.empty()){

            ans +=st.top();
            st.pop();
        }

                reverse(ans.begin(),ans.end());

        return ans;
        
    }
