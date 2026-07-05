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
            
         mp[s[j]]++;
         //abhi agar nhi hai a b and c mtlb aage jao abhi
         if(mp['a']==0 || mp['b']==0 || mp['c']==0){
            j++;
         }
         else if(mp['a']>0 && mp['b']>0 && mp['c']>0){
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                //mtlb valid hai ab 
               result=result+(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
         }
         
        }
        return result;
    }
};