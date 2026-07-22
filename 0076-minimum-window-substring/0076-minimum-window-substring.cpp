class Solution {
public:
    string minWindow(string s, string t) {


     //edge case:- agr t hi bda hogya to s mai nhi hoga
     if(t.size()>s.size()){
        return "";
     }

     unordered_map<char,int>mp;
    //t string mai jitne bhi char hai unko pehle hi map mai dal do
     for(char ch :t){
         mp[ch]++;
     }
      //now travering on the main string which is "s"
       int i=0;
       int j=0;
       int count_req=t.size();
       int minWindowSize =INT_MAX;
       int start_i=0; //this is to find the starting of the valid substring because hmko size nhi balki string deni hai
    
       while(j<s.size()){
      //map mai frequency 0 se jayada hui which means hme chahiye so count_req increase.
       char ch=s[j];

       if(mp[ch]>0){
        count_req--;
       }
       mp[ch]--;//uski freq dec krdo
       
        while(count_req==0){
         //shrinking window 
         int currWindSize=j-i+1;
         if (minWindowSize>currWindSize){
           minWindowSize=currWindSize;
           start_i=i;
         }
         mp[s[i]]++;

         if( mp[s[i]]>0){
            count_req++;
         }
         i++;
        }
        j++;
       }
       return minWindowSize ==INT_MAX ?  "":s.substr(start_i,minWindowSize);
    }
};