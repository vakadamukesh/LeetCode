class Solution {
    vector<int>prevs(vector<int>&nums)
    {
        vector<int>ans(nums.size(),0);
        stack<pair<int,int>>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && st.top().first>=nums[i])
            {
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({nums[i],i});
        }

        return ans;

    }

    vector<int>nexts(vector<int>&nums)
    {
        vector<int>ans(nums.size(),0);
        stack<pair<int,int>>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=nums[i])
            {
                st.pop();
            }
            if(st.empty()){
                ans[i]=nums.size();
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({nums[i],i});
        }

        return ans;

    }
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int>ps=prevs(nums);
        vector<int>ns=nexts(nums);

        for(auto it : ps){
            cout<<it<<" ";
        }
        cout<<endl;

        for(auto it : ns){
            cout<<it<<" ";
        }


        for(int i=0;i<nums.size();i++)
        {
            int left=ps[i];
            int right=ns[i];

            int len=right-left-1;

            if(nums[i] > (threshold/((double)len))){
                return len;
            }

        }

        return -1;
    }
};