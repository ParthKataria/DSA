// https://leetcode.com/problems/interval-list-intersections/submissions/
vector<vector<int>> intervalIntersection(vector<vector<int>>&v,vector<vector<int>>&w) {
        int n=v.size(),m=w.size(),i=0,j=0;
        vector<vector<int>>ans;
        while(i<n and j<m)
        {
            if(v[i][0]>w[j][1])
                j++;
            else if(v[i][1]<w[j][0])
                i++;
            else
            {
                ans.push_back({max(v[i][0],w[j][0]),min(v[i][1],w[j][1])});
                if(v[i][1]<w[j][1])
                    i++;
                else
                    j++;
            }    
        }
        return ans;
    }
// https://codeforces.com/contest/439/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int func(int md,vector<int>&v,vector<int>&w,vector<int>&a,vector<int>&b)
{
    int x=upper_bound(v.begin(),v.end(),md)-v.begin();
    int y=upper_bound(w.begin(),w.end(),md)-w.begin();
    int z=a[0];
    if(x<a.size())
        z-=a[x];
    int ll=0;
    if(y<b.size())
        ll+=b[y];
    int ans=x*md-z+ll-(b.size()-y)*md;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>v(n),w(m);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<m;i++)
        cin>>w[i];
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    vector<int>a=v;
    vector<int>b=w;
    for(int i=n-2;i>=0;i--)
        a[i]+=a[i+1];
    for(int i=m-2;i>=0;i--)
        b[i]+=b[i+1];
    int l=v[0],r=w[m-1],ans=0;
    while(l<=r)
    {
        // cout<<l<<" "<<r<<endl;
        int md1=l+(r-l)/3;
        int md2=r-(r-l)/3;
        int ans1=func(md1,v,w,a,b);
        int ans2=func(md2,v,w,a,b);
        if(ans1<ans2)
        {
            ans=ans1;
            r=md2-1;
        }
        else
        {
            ans=ans2;
            l=md1+1;
        }
    }
    cout<<ans<<endl;
}
// https://codeforces.com/contest/1355/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int n,a,r,m;
vector<int>v;
int func(int md)
{
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>md)
            y+=v[i]-md;
        if(v[i]<md)
            x+=md-v[i];
    }
    int l=x*a+y*r;
    int z=min(x,y);
    x-=z;
    y-=z;
    int f=m*z+x*a+y*r;
    return min(l,f);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>r>>m;
    v.resize(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int l=0,r=1e9,ans=0;
    while(l<=r)
    {
        // cout<<l<<" "<<r<<endl;
        int md1=l+(r-l)/3;
        int md2=r-(r-l)/3;
        int ans1=func(md1);
        int ans2=func(md2);
        if(ans1<ans2)
        {
            ans=ans1;
            r=md2-1;
        }
        else
        {
            ans=ans2;
            l=md1+1;
        }
    }
    cout<<ans<<endl;
}
// https://codeforces.com/problemset/problem/1003/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,x,l=0;
    cin>>a>>b>>x;
    string ans="";
    if(b>a)
        l=1;
    for(int i=0;i<x;i++)
    {
        ans+=(l+'0');
        if(l==1)
            b--;
        else
            a--;
        l^=1;
    }
    if(ans[x-1]=='0')
    {
        while(a>0)
        {
            ans+='0';
            a--;
        }
        while(b>0)
        {
            ans+='1';
            b--;
        }
    }
    else
    {
        while(b>0)
        {
            ans+='1';
            b--;
        }
        while(a>0)
        {
            ans+='0';
            a--;
        }
    }
    cout<<ans<<endl;
}
// https://codeforces.com/problemset/problem/1003/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,x;
    cin>>n>>q;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    while(q--)
    {
        cin>>x;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int y=(1<<i);
            if(mp.find(y)!=mp.end())
            {
                int z=min(mp[y],x/y);
                ans+=z;
                x-=z*y;
            }
        }
        if(x==0)
            cout<<ans<<"\n";
        else
            cout<<-1<<"\n";
    }
}
// https://atcoder.jp/contests/abc215/tasks/abc215_d?lang=en
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    cin>>n>>m;
    vector<int>v(m+1,0);
    for(int j=2;j<m+1;j++)
        if(v[j]==0)
            for(int k=j*j;k<m+1;k+=j)
                v[k]=1;
    vector<int>p;
    set<int>w;
    for(int i=2;i<m+1;i++)
        if(v[i]==0)
            p.push_back(i);
    vector<int>ans(m+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(binary_search(p.begin(),p.end(),x))
            w.insert(x);
        else
        for(int j=0;x>1 and j<p.size();j++)
           if((x%p[j])==0)
           {
               w.insert(p[j]);
               while((x%p[j])==0)
                    x/=p[j];
           }
    }
    while(!w.empty())
    {
        int ll=*w.begin();
        w.erase(ll);
        for(int j=ll;j<=m;j+=ll)
            ans[j]=1;
    }
    vector<int>ans2;
    ans2.push_back(1);
    for(int i=2;i<=m;i++)
        if(ans[i]==0)
            ans2.push_back(i);
    cout<<ans2.size()<<endl;
    for(auto it:ans2)
        cout<<it<<endl;
}
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
int minNumberOperations(vector<int>&v) {
        int ans=v[0];
        for(int i=1;i<v.size();i++)
            ans+=max(0,v[i]-v[i-1]);
        return ans;
    }
// https://leetcode.com/problems/maximum-subarray-min-product/
int maxSumMinProduct(vector<int>&v) {
        int n=v.size(),mod=1e9+7;
        vector<pair<int,int>>w(n);
        for(int i=0;i<n;i++)
            w[i]={v[i],i};
        sort(w.begin(),w.end());
        set<int>s;
        s.insert(-1);
        s.insert(n);
        vector<long long>dp(n+1);
        for(int i=1;i<=n;i++)
            dp[i]+=dp[i-1]+v[i-1];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            auto it=s.upper_bound(w[i].second);
            int r=*it-1;
            it--;
            int l=*it+1;
            ans=max(ans,w[i].first*(dp[r+1]-dp[l]));
            s.insert(w[i].second);
        }
        return ans%mod;
    }
// https://leetcode.com/problems/add-strings/submissions/
string addStrings(string a, string b) {
        int i=a.size()-1,j=b.size()-1,carry=0;
        string ans="";
        while(i>=0 or j>=0)
        {
            int x=0,y=0;
            if(i>=0)
                x=a[i]-'0';
            if(j>=0)
                y=b[j]-'0';
            int z=x+y+carry;
            ans+=(z%10)+'0';
            carry=z/10;
            i--;
            j--;
        }
        while(carry>0)
        {
            ans+=(carry%10)+'0';
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://leetcode.com/problems/add-binary/submissions/
string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,carry=0;
        string ans="";
        while(i>=0 or j>=0)
        {
            int x=0,y=0;
            if(i>=0)
                x=a[i]-'0';
            if(j>=0)
                y=b[j]-'0';
            int z=x+y+carry;
            ans+=(z%2)+'0';
            carry=z/2;
            i--;
            j--;
        }
        while(carry>0)
        {
            ans+=(carry%2)+'0';
            carry/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
int value(char r)
    {
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;
     
        return -1;
    }
    int romanToDecimal(string &str) {
        int ans=0,n=str.size();
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            {
                if(value(str[i])>=value(str[i+1]))
                    ans+=value(str[i]);
                else
                {
                    ans+=value(str[i+1])-value(str[i]);
                    i++;
                }
            }
            else
                ans+=value(str[i]);
        }
        return ans;
    }
// https://codeforces.com/contest/975/problem/C#
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,x,y=0;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
        v[i]+=v[i-1];
    while(q--)
    {
        cin>>x;
        y+=x;
        int z=upper_bound(v.begin(),v.end(),y)-v.begin();
        if(z==0)
        {
            cout<<n<<endl;
            continue;
        }
        if(z==n and y>=v[n-1])
        {
            cout<<n<<endl;
            y=0;
            continue;
        }
        z--;
        cout<<n-1-z<<endl;
    }
}
// KMP Algorithm
vector<int>prefix(string s)
{
    int n=s.size();
    vector<int>v(n,0);
    for(int i=1;i<n;i++)
    {
        int j=v[i-1];
        while(j>0 and s[i]!=s[j])
            j=v[j-1];
        if(s[i]==s[j])
            j++;
        v[i]=j;
    }
    return v;
}
int strstr(string s, string x)
{
    int i=0,j=0;
    vector<int>v=prefix(x);
    while(i<s.size())
    {
        if(s[i]==x[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=v[j-1];
            else
                i++;
        }
        if(j==x.size())
            return i-x.size();
    }
    return -1;
}
// https://codeforces.com/contest/126/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    if(n<3)
    {
        cout<<"Just a legend"<<endl;
        return 0;
    }
    vector<int>v(n,0);
    for(int i=1;i<n;i++)
    {
        int j=v[i-1];
        while(j>0 and s[i]!=s[j])
            j=v[j-1];
        if(s[i]==s[j])
            j++;
        v[i]=j;
    }
    // for(auto it:v)
    //     cout<<it<<" ";
    // v[n-1]=min(n/3,v[n-1]);
    if(v[n-1]==0)
    {
        cout<<"Just a legend"<<endl;
        return 0;
    }
    for(int i=v[n-1];i<n-1;i++)
        if(v[i]==v[n-1])
        {
            cout<<s.substr(0,v[n-1])<<endl;
            return 0;
        }
    if(v[v[n-1]-1]!=0)
    {
        cout<<s.substr(0,v[v[n-1]-1])<<endl;
            return 0;
    }
    cout<<"Just a legend"<<endl;
}
