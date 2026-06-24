class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxfruits=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;//frequency increasing
            
             if(mp.size()<=2){//mtlb 2 fruits (valid)
             maxfruits=max(maxfruits,j-i+1);//updation of the maxlen
             j++;
             }
             //window shrinking 
             else if(mp.size()>2){//mtlb invalid
              while(mp.size()>2){
                 mp[fruits[i]]--;//kam kro frequency left se
                 if(mp[fruits[i]]==0){//mtlb left ko htana hai 
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