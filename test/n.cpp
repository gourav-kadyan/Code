class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int i=0;
        int j=0;
       int len=fruits.size();
       int best=INT_MIN;
       map<int,int>mp;
        while(j<len)
        {
            if(mp.find(fruits[j])==mp.end())
            {
                if(mp.size()==2)
                {
                    auto it=mp.begin();
                    auto it2=it;
                    it2++;
                    best=max(best,it->second+it2->second);

                    while(mp.size()>=2)
                    {
                        mp[fruits[i]]--;
                        if(mp[fruits[i]]==0)
                        {
                            mp.erase(fruits[i]);
                        }
                        i++;
                    }
                    mp[fruits[j]]++;
                    j++;

                }else{
                    mp[fruits[j]]++;
                    j++;
                }
            }else{
                mp[fruits[j]]++;
                j++;
            }
           
        }
        if(mp.size()>0)
        {
            auto it=mp.begin();
            auto it2=it;
            it2++;
            if(it2!=mp.end())
            {
                best=max(best,it->second+it2->second);
            }else{
                best=max(best,it->second);
            }
           
        }
        return best;
    }
};