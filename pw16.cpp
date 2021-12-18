// https://leetcode.com/problems/maximum-number-of-balloons/submissions/
int maxNumberOfBalloons(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        int ans=INT_MAX;
        string z="ban",w="lo";
        for(int i=0;i<3;i++)
            ans=min(ans,mp[z[i]]);
        for(int i=0;i<2;i++)
            ans=min(ans,mp[w[i]]/2);
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1#
string longestCommonPrefix (string arr[], int N)
    {
        int j=INT_MAX;
        string s="";
        for(int i=0;i<N;i++)
            if(arr[i].size()<j)
            {
                j=arr[i].size();
                s=arr[i];
            }
        int k=0,c=1;
        while(c==1 and k<j)
        {
            for(int i=0;i<N;i++)
                if(arr[i][k]!=s[k])
                    c=0;
            if(c)
                k++;
        }
        if(k==0)
            return "-1";
        return s.substr(0,k);
    }
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#
 bool tru(int l,int r,string &s)
  {
    while(l<r)
    {
        if(s[l]!=s[r])
        return false;
        l++;
        r--;
    }
    return true;
  }
    string longestPalin (string s) {
        int ans=0,l=0,r=0;
        for(int i=0;i<s.size();i++)
            for(int j=i;j<s.size();j++)
            if(tru(i,j,s) and j-i+1>ans)
            {
                ans=j-i+1;
                l=i;
                r=j;
            }
        return s.substr(l,r-l+1);    
    }
// https://leetcode.com/problems/reverse-only-letters/submissions/
string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            while(l<=r and (s[l]<'A' or (s[l]>'Z' and s[l]<'a')))
                l++;
            while(r>=l and (s[r]<'A' or (s[r]>'Z' and s[r]<'a')))
                r--;
            if(l<r)
            {
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
// https://leetcode.com/problems/valid-palindrome-ii/submissions/
bool valid(int l,int r,string s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }    
        return true;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
                return valid(l+1,r,s) or valid(l,r-1,s);
        }
        return true;
    }
// https://leetcode.com/problems/buddy-strings/submissions/ 
bool buddyStrings(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int sum=0,n=s.size(),mx=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            mx=max(mx,mp[s[i]]);
            if(s[i]!=t[i])
                sum++;
        }
        if(sum==0 and mx>=2)
            return true;
        for(int i=0;i<n;i++)
            mp[t[i]]--;
        for(auto it:mp)
            if(it.second!=0)
                return false;
        return sum==2;
    }
// https://lightoj.com/problem/hidden-secret
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
    int t;
    cin>>t;
    string c;
    getline(cin,c);
    for(int k=1;k<=t;k++)
    {
        string a,b;
        getline(cin,a);
        // cout<<a<<endl;
        unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>='A' and a[i]<='Z')
                mp[a[i]-'A']++;
            if(a[i]>='a' and a[i]<='z')
                mp[a[i]-'a']++;
        }
        getline(cin,b);
        // cout<<b<<endl;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]>='A' and b[i]<='Z')
                mp[b[i]-'A']--;
            if(b[i]>='a' and b[i]<='z')
                mp[b[i]-'a']--;
        }
        int flag=1;
        for(auto it:mp)
            if(it.second!=0)
            {
                flag=0;
                break;
            }
        if(flag)
            cout<<"Case "<<k<<": Yes"<<endl;
        else
            cout<<"Case "<<k<<": No"<<endl;
    }
}
// https://leetcode.com/problems/repeated-substring-pattern/submissions/
bool repeatedSubstringPattern(string s) {
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
        if(v[n-1]==0)
            return false;
        v[n-1]=n-v[n-1];
        string l=s.substr(0,v[n-1]);
        for(int i=v[n-1];i<n;i+=v[n-1])
        {
            string w=s.substr(i,v[n-1]);
            if(l!=w)
                return false;
        }
        return true;
    }
// https://leetcode.com/problems/minimum-area-rectangle/submissions/
int minAreaRect(vector<vector<int>>&v) {
        map<vector<int>,int>mp;
        int n=v.size();
        for(int i=0;i<n;i++)
            mp[v[i]]=1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(v[i][0]!=v[j][0] and v[i][1]!=v[j][1] and mp.find({v[i][0],v[j][1]})!=mp.end() and mp.find({v[j][0],v[i][1]})!=mp.end())
                    ans=min(ans,abs(v[i][0]-v[j][0])*abs(v[i][1]-v[j][1]));
        if(ans<INT_MAX)
        return ans;
        return 0;
    }
// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/submissions/
 bool valid(int md,string &s,unordered_map<char,int>&mp2)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<md;i++)
            mp[s[i]]++;
        int j=0;
        for(auto it:mp)
            if(it.second==md or (md-1==it.second and mp2[it.first]>=md))
                return true;
        for(int i=md;i<s.size();i++)
        {
            mp[s[j]]--;
            mp[s[i]]++;
            for(auto it:mp)
            if(it.second==md or (md-1==it.second and mp2[it.first]>it.second))
                return true;
            j++;
        }
        return false;
    }
    int maxRepOpt1(string s) {
        int l=1,r=s.size(),ans=0;
        unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++)
            mp2[s[i]]++;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(valid(md,s,mp2))
            {
                ans=md;
                l=md+1;
            }
            else
                r=md-1;
        }
        return ans;
    }
// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/submissions/
int minimumSwap(string s1, string s2) {
        int ans=0;
        vector<set<int>>v(2);
        for(int i=0;i<s1.size();i++)
            if(s1[i]!=s2[i])
                v[s1[i]-'x'].insert(i);
        for(int i=0;i<s1.size();i++)
            if(s1[i]!=s2[i])
            {
                int x=s1[i]-'x';
                auto it=v[x].upper_bound(i);
                if(it!=v[x].end())
                {
                    ans++;
                    int y=*it;
                    swap(s2[i],s1[y]);
                    v[x].erase(y);
                    continue;
                }
                x^=1;
                auto it2=v[x].upper_bound(i);
                if(it2!=v[x].end())
                {
                    ans+=2;
                    int y=*it2;
                    swap(s1[i],s1[y]);
                    v[x].erase(y);
                    continue;
                }
                return -1;
            }
        return ans;
    }
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/submissions/
int longestSubstring(string s, int k) {
        int ans=0,n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++)
            dp[i+1][s[i]-'a']++;
        for(int i=1;i<=n;i++)
            for(int j=0;j<26;j++)
                dp[i][j]+=dp[i-1][j];
        map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
            int mx=-1;
            for(auto it:mp)
                if(it.second.size()<k)
                    mx=max(mx,*it.second.rbegin());
            // cout<<mx<<" ";
            while(1)
            {
                if(i==mx)
                    break;
                int j=0;
                for(j=0;j<26;j++)
                    if(dp[i+1][j]-dp[mx+1][j]>0 and dp[i+1][j]-dp[mx+1][j]<k)
                        mx=max(mx,*mp['a'+j].rbegin());
                if(j==26)
                    break;
            }
            ans=max(ans,i-mx);
        }
        return ans;
    }
// https://leetcode.com/problems/maximum-swap/submissions/
int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int>v(n);
        v[n-1]=n-1;
        int mx=s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]>mx)
            {
                mx=s[i];
                v[i]=i;
            }
            else
                v[i]=v[i+1];
        }
        for(int i=0;i<n-1;i++)
            if(s[v[i+1]]>s[i])
            {
                swap(s[v[i+1]],s[i]);
                break;
            }
        return stoi(s);
    }
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/
long long func(int x,vector<int>&v)
    {
        long long sum=0;
        for(int i=0;i<v.size();i++)
            sum+=abs(x-v[i]);
        return sum;
    }
    int minMoves2(vector<int>&v) {
        long long ans=0,l=INT_MAX,r=INT_MIN,n=v.size();
        for(int i=0;i<n;i++)
        {
            l=min(l,1ll*v[i]);
            r=max(r,1ll*v[i]);
        }
        while(l<=r)
        {
            long long md1=l+(r-l)/3,md2=r-(r-l)/3,ans1=func(md1,v),ans2=func(md2,v);
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
        return ans;
    }
// https://leetcode.com/problems/reordered-power-of-2/submissions/
bool reorderedPowerOf2(int n) {
        vector<string>v(32);
        for(int i=0;i<32;i++)
        {
            long long x=pow(2,i);
            v[i]=to_string(x);
        }
        string s=to_string(n);
        vector<int>w(10);
        for(int i=0;i<s.size();i++)
            w[s[i]-'0']++;
        for(int i=0;i<32;i++)
        {
            vector<int>l(10);
            for(int j=0;j<v[i].size();j++)
                l[v[i][j]-'0']++;
            int flag=1;
            for(int j=0;j<10;j++)
                if(w[j]!=l[j])
                {
                    flag=0;
                    break;
                }
            if(flag)
                return true;
        }
        return false;
    }
// https://leetcode.com/problems/fraction-addition-and-subtraction/submissions/
string fractionAddition(string s) {
        string w=s;
        if(s[0]!='-')
            w="+"+s;
        vector<int>a,b;
        int z=1,i=0;
        cout<<w<<" ";
        while(i<w.size())
        {
            string p="";
            while(w[i]!='/')
            {
                p+=w[i];
                i++;
            }
            a.push_back(stoi(p));
            cout<<p<<" ";
            i++;
            p="";
            while(1)
            {
                if(i==w.size() or w[i]=='+' or w[i]=='-')
                    break;
                p+=w[i];
                i++;
            }
            cout<<p<<" ";
            b.push_back(stoi(p));
            z*=stoi(p);
            // i++;
        }
        for(auto it:a)
            cout<<it<<" ";
        for(auto it:b)
            cout<<it<<" ";
        cout<<z<<" ";
        int sum=0,sign=1;;
        for(int i=0;i<a.size();i++)
            sum+=a[i]*(z/b[i]);
        if(sum<0)
            sign=-1;
        sum=abs(sum);
        int g=__gcd(sum,z);
        while(g!=1)
        {
            sum/=g;
            z/=g;
            g=__gcd(sum,z);
        }
        sum*=sign;
        string ans=to_string(sum)+"/"+to_string(z);
        return ans;
    }

int merge(int l,int r,vector<int>&v)
    {
        if(l>=r)
            return 0;
        int md=(l+r)/2;
        int x=merge(l,md,v);
        int y=merge(md+1,r,v);
        int z=0,i=l,j=md+1;
        while(i<=md and j<=r)
        {
            if(v[i]<=v[j])
                i++;
            else
            {
                z+=md-i+1;
                j++;
            }
        }
        inplace_merge(v.begin()+l,v.begin()+md+1,v.begin()+r+1);
        return x+y+z;
    }
    bool isIdealPermutation(vector<int>& v) {
        int sum=0,n=v.size();
        for(int i=0;i<n-1;i++)
            if(v[i]>v[i+1])
                sum++;
        return sum==merge(0,n-1,v);
    }
// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/submissions/
vector<int> numOfBurgers(int a, int b) {
        if(a%2)
            return {};
        int z=a/2-b;
        int y=b-z;
        if(z<0 or y<0)
            return {};
        return {z,y};
    }
// https://leetcode.com/problems/rabbits-in-forest/submissions/
int numRabbits(vector<int>&v) {
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++)
            mp[v[i]]++;
        int ans=0;
        for(auto it:mp)
            while(it.second>0)
            {
                if(it.second<it.first+1)
                {
                    it.second=0;
                    ans+=it.first+1;
                }
                else
                {
                    ans+=it.first+1;
                    it.second=it.second-it.first-1;
                }
            }
        return ans;
    }
// https://lightoj.com/problem/making-huge-palindromes
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        string s;
        cin>>s;
    string w=s;
    reverse(w.begin(),w.end());
    string x=w+"&"+s;
    int n=x.size();
    vector<int>v(n,0);
    for(int i=1;i<n;i++)
    {
        int j=v[i-1];
        while(j>0 and x[i]!=x[j])
            j=v[j-1];
        if(x[i]==x[j])
            j++;
        v[i]=j;
    }
    cout<<"Case "<<k<<": "<<2*s.size()-v[n-1]<<"\n";
}
}
// https://codeforces.com/problemset/problem/1294/D
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int z = 4e5, q, x, n;
    set<int>s;

    for (int i = 0; i <= z; i++)
        s.insert(i);

    cin >> q >> x;

    while (q--) {
        cin >> n;
        int y = *s.begin();
        n -= ((n - y) / x) * x;

        if (n < y)
            n += x;

        int l = 0, r = (z - n) / x, ans = -1;

        while (l <= r) {
            int md = (l + r) / 2;

            if (s.find(n + md * x) != s.end()) {
                ans = n + md * x;
                r = md - 1;
            } else
                l = md + 1;
        }

        s.erase(ans);
        cout << *s.begin() << "\n";
    }
}
