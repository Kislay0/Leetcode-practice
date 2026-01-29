class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<bool> available(recipes.size(),false);
        unordered_set<string> supp(supplies.begin(), supplies.end());
        while(true){
            bool flag = true;
            for (int i = 0; i<recipes.size(); i++){
                if(available[i]) continue;
                bool possible = true;
                for (string material: ingredients[i]){
                    if (!supp.count(material)){
                        possible = false;
                        break;
                    }
                }
                if(possible) {
                    supp.insert(recipes[i]);
                    available[i] = true;
                    flag = false;
                }
            }
            if (flag) break;
        }
        vector<string>ans;
        for (int i = 0; i<recipes.size(); i++){
            if (available[i]) ans.push_back(recipes[i]);
        }
        return ans;
    }
};