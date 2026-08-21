class Solution{
 public :
        vector<int> twoSum(vector<int>& nums , int target){
       // Better approach 
               // unordered_map<int, int> mp;
        
        // for(int i = 0; i < nums.size(); i++) {
            
        //     int complement = target - nums[i];
            
        //     // If complement already exists
        //     if(mp.find(complement) != mp.end()) {
        //         return {mp[complement], i};
        //     }
            
        //     // Store current number and index
        //     mp[nums[i]] = i;
        // }
        
        // return {};

          // Brute force approach 
          int n = nums.size();
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
               if(nums[i] +nums[j]==target) return {i,j};
          }
        }
     return {};
        }
}
