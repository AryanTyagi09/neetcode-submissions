class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int i=0;
        int j=0;
        int len=0;

        while(j<s.size())
        {
            while(count[s[j]])
            {
                count[s[i]]=0;
                i++;
            }
            count[s[j]]=1;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};
