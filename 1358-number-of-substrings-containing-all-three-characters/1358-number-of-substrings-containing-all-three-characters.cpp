// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int result=0;
//         for(int i=0;i<s.size();i++){
//              int a=0;
//              int b=0;
//              int c=0;
//             for(int j=i;j<s.size();j++){
                
//                if(s[j]=='a') a++;
//                else if (s[j]=='b') b++;
//                else if (s[j]=='c') c++;
                
//                  if(a>0 && b>0 && c>0) result++;
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int result=0;
        int i=0;
        int j=0;
        while(j<s.size()){ 
         mp[s[j]]++;// Naya character window me add karo agar already hai to uski freq increase kro
         // Agar abhi tak a, b ya c me se koi ek bhi missing hai
         // to window ko aur expand karo
         if(mp['a']==0 || mp['b']==0 || mp['c']==0){
            j++;
         }  // Agar teeno characters mil gaye
         else if(mp['a']>0 && mp['b']>0 && mp['c']>0){
            // Jab tak window valid hai,
            // har valid window ke liye answer add karo
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                //mtlb valid hai ab 
               result=result+(n-j);//result
               // Left se window ko shrink karo
                mp[s[i]]--;
                // Left pointer aage badhao
                i++;
            }// Right pointer ko next character par le jao
            j++;
         }
         
        }
        return result;
    }
};
