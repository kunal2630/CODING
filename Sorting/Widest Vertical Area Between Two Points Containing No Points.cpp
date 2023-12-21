 int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
       //Confusing problem description but its just asking us to Find largest horizontal distance between two adjacent points.
        sort(points.begin(),points.end());
        int maxi=0;
        int n=points.size();
        for(int i=1;i<n;i++){

            maxi=max(maxi,points[i][0]-points[i-1][0]);
        }
        return maxi;
    }
