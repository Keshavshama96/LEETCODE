class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //edge case(agar s1 bda hai s2 se)0
        if(s1.size()>s2.size()) return false;
        //sort s1
        sort(s1.begin(),s1.end());
        //jitna k ka size hai utna pehle hi rok lo i ko kyuki nhi to out of bound (s2.size()-s1.size())
        for(int i=0;i<=s2.size()-s1.size();i++){
             //s1 size ki substring nikaal lo
             string substring=s2.substr(i,s1.size());
             //substring ko sort krdo
             sort(substring.begin(),substring.end());
             
         //check s1==substring
         if(s1==substring){
            return true;
         }
            
        }
        return false;
    }
};