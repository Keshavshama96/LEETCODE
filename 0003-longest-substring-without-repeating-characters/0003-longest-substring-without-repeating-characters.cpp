class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int i=0;
        int j=0;
       int maxlen=0;
        while(j<s.size()){
         mp[s[j]]++;
             // agr mp ka size == window size ...mtlb valid hai 
           if(mp.size()==j-i+1){
              maxlen=max(maxlen,j-i+1);
              j++;
           }//winodw bdi hai mtlb koi to duplicate aagya ab 
           else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){//jab tak bdi hai window size
                    mp[s[i]]--;//left waale ki frquency kam kro
                    if(mp[s[i]] == 0) {//agar frequency 0 ho gayi
                        mp.erase(s[i]);//map se remove karo
                    }
                    i++;//shrink window
                }
              j++;
           }
        }
    return maxlen;
    }
};