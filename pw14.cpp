// https://codeforces.com/problemset/status?my=on
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool valid(int x,unordered_map<int,int>&mp,int k)
{
    int ans=0;
    for(auto it:mp)
    {
        int y=it.second;
        while(y>=x)
        {
            ans++;
            y-=x;
        }
    }
    return ans>=k;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n>>k;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int md=(l+r)/2;
        if(valid(md,mp,k))
        {
            ans=md;
            l=md+1;
        }
        else
            r=md-1;
    }
    vector<int>v;
    for(auto it:mp)
        for(int i=0;i<it.second/ans and v.size()<k;i++)
            v.push_back(it.first);
    // cout<<ans<<"\n";
    for(auto it:v)
        cout<<it<<" ";
    cout<<"\n";
}
// https://codeforces.com/problemset/problem/1550/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,a,b;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>s;
        if(b>=0)
            cout<<a*n+b*n<<endl;
        else
        {
            stack<char>st;
            for(int i=0;i<s.size();i++)
                if(st.empty() or st.top()!=s[i])
                    st.push(s[i]);
            int x=0,y=0;
            while(!st.empty())
            {
                if(st.top()=='0')
                    x++;
                else
                    y++;
                st.pop();
            }
            cout<<a*n+(min(x,y)+1)*b<<endl;
        }
    }
}
// https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/
bool check(int i,int j,int k,int dp[][26])
    {
        if(i==j)
            return true;
        int cnt=0;
        for(int k=0;k<26;k++)
            if((dp[j+1][k]-dp[i][k])%2)
                cnt++;
        if(cnt<=1)
            return true;
        return k>=cnt/2;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int dp[n+1][26];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i+1][s[i]-'a']++;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<26;j++)
                dp[i][j]+=dp[i-1][j];
        vector<bool>ans(queries.size());
        for(int i=0;i<queries.size();i++)
            ans[i]=check(queries[i][0],queries[i][1],queries[i][2],dp);
        return ans;
    }
// https://leetcode.com/problems/sum-of-subarray-minimums/submissions/
int sumSubarrayMins(vector<int>&v) {
        vector<pair<long long,long long>>w;
        for(int i=0;i<v.size();i++)
            w.push_back({v[i],i});
        sort(w.begin(),w.end());
        set<int>s;
        s.insert(-1);
        s.insert(v.size());
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            auto it=s.upper_bound(w[i].second);
            int r=*it -1;
            it--;
            int l=*it+1;
            ans=(ans+(w[i].first*(w[i].second-l+1)*(r-w[i].second+1))%mod)%mod;
            s.insert(w[i].second);
        }
        return ans;
    }
// https://leetcode.com/problems/remove-outermost-parentheses/submissions/
string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(!st.empty())
                    ans+=s[i];
                st.push('(');
            }
            else
            {
                st.pop();
                if(!st.empty())
                    ans+=s[i];
            }
        }
        return ans;
    }
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/submissions/
string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push({'(',i});
            else if(s[i]==')')
            {
                if(st.empty())
                    s[i]='_';
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            s[st.top().second]='_';
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++)
            if(s[i]!='_')
                ans+=s[i];
        return ans;
    }
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/
string reverseParentheses(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push("(");
            else if(s[i]==')')
            {
                if(st.top()=="(")
                    st.pop();
                else
                {
                    string x=st.top();
                    st.pop();
                    st.pop();
                    reverse(x.begin(),x.end());
                    if(st.empty() or st.top()=="(")
                        st.push(x);
                    else
                    {
                        string y=st.top();
                        st.pop();
                        st.push(y+x);
                    }
                }
            }
            else
            {
                if(st.empty() or st.top()=="(")
                {
                    string x="";
                    x+=s[i];
                    st.push(x);
                }
                else
                {
                    string x=st.top();
                    st.pop();
                    st.push(x+s[i]);
                }
            }
        }
        return st.top();
    }
// https://leetcode.com/problems/range-frequency-queries/submissions/
class RangeFreqQuery {
public:
    map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>&v) {
        for(int i=0;i<v.size();i++)
            mp[v[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        if(mp.find(value)==mp.end())
            return 0;
        int it=upper_bound(mp[value].begin(),mp[value].end(),right)-lower_bound(mp[value].begin(),mp[value].end(),left);
        return it;
    }
};
// https://leetcode.com/problems/validate-stack-sequences/submissions/
bool validateStackSequences(vector<int>& v, vector<int>& w) {
        stack<int>st;
        int j=0;
        for(int i=0;i<v.size();i++)
        {
            st.push(v[i]);
            while(!st.empty() and st.top()==w[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
// https://leetcode.com/problems/longest-well-performing-interval/submissions/
int longestWPI(vector<int>&v) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>8)
                v[i]=1;
            else
                v[i]=-1;
        }
        unordered_map<int,int>mp;
        int ans=0,x=0;
        for(int i=0;i<v.size();i++)
        {
            x+=v[i];
            if(x>0)
                ans=i+1;
            else 
            {
                if(mp.find(x-1)!=mp.end())
                    ans=max(ans,i-mp[x-1]);
            }
            if(mp.find(x)==mp.end())
                mp[x]=i;
        }
        return ans;
    }
// https://leetcode.com/problems/online-stock-span/submissions/
stack<pair<int,int>>st;
    int cnt=-1;
    int next(int p) {
        if(cnt==-1)
            st.push({INT_MAX,-1});
        cnt++;
        while(st.top().first<=p)
            st.pop();
        int ans=0;
        if(st.top().first>p)
            ans=cnt-st.top().second;
        st.push({p,cnt});
        return ans;
    }
// https://leetcode.com/problems/min-stack/submissions/
stack<int>st1,st2;
    void push(int val) {
        st1.push(val);
        if(st2.empty() or st2.top()>=val)
            st2.push(val);
    }
    
    void pop() {
        int x=st1.top();
        st1.pop();
        if(st2.top()==x)
            st2.pop();
    }
    
    int top() {
        if(st1.empty())
            return -1;
        return st1.top();
    }
    
    int getMin() {
        if(st2.empty())
            return -1;
        return st2.top();
    }
// https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
int evalRPN(vector<string>&v) {
        stack<int>st;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x+y);
            }
            else if(v[i]=="-")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y-x);
            }
            else if(v[i]=="*")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x*y);
            }
            else if(v[i]=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
            }
            else 
                st.push(stoi(v[i]));
        }
        return st.top();
    }
// https://www.spoj.com/problems/JNEXT/
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
    int t,n;
    char x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string ans="";
        for(int i=0;i<n;i++)
        {
            cin>>x;
            ans+=x;
        }
        if(next_permutation(ans.begin(),ans.end()))
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
}
// https://lightoj.com/problem/closest-distance
#include<bits/stdc++.h>
using namespace std;
double dist(pair<double,double>&a,pair<double,double>&b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        vector<double>v(8);
        for(int i=0;i<8;i++)
            cin>>v[i];
        double ans=0.0;
        for(int i=0;i<300;i++)
        {
            pair<double,double>a={(v[2]+2*v[0])/3,(v[3]+2*v[1])/3};
            pair<double,double>b={(2*v[2]+v[0])/3,(2*v[3]+v[1])/3};
            pair<double,double>c={(v[6]+2*v[4])/3,(v[7]+2*v[5])/3};
            pair<double,double>d={(2*v[6]+v[4])/3,(2*v[7]+v[5])/3};
            double x=dist(a,c);
            double y=dist(b,d);
            if(x<y)
            {
                ans=x;
                v[2]=b.first;
                v[3]=b.second;
                v[6]=d.first;
                v[7]=d.second;
            }
            else
            {
                ans=y;
                v[0]=a.first;
                v[1]=a.second;
                v[4]=c.first;
                v[5]=c.second;
            }
        }
        cout<<"Case "<<k<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
}
// https://leetcode.com/problems/remove-duplicate-letters/submissions/
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/
string removeDuplicateLetters(string s) {
        int n=s.size();
        map<char,int>mp;
        set<char>st;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        string ans="";
        ans+=s[0];
        mp[s[0]]--;
        st.insert(s[0]);
        for(int i=1;i<n;i++)
        {
            mp[s[i]]--;
            if(st.find(s[i])!=st.end())
                continue;
            int x=ans.size()-1;
            while(!ans.empty() and ans[x]>s[i] and mp[ans[x]]>0)
            {
                st.erase(ans[x]);
                ans.pop_back();  
                x=ans.size()-1;
            } 
            ans+=s[i];
            st.insert(s[i]);
        }
        return ans;
    }
// https://leetcode.com/problems/contiguous-array/submissions/
int findMaxLength(vector<int>&v) {
        int n=v.size();
        for(int i=0;i<n;i++)
            if(v[i]==0)
                v[i]=-1;
        unordered_map<int,int>mp;
        int ans=0,x=0;
        for(int i=0;i<n;i++)
        {
            x+=v[i];
            if(x==0)
                ans=i+1;
            else if(mp.find(x)!=mp.end())
                ans=max(ans,i-mp[x]);
            else
                mp[x]=i;
        }
        return ans;
    }
// https://leetcode.com/problems/binary-subarrays-with-sum/submissions/
int numSubarraysWithSum(vector<int>&v, int goal) {
        int n=v.size();
        unordered_map<int,int>mp;
        int ans=0,x=0;
        for(int i=0;i<n;i++)
        {
            x+=v[i];
            if(x==goal)
                ans++;
            if(mp.find(x-goal)!=mp.end())
                ans+=mp[x-goal];
            mp[x]++;
        }
        return ans;
    }
// https://leetcode.com/contest/weekly-contest-269/problems/removing-minimum-and-maximum-from-array/
class Solution {
public:
    int minimumDeletions(vector<int>&v) {
        int mn=INT_MAX,mx=INT_MIN,id1=0,id2=0,n=v.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>mx)
            {
                mx=v[i];
                id2=i;
            }
            if(v[i]<mn)
            {
                mn=v[i];
                id1=i;
            }
        }
        if(id1>id2)
            ans=min(min(id1+1,n-id2),id2+1+n-id1);
        else
            ans=min(min(id2+1,n-id1),id1+1+n-id2);
        return ans;
    }
};
