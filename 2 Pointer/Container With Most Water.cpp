int maxArea(vector<int>& height) {

       /*

       Intuition - Our aim to maximum width and height , that why using two pointer we started from start-end pair which will maximise our width and to maximise left and right height we traverse such that if left height is less we increment i else we decrement j 



       */
       int ans=0;
       int i=0;
       int j=height.size()-1;

       while(i<j){

           ans=max(ans,min(height[i],height[j])*(j-i));

           if(height[i]<height[j]){

               i++;

           }
           else{

               j--;
           }

       }

       return ans;
    }
