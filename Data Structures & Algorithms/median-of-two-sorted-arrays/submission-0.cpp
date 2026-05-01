class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int b=nums2.size();
        int c=a+b;
        vector<int>abc;
        for(int i=0;i<a;i++)
        {
            abc.push_back(nums1[i]);
        }
        for(int i=0;i<b;i++)
        {
            abc.push_back(nums2[i]);
        }
        sort(abc.begin(),abc.end());
        int n=abc.size();
        if(n%2==1)
        {
            return abc[n/2];
        }
        else
        {
            return (abc[n/2] +abc[n/2 -1])/2.0;
        }


    }
};
