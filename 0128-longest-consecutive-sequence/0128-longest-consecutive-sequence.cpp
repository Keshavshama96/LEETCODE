class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //if array is empty 
        if (nums.size() == 0) return 0;

        int longest=1;
        unordered_set<int>store;
       //inserting all the elements from the vector to the set
        for( int num:nums){
            store.insert(num);//not num[i]because iterator mai mun hi khud puri value hai 
        }
       //checking the main thing now 
       for (int num:store){
           if (store.count(num-1)){//uske piche ka element hai 
            continue;
           }else {//vhi starting element hai .
              int count=1;
              int x=num;
             //count consecutive elements
             while (store.count(x + 1)) {//CHECKING AGLA HAI KI NA
                    x = x + 1; // going to next element
                    count++;
                }
                //checking the longest
                longest=max(longest,count);

           }
       }
       return longest;
    }
};