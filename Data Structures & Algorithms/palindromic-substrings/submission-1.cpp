class Solution {
public:
 
bool pal(string &s,int i,int j){
    if(i>=j) return true;

    if(s[i]==s[j]){
        return pal(s,i+1,j-1);

    }
    return false;
}
    int countSubstrings(string s) {
       int n= s.size();
       int maxc=0;
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(pal(s,i,j)){
                maxc++;
            }
        }
       }
       return maxc;
    }
};
