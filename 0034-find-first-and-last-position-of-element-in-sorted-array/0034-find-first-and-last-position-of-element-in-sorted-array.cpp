class Solution {
public:
     
      //firstposition
    int firstposition(vector<int>& nums, int target){
         int low=0;
      int high=nums.size()-1;
  int first=-1;//agr hua first to shi nhi to -1 return hoga
      while(low<=high){
        int mid= low+(high-low)/2;
         if(nums[mid]==target){//mtlb isko lelo
            first=mid;
            high=mid-1;// we are looking for first postion of target so hme jana ji left hai so... eliminate the right side
         }else if(nums[mid]<target){
            low=mid+1;//target bda hai 
         }
         else{
            high=mid-1;//target chota haib 
         }
      }
      return first;//return last
    }
   //lastposition
   int lastposition(vector<int>& nums, int target ){
     int low=0;
      int high=nums.size()-1;
 int last=-1;//agr hua last to shi nhi to -1 return hoga
      while(low<=high){
        int mid= low+(high-low)/2;
         if(nums[mid]==target){//isko lelo
            last=mid;
            low=mid+1;// we are looking for last postion of target so hme jana ji right hai so... eliminate the left side
         }else if(nums[mid]<target){
            low=mid+1;//target bda hai
         }
         else{
            high=mid-1;//target chota hai
         }
      }
      return last;//return last
    }


    vector<int> searchRange(vector<int>& nums, int target) {
//normal returing the functions
    // return {firstposition(nums,target),lastposition(nums, target)};

 //INTERVIEW mai tc bchana hai to  returing the functions like this
  int first=firstposition(nums,target);
  if(first==-1){
    return {-1,-1};
  }else{
    return{first,lastposition(nums,target)};
  }

    }
};