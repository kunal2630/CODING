
//Bruteforce 

int ans=0;

    void timeToCollect(vector<string>& garbage, vector<int> preTravel,char garbageType){

        int lastHouseWhereGarbagepresent=-1;
        for(int i=0;i<garbage.size();i++){

            string houseGarbage=garbage[i];
            int cnt=0;
            for(int i=0;i<houseGarbage.size();i++){

                if(houseGarbage[i]==garbageType){

                    cnt++;
                }
            }
            if(cnt>0){

               lastHouseWhereGarbagepresent=i;
               ans+=cnt;
            }
        }

        if(lastHouseWhereGarbagepresent>0){
        ans +=preTravel[lastHouseWhereGarbagepresent-1];
        }
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
       
        vector<int> preTravel(travel.size(),0);
        preTravel[0]=travel[0];
        for(int i=1;i<travel.size();i++){

            preTravel[i] =travel[i]+preTravel[i-1];
        }
        timeToCollect(garbage,preTravel,'M');
        timeToCollect(garbage,preTravel,'P');
       timeToCollect(garbage,preTravel,'G');
       return ans;

  }


// Optimised-

/*

   Intuition - It doesnt matter which type of garbage is present , it will always take 1 unit of time to pick 

   Also a particular truck which is assigned to pick a specific type of garbage will go to house if that type of grarbage is present in that house , so for every type of garbage we can find which is the last house in which that type of garbage is present


   */

    int time=0;
   

    void timeToCollect(vector<string>& garbage, vector<int> preTravel){

        int lastHouseWhereGarbagetypeGpresent=-1,
            lastHouseWhereGarbagetypePpresent=-1,
            lastHouseWhereGarbagetypeMpresent=-1;

        for(int k=0;k<garbage.size();k++){

             string houseGarbage=garbage[k];

            for(int i=0;i<houseGarbage.size();i++){

                if(houseGarbage[i]=='G'){

                    
                    //keep on updating house no , and at last we will get last house no where garbage is present
                    lastHouseWhereGarbagetypeGpresent=k;
                }

                else if(houseGarbage[i]=='P'){
                     
                    
                      lastHouseWhereGarbagetypePpresent=k;
                }
                else{

                   
                     lastHouseWhereGarbagetypeMpresent=k;

                }

                
            }
            //1 unit timme for every garbnage time
            time +=houseGarbage.size();

           
        }

        //time taken to travel from house 0 to lst house where garbage type M is present
        if(lastHouseWhereGarbagetypeMpresent>0){
        time +=preTravel[lastHouseWhereGarbagetypeMpresent-1];
        }

        if(lastHouseWhereGarbagetypePpresent>0){
        time +=preTravel[lastHouseWhereGarbagetypePpresent-1];
        }

        if(lastHouseWhereGarbagetypeGpresent>0){
        time +=preTravel[lastHouseWhereGarbagetypeGpresent-1];
        }
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        //prefix sum to store travel time
        vector<int> preTravel(travel.size(),0);
        preTravel[0]=travel[0];
        for(int i=1;i<travel.size();i++){

            preTravel[i] =travel[i]+preTravel[i-1];
        }

        timeToCollect(garbage,preTravel);
       
       return time;

  }
