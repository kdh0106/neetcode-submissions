#include<iostream>
#include<vector>
#include<algorithm>


bool compare(pair<string, int> a, pair<string, int> b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        vector<pair<string, int>> v_pair;
        for(int i = 0; i < strs.size(); i++){
            v_pair.push_back({strs[i], i});
            sort(v_pair[i].first.begin(), v_pair[i].first.end());
        }
        sort(v_pair.begin(), v_pair.end(), compare);
        
        string std = v_pair[0].first;
        vector<string> v_tmp;
        for(int i = 0; i < v_pair.size(); i++){
            if(v_pair[i].first == std){
                v_tmp.push_back(strs[v_pair[i].second]);
            }
            else{
                v.push_back(v_tmp);
                v_tmp.clear();
                v_tmp.push_back(strs[v_pair[i].second]);
                std = v_pair[i].first;
            }
        }
        v.push_back(v_tmp);
        return v;
    }
};
