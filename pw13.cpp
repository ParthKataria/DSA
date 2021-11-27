// https://leetcode.com/problems/daily-temperatures/submissions/
vector<int> dailyTemperatures(vector<int>&v) {
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(st.empty())
                ans.push_back(0);
            else if(st.top().first>v[i])
                ans.push_back(st.top().second-i);
            else if(v[i]>=st.top().first)
            {
                while(!st.empty() and v[i]>=st.top().first)
                    st.pop();
                if(st.empty())
                    ans.push_back(0);
                else 
                    ans.push_back(st.top().second-i);
            }
            st.push({v[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://leetcode.com/problems/next-greater-element-ii/submissions/
vector<int> ngr(vector<int>v)
    {
        int n=v.size(),i;
        for(int i=0;i<n;i++)
            v.push_back(v[i]);
        stack<int>s;
        vector<int>ans;
        for(i=2*n-1;i>=0;i--)
        {
            if(s.empty())
                ans.push_back(-1);
            else if(!s.empty() and v[i]<s.top())
                ans.push_back(s.top());
            else if(!s.empty() and v[i]>=s.top())
            {
                while(!s.empty() and v[i]>=s.top())
                    s.pop();
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            s.push(v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>&v) {
        vector<int>ans1=ngr(v);
        vector<int>ans2(v.size());
        for(int i=0;i<v.size();i++)
            ans2[i]=ans1[i];
        return ans2;
    }
// https://leetcode.com/problems/asteroid-collision/submissions/
vector<int> asteroidCollision(vector<int>&v) {
        stack<int>st;
        for(int i=0;i<v.size();i++)
        {
            st.push(v[i]);
            while(st.size()>=2)
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if((x>0 and y>0) or y<0)
                {
                    st.push(y);
                    st.push(x);
                    break;
                }
                else
                {
                    if(abs(x)>abs(y))
                        st.push(x);
                    else if(abs(x)<abs(y))
                        st.push(y);
                }
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://leetcode.com/problems/132-pattern/submissions/
bool find132pattern(vector<int>&v) {
        int n=v.size();
        multiset<int>s1;
        for(int i=n-1;i>=1;i--)
            s1.insert(v[i]);
        int mn=v[0];
        for(int i=1;i<n-1;i++)
        {
            s1.erase(s1.lower_bound(v[i]));
            auto it=s1.lower_bound(v[i]);
            if(it!=s1.begin())
            {
                it--;
                if(*it>mn)
                    return true;
            }
            mn=min(mn,v[i]);
        }    
        return false;
    }
// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/submissions/
int func(int x,int &t,vector<int>&v,vector<int>&w)
    {
        int y=upper_bound(v.begin(),v.end(),x)-v.begin();
        int i=v.size()-y;
        return abs(t-(w[0]-w[y]+i*x));
    }
    int findBestValue(vector<int>&v, int t) 
    {
        sort(v.begin(),v.end());
        int n=v.size(),l=0,r=v[n-1]-1,ans=v[n-1];
        vector<int>w=v;
        for(int i=n-2;i>=0;i--)
            w[i]+=w[i+1];
        if(w[0]<=t)
            return ans;
        while(l<=r)
        {
            int md1=l+(r-l)/3,md2=r-(r-l)/3;
            int a=func(md1,t,v,w);
            int b=func(md2,t,v,w);
            if(a>b)
            {
                ans=md2;
                l=md1+1;
            }
            else
            {
                ans=md1;
                r=md2-1;
            }
        }
        return ans;
    }
// https://www.spoj.com/problems/KOPC12A/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(int x,vector<int>&v,vector<int>&c)
{
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans+=abs(x-v[i])*c[i];
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=INT_MAX,r=0,ans=0;
        vector<int>v(n),c(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            l=min(l,v[i]);
            r=max(r,v[i]);
        }
        for(int i=0;i<n;i++)
            cin>>c[i];
        while(l<=r)
        {
            int a=l+(r-l)/3,b=r-(r-l)/3;
            int x=func(a,v,c);
            int y=func(b,v,c);
            if(x>y)
            {
                ans=y;
                l=a+1;
            }
            else
            {
                ans=x;
                r=b-1;
            }
        }
        cout<<ans<<endl;
    }
}
// https://www.codechef.com/problems/AMCS03
#include<bits/stdc++.h>
using namespace std;
#define int long long
double func(double x,vector<int>&v,vector<int>&w)
{
    double mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        mn=min(mn,v[i]*x+w[i]);
        mx=max(mx,v[i]*x+w[i]);
    }
    return mx-mn;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>v(n),w(n);
    for(int i=0;i<n;i++)
        cin>>v[i]>>w[i];
    double l=0,r=k,ans=0;
    for(int i=0;i<100;i++)
    {
        double a=l+(r-l)/3,b=r-(r-l)/3;
        double x=func(a,v,w);
        double y=func(b,v,w);
        if(x>y)
        {
            ans=y;
            l=a;
        }
        else
        {
            ans=x;
            r=b;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
// https://leetcode.com/problems/baseball-game/submissions/
 int calPoints(vector<string>&v) {
        stack<int>s;
        for(int i=0;i<v.size();i++)
        {
            if(v[i][0]=='C')
                s.pop();
            else if(v[i][0]=='D')
                s.push(2*s.top());
            else if(v[i][0]=='+')
            {
                int x=s.top();
                s.pop();
                int y=x+s.top();
                s.push(x);
                s.push(y);
            }
            else 
                s.push(stoi(v[i]));
        }
        int ans=0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/submissions/
string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<s.size();i++)
        {
            if(st.empty() or s[i]!=st.top().first)
                st.push({s[i],1});
            else
            {
                auto it=st.top();
                st.pop();
                it.second++;
                if(it.second<k)
                    st.push(it);
            }
        }
        string ans="";
        while(!st.empty())
        {
            auto it=st.top();
            st.pop();
            while(it.second>0)
            {
                ans+=it.first;
                it.second--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://leetcode.com/problems/backspace-string-compare/submissions/
 bool backspaceCompare(string s, string t) {
        stack<char>a,b;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' and !a.empty())
                a.pop();
            else if(s[i]!='#')
                a.push(s[i]);
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#' and !b.empty())
                b.pop();
            else if(t[i]!='#')
                b.push(t[i]);
        }
        if(a.size()!=b.size())
            return false;
        while(a.size()>0)
        {
            if(a.top()!=b.top())
                return false;
            a.pop();
            b.pop();
        }
        return true;
    }
// https://leetcode.com/problems/score-of-parentheses/submissions/
int scoreOfParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(0);
            else
            {
                if(st.top()==0)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int sum=0;
                    while(st.top()!=0)
                    {
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
// https://www.hackerrank.com/contests/hourrank-14/challenges/lilys-homework/problem
int n=arr.size();
    vector<int>v=arr,w=arr,arr2=arr;
    map<int,int>mp,mp2;
        for(int i=0;i<n;i++)
             mp[arr[i]]=i; 
        for(int i=0;i<n;i++)
             mp2[arr[i]]=i;
       sort(v.begin(),v.end());
       int ans=0;
       for(int i=0;i<n;i++)
           if(v[i]!=arr[i])
           {
                ans++;
                mp[arr[i]]=mp[v[i]];
                swap(arr[i],arr[mp[v[i]]]);
           }
       sort(w.rbegin(),w.rend());
       int ans2=0;
       for(int i=0;i<n;i++)
           if(w[i]!=arr2[i])
           {
                ans2++;
                mp2[arr2[i]]=mp2[w[i]];
                swap(arr2[i],arr2[mp2[w[i]]]);
           }
       return min(ans,ans2);
// https://leetcode.com/problems/maximum-width-ramp/
int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(int i=0;i<n;i++)
            s.insert(i);
        int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++)
        {
            if(*s.begin()!=v[i].second)
                ans=max(ans,v[i].second-*s.begin());
            s.erase(v[i].second);
        }
        return ans;
}
// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
 vector<int>nsr(vector<int>&v)
    {
        int n=v.size();
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
                ans.push_back(n);
            else if(s.top().first<v[i])
                ans.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=v[i])
                    s.pop();
                if(s.empty())
                    ans.push_back(n);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>nsl(vector<int>&v)
    {
        int n=v.size();
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                ans.push_back(-1);
            else if(s.top().first<v[i])
                ans.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=v[i])
                    s.pop();
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>&v) {
        int ans=0,n=v.size();
        vector<int>a=nsr(v);
        vector<int>b=nsl(v);
        for(int i=0;i<n;i++)
            ans=max(ans,v[i]*(a[i]-b[i]-1));
        return ans;
    }
// https://leetcode.com/problems/maximal-rectangle/submissions/
 vector<int>nsr(vector<int>&v)
    {
        int n=v.size();
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
                ans.push_back(n);
            else if(s.top().first<v[i])
                ans.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=v[i])
                    s.pop();
                if(s.empty())
                    ans.push_back(n);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>nsl(vector<int>&v)
    {
        int n=v.size();
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                ans.push_back(-1);
            else if(s.top().first<v[i])
                ans.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=v[i])
                    s.pop();
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>&v) {
        int ans=0,n=v.size();
        vector<int>a=nsr(v);
        vector<int>b=nsl(v);
        for(int i=0;i<n;i++)
            ans=max(ans,v[i]*(a[i]-b[i]-1));
        return ans;
    }
    int maximalRectangle(vector<vector<char>>&matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>>v(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                v[i][j]=matrix[i][j]-'0';
        for(int i=1;i<v.size();i++)
            for(int j=0;j<v[i].size();j++)
                if(v[i][j]==1)
                    v[i][j]+=v[i-1][j];
        int ans=0;
        for(int i=0;i<v.size();i++)
            ans=max(ans,largestRectangleArea(v[i]));
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
string FirstNonRepeating(string s){
            int arr[26]={0};
            string ans="";
            for(int i=0;i<s.size();i++)
            {
                if(arr[s[i]-'a']==0)
                    arr[s[i]-'a']=i+1;
                  else
                    arr[s[i]-'a']=-1;
              int x=INT_MAX;
                for(int j=0;j<26;j++)
                    if(arr[j]>0)
                        x=min(x,arr[j]);
              if(x==INT_MAX)
                ans+='#';
               else
                ans+=s[x-1];
            }
            return ans;
        }
