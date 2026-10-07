class Solution {
public:

    vector<string> ans;

    void removeInvalid(string s, int start, int last,
                       char open, char close) {

        int balance = 0;

        for(int i = start; i < s.size(); i++) {

            if(s[i] == open)
                balance++;

            if(s[i] == close)
                balance--;

            // Too many close brackets
            if(balance < 0) {

                for(int j = last; j <= i; j++) {

                    // Don't remove duplicate brackets
                    if(s[j] == close &&
                       (j == last || s[j-1] != close)) {

                        string temp = s.substr(0, j)
                                    + s.substr(j + 1);

                        removeInvalid(temp, i, j,
                                      open, close);
                    }
                }

                return;
            }
        }

        // No extra close brackets.
        // Now reverse and check the other direction.
        reverse(s.begin(), s.end());

        if(open == '(') {

            removeInvalid(s, 0, 0, ')', '(');

        } else {

            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        removeInvalid(s, 0, 0, '(', ')');

        return ans;
    }
};