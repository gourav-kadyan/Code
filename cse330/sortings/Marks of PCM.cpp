static bool myComp(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b)
    {
       if(a.first==b.first && a.second.first==b.second.first)
            return a.second.second<b.second.second;
       else if(a.first==b.first)
            return a.second.first>b.second.first;
       else
            return a.first<b.first;
   }
   
    void customSort (int phy[], int chem[], int math[], int N)
    {
       vector<pair<int,pair<int,int>>>v;
       int i ;
       for(i = 0; i<N; i++)
           v.push_back({phy[i],{chem[i],math[i]}});
       
       sort(v.begin(),v.end(),myComp);
       for(int i =0; i<N; i++)
       {
           phy[i]= v[i].first;
           chem[i]= v[i].second.first;
           math[i]= v[i].second.second;
       }
    } 