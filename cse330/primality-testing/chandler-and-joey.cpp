#include<stdio.h>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 int a[101];
 int GCD(int a, int b)
 {
  if (b==0) return a;
  return GCD(b,a%b);
 }
 int main()
 { 
 int t,n,i,c,p,max;
 unsigned long long int sum1,sum2,n1;
 scanf("%d",&t);
  while(t--)
  {  
    sum1=0;
    sum2=0;
    p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    max=*max_element(a,a+n);
    for(i=0;i<n;i++)
    sum2+=a[i];
    for(i=0;i<n;i++)
    p=GCD(a[i],p);
    c=(max/p)-n;                // c is total number of moves taken by both players 
    n1=c+n;
    sum1=(n1*(2*p+(n1-1)*p))/2; // sum of AP series whose common difference is GCD of n numbers

    if((c&1)==0)                // if total number of moves are even Chandler wins
    {
        printf("Chandler %llu\n",sum1-sum2);
    }
    else                        // if total number of moves are odd Joey wins
    {
        printf("Joey %llu\n",sum1-sum2);
     }

  }
     return 0;
}