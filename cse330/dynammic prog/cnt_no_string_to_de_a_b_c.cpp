// A O(1) CPP program to find number of strings
// that can be made under given constraints.
#include<bits/stdc++.h>
using namespace std;
int countStr(int n){
	
	int count = 0;
	
	if(n>=1){
		//aaa...
		count += 1;
		//b...aaa...
		count += n;
		//c...aaa...
		count += n;
		
		if(n>=2){
		//bc...aaa...
		count += n*(n-1);
		//cc...aaa...
		count += n*(n-1)/2;
		
		if(n>=3){
			//bcc...aaa...
			count += (n-2)*(n-1)*n/2;
		}
		}
	
	}
	
	return count;
	
}

// Driver code
int main()
{
int n = 3;
cout << countStr(n);
return 0;
}
