class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;

        // store frequency of t
        for(int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }

        int total = t.size();   // total chars we need
        int start = 0, end = 0;

        int ans = INT_MAX;
        int index = -1;

        while(end < s.size()) {

            // decrease count of current char
            if(m[s[end]] > 0) {
                total--;   // useful char matched
            }
            m[s[end]]--;

            // when all chars matched
            while(total == 0) {

                // update minimum window
                if(ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                // try to shrink window
                m[s[start]]++;

                if(m[s[start]] > 0) {
                    total++;   // lost a required char
                }

                start++;
            }

            end++;
        }

        if(index == -1) return "";

        return s.substr(index, ans);
    }
};