class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxfre=0;
        int ans=0;
        vector<int>fre(26,0);
        while(i<s.size()){
           fre[s[i]-'A']++;
           maxfre=max(maxfre,fre[s[i]-'A']);
           while((i-j+1)-maxfre>k){
             fre[s[j]-'A']--;
             j++;
           }
           ans=max(ans,i-j+1);
           i++;
        }
        return ans;
    }
};