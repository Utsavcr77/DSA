class Solution {
public:

int mini(vector<int>& arr,int n){
    int mini = 0;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
    }
    return mini;
}

int maxi(vector<int>& arr,int n){
    int max1=0;
    for(int i=0;i<n;i++){
        max1=max(max1,arr[i]);
    }
    return max1;
}

bool possible(vector<int>& arr,int day, int m, int k){
    int cnt=0;
    int noofB=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noofB+=(cnt/k);
            cnt=0;
        }
    }
        noofB+=(cnt/k);
        if(noofB>=m) {
            return true;
        }
        else{
            return false;
        }
}

    int minDays(vector<int>& arr, long m, long k) {
        int n=arr.size();
        int low=mini(arr,n),high=maxi(arr,n),ans=high;
        if(n<(m*k)) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(arr,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};