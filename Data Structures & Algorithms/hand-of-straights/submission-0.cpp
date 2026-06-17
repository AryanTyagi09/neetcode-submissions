class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        
        if(n%groupSize !=0) return false;

        map<int,int>fre;
        for(auto & x:hand){
          fre[x]++;

        }
        while(!fre.empty()){
        int curr=fre.begin()->first;
        for(int i=0;i<groupSize;i++){
            if(fre[curr+i] ==0) return false;

            fre[curr+i]--;
            if(fre[curr+i]<1) fre.erase(curr+i);
         }
        }
        return true;
        
    }
};
