#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v_prefix;
        vector<int> v_suffix;
        vector<int> ans;
        int len = nums.size();
        int product_p = 1;
        int product_s = 1;
        for(int i = 0; i < len; i++){
            product_p *= nums[i];
            v_prefix.push_back(product_p);
            product_s *= nums[len - 1 - i];
            v_suffix.push_back(product_s);
        }
        reverse(v_suffix.begin(), v_suffix.end());
        for(int i = 0; i < len; i++){
            if(i == 0)
                ans.push_back(v_suffix[i + 1]);
            else if(i == len - 1)
                ans.push_back(v_prefix[i - 1]);
            else
                ans.push_back(v_prefix[i-1] * v_suffix[i+1]);
        }
        return ans;
    }
};
