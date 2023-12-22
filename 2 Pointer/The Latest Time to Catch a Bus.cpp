 int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());

        int j=0;
        int n=buses.size();
        int m=passengers.size();
        int last_time=0;
        int prev=0;

        for(int i=0;i<n;i++){

            int cnt=0;

            //for each buses[i] we will try to find the last time at which we can arrive at bus station
            while( j<m && passengers[j]<=buses[i] && cnt<capacity){

                //prev is last time when some passenger arrived at bus station so we can't also arrive at station at that same time and passengers[j]-1 is time we are trying to reach the station and clearly passengers[j]-1 and  prev should not be equal 
                if( passengers[j]-1 !=prev){

                       last_time =passengers[j]-1;
                }
                cnt++;
                prev=passengers[j];
                j++;
            }
            
            //means seat available in bus ,so we can take that bus as it could be the last bus which will maximize last_time
            if(cnt<capacity && buses[i] !=prev) last_time=buses[i];


        }

        return last_time;
    }
