class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>car;
        ;
        for(int i=0;i<n;i++){
           double time=double(target-position[i])/speed[i];
           car.push_back({position[i],time});

        }
        sort(car.rbegin(),car.rend());
        int fleets=0;
        double pretime=0;
        for(int i=0;i<n;i++){
            double cartime=car[i].second;
            if(cartime>pretime){
                fleets++;
                pretime=cartime;

            }
        }
        return fleets;
    }
};
