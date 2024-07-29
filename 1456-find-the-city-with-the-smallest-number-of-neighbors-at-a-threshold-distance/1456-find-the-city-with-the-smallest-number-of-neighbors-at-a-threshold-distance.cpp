class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int k=0;k<matrix.size();k++){
	    for(int i=0;i<matrix.size();i++){
	        for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX)
                 continue;
	            if(matrix[i][j]>matrix[i][k]+matrix[k][j]){
	                matrix[i][j]=matrix[i][k]+matrix[k][j];
	            }
	        }
	    }
	    }
        int idx,mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            int count=0;
	        for(int j=0;j<matrix[0].size();j++){
	            if(matrix[i][j]<=d){
                    count++;
                }
	        }
            if(mini>=count){
            mini=count;
            idx=i;
            }
	    }
        return idx;
	    
	    
    }
};