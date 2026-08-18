class Solution {
public:
int lower(vector<int>& arr,int x, int n){
    int low=0,high=n-1;
    int lb=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            lb=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return lb;
}

int upper(vector<int>& arr,int x, int n){
    int low=0,high=n-1;
    int up=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            up=mid;
            high=mid-1;
        }
        else low = mid+1;
    }
    return up;
}
    
    
    
vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int lb=lower(arr,target,n);
        if(lb==n || arr[lb]!=target) return {-1,-1};
        int up=upper(arr,target,n);
        return{lb,up-1};
    }
};