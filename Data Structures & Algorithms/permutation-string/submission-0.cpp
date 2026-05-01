class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
        return false;

        vector<int>s1count(26,0);
        vector<int>window(26,0);
       
        for(int i=0;i<s1.size();i++)
        {
            s1count[s1[i]-'a']++;

        }
         int k=s1.size();
        for(int j=0;j<s2.size();j++ )
        {
            window[s2[j]-'a']++;
            if(j>=k)
            {
                window[s2[j-k]-'a']--;

            }
            if(s1count==window)
            return true;

        }
        return false;
    }
};
