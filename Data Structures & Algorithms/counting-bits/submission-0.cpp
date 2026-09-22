class Solution {
public:
    vector<int> countBits(int n) {
       
       vector<int>ans;
       for(int i=0;i<=n;i++){
        int count=0;
        int x=i;
        if(x==0){
            ans.push_back(0);
        }
        else{
            while(x!=0){
            if(x&1){
                count++;
            }
            x=x>>1;
        }
        ans.push_back(count);
       }
        }
        
       return ans;
    }
};
