class Solution {
public:
         //calute the zeros
         bool allZero(vector<int> &counter){
            for(int i:counter){
                if(i!=0){
                    return false;
                }
            }
            return true;
         }


    vector<int> findAnagrams(string s, string p) {
        //vector to maintain the frequency
        vector<int>counter(26,0);
        //p string ki frequency dal do pehle hi vector mai baki zero krdo 
        for(int i=0;i<p.size();i++){
            counter[p[i]-'a']++;
        }
        //vector to store the indexes
        vector<int>result;
        int i=0;
        int j=0;
        int k=p.size();
        while(j<s.size()){
            counter[s[j]-'a']--;//minus krdo jo element aaya 

            //checking window
            //if window is smaller
            if(j-i+1<k) {
                j++; //just move j (because abhi to required window tak pauhe nhi)
            }
            //if window is equal now
            else if (j-i+1==k){
                //check whole teh vector is zero? if yes means valid
             if(allZero(counter)){
               result.push_back(i);//result mai i daal do vhi hai strting of anagram
             }
            //before sliding , check a[i] 
             counter[s[i]-'a']++; 
             //slide 
             i++;
             j++;
            }
            
        }
       return result;
    }
};