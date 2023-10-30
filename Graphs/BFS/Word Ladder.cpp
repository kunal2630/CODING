//Same as genetic mutation question

    int ladderLength(string s, string e, vector<string>& b) {

        queue<pair<string,int>> q;
        q.push({s,1});
        map<string,int> mp;
        while(!q.empty()){


            string word=q.front().first;
            int m=q.front().second;
            q.pop();

            for(int i=0;i<b.size();i++){

                string bword=b[i];
                int diff=0;

                for(int j=0;j<word.size();j++){


                    if(word[j]!=bword[j]){

                        diff++;
                    }


                }

                if(diff==1 && (mp.find(bword)==mp.end() || mp[bword]>m+1)){

                    q.push({bword,m+1});
                    mp[bword]=m+1;
                }
            }
        }

        auto it=mp.find(e);

        if(it==mp.end()) return 0;
        return it->second;
        
    }
