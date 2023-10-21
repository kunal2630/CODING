
    
    //Aproach 1 -

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

    //Aproach 2 -

    /*

    From Approach 1 we know that  stack<NestedInteger>  st - so clearly our stack holds NesterInteger complete obj which is taking is lot of sapce to improve space complexity instead of storing complete object we could just store address

    To get address we use - &
    To store adreess we use - *
    To access value from pointer we use -  ->
    

    */

     //I could also have used : stack<NestedInteger> but, using pointer will help me save space
    stack<NestedInteger*> st;

    NestedIterator(vector<NestedInteger> &nestedList) {

        int n=nestedList.size();
        for(int i=n-1;i>=0;i--){

            //&obj - to store address
            st.push(&nestedList[i]); 
        }


        
    }
    
    int next() {

        int num=st.top()->getInteger();
        st.pop();
        return num;
        
    }
    
    bool hasNext() {

        
        while(!st.empty()){

            NestedInteger* curr=st.top();

            
            if(curr->isInteger()){

                return true;
            }

            st.pop();

            vector<NestedInteger>& v=curr->getList();

            for(int i=v.size()-1;i>=0;i--){

                st.push(&v[i]);
            }
        }
        
        //if stack is empty
        return false;

        
    }

 //Approach -3  - Bets Time and space Complexity

    /*

    The problem with 1st and 2nd approach was that we are most of the task in hasNext() , but we know that in program hasNext() and 
    next() are called multiple times but first function which is a constrructor function it is callled once si do most of 
    the calculation in this constructor function so that hasNext() and next() can be implemented in O(1) time 

    Steps - We can open complete nested list in the constructor function 


    */

    //To store complete list

    //Store address instead of object to reduce space
    queue<NestedInteger*> q;

    void openList(vector<NestedInteger> &nestedList){

        int n= nestedList.size();

        for(int i=0;i<n;i++){

            NestedInteger& obj=nestedList[i];

          
            if(obj.isInteger()){

                //Curent element is a Integer type
                q.push(&obj);
            }

            else{

                 //Curent element is a List type , so call the recursion with currentList
                openList(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {

        openList(nestedList);
        
    }
    
    int next() {

        int el=q.front()->getInteger();
        q.pop();
        return el;
        
    }
    
    bool hasNext() {

        return !q.empty();
        
    }
