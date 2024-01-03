class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
       //Just have to find number of security device in each row and then start taking count of two  devices as a pair and calculate answer  that is if total security devices in each row are - {3,0,2,0,5,8} we can find tottal laser as - 3*2 +2*5+5*8 (just ignore 0 an take a pair one at a time)
       
        
      //Approach 1 - Taking extra space to store count of security device in each row 

      class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int> device;
        for(auto it:bank){

            int cnt=0;
            for(auto de:it){

                if(de=='1') cnt++;
            }

            device.push_back(cnt);
        }
        int oldDevice=-1;
        int ans=0;

        for(auto& it:device){

            if(it>0 && oldDevice==-1){

                oldDevice=it;
            }
            else if(it>0 && oldDevice!=-1){

                ans +=(it*oldDevice);
                oldDevice=it;

            }
        }

        return ans;
    }
};
      
      
      
      //Approach 2 - Space Optimised
        int prev=0,ans=0;

        for(auto& it:bank){

            int cnt=0;
            for(auto& de:it){

                if(de=='1') cnt++;
            }

            if(cnt>0){

                ans +=prev*cnt;
                prev=cnt;
            }

        }
      
        return ans;
    }
};
