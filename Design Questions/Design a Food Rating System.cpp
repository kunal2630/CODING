class FoodRatings {
public:

   /*

   Intuition -
    
    We can use three maps 

    Map 1-

    for changeRating function to change rating fast we need to store it in  a map so that we can access rating in O(1) time

   Map 2-

   To get highest rated food of any cuisine we can maintain a maping of cuisnes with foodss and their rating and store food and rating such that our first or last element can directly point to highest rated food , so we can use priority_queue or set(as ordered_set which is set  that store elements in ascending order)

   Map 3 -

   To update items in the second map we need cuisines for the food item so third map can be maintained for cuisnes and food


   Reason for storing ratings as -ve in the map 

   //first item will have highest absolute rating "we put all ratings in negative" (ordered_set)
        //Why did we not put them in ascending order and just return the last element of ordered_set ?
        //Ans : Because We can have a case like below
        //{(15, abc), (16, ramen), (16, sushi)} -> Order in ordered_set. last element is not lexicographically smaller
        //{(-16, ramen), (-16, sushi), (-15, abc)} -> First element is now lexicographically smaller

   

   */
    unordered_map<string,int> foodRating;
    unordered_map<string,set<pair<int,string>>> foodInf;
    unordered_map<string,string> foodCuisines;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        int n=foods.size();

        for(int i=0;i<n;i++){

            foodRating[foods[i]]=ratings[i];
            foodCuisines[foods[i]]=cuisines[i];
            foodInf[cuisines[i]].insert({-ratings[i],foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        
        string getCuisine=foodCuisines[food];
        int oldRating=foodRating[food];

        foodInf[getCuisine].erase({-oldRating,food});
        foodInf[getCuisine].insert({-newRating,food});
        foodRating[food]=newRating;



    }
    
    string highestRated(string cuisine) {
        
            return begin(foodInf[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
