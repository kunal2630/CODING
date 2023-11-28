 /*

    If we have two section which contain two seats then we can place as many partion between them as there are plants present between them so we have to find  seats section then find plants between them , suppose first section last seat is at ith index and second section first seat is at jth index so we can easily find number of plants between them by join j-i and that will be total partiotion between them

    So do this process for every partion and club their result by doing multiplication as total no of partition can be calculated like that

    */
    int mod=1e9+7;
    int numberOfWays(string corridor) {
        
        long long  ans=1;
        vector<int> v;

        //storing every seat index present in corridor
        for(int i=0;i<corridor.size();i++){

            if(corridor[i]=='S') v.push_back(i); 
        }

        //if  total number of seats is odd then we can never club them all in group of two so return 0
        if(v.empty() || v.size()%2!=0) return 0;

        
        //No of plants between two section can be found using last index of last section and first index of current section
        for(int i=1;i<v.size()-1;i+=2){

            ans=(ans*(v[i+1]-v[i]))%mod;
        }
        return ans;
    }
