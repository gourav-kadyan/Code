int lcsK(int k, string st){
       // code here
       int n=st.size();
       int dp[n+5]={0};
       if(st[0]=='0') dp[0]=1;
       for(int i=1;i<n;i++)
       {
           if(st[i]=='0')
           dp[i]=dp[i-1]+1;
           else
           dp[i]=0;
       }
       if(dp[n-1]==n)
       return n*k;
       int u=0;
       for(int i=0;i<n;i++)
       {
           if(st[i]=='1')
           {
               u=i-1;
               break;
           }
       }
       if(u==-1)
       return *max_element(dp,dp+n);
       return max(*max_element(dp,dp+n),dp[n-1]+dp[u]);
   }