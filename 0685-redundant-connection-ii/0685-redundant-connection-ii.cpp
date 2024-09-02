class Solution {
public:


    class DSU {

    private:
   
        int parent[1001];
        int rank[1001];
   
    public:
        
        DSU(int n) {
            
            for(int i = 0; i < n + 1; i++) {
                parent[i] = i;
                rank[i] = 0;
            }

        }

        int ultparent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = ultparent(parent[node]);
        }

        bool connected(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return true;
            else return false;

        }

        void unionbyrank(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return;
            else {
                if(rank[parent1] < rank[parent2]) {
                    parent[parent1] = parent2;
                } else if(rank[parent1] > rank[parent2]) {
                    parent[parent2] = parent1;
                } else {
                    parent[parent1] = parent2;
                    rank[parent2]++;
                }
            }

        }

    };


    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        int nodeindegree2 = -1;

        int indegree[n + 1];

        for(int i = 0; i <= n; i++) {
            indegree[i] = 0; 
        }

        //trying to find node with indegree 2

        for(int i = 0; i < n; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;

            if(indegree[v] == 2) {
                nodeindegree2 = v;
            }

        }

        //It means there that there is no node having indegree 2

        if(nodeindegree2 == -1) {
            
            //there must be a cycle

            DSU graph(n);

            for(int i = 0; i < n; i++) {
                
                int u = edges[i][0];
                int v = edges[i][1];

                if(graph.connected(u, v)) {
                    return {u, v};
                } else {
                    graph.unionbyrank(u, v);
                }
            }

    
        }

        // trying to find two edges that are coming towards the node having indegree 2

        int edgewithind1 = -1;
        int edgewithind2 = -1;

        for(int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if(indegree[v] == 2) {
                if(edgewithind1 == -1) {
                    edgewithind1 = i;
                } else {
                    edgewithind2 = i;
                }
            }
        }

        //removing edge2 to check is it the extra edge

        // why edge2 first because if both edge1 and edge2 are in the cycle then i need to remove that edge which is coming in the last

        DSU graph(n);

        bool stillcycle = false;

        for(int i = 0; i < n; i++) {
            
            if(i == edgewithind2) continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if(graph.connected(u, v)) {
                stillcycle = true;
            } else {
                graph.unionbyrank(u, v);
            }

        }

        if(!stillcycle) {
            return {edges[edgewithind2][0], edges[edgewithind2][1]};
        }


        return { edges[edgewithind1][0], edges[edgewithind1][1] };
    
    }
};