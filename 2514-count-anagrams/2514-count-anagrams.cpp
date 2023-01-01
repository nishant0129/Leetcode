class Solution {
public:
    const int mod=1e9+7;
    
    long long int  power(long long int a, int n)
    {
        long long int res = 1;
        
        while (n>0)
        {
            if (n & 1ll)
            {
                res = (res * a) % mod;
            }
            n >>= 1ll;
            a = (a * a) % mod;
        }
        return res;
    }
    
    long long int modinverse(long long int a)
    {
        return power(a, mod - 2);
    }
    
    
    int countAnagrams(string s) {
        vector<long long int>fact(100001,1);
        for(int i=2; i<=100000; i++)
        {
            fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
        }
        map<char,int>mp;
        int cnt=0,ans=1;
        s.push_back(' ');
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
            {
              
                long long int cp=fact[cnt];
                for(auto k:mp)
                {
                    int z=k.second;
                    cp=((cp)*modinverse(fact[z]))%mod;
                }
                ans = ((ans%mod) *(cp % mod))%mod;
                        // ans=((ans%mod)*((fact[cnt]*mod)*modinverse(cp)))%mod;
                cnt=0;
                mp.clear();
            }
            else
            {   cnt++;
                mp[s[i]]++;
            }
        }
        // int cp=1;
        // for(auto k:mp)
        // {
        //     int z=k.second;
        //     cp=((cp%mod)*(fact[z]%mod))%mod;
        // }
        // ans=((ans%mod)*((fact[cnt]*mod)*modinverse(cp)))%mod;
        return ans%mod;
    }
};