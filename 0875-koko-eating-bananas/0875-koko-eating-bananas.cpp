class Solution {
public:

int maxi(vector<int>& arr){
    int n=arr.size();
    int maxm=INT_MIN;
    for(int i=0;i<n;i++){
            maxm=max(maxm,arr[i]);
    }
    return maxm;
}

long long f2(vector<int>& arr,int h){
    int n=arr.size();
    long long totalh=0;
    for(int i=0;i<=n-1;i++){
        totalh+=ceil((double)arr[i]/(double)h);
    }
    return totalh;
}
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int low=1,high=maxi(arr);
        int ans=INT_MIN;
        while(low<=high){
            int mid=(low+high)/2;
            long long reqt=f2(arr,mid);
            if(reqt<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};