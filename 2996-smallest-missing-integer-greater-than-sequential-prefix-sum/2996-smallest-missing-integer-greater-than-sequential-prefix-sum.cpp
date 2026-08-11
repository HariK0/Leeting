class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];

        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                sum = sum + nums[i];
            }
            else{
                break;
            }
        }

        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }

        int ans = sum;
        while(true){
            if(mpp.find(ans) == mpp.end()){
                return ans;
            }
            else{
                ans++;
            }
        }

        return ans;
    }
};