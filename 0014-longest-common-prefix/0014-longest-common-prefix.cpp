class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string S1=strs[0];
        string S2=strs[n-1];
        int minLength=min(S1.size(),S2.size());
        for(int i=0;i<minLength;i++){
            if(S1[i]!=S2[i]){
                break;
            }
            ans.push_back(S1[i]);
        }
        return ans;
    }
};