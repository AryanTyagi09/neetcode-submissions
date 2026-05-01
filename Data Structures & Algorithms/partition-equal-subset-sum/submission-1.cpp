#include <bits/stdc++.h>
#include <cstring>   
using namespace std;
class Solution {
public:
int t[101][5001];
bool solve(vector<int>& nums,int i,int x)
{
    if(x==0)
    return true;

    if(i>=nums.size())
    {
        return false;

    }
    if(t[i][x]!=-1)
    {
        return t[i][x];
    }
    bool take=false;
    if(nums[i]<=x)
    {
        take=solve(nums,i+1,x-nums[i]);
    }
    bool skip=solve(nums,i+1,x);

    return t[i][x]=take||skip;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=accumulate(begin(nums),end(nums),0);
        if(s%2!=0)
        return false;
        memset(t,-1,sizeof(t));

        int x=s/2;
        
        return solve(nums,0,x);
        
        
    }
};
