//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int length){
    // Case 1: Strings with all 'a'
    long long int strings_all_a = 1;

    // Case 2: Strings with at most 1 'b'
    long long int strings_at_most_1_b = length;

    // Case 3: Strings with at most 1 'c'
    long long int strings_at_most_1_c = length;

    // Case 4: Strings with one 'b' and one 'c'
    long long int strings_one_b_one_c = length * (length - 1);

    // Case 5: Strings with two 'c'
    long long int strings_two_c = (length * (length - 1)) / 2;

    // Case 6: Strings with one 'b' and two 'c'
    long long int strings_one_b_two_c = (length * (length - 1) * (length - 2)) / 2;

    long long int total_strings = strings_all_a + strings_at_most_1_b + strings_at_most_1_c +
                        strings_one_b_one_c + strings_two_c + strings_one_b_two_c;

    return total_strings;
}