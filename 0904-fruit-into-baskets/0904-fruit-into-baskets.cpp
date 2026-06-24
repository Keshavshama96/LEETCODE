class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxfruits=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;//current fruit ki frequency increase
            
             if(mp.size()<=2){//mtlb 2 fruits (valid)
             maxfruits=max(maxfruits,j-i+1);//updation of the maxfruits
             j++;
             }
             //window shrinking 
             else if(mp.size()>2){//mtlb invalid window
              while(mp.size()>2){
                 mp[fruits[i]]--;//kam kro frequency left se
                 if(mp[fruits[i]]==0){//// fruit completely removed
                    mp.erase(fruits[i]);//htado
                 }
                 i++;//shrink
              }
              j++;
             }
        }
        return maxfruits;
    }
};