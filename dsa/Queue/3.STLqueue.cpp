#include <iostream>
#include <queue>
using namespace std;

int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
  

   while(q.empty() == false)
   {
       cout << q.front() << " " << q.back() << endl;
       cout << q.size() << " " << q.empty() << endl;
       q.pop();
   }
    cout << q.empty() << endl;
  
    return 0; 
} 