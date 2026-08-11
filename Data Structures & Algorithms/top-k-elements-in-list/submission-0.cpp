#include<iostream>
#include<vector>
#include<algorithm>

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int, int>> v;
        sort(nums.begin(), nums.end());
        int std = nums[0];
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == std){
                cnt++;
            }
            else{
                v.push_back({std, cnt});
                std = nums[i];
                cnt = 1;
            }
        }
        v.push_back({std, cnt});
        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
