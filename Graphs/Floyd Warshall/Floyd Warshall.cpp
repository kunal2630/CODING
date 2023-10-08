void shortest_distance(vector<vector<int>>&mat){
	    // Code here
	    
	    int n=mat.size();
	    int m=mat[0].size();
	    
	    for(int i=0;i<n;i++){
	        
	        for(int j=0;j<m;j++){
	            
	            if(mat[i][j]==-1) mat[i][j]=1e9;
	        }
	    }
	    
	    for(int via=0;via<n;via++){
	        
	        for(int i=0;i<n;i++){
	        
    	        for(int j=0;j<m;j++){
    	            
    	            mat[i][j]=min(mat[i][j],(mat[i][via]+mat[via][j]));
    	        }
	         }
	    }
	    
	     for(int i=0;i<n;i++){
	        
	        for(int j=0;j<m;j++){
	            
	            if(mat[i][j]==1e9) mat[i][j]=-1;
	        }
	    }
	    
	    
	   // for(int i=0;i<n;i++){
	        
	   //     if(mat[i][i]<0) cout<<"Negative Cycle";
	   // }
	}
