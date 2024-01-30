int evalRPN(vector<string>& tokens) {
        
        //Just use stack if any operator comes pop out two elements from stack do the operation on it and push it back in the stack
        stack<string> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){

            string curr=tokens[i];
            if(curr=="+" ||curr=="-" || curr=="*" || curr=="/"){

                
                int operand2=stoi(st.top());
                st.pop();
                int operand1=stoi(st.top());
                st.pop();
                
                if(curr=="+"){
                    
                    int val=operand1+operand2;
                    st.push(to_string(val));
                }
                else if(curr=="-"){
                     int val=operand1-operand2;
                     st.push(to_string(val));
                }
                else if(curr=="/"){
                     int val=operand1/operand2;
                     st.push(to_string(val));
                }
                else if(curr=="*"){
                     int val=operand1*operand2;
                     st.push(to_string(val));
                }
            }
            else{

                st.push(tokens[i]);
            }

        }
        return stoi(st.top());
    }
