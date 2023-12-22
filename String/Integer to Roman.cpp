    string intToRoman(int num) {
        
        /*

        1897 = 1000 + 800 + 90 +7 

        Try to break the number according to their places(tens,unit, hundred )

        Store closest roman for number like for 100,400,500,900,1000 etc 

        Clearly 200,300,700,800 ,600 can be written using 100,500or 1000 so didnt store that 


        */

      //Approach -1 
      
        vector<pair<int,string>> v={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

        string ans="";
 
        //Start traversing from 0th index assigning roman value
        for(int i=0;i<v.size();i++){

            while(num>=v[i].first){

                ans +=v[i].second;
                num -=v[i].first;
            }
        }

        return ans;
    


    //Optimal

        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundred[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousand[]={"","M","MM","MMM"};

        return thousand[num/1000]+hundred[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];

    }
