#include<algorithm>
#include<iostream>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        reverse(digits.begin(), digits.end());
        int plus = 1;
        for(int i = 0; i < digits.size(); i++){
            if(digits[i] + plus == 10){
                ans.push_back(0);
            }
            else{
                ans.push_back(digits[i] + plus);
                plus = 0;
            }
        }
        if(plus > 0)
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        return ans;
    }
};
