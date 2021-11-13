// https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/
  int subarraysDivByK(vector<int>&v, int k) {
        unordered_map<int,int>mp;
        int n=v.size(),ans=0,z=v[0]%k;
        if(z<0)
            z+=k;
        if(z==0)
            ans++;
        mp[z]++;
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
            int x=v[i]%k;
            if(x<0)
                x+=k;
            if(mp.find({x})!=mp.end())
                ans+=mp[x];
            if(x==0)
                ans++;
            mp[x]++;
        }    
        return ans;
    }
// https://leetcode.com/problems/subarray-sum-equals-k/submissions/
int subarraySum(vector<int>&v, int k) {
        int n=v.size(),ans=0;
        unordered_map<int,int>mp;
        mp[v[0]]++;
        if(v[0]==k)
            ans++;
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
            if(v[i]==k)
            {
                ans++;
                if(mp.find(0)!=mp.end())
                    ans+=mp[0];
            }    
            else
                if(mp.find(v[i]-k)!=mp.end())
                    ans+=mp[v[i]-k];
            mp[v[i]]++;
        }
        return ans;
    }
// https://leetcode.com/problems/word-pattern/submissions/
bool wordPattern(string pattern, string s) {
        vector<string>v;
        string x="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
                x+=s[i];
            else
            {
                v.push_back(x);
                x="";
            }
        }
        v.push_back(x);
        if(pattern.length()!=v.size())
            return false;
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        for(int i=0;i<v.size();i++)
        {
            if(mp.find(pattern[i])==mp.end() and mp2.find(v[i])==mp2.end())
            {
                mp[pattern[i]]=v[i];
                mp2[v[i]]=pattern[i];
            }    
            else if(mp[pattern[i]]!=v[i] or mp2[v[i]]!=pattern[i])
                return false;
        }
        return true;
    }
// https://leetcode.com/problems/isomorphic-strings/submissions/
bool isIsomorphic(string s, string t) {
        if(s.length()!=t.size())
            return false;
        unordered_map<char,char>mp;
        unordered_map<char,char>mp2;
        for(int i=0;i<s.size();i++)
        {   
            if(mp.find(s[i])==mp.end() and mp2.find(t[i])==mp2.end())
            {
                mp[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }   
            if(mp[s[i]]!=t[i] or mp2[t[i]]!=s[i])
                return false;
        }
        return true;
    }
// https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/
bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;
        for(int i=1;i<words.size();i++)
        {
            int j;
            for(j=0;j<min(words[i-1].size(),words[i].size());j++)
                if(words[i-1][j]!=words[i][j])
                {
                    if(mp[words[i][j]]<mp[words[i-1][j]])
                        return false;
                    break;
                }    
            if(j==min(words[i-1].size(),words[i].size()) and j==words[i].size() and j!=words[i-1].size())
                return false;
        }
        return true;
    }
// https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
 bool valid(vector<int>&a,vector<int>&b)
    {
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        vector<int>v(26,0),w(26,0),ans;
        for(int i=0;i<p.size();i++)
            v[p[i]-'a']++;
        for(int i=0;i<p.size();i++)
            w[s[i]-'a']++;
        if(valid(v,w))
            ans.push_back(0);
        int j=0;
        for(int i=p.size();i<s.size();i++)
        {
            w[s[j]-'a']--;
            j++;
            w[s[i]-'a']++;
            if(valid(v,w))
                ans.push_back(j);
        }
        return ans;
    }
// https://leetcode.com/problems/continuous-subarray-sum/submissions/
bool checkSubarraySum(vector<int>&v, int k) {
        unordered_map<int,int>mp;
        int n=v.size(),ans=0,z=v[0]%k;
        int cnt=0;
        for(int i=0;i<n;i++)
            if((v[i]%k) ==0)
                cnt++;
        if(z<0)
            z+=k;
        if(z==0)
            ans++;
        mp[z]++;
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
            int x=v[i]%k;
            if(x<0)
                x+=k;
            if(mp.find({x})!=mp.end())
                ans+=mp[x];
            if(x==0)
                ans++;
            mp[x]++;
        }    
        return ans>cnt;
    }
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#
int lenOfLongSubarr(int v[],  int n, int k) 
    { 
        int ans=0;
        unordered_map<int,int>mp;
        mp[v[0]]=0;
        if(v[0]==k)
            ans=1;
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
            if(v[i]==k)
                ans=i+1;  
            else
                if(mp.find(v[i]-k)!=mp.end())
                    ans=max(ans,i-mp[v[i]-k]);
            if(mp.find(v[i])==mp.end())
                mp[v[i]]=i;
        }
        return ans;
    } 
