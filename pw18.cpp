// https://leetcode.com/problems/surface-area-of-3d-shapes/submissions/
int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>v(n+2,vector<int>(n+2,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                v[i+1][j+1]=grid[i][j];
        int ans=0;
        vector<int>x={1,-1,0,0};
        vector<int>y={0,0,1,-1};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(v[i][j]>0)
                    ans+=2;
                for(int k=0;k<4;k++)
                    ans+=max(0,v[i][j]-v[i+x[k]][j+y[k]]);
            }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1#
 long long power(int x,int y)
    {
        long long temp;
        if( y == 0)
            return 1;
        temp = power(x, y / 2);
        if (y % 2 == 0)
            return (temp * temp)%mod;
        else
            return (x *((temp * temp)%mod))%mod;
    }
// https://leetcode.com/problems/ugly-number-iii/   
long long fxn(long long a, long long b, long long c, long long mid)
    {
        return ((mid/a)+(mid/b)+(mid/c)-(mid/ab)-(mid/bc)-(mid/ca)+(mid/abc));
    }
    
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        if(a==b && a==c) return a*n;

        long long s=1, e=2000000001,mid;
        long long m;
        long long ans;
        ab=__gcd(a,b), bc=__gcd(b,c), ca=__gcd(a,c);
        
        ab = (a*b)/ab;
        bc = (b*c)/bc;
        ca = (c*a)/ca;
        
        abc=__gcd(ab,c);
        abc = (ab*c)/abc;
        
        while(s<=e)
        {
            mid= s+(e-s)/2;
            m=fxn(a,b,c,mid);
            if(m==n)
            {
                ans=mid;
                e=mid-1;
            }
            else if(m>n)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
// https://leetcode.com/problems/nth-magical-number/submissions/
int nthMagicalNumber(int n, int a, int b) {
        long long l=1,r=1e18,ans=0,mod=1e9+7;
        int lcm=(a*b)/__gcd(a,b);
        while(l<=r)
        {
            long long md=(l+r)/2;
            long long cnt=md/a +md/b -md/lcm;
            if(cnt>=n)
            {
                ans=md;
                r=md-1;
            }
            else
                l=md+1;
        }
        return ans%mod;
    }
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
vector<string> func(int x,string &s)
        {
            if(x==s.size()-1)
                return {s.substr(x)};
            vector<string>z=func(x+1,s);
            vector<string>ans;
            for(int i=0;i<z.size();i++)
            {
                for(int j=1;j<z[i].size();j++)
                    ans.push_back(z[i].substr(0,j)+s[x]+z[i].substr(j));
                ans.push_back(s[x]+z[i]);
                ans.push_back(z[i]+s[x]);
            }
            return ans;
        }
vector<string>find_permutation(string S)
{
    sort(S.begin(),S.end());
    vector<string>ans=func(0,S);
    // sort(ans.begin(),ans.end());
    return ans;
}
// https://leetcode.com/problems/lexicographical-numbers/submissions/
void rec(int n, int s,vector<int>&v){
        if(s>n) return;
        v.push_back(s);
        rec(n, s*10,v);
        if((s+1)%10) rec(n, s+1,v);
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        rec(n,1,v);
        return v;
    }
// https://leetcode.com/problems/three-equal-parts/submissions/
bool compare(string a,string b)
    {
        int n=b.size();
        int i=0,j=0;
        while(j<n)
        {
            if(a[i]!=b[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
    vector<int> threeEqualParts(vector<int>&v) {
        int n=v.size(),sum=0,cnt=0;
        for(int i=0;i<n;i++)
            sum+=v[i];
        if((sum%3)!=0)
            return {-1,-1};
        if(sum==0)
            return {0,n-1};
        string a="",b="",c="";
        int id;
        for(int i=0;i<n;i++)
        {
            cnt+=v[i];
            if(cnt<=sum/3)
                a+=(v[i]+'0');
            else if(3*cnt<=2*sum)
                b+=(v[i]+'0');
            else
                c+=(v[i]+'0');
        }
        cout<<a<<" "<<b<<" "<<c<<"\n";
        int x=c.size(),y=a.size(),p=0;
        for(int i=0;i<a.size();i++)
        {
         if(a[i]=='1')
            {
                a=a.substr(i);
                break;
            }
        else
            p++;
        }    
        if(compare(a,c) and compare(b,c))
            return {p+x-1,y+x};
        return {-1,-1};
    }
// https://leetcode.com/problems/sum-of-subsequence-widths/submissions/
 int sumSubseqWidths(vector<int>&v) {
        int n=v.size(),mod=1e9+7,ans=0;
        sort(v.begin(),v.end());
        vector<long long>w(n+1,1);
        for(int i=1;i<=n;i++)
            w[i]=(w[i-1]*2)%mod;
        for(int i=0;i<n;i++)
        {
            cout<<ans<<" ";
            ans=(ans+v[i]*(w[i]-w[n-i-1]))%mod;
        }    
        return ans;
    }
// https://codeforces.com/contest/1616/problem/B
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        int i;

        for (i = 1; i < n; i++)
            if (s[i] > s[i - 1])
                break;

        string w = s.substr(0, i);
        string ans = w;
        reverse(w.begin(), w.end());
        ans += w;
        string l = "";
        l += s[0];
        l += s[0];
        ans = min(ans, l);
        cout << ans << "\n";
    }
}
// https://leetcode.com/problems/combinations/
void func(int i,int j,vector<int>&visited,vector<vector<int>>&ans)
    {
        if(i==0)
        {
            vector<int>v;
            for(int i=1;i<visited.size();i++)
                if(visited[i])
                    v.push_back(i);
            ans.push_back(v);
        }
        for(int k=j;k<visited.size();k++)
        {
            visited[k]=1;
            func(i-1,k+1,visited,ans);
            visited[k]=0;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>visited(n+1,0);
        vector<vector<int>>ans;
        func(k,1,visited,ans);
        return ans;
    }
// https://leetcode.com/problems/subsets/submissions/
void func(int i,vector<int>&v,vector<int>&w,vector<vector<int>>&ans)
    {
        if(i==v.size())
        {
            ans.push_back(w);
            return;
        }
        w.push_back(v[i]);
        func(i+1,v,w,ans);
        w.pop_back();
        func(i+1,v,w,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>&v) {
        vector<int>w;
        vector<vector<int>>ans;
        func(0,v,w,ans);
        return ans;
    }
// https://leetcode.com/problems/letter-case-permutation/submissions/
void recur(int i,string &w,string &s,vector<string>&ans)
    {
        if(i==s.size())
        {
            ans.push_back(w);
            return;
        }
        w.push_back(s[i]);
        recur(i+1,w,s,ans);
        w.pop_back();
        if(s[i]>='a' and s[i]<='z')
        {
            w.push_back(s[i]-32);
            recur(i+1,w,s,ans);
            w.pop_back();
        }
        else if(s[i]>='A' and s[i]<='Z')
        {
            w.push_back(s[i]+32);
            recur(i+1,w,s,ans);
            w.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string w="";
        recur(0,w,s,ans);
        return ans;
    }
// https://leetcode.com/problems/path-with-maximum-gold/
vector<int>x={1,-1,0,0};
    vector<int>y={0,0,1,-1};
    int recur(int i,int j,vector<vector<int>>&v,vector<vector<int>>&vis)
    {
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size() or vis[i][j]==1 or  v[i][j]==0)
            return 0;
        int mx=0;
        vis[i][j]=1;
        for(int k=0;k<4;k++)
            mx=max(mx,v[i][j]+recur(i+x[k],j+y[k],v,vis));
        vis[i][j]=0;
        return mx;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),mx=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    mx=max(mx,recur(i,j,grid,vis));
        return mx;
    }
// https://leetcode.com/problems/n-queens/submissions/
bool safe(vector<string>&v,int i,int j)
    {
        for(int k=0;k<i;k++)
            if(v[k][j]=='Q')
                return false;
        int x=i-1,y=j-1;
        while(x>=0 and y>=0)
        {
            if(v[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        x=i-1;
        y=j+1;
        while(x>=0 and y<v.size())
        {
            if(v[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        return true;
    }
    void recur(int i,int &n,vector<string>&v,vector<vector<string>>&ans)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++)
        {
            v[i][j]='Q';
            if(safe(v,i,j))
                recur(i+1,n,v,ans);
            v[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n);
        string s="";
        for(int i=0;i<n;i++)
            s+='.';
        for(int i=0;i<n;i++)
            v[i]=s;
        vector<vector<string>>ans;
        recur(0,n,v,ans);
        cout<<ans.size()<<"\n";
        return ans;
    }
// https://codeforces.com/problemset/problem/1335/E2
#include"bits/stdc++.h"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    map<int,vector<int>>mp;
    vector<vector<int>>dp(2e5+1,vector<int>(201,0));
    while(t--)
    {
        mp.clear();
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            mp[v[i]].push_back(i+1);
            dp[i+1][v[i]]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=200;j++)
                dp[i][j]+=dp[i-1][j];
        int ans=1,l=0,r=0,mx=0;
        for(auto it:mp)
        {
            l=0;
            r=it.second.size()-1;
            while(l<r)
            {
                mx=0;
                for(int i=1;i<=200;i++)
                    mx=max(mx,dp[(it.second[r])-1][i]-dp[(it.second[l])][i]);
                ans=max(ans,mx+2*(l+1));
                l++;
                r--;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
            for(int j=1;j<=200;j++)
                dp[i][j]=0;
    }
}
// https://codeforces.com/problemset/problem/1213/D2
#include"bits/stdc++.h"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            mp[v[i]].push_back(0);
            while(v[i]>0)
            {
                v[i]/=2;
                cnt++;
                mp[v[i]].push_back(cnt);
            }
        }
        int ans=INT_MAX;
        for(auto it:mp)
            if(it.second.size()>=k)
            {
                int sum=0;
                sort(it.second.begin(),it.second.end());
                for(int i=0;i<k;i++)
                    sum+=it.second[i];
                ans=min(ans,sum);
            }
        cout<<ans<<"\n";
}
// https://leetcode.com/problems/palindrome-partitioning/submissions/
bool ispalindrome(int l,int r,string &s)
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
    vector<vector<string>> func(string s)
    {
        vector<vector<string>>ans;
        for(int i=0;i<s.size();i++)
            if(ispalindrome(0,i,s))
            {
                vector<vector<string>>w=func(s.substr(i+1));
                if(!w.empty())
                for(int j=0;j<w.size();j++)
                {
                    w[j].push_back(s.substr(0,i+1));
                    ans.push_back(w[j]);
                }   
                else
                    ans.push_back({s.substr(0,i+1)});
            }
        return ans;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans=func(s);
        for(int i=0;i<ans.size();i++)
            reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
// https://leetcode.com/problems/combination-sum-iii/submissions/
void recur(int i,int k,vector<int>&v,vector<vector<int>>&ans,int &u)
    {
        if(k==0)
        {
            vector<int>w;
            for(int j=1;j<10;j++)
                if(v[j]==1)
                    w.push_back(j);
            if(w.size()==u)
            ans.push_back(w);
            return;
        }
        if(i==0)
            return;
        if(k-i>=0)
        {
            v[i]=1;
            recur(i-1,k-i,v,ans,u);
            v[i]=0;
        }
        recur(i-1,k,v,ans,u);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v(10,0);
        recur(9,n,v,ans,k);
        return ans;
    }
// https://leetcode.com/problems/combination-sum-ii/
void sets(int i, int sum, vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans)
    {
        if(i==candidates.size())
        {
            if(sum==target)
            {
                ans.push_back(v);
            }
            return;
        }
        if(candidates[i]+sum <= target)
        {
            v.push_back(candidates[i]);
            sets(i,sum+candidates[i],candidates,target,v,ans);
            v.pop_back();
        }
        sets(i+1,sum,candidates,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sets(0,0,candidates,target,v,ans);
        return ans;
    }
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
    void recur(int i,string &w,string &s,vector<string>&ans,vector<vector<char>>&v)
    {
        if(i==s.size())
        {
            ans.push_back(w);
            return;
        }
        for(int j=0;j<v[s[i]-'0'].size();j++)
        {
            w.push_back(v[s[i]-'0'][j]);
            recur(i+1,w,s,ans,v);
            w.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<vector<char>>v(10);
        v[2]={'a','b','c'};
        v[3]={'d','e','f'};
        v[4]={'g','h','i'};
        v[5]={'j','k','l'};
        v[6]={'m','n','o'};
        v[7]={'p','q','r','s'};
        v[8]={'t','u','v'};
        v[9]={'w','x','y','z'};
        vector<string>ans;
        string w="";
        recur(0,w,digits,ans,v);
        return ans;
    }
// https://leetcode.com/problems/subsets-ii/submissions/
void recur(int i,vector<int>&v,vector<int>w,set<vector<int>>&s)
    {
        if(i==v.size())
        {
            sort(w.begin(),w.end());
            s.insert(w);
            return;
        }
        recur(i+1,v,w,s);
        w.push_back(v[i]);
        recur(i+1,v,w,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>&v) {
        set<vector<int>>s;
        vector<int>w;
        recur(0,v,w,s);
        vector<vector<int>>ans;
        while(!s.empty())
        {
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
        return ans;
    }
// https://leetcode.com/problems/sudoku-solver/submissions/
bool valid(int i,int j,char val,vector<vector<char>>& board)
    {
        for(int k=0;k<9;k++)
            if(board[i][k]==val)
                return false;
        for(int k=0;k<9;k++)
            if(board[k][j]==val)
                return false;
        int x=i/3,y=j/3;
        for(int k=0;k<3;k++)
            for(int l=0;l<3;l++)
                if(board[x*3 + k][y*3 +l]==val)
                    return false;
        return true;
    }
    bool recur(int i,int j,vector<vector<char>>&v)
    {
        if(i==9)
            return true;
        if(j==9)
            return recur(i+1,0,v);
        if(v[i][j]!='.')
            return recur(i,j+1,v);
        for(int k=1;k<10;k++)
            if(valid(i,j,'0'+k,v))
            {
                v[i][j]='0'+k;
                bool z=recur(i,j+1,v);
                if(z)
                    return true;
                v[i][j]='.';
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>&v) {
        bool ans=recur(0,0,v);
    }
// https://leetcode.com/problems/generate-parentheses/submissions/
void recur(int i,int j,int &n,string &w,vector<string>&ans)
    {
        if(i==0 and j==0)
        {
            if(!w.empty())
            ans.push_back(w);
            return;
        }
        if(i>0)
        {
            w.push_back('(');
            recur(i-1,j,n,w,ans);
            w.pop_back();
        }
        if(j>0 and n-i>=n-j+1)
        {
            w.push_back(')');
            recur(i,j-1,n,w,ans);
            w.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string w="";
        vector<string>ans;
        recur(n,n,n,w,ans);
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1# ********
int safePos(int n, int k) {
        if(n==1)
            return 1;
        return (safePos(n-1,k)+k-1)%n +1;
    }
// https://leetcode.com/problems/verbal-arithmetic-puzzle/submissions/
class Solution {
public:
    bool recur(int i,int &sum,vector<char>&cha,vector<int>&v,map<char,int>&mp2,set<char>&ko)
    {
        if(i==cha.size())
            return sum==0;  
        for(int j=0;j<10;j++)
        {
            if(j==0 and v[j]==0 and ko.find(cha[i])!=ko.end())
                continue;
            if(v[j]==0)
            {
                v[j]=1;
                sum+=mp2[cha[i]]*j;
                bool ll=recur(i+1,sum,cha,v,mp2,ko);
                if(ll)
                    return true;
                v[j]=0;
                sum-=mp2[cha[i]]*j;
            }
        }   
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        map<char,int>mp2;
        for(int i=0;i<words.size();i++)
            for(int j=0;j<words[i].size();j++)
                mp2[words[i][j]]+=pow(10,words[i].size()-1-j);  
        for(int i=0;i<result.size();i++)
            mp2[result[i]]-=pow(10,result.size()-1-i); 
        set<char>s;
        for(int i=0;i<words.size();i++)
            // if(words[i].size()>1)
                s.insert(words[i][0]);
        // if(s.size()>1)
            s.insert(result[0]);
        vector<char>cha;
        for(auto it:mp2)
            cha.push_back(it.first);
        vector<int>v(10,0);
        int sum=0;
        return recur(0,sum,cha,v,mp2,s);
    }
};
// https://leetcode.com/problems/sequential-digits/submissions/
vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        for(int i=1;i<10;i++)
        {
            string x="";
            for(int j=i;j<10;j++)
            {
                x+=(j+'0');
                int z=stoi(x);
                v.push_back(z);
            }
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        int l=lower_bound(v.begin(),v.end(),low)-v.begin();
        int r=upper_bound(v.begin(),v.end(),high)-v.begin();
        for(int i=l;i<r;i++)
            ans.push_back(v[i]);
        return ans;
    }
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/
int recur(int i,vector<string>&v,vector<int>&vis)
    {
        if(i==v.size())
        {
            int cnt=0;
            for(int j=0;j<26;j++)
                if(vis[j])
                    cnt++;
            return cnt;
        }
        int mx=recur(i+1,v,vis);
        int flag=1;
        for(int j=0;j<v[i].size();j++)
            if(vis[v[i][j]-'a'])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            for(int j=0;j<v[i].size();j++)
                vis[v[i][j]-'a']++;
            mx=max(mx,recur(i+1,v,vis));
            for(int j=0;j<v[i].size();j++)
                vis[v[i][j]-'a']--;
        }
        return mx;
    }
    int maxLength(vector<string>&v) {
        vector<string>w;
        for(int i=0;i<v.size();i++)
        {
            int flag=1;
            unordered_map<char,int>mp;
            for(int j=0;j<v[i].size();j++)
            {
                mp[v[i][j]]++;
                if(mp[v[i][j]]>1)
                {
                    flag=0;
                    break;
                }
            }    
            if(flag)
                w.push_back(v[i]);
        }
        vector<int>vis(26,0);
        return recur(0,w,vis);
    }
// https://leetcode.com/problems/gray-code/submissions/
bool recur(int x,int cnt,int &n,vector<int>&w,vector<int>&visited)
    {
        if(w.size()==visited.size())
            return true;
        if(cnt==n)
            return false;
        for(int j=n-1;j>=0;j--)
        {
            int y= x xor (1<<j);
            if(visited[y]==0)
            {
                visited[y]=1;
                w.push_back(y);
                int z=__builtin_popcount(y);
                bool ans;
                if(z==1)
                    ans=recur(y,cnt+1,n,w,visited);
                else
                    ans=recur(y,cnt,n,w,visited);
                if(ans)
                    return true;
                w.pop_back();
                visited[y]=0;
            }
        }
        return false;
    }
    vector<int> grayCode(int n) {
        vector<int>visited((1<<n),0);
        visited[0]=1;
        vector<int>w;
        w.push_back(0);
        bool z=recur(0,0,n,w,visited);
        return w;
    }
// https://codeforces.com/contest/1623/problem/C
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
bool valid(int x, vector<int>v, vector<int>&w) {
    int n = v.size();

    for (int i = n - 1; i >= 2; i--) {
        int mx = max(1ll * 0, v[i] - x);
        mx = min(mx, w[i]) / 3;
        v[i - 1] += mx;
        v[i - 2] += 2 * mx;
    }

    for (int i = 0; i < n; i++)
        if (v[i] < x)
            return false;

    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> v(n);
        int l = INT_MAX, r = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            l = min(l, v[i]);
            r = max(r, v[i]);
        }

        int ans = l;

        while (l <= r) {
            int md = (l + r) / 2;

            if (valid(md, v, v)) {
                ans = md;
                l = md + 1;
            } else
                r = md - 1;
        }

        cout << ans << "\n";
    }
}
// https://codeforces.com/contest/1096/problem/D
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int recur(int id,int mask,vector<int>&v,string &s,vector<vector<int>>&dp)
{
    if(id==v.size())
        return 0;
    if(dp[id][mask]!=-1)
        return dp[id][mask];
    if(s[id]!='a' and s[id]!='h' and s[id]!='r' and s[id]!='d')
        return dp[id][mask]=recur(id+1,mask,v,s,dp);
    if(s[id]=='h')
    {
        if(mask&(1<<3))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        return dp[id][mask]=min(v[id]+recur(id+1,mask,v,s,dp),recur(id+1,(1<<3),v,s,dp));
    }
    if(s[id]=='a')
    {
        if(mask&(1<<2))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<3)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        return dp[id][mask]=min(v[id]+recur(id+1,mask,v,s,dp),recur(id+1,(1<<3)|(1<<2),v,s,dp));
    }
    if(s[id]=='r')
    {
        if(mask&(1<<1))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<3)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<2)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        return dp[id][mask]=min(v[id]+recur(id+1,mask,v,s,dp),recur(id+1,(1<<3)|(1<<2)|(1<<1),v,s,dp));
    }
    if(s[id]=='d')
    {
        if(mask&(1<<0))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<3)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<2)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        if(!(mask&(1<<1)))
            return dp[id][mask]=recur(id+1,mask,v,s,dp);
        return dp[id][mask]=v[id]+recur(id+1,mask,v,s,dp);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>>dp(n+1,vector<int>((1<<4),-1));
    cout<<recur(0,0,v,s,dp)<<"\n";
}
// https://leetcode.com/problems/count-binary-substrings/submissions/
    int countBinarySubstrings(string s) {
        vector<int>v(2,0);
        int ans=0,change=0;
        v[s[0]-'0']++;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
                v[s[i]-'0']++;
            else if(change==0)
            {
                change=1;
                v[s[i]-'0']++;
            }
            else if(change==1)
            {
                ans+=min(v[0],v[1]);
                change=1;
                v[s[i]-'0']=1;
            }
        }
        ans+=min(v[0],v[1]);
        return ans;
    }
// https://codeforces.com/problemset/problem/1355/D
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    if((s/n)>1)
    {
        cout<<"YES"<<"\n";
        int z=s/n;
        vector<int>v(n,z);
        v[n-1]+=s-z*n;
        for(int i=0;i<n;i++)
            cout<<v[i]<<"\n";
        cout<<"\n"<<1<<"\n";
    }
    else
        cout<<"NO"<<"\n";
}
// https://codeforces.com/problemset/problem/798/C
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int x = v[0];

    for (int i = 1; i < n; i++)
        x = __gcd(x, v[i]);

    cout << "YES" << "\n";

    if (x > 1)
        cout << 0 << "\n";
    else {
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
            if (v[i] % 2) {
                if (v[i + 1] % 2 == 0) {
                    ans += 2;
                    i++;
                } else {
                    ans++;
                    v[i + 1] = 2;
                }
            }

        if (v[n - 1] % 2)
            ans += 2;

        cout << ans << "\n";
    }
}
// https://www.codechef.com/submit/MEANIDIAN
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int valid(int md,vector<int>v,int sum,int id)
{
    int n=v.size();
    for(int i=id;i<n;i++)
        if(v[i]<md)
            sum+=md-v[i];
    if(sum>md*n)
        return -1;
    sum+=md*n-sum;
    return sum;
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
        int sum=0;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        int id=n/2;
        if(n%2 ==0)
            id--;
        int l=v[id],r=1e9,ans=0;
        while(l<=r)
        {
            int md=(l+r)/2;
            int x=valid(md,v,sum,id);
            if(x!=-1)
            {
                ans=x-sum;
                r=md-1;
            }
            else
                l=md+1;
        }
        cout<<ans<<"\n";
    }
}
// https://www.codechef.com/submit/SOS
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
void recur(int i,string &s,vector<vector<int>>&graph,vector<int>&visited,int &cnt)
{
    if(s[i]=='B')
        cnt++;
    visited[i]=1;
    for(int j=0;j<graph[i].size();j++)
        if(!visited[graph[i][j]])
            recur(graph[i][j],s,graph,visited,cnt);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        vector<vector<int>>graph(n);
        for(int i=0;i<n-1;i++)
        {
            cin>>x>>y;
            if((s[x-1]=='G' and s[y-1]=='R') or (s[x-1]=='R' and s[y-1]=='G'))
                continue;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
        }
        vector<int>visited(n,0);
        int flag=1;
        for(int i=0;i<n;i++)
            if(flag==1 and !visited[i])
            {
                int cnt=0;
                recur(i,s,graph,visited,cnt);
                if(cnt>1)
                {
                    flag=0;
                    break;
                }
            }
        if(flag)
            cout<<"YES"<<"\n";
        else    
            cout<<"NO"<<"\n";
    }
}
// https://leetcode.com/problems/closest-subsequence-sum/submissions/
class Solution {
public:
    void recur(long long sum,long long id,int &i,vector<long long>&v,vector<int>& nums)
    {
        if(id==i)
        {
            v.push_back(sum);
            return;
        }
        recur(sum+nums[id],id+1,i,v,nums);
        recur(sum,id+1,i,v,nums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<long long>v,w;
        int n=nums.size(),z=n/2;
        recur(0,0,z,v,nums);
        recur(0,n/2,n,w,nums);
        sort(w.begin(),w.end());
        sort(v.begin(),v.end());
        long long ans=1e17;
        for(int i=0;i<v.size();i++)
        {
            ans=min(ans,abs(goal-v[i]));
            int it=upper_bound(w.begin(),w.end(),goal-v[i])-w.begin();
            if(it<w.size())
                ans=min(ans,abs(goal-v[i]-w[it]));
            if(it>0)
                ans=min(ans,abs(goal-v[i]-w[it-1]));
        }
        for(int i=0;i<w.size();i++)
        {
            ans=min(ans,abs(goal-w[i]));
            int it=upper_bound(v.begin(),v.end(),goal-w[i])-v.begin();
            if(it<v.size())
                ans=min(ans,abs(goal-w[i]-v[it])); 
            if(it>0)
                ans=min(ans,abs(goal-w[i]-v[it-1]));
        }
        return ans;
    }
};
// https://www.codechef.com/COOK137B/problems/MERGEDLIS
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int lis(vector<int>&v)
{
    int n=v.size();
    vector<int>d;
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(d.begin(),d.end(),v[i]);
        if(it==d.end())
            d.push_back(v[i]);
        else
            *it=v[i];
    }
    return d.size();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int>v(n),w(m);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<m;i++)
            cin>>w[i];
        cout<<lis(v)+lis(w)<<"\n";
    }
}
