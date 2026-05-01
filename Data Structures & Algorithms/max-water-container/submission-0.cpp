class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;int r=heights.size()-1;
        int maxw=0;
        while(l<r)
        {
            int h=min(heights[l],heights[r]);
            int w=r-l;
            int area=h*w;
            maxw=max(maxw,area);

            if(heights[l]<heights[r])
            {
                l++;
            }
            else
            r--;
        }
        return maxw;
    }
};
