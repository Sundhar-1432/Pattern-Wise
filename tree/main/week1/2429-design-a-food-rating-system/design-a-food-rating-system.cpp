class FoodRatings {
public:
    unordered_map<string, pair<string, int>> food_map; 
    unordered_map<string, set<pair<int,string>>> high_rate; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food_map[foods[i]] = {cuisines[i], ratings[i]};
            high_rate[cuisines[i]].insert({-ratings[i],foods[i]});

        }
    }

    void changeRating(string food, int newRating) {
       auto [name,rate]=food_map[food];

       high_rate[name].erase({-rate,food});
       high_rate[name].insert({-newRating,food});
       food_map[food].second=newRating;
    }

    string highestRated(string cuisine) {
        return high_rate[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */