class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        for(int num:hand){
            mp[num]++;
        }

        while(!mp.empty()){
            auto st=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int num=st+i;
                if(mp.find(num)==mp.end())return false;

                if(--mp[num]==0){
                    cout<<num;
                    mp.erase(num);
                }
            }
        }
        return true;
    }
};