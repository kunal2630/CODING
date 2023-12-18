/*

    In getRandom() function - 

    We need to return random number from our stored set of numbers , so we can use random number generator function to generate random index of numbers then just return the number stored at that index

    randomIndex= rand() % num.size();
    Modulus with num.size() will ensure that we will get index value as 0 to num.size()-1
    
    So we have to maintain a mapping for number with their index 


    */
    vector<int> num;

    //for mapping number and their index in the num array
    unordered_map<int,int>  mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(mp.find(val)!=mp.end()) return false;

        //Pushed new number in the array at the last
        num.push_back(val);

        //Updated map by assigning index to the lastest value
        mp[val]=num.size()-1;

        return true;
        
    }
    
    bool remove(int val) {
        
         /*

         Removing item from num array takes O(n) time  as we have traverse the array complete for finding the element but we can improve it 

         As we are storing  each element index in the map , so to remove the current element just get the index of the element you want to remove from the map , at that index place the last element of the num , and remove the last element of num in O(1) using num.pop_back() 

         */
         
         
         if(mp.find(val)==mp.end()) return false;

         //Getting index of the number we want to remove from map
         int idx=mp[val];
         int lastNum=num.back();

        //removing val from num , by storing last number at its place
        num[idx]=lastNum;

         //assigning new index to the last number of num
         mp[lastNum]=idx;

         
       

         num.pop_back();
         mp.erase(val);
         
        return true;

    }
    
    int getRandom() {
        
        return num[rand()%num.size()];
    }
