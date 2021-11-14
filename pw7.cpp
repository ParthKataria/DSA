// https://binarysearch.com/problems/Maximum-Number-After-One-Swap
int solve(int n) {
    string s=to_string(n);
    vector<int>v(s.size());
    v[s.size()-1]=s[s.size()-1]-'0';
    for(int j=s.size()-2;j>=0;j--)
        v[j]=max(v[j+1],s[j]-'0');
    for(int i=0;i<s.size()-1;i++)
        if(v[i+1]+'0'>s[i])
        {
            for(int j=s.size()-1;j>i;j--)
                if(s[j]==v[i+1]+'0')
                {
                    s[j]=s[i];
                    break;
                }  
            s[i]=v[i+1]+'0';
            break;  
        }
    return stoi(s);
}
// https://binarysearch.com/problems/Number-of-Operations-to-Decrement-Target-to-Zero
int solve(vector<int>&v, int t) {
    if(t==0)
        return 0;
        unordered_map<int,int>mp1,mp2;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum>t)
                break;
            mp1[sum]=i+1;
        }
        sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            sum+=v[i];
            if(sum>t)
                break;
            mp2[sum]=v.size()-i;
        }
        int ans=INT_MAX;
        mp1[0]=0,mp2[0]=0;
        for(auto it:mp1)
        if(mp2.find(t-it.first)!=mp2.end() and it.second+mp2[t-it.first]<=v.size())
            ans=min(ans,it.second+mp2[t-it.first]);
        if(ans<INT_MAX)
            return ans;
        return -1;
}
// https://binarysearch.com/problems/Minimum-Window-Substring
bool check(vector<int>&a,vector<int>&b)
{
    for(int i=0;i<26;i++)
        if(a[i]<b[i])
            return false;
    return true;
}
int solve(string a, string b) {
    vector<int>v(26,0),w(26,0);
    for(int i=0;i<b.size();i++)
        v[b[i]-'a']++;
    int ans=INT_MAX,j=0;
    for(int i=0;i<a.size();i++)
    {
        w[a[i]-'a']++;
        while(check(w,v))
        {
            ans=min(ans,i-j+1);
            w[a[j]-'a']--;
            j++;
        };
    }
    if(ans<INT_MAX)
        return ans;
    return -1;
}
// https://binarysearch.com/problems/Largest-Sublist-Sum
int solve(vector<int>&v) {
    int mx=INT_MIN,sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        mx=max(mx,sum);
        if(sum<0)
            sum=0;
    }
    return mx;
}
// https://binarysearch.com/problems/Packing-Boxes
vector<vector<int>> solve(vector<int>& v) {
    vector<int>w;
    vector<vector<int>>ans;
    for(int i=0;i<v.size();i++)
    {
        if(w.empty())
            w.push_back(v[i]);
        else if(v[i]==v[i-1])
            w.push_back(v[i]);
        else if(v[i]!=v[i-1])
        {
            ans.push_back(w);
            w.clear();
            w.push_back(v[i]);
        }
    }
    if(!w.empty())
        ans.push_back(w);
    return ans;
}
// https://codeforces.com/problemset/problem/1598/C#
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
            mp[x]++;
        }
        if(((2*sum)%n)>0)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0,ans1=0,y=(2*sum)/n;;
        for(auto it:mp)
        {
            if(2*it.first==y)
                ans1+=it.second*(it.second-1)/2;
            else if(mp.find(y-it.first)!=mp.end())
                ans+=it.second*mp[y-it.first];
        }
        cout<< ans1 + ans/2<<endl;
    }
}
// https://codeforces.com/problemset/problem/1399/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(int y,map<int,int>&mp)
{
    int ans=0,ans1=0;
        for(auto it:mp)
        {
            if(2*it.first==y)
                ans1+=it.second/2;
            else if(mp.find(y-it.first)!=mp.end())
                ans+=min(it.second,mp[y-it.first]);
        }
        return ans1 + ans/2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[x]++;
        }
        for(int i=2;i<=100;i++)
            ans=max(ans,func(i,mp));
        cout<<ans<<'\n';
    }
}
