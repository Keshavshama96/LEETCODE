// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
        
//         //edge case(agar s1 bda hai s2 se)0
//         if(s1.size()>s2.size()) return false;
//         //sort s1
//         sort(s1.begin(),s1.end());
//         //jitna k ka size hai utna pehle hi rok lo i ko kyuki nhi to out of bound (s2.size()-s1.size())
//         for(int i=0;i<=s2.size()-s1.size();i++){
//              //s1 size ki substring nikaal lo
//              string substring=s2.substr(i,s1.size());
//              //substring ko sort krdo
//              sort(substring.begin(),substring.end());
             
//          //check s1==substring
//          if(s1==substring){
//             return true;
//          }
            
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.size()>s2.size()) return false;
      //vector for s1
      vector<int>s1_vec(26,0);
      //vector for s2
      vector<int>s2_vec(26,0);
      //marking the s1 characters in the s1_vec
      for(char ch:s1){
          s1_vec[ch-'a']++;
      }

      int i=0;
      int j=0;
      while(j<s2.size()){
        s2_vec[s2[j]-'a']++;
        //abhi chota hai window
        if(j-i+1<s1.size()){
            j++;
        }//window hit
        else if(j-i+1==s1.size()){
         if(s1_vec==s2_vec){//valid 
            return true;
         }else{
            s2_vec[s2[i]-'a']--;
            i++;
         }
          j++;
        }
      }   
     return false;
    }
};