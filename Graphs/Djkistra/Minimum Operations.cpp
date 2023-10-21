/*
  
  Problem link - https://www.codingninjas.com/studio/problems/minimum-operations_8360665?
utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

  */

int minimumOperations(int n, int start, int end, vector<int> &a)
{
   


    /*

     Reason for using djkistra -

     1.Start is given
     2.End is given
     3.Asking about minimum cost/Operation
     4.Edge weight - 1(Same for all)
     5.Fixed nodes - 1000 because everytime we do multiplication we are supposed
       to do mod of it with 1000 so all the multiplication values have be between 0 to 1000
     6.No need of priority_queue as eveytime distance/cost is increasing by 1 only so queue
       will automatically store distances in increasing order

    */
    



    queue<pair<int,int>> q;
    q.push({0,start});
    vector<int> dis(1000,1e9);
    dis[start]=0;

    while(!q.empty()){

        int size=q.size();

        while(size--){

            int node=q.front().second;
            q.pop();
            
            //For every node it can be multiplied with all array values
            
            for(int i=0;i<n;i++){

                int newnode=(node*a[i])%1000;

                if(dis[node]+1<dis[newnode]){

                    dis[newnode]=dis[node]+1;
                    q.push({dis[newnode],newnode});
                }
            }

        }
        
        

    };

    return dis[end]==1e9?-1:dis[end];
}
