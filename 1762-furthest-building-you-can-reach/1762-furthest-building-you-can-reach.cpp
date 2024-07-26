class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0;
        while(i<heights.size()-1){
            int diff = heights[i+1]-heights[i];
            if(diff<=0){
                i++;
            }else{
                if(diff<=bricks){
                    pq.push(diff);
                    bricks-= diff;
                    i++;
                }else{
                    if(ladders==0){
                        return i;
                    }else{
                        if(!pq.empty()){
                        int top = pq.top();
                        if(top>diff){
                            pq.pop();

                            ladders--;
                            bricks+= top;
                            bricks-= diff;
                            pq.push(diff);
                            i++;
                        }else{
                            ladders--;
                            i++;
                        }
                        }else{
                            ladders--;
                            i++;
                        }
                    }
                }
            }
        }
        return i;
    }
};



