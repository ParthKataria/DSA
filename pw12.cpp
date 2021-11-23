// https://leetcode.com/problems/next-permutation/submissions/
 void nextPermutation(vector<int>&v) {
        int n=v.size(),mx=v[n-1],i;
        for(i=n-2;i>=0;i--)
        {
            if(v[i]<mx)
                break;
            mx=max(mx,v[i]);
        }
        if(i==-1)
        {
            sort(v.begin(),v.end());
            return;
        }  
        int id=n-1,mn=INT_MAX;
        for(int j=n-1;j>i;j--)
            if(v[j]>v[i] and mn>v[j])
            {
                mn=v[j];
                id=j;
            }
        swap(v[i],v[id]);
        sort(v.begin()+i+1,v.end());
    }
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
int findPlatform(int arr[], int dep[], int n)
    {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
            v.push_back({arr[i],0});
          for(int i=0;i<n;i++)
               v.push_back({dep[i],1});
           sort(v.begin(),v.end());
         int ans=0,mx=INT_MIN;
         for(int i=0;i<v.size();i++)
         {   if(v[i][1]==0)
             {
                 ans++;
                 mx=max(ans,mx);
             }
           else
                ans--;
        }
          return mx;
    }
// https://leetcode.com/problems/sliding-window-maximum/submissions/
vector<int> maxSlidingWindow(vector<int>&v, int k) {
        vector<int>ans;
        deque<int>q;
        for(int i=0;i<k;i++)
        {
            while(!q.empty() and q.back()<v[i])
                q.pop_back();
            q.push_back(v[i]);
        }
        ans.push_back(q.front());
        int j=0;
        for(int i=k;i<v.size();i++)
        {
            if(v[j]==q.front())
                q.pop_front();
            j++;
            while(!q.empty() and q.back()<v[i])
                q.pop_back();
            q.push_back(v[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/
string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() and st.top()==s[i])
                st.pop();
            else 
                st.push(s[i]);
        }
        string x="";
        while(!st.empty())
        {
            x+=st.top();
            st.pop();
        }
        reverse(x.begin(),x.end());
        return x;
    }
// https://leetcode.com/problems/valid-parentheses/submissions/
bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
                st.push(s[i]);
            else 
            {
                if(st.empty())
                    return false;
                if(s[i]==')' and st.top()!='(')
                    return false;
                if(s[i]=='}' and st.top()!='{')
                    return false;
                if(s[i]==']' and st.top()!='[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
    int minAddToMakeValid(string s) {
        stack<char>st;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push('(');
            else 
            {
                if(st.empty())
                    sum++;
                else
                    st.pop();
            }
        }
        return sum+st.size();
    }
// https://leetcode.com/problems/3sum-with-multiplicity/submissions/
int threeSumMulti(vector<int>&v, int t) {
        sort(v.begin(),v.end());
        int n=v.size(),ans=0,mod=1e9+7;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1,sum=t-v[i];
            while(j<k)
            {
                if(v[j]+v[k]<sum)
                    j++;
                else if(v[j]+v[k]>sum)
                    k--;
                else if(2*v[j]==sum)
                {
                    int r=j+1,cnt=1;
                    while(r<n and v[r]==v[r-1])
                    {
                        cnt++;
                        r++;
                    }    
                    ans=(ans+(cnt*(cnt-1))/2)%mod;
                    j=r;
                }
                else if(2*v[k]==sum)
                {
                    int r=j-1,cnt=1;
                    while(r>i and v[r]==v[r+1])
                    {
                        cnt++;
                        r--;
                    }  
                    ans=(ans+(cnt*(cnt-1))/2)%mod;
                    k=r;
                }
                else 
                {
                    int x=j+1,y=k-1,cnt1=1,cnt2=1;
                    while(v[x]==v[x-1])
                    {
                        cnt1++;
                        x++;
                    }
                    while(v[y]==v[y+1])
                    {
                        cnt2++;
                        y--;
                    }
                    j=x,k=y;
                    ans=(ans+cnt1*cnt2)%mod;
                }
            }
        }
        return ans;
    }
https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/submissions/
int minInsertions(string s) {
        stack<char>st;
        int ans=0,cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(cnt==1)
                {
                    if(st.empty())
                        ans+=2;
                    else
                    {
                        ans++;
                        st.pop();
                    }
                    cnt=0;
                }   
                st.push('(');
            }    
            else
            {
                cnt++;
                if(cnt==2)
                {
                    if(st.empty())
                        ans++;
                    else
                        st.pop();
                    cnt=0;
                }
            }  
        }
        if(cnt==1)
        {
            if(!st.empty())
            {
                ans++;
                st.pop();
            }
            else
                ans+=2;
        }
        return ans+st.size()*2;
    }
// https://leetcode.com/problems/subarray-product-less-than-k/submissions/
int numSubarrayProductLessThanK(vector<int>&v, int k) {
        if(k<=1)
            return 0;
        int j=0,ans=0,i=0,n=v.size(),p=1;
        while(i<n)
        {
            p*=v[i];
            if(p>=k)
            {
                ans+=(i-j)*(i-j+1)/2;
                while(p>=k)
                {
                    p/=v[j];
                    j++;
                }
                ans-=(i-j)*(i-j+1)/2;
            }
            i++;
        }
        ans+=(n-j)*(n-j+1)/2;
        return ans;
    }
// https://leetcode.com/problems/4sum/submissions/
vector<vector<int>> fourSum(vector<int>&v, int t) {
        sort(v.begin(),v.end());
        int n=v.size();
        set<vector<int>>s;
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++)
            for(int l=i+1;l<n-2;l++)
            {
                int j=l+1,k=n-1,sum=t-v[i]-v[l];
                while(j<k)
                {
                    if(v[j]+v[k]<sum)
                        j++;
                    else if(v[j]+v[k]>sum)
                        k--;
                    else if(2*v[j]==sum)
                    {
                        s.insert({v[i],v[l],v[j],v[j]});
                        int r=j+1,cnt=1;
                        while(r<n and v[r]==v[r-1])
                        {
                            cnt++;
                            r++;
                        }    
                        // ans=(ans+(cnt*(cnt-1))/2)%mod;
                        j=r;
                    }
                    else if(2*v[k]==sum)
                    {
                        s.insert({v[i],v[l],v[k],v[k]});
                        int r=j-1,cnt=1;
                        while(r>i and v[r]==v[r+1])
                        {
                            cnt++;
                            r--;
                        }  
                        // ans=(ans+(cnt*(cnt-1))/2)%mod;
                        k=r;
                    }
                    else 
                    {
                        s.insert({v[i],v[l],v[j],v[k]});
                        int x=j+1,y=k-1,cnt1=1,cnt2=1;
                        while(v[x]==v[x-1])
                        {
                            cnt1++;
                            x++;
                        }
                        while(v[y]==v[y+1])
                        {
                            cnt2++;
                            y--;
                        }
                        j=x,k=y;
                        // ans=(ans+cnt1*cnt2)%mod;
                    }
                }
            }
        while(!s.empty())
        {
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
            return ans;
    }
// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
int singleNonDuplicate(vector<int>&v) {
        int n=v.size();
        if(n==1)
            return v[0];
        if(v[0]!=v[1])
            return v[0];
        if(v[n-1]!=v[n-2])
            return v[n-1];
        int l=1,r=n-2;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(v[md]!=v[md-1] and v[md]!=v[md+1])
                return v[md];
            if(md%2)
            {
                if(v[md]!=v[md-1])
                    r=md-1;
                else
                    l=md+1;
            }
            else
            {
                if(v[md+1]!=v[md])
                    r=md-1;
                else
                    l=md+1;
            }
        }
        return -1;
    }
// https://www.spoj.com/problems/ABCDEF/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    unordered_map<int,int>mp1,mp2;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                mp1[v[i]*v[j]+v[k]]++;
                if(v[k]!=0)
                    mp2[v[k]*(v[i]+v[j])]++;
            }
    int ans=0;
    for(auto it:mp1)
        if(mp2.find(it.first)!=mp2.end())
            ans+=it.second*mp2[it.first];
    cout<<ans<<endl;
}
