class Solution {
public:
    int countNicePairs(vector<int>& nums) {

        // brute force approach 
        // int n = nums.size();
        // int count =0;

        // for(int i=0;i<n-1;i++){
        //     for(int j= i+1;j<n;j++){

        //         long long  rev1=0 , rev2= 0;
        //         int m1=nums[i] , m2 = nums[j];

        //         while(m1>0 ){
        //             int d1=m1%10;
        //             rev1 = rev1*10 + d1 ;             
        //             m1 /=10 ;
                    
        //         }

        //         while(m2>0){
        //             int d2 = m2%10 ;
        //             rev2 = rev2*10 + d2 ;
        //             m2 /=10 ;
        //         }

        //         if(nums[i] + rev2 == nums[j]+ rev1) {
        //             count++;
        //         }
        //     }
        // }
        // return count ;

         const int MOD = 1e9 + 7;
        unordered_map<int, long long> mp;

        long long count = 0;

        for (int num : nums) {
            int original = num;
            int rev = 0;

            while (num > 0) {
                rev = rev * 10 + num % 10;
                num /= 10;
            }

            int key = original - rev;

            count = (count + mp[key]) % MOD;
            mp[key]++;
        }

        return count;
    }
};
