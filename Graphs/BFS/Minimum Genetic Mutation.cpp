
    /*

    We have to change starting word to ending word , so at a time we are allowed to change 1 characters from starting word and if after changing letter of the word if the new word which formed is present in bank then it will be 1 mutation ,so we have return such min number of mutation

    Whenever there is question of changing one word to another and we need something minimum think of bfs



    */
    int minMutation(string s, string e, vector<string>& b) {

        if(s==e) return 0;
       
        queue<pair<string,int>> q;

        //push starting word into queue and its mutaion is 0
        q.push({s,0});

        //map to keep track of word and its mutation
        map<string,int> mp;
        mp[s]=0;

        while(!q.empty()){

            string temp=q.front().first;
            int m=q.front().second;
            q.pop();

            //Trying to change current word into one of the bank words

            for(int i=0;i<b.size();i++){

                string word=b[i];

                //To store how many different letters are present in curr word and bank word
                int diff=0;

                    for(int j=0;j<8;j++){

                        if(temp[j]!=word[j]){

                            diff++;
                        }
                    }

                    // as we are allowed to change one word at a time

                    if(diff==1){                   
                        
                        
                        //We will push the current bank word in the queue only if no of mutation taken by it is less than earlier muation 
                        if(mp.find(word)==mp.end() || mp[word]>m+diff) {


                            q.push({word,m+diff});
                            mp[word]=m+diff;

                        }
                    }
  
            }
        }

        auto it=mp.find(e);

        //If end word is not in map means we have not able to reach end so return -1
        if(it==mp.end()){

            return -1;
        }
        
        return it->second;

       
        
    }
