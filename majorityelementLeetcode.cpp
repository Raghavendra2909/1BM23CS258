class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int max_count = 1;
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1; 
            }

            if (count > max_count) {
                max_count = count;
                result = nums[i];
            }
        }
        
        return result;
    }
};
