vector<int> RopeCutting(int arr[], int n)
    {
        // Complete the function
        vector<int>ans;
        sort(arr,arr+n);
        int count = 1;
        int length = n;
        for(int i = 0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                count++;
            }else{
                length -= count;
                ans.push_back(length);
                count = 1;
            }
        }return ans;
    }