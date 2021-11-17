// https://www.codechef.com/submit/ALIENIN
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool valid(double x,int d,vector<int>&v)
{
    double t=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(t+x>v[i]+d)
            return false;
        else if(t+x<=v[i])
            t=v[i];
        else
            t+=x;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        double l=0,r=INT_MAX-1,ans=0.0;
        for(int i=0;i<100;i++)
        {
            double md=(l+r)/2;
            if(valid(md,d,v))
            {
                ans=md;
                l=md;
            }
            else
                r=md;
        }
        cout<<ans<<fixed<<setprecision(10)<<endl;
    }
}
// https://leetcode.com/problems/subarrays-with-k-different-integers/************Sliding Window Atmost(k)-Atmost(k-1)
// TLE
int func(int x,int y,int k,vector<int>&v)
    {
        int z=x,ans=0;
        unordered_map<int,int>mp;
        for(int i=x;i<=y;i++)
        {
            mp[v[i]]++;
            while(mp.size()==k)
            {
                ans+=1+y-i;
                mp[v[z]]--;
                if(mp[v[z]]==0)
                    mp.erase(v[z]);
                z++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>&v, int k) {
        unordered_map<int,int>mp;
        int ans=0,j=0;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]++;
            if(mp.size()>k)
                ans+=func(j,i-1,k,v);
            while(mp.size()>k)
            {
                mp[v[j]]--;
                if(mp[v[j]]==0)
                    mp.erase(v[j]);
                j++;
            }
        }
        ans+=func(j,v.size()-1,k,v);
        return ans;
    }
// https://binarysearch.com/problems/Triple-Inversion
int merge_sort(int l,int r,vector<int>&v)
    {
        if(l>=r)
            return 0;
        int md=(l+r)/2;
        int x=merge_sort(l,md,v);
        int y=merge_sort(md+1,r,v);
        int z=0,k=md+1,j=l;
        while(j<=md and k<=r)
        {
            if(v[j]<=v[k])
                j++;
            else 
            {
                if(v[j]>v[k]*3)
                {
                    cout<<v[j]<<" "<<v[k]<<endl;
                    z+=md-j+1;
                    k++;
                }  
                else     
                    j++;
            }
        }
        inplace_merge(v.begin()+l,v.begin()+md+1,v.begin()+r+1);
        return x+y+z;
    }
int solve(vector<int>&v) {
    int n=v.size();
    return merge_sort(0,n-1,v);
}
// https://leetcode.com/problems/heaters/submissions/
bool valid(int md,vector<int>&v,vector<int>&w)
    {
        int i=0,j=0,n=v.size(),m=w.size();
        while(i<n and j<m)
        {
            if(abs(w[j]-v[i])<=md)
                i++;
            else
                j++;
        }
        if(i==n)
            return true;
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l=0,r=INT_MAX,ans=INT_MAX;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(valid(md,houses,heaters))
            {
                ans=md;
                r=md-1;
            }
            else
                l=md+1;
        }
        return ans;
    }
// https://leetcode.com/problems/two-best-non-overlapping-events/submissions/
int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size(),ans=0;
        vector<int>v(n);
        v[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--)
            v[i]=max(v[i+1],events[i][2]);
        for(int i=0;i<n;i++)
        {
            vector<int>w={events[i][1]+1,0,0};
            int it=lower_bound(events.begin(),events.end(),w)-events.begin();
            int x=0;
            if(it<n)
                x=v[it];
            ans=max(ans,events[i][2]+x);
        }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
int maxLen(vector<int>&v, int n)
    {   
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum==0)
                ans=max(ans,i+1);
            if(mp.find(sum)!=mp.end())
                ans=max(ans,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int> mp;
        for(char &x : p)
            ++mp[x];
            
        int n=s.size(), count=mp.size(), ans=INT_MAX;
        pair<int,int> temp;
        for(int i=0,j=0; i<n; ++i)
        {
            --mp[s[i]];
            if(mp[s[i]]==0)
                --count;
            while(count==0)
            {
                if(ans>i-j+1)
                {
                    temp.first=j;
                    temp.second=i;
                    ans=i-j+1;
                }
                ++mp[s[j]];
                if(mp[s[j]]==1)
                    ++count;
                ++j;
            }
        }
        if(ans==INT_MAX)
            return "-1";
        string x = "";
        for(int i=temp.first; i<=temp.second; ++i)
            x+=s[i];
        return x;
    }
