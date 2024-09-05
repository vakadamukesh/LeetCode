class Solution {
public:
    void removeValuesInsideNode(int node, vector<int>& nums, vector<int> adj[], set<int>& se){
        se.erase(se.find(nums[node]));
        
        for(auto el:adj[node]){
            if(se.find(nums[el])!=se.end()){
                removeValuesInsideNode(el, nums, adj, se);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int node = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                node = i;
                break;
            }
        }

        vector<int> adj[n];
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        vector<int> ans(n,1);
        if(node==-1){
            return ans;
        }

        set<int> se;
        for(int i=1;i<=1e5 + 10;i++){
            se.insert(i);
        }

        int currNode = node;

        while(currNode!=-1){
            removeValuesInsideNode(currNode, nums, adj, se);
            ans[currNode] = *se.begin();
            currNode = parents[currNode];
        }

        return ans;
    }
};