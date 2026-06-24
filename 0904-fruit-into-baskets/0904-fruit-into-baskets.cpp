class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxfruits=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
             
             if(mp.size()<=2){
             maxfruits=max(maxfruits,j-i+1);
             j++;
             }
             else if(mp.size()>2){
              while(mp.size()>2){
                 mp[fruits[i]]--;
                 if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                 }
                 i++;
              }
              j++;
             }
        }
        return maxfruits;
    }
};