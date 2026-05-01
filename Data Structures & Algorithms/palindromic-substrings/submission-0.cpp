class Solution {
public:
bool solve(string &s,int l,int r ){
    if(l>=r) return true;

    if(s[l]==s[r]){
        return solve(s,l+1,r-1);
    }
    return false;
}
    int countSubstrings(string s) {
        int n=s.length();
        int max=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    max++;
                }
            }
        }
        return max;
    }
};
