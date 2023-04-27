int solve(int i,int a[],int n,int sum1,int sum2){

        if(i>n)

            return 0;

        if(sum1==sum2)

            return 1;

        if(sum1>sum2)

            return 0;

        return solve(i+1,a,n,sum1+a[i],sum2-a[i]) || solve(i+1,a,n,sum1,sum2);

    }

    int sisterCoin(int a[], int n, int sum1){

        // Code Here

        int sum2=0;

        for(int i=0;i<n;i++)

            sum2+=a[i];

        if((sum1+sum2)%2!=0)

            return 0;

        return solve(0,a,n,sum1,sum2);

    }