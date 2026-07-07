class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        
        vector<pair<char,int>> v;
        for(auto& p : freq){
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), [](pair<char,int>& a, pair<char,int>& b){
            return a.second > b.second;  // descending order by count
        });
        
        string ans = "";
        for(auto& p : v){
            ans += string(p.second, p.first);  // repeat char p.first, p.second times
        }
        
        return ans;
    }
};