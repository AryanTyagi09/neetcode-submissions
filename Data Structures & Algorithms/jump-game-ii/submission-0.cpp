class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach=0;
        int jump=0;
        int range =0;

        int n=nums.size();
        for(int i=0;i<n-1;i++){
           maxreach=max(maxreach,nums[i]+i);
           if(i==range){
            jump++;
            range=maxreach;
           }
         }
         return jump;
        }
        
    
};
