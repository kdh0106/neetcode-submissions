#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int len = 1;
        int combo = 1;
        int std = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == std + 1){
                combo++;
                std++;
            }
            else if(nums[i] > std + 1){
                len = max(len, combo);
                std = nums[i];
                combo = 1;
            }
        }
        return max(len, combo);
    }
};
