class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum=0;
        int rightsum=0;
        int maxsum=INT_MIN;
        //sum of k card (from the begining)
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }
        //leftsum ko maxsum mai daldo
        maxsum=leftsum;//sum of first k elements

        //its time to minus from the end of begining of window k and add one by one element from the end 
       int rightindex=cardPoints.size()-1;//piche se add krna hai uske liye hai ye 
        for(int i=k-1;i>=0;i--){
            leftsum-=cardPoints[i];
            //add kro pichle se
            rightsum+=cardPoints[rightindex];
            //rightindex ko piche bhi lena hai 
            rightindex--;

            maxsum=max(maxsum,(leftsum+rightsum));
        }
        return maxsum;
    }
};