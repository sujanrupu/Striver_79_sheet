class Solution{
public:
    bool isPossible(bool graph[101][101],vector<int>&color,int node,int col,int n){
         for(int i=0;i<n;i++){
             if(node!=i&&graph[node][i]==true&&color[i]==col){
                 return false;
             }
         }
         return true;
    }
    bool graphColor(bool graph[101][101],vector<int>&color,int m ,int n, int node){
        if(node==n){
            return true;
        }
        for(int i=0;i<m;i++){
            if(isPossible(graph,color,node,i,n)){
                color[node]=i;
                if(graphColor(graph,color,m,n,node+1)){
                    return true;
                }else{
                     color[node]=-1;
                }
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n);
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        if(graphColor(graph,color,m,n,0)==true){
            return true;
        }
        return false;
    }
};
