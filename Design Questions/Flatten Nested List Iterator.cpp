class NestedIterator {
public:
    
    
    /*

    Always remember that flattening question can easily be done using stack or recursion , because if any time they ask about current value we can just return stack top

    So here st.top() contain NestedInteger obj but in question it is told that we need to always return Integer value so before returning we  did st.top().getInteger(); 
    
    to get integer value  Also we have to make sure that st.top() always contain Integer type object not List , we will mange that in hasNext().

    */
    
    //Stack to hold all nestedList items
    stack<NestedInteger>  st;

    NestedIterator(vector<NestedInteger> &nestedList) {

        //Inserrt all nestedList items in the stack in reverse order so that stack top will always contain element in serial order
        for(int i=nestedList.size()-1;i>=0;i--){

            st.push(nestedList[i]);
        }
        
    }
    
    int next() {

        //Get stack top value and returns it
        int num=st.top().getInteger();
        st.pop();
        return num;
        
    }
    
    bool hasNext() {

        while(!st.empty()){

            //Stack top contain nestedList items which is in actual NestedInteger object
            auto it=st.top();

            //If top value is of Integer type then no issues then straightaway return true
            if(it.isInteger()){

                return true;
            }

            //If top value is not of Integer type then we have to make sure that we are inserting Integer type values

            st.pop();

            //Ex- {{4,6},{7,8}} type values in  st.top() so store it in vector then insert it in stack in reverse order but continue this till we not get Integer type values in stack top
            
            vector<NestedInteger>& v=it.getList();
            for(int i=v.size()-1;i>=0;i--){


                st.push(v[i]);

            }
        }

        return false;
        
    }
