class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ans.push_back({i,j});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            //row
            for(int j=0;j<ans[i].first;j++)
            matrix[j][ans[i].second]=0;
            for(int j=ans[i].first;j<n;j++)
            matrix[j][ans[i].second]=0;
            //column
            for(int k=0;k<ans[i].second;k++)
            matrix[ans[i].first][k]=0;
            for(int k=ans[i].second;k<m;k++)
            matrix[ans[i].first][k]=0;

        }
    }
};