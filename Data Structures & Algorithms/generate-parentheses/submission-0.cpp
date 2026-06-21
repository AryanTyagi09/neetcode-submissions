class Solution {
public:
vector<string>ans;
void solve(int open,int close,int n,string &temp){
    if(temp.size()==2*n){
        ans.push_back(temp);
    }
    if(open<n){
        temp.push_back('(');
        solve(open+1,close,n,temp);
        temp.pop_back();
    }
    if(close<open){
       temp.push_back(')');
       solve(open,close+1,n,temp);
       temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string temp="";
        solve(0,0,n,temp);
        return ans;
    }
};
