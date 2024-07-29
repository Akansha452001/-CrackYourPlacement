class Solution {
public:
    long long maxScore(vector<int>& cardPoints, int k) {
    //     if(k>cardPoints.size())
    //     return -1;
    //    long long maxi=LLONG_MIN;
    
    //    for(int j=0;j<=k;j++){
    //     long long total=0;
    //     for(int i=0;i<j;i++){
    //         total+=cardPoints[i];
    //     }
    //     for(int i=cardPoints.size()-k+j;i<cardPoints.size();i++){
    //         total+=cardPoints[i];
    //     }
    //     maxi=max(maxi,total);
    //    }
    //    return maxi;
    int total=0;
    for(int i=0;i<k;i++){
        total+=cardPoints[i];
    }
    int maxi=total;
    for(int i=1;i<=k;i++){
        total-=cardPoints[k-i];
        total+=cardPoints[cardPoints.size()-i];
        maxi=max(total,maxi);

    }
    return maxi;
    }
};