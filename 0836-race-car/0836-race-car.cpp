class Solution {
public:
    int racecar(int target) {
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{1,0}});
        while(!q.empty()){
            int pos=q.front().first;
            int speed=q.front().second.first;
            int count=q.front().second.second;
            q.pop();
            if(pos==target){
                return count;
            }
            if(pos>=2*target && pos>0 && speed>0){
                continue;
            }
            if(pos<=2*target&& pos<0 && speed<0){
                //cout<<pos<<" "<<speed<<endl;
                continue;
            }
            q.push({pos+speed,{speed*2,count+1}});
            if((pos+speed)<target && speed<0){
                q.push({pos,{1,count+1}});
            }else if((pos+speed)>target && speed>0){
                q.push({pos,{-1,count+1}});
            }
        }
        return 0;
    }
};