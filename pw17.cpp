 // https://leetcode.com/problems/corporate-flight-bookings/submissions/************
vector<int> corpFlightBookings(vector<vector<int>>&w, int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<w.size();i++)
        {
            ans[w[i][0]-1]+=w[i][2];
            ans[w[i][1]]-=w[i][2];
        }
        for(int i=1;i<n;i++)
            ans[i]+=ans[i-1];
        ans.pop_back();
        return ans;
    }
// https://leetcode.com/problems/global-and-local-inversions/submissions/
 bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i]-i) > 1)
                return false;
        }
        return true;
    }
// https://leetcode.com/problems/excel-sheet-column-title/submissions/
string convertToTitle(int x) {
        string ans="";
        while(x>0)
        {
            int y=x%26;
            if(y==0)
                y=26;
            ans+=('A'+(y-1));
            x/=26;
            if(y==26)
                x--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
// https://cses.fi/problemset/result/3263224/
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int power(int x, int y) {
    int ans = 1;

    while (y > 0) {
        if (y & 1)
            ans = (ans * x) % mod;

        y /= 2;
        x = (x * x) % mod;
    }

    return ans % mod;
}
int modinverse(int x) {
    return power(x, mod - 2);
}
int ncr(int n, int r, vector<int>&fact) {
    return (fact[n] * ((modinverse(fact[n - r]) * modinverse(fact[r]) ) % mod));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    vector<int> fact(1e6 + 1, 1);

    for (int i = 2; i <= 1e6; i++)
        fact[i] = (i * fact[i - 1]) % mod;

    int n, a, b;
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << ncr(a, b, fact) % mod << "\n";
    }
}
// https://leetcode.com/problems/broken-calculator/solution/
int brokenCalc(int s, int t) {
        int ans=0;
        while(t>s)
        {
            if(t%2)
            {
                t++;
                ans+=2;
                t/=2;
            }
            else
            {
                ans++;
                t/=2;
            }
        }
        ans+=s-t;
        return ans;
    }
// https://cses.fi/problemset/task/1081
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int power(int x, int y) {
    int ans = 1;

    while (y > 0) {
        if (y & 1)
            ans = (ans * x) % mod;

        y /= 2;
        x = (x * x) % mod;
    }

    return ans % mod;
}
void solve(int i, int x, vector<pii>&dp, unordered_map<int, int>&mp) {
    if (i == 0) {
        mp[x]++;
        return;
    }

    for (int j = 0; j <= dp[i - 1].ss; j++)
        solve(i - 1, x * pow(dp[i - 1].ff, j), dp, mp);
}
void factor(int x, vector<int>&v, unordered_map<int, int>&mp) {
    vector<pii>dp;

    for (int i = 0; i < v.size(); i++) {
        if (x == 1)
            break;

        if (binary_search(v.begin(), v.end(), x)) {
            dp.push_back({x, 1});
            break;
        }

        if (x % v[i] == 0) {
            int cnt = 0;

            while ((x % v[i]) == 0) {
                cnt++;
                x /= v[i];
            }

            dp.push_back({v[i], cnt});
        }
    }

    solve(dp.size(), 1, dp, mp);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    vector<int> prime(1e6 + 1, 0);

    for (int i = 2; i <= 1e6; i++)
        if (prime[i] == 0)
            for (int j = i * i; j <= 1e6; j += i)
                prime[j] = 1;

    vector<int>v;

    for (int i = 2; i <= 1e6; i++)
        if (prime[i] == 0)
            v.push_back(i);

    // cout << v.size() << "\n";
    int n, x;
    cin >> n;
    unordered_map<int, int>mp;

    for (int i = 0; i < n; i++) {
        cin >> x;
        factor(x, v, mp);
    }

    int mx = 1;

    for (auto it : mp)
        if (it.ss > 1)
            mx = max(mx, it.ff);

    cout << mx << "\n";
}
// https://www.hackerrank.com/challenges/the-great-xor/problem?isFullScreen=false
long theGreatXor(long x) {
    string s="";
    while(x>0)
    {
        if(x&1)
            s+='1';
        else 
            s+='0';
        x/=2;
    }
    reverse(s.begin(),s.end());
    long  n=s.size(),ans=0;
    for(int i=0;i<n;i++)
        if(s[i]=='0')
            ans+=pow(2,n-i-1);
    return ans;
}
// https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/
 vector<int> xorQueries(vector<int>&v ,vector<vector<int>>& q) {
        int n=v.size();
        int dp[n+1][32];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<32;j++)
                if(v[i]&(1<<j))
                    dp[i+1][j]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<32;j++)
                dp[i][j]+=dp[i-1][j];
        vector<int>ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            int a=0;
            for(int j=0;j<32;j++)
                if((dp[q[i][1]+1][j]-dp[q[i][0]][j])%2)
                    a|=(1<<j);
            ans[i]=a;
        }
        return ans;
    }
// https://www.hackerrank.com/challenges/maximizing-xor/problem?isFullScreen=false
int maximizingXor(int l, int r) {
    int z=r;
    for(int i=0;i<13;i++)
    {
        int c=(1<<i),a=l&c,b=r&c;
        if(a&b and z-c>=l)
            z^=c;
        if(a==0 and b==0 and l+c<=r)
        l+=c;
    }
    return l^z;
}
// https://leetcode.com/problems/single-number-iii/submissions/
vector<int> singleNumber(vector<int>&v) {
        int c=0,n=v.size();
        for(int i=0;i<n;i++)
            c^=v[i];
        int a=0;
        for(int i=0;i<32;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
                if(v[j]&(1<<i))
                    sum++;
            if(sum%2)
            {
                for(int j=0;j<n;j++)
                if(v[j]&(1<<i))
                    a^=v[j];
                break;
            }    
        }
        return {a,c^a};
    }
// https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/
int rangeBitwiseAnd(int l, int r) {
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int x=(1<<i);
            if((r&x)>0 and (r^x)<l)
                ans|=x;
        }
        return ans&l;
    }
// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/submissions/
vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& c) {
        int n=c.size();
        vector<vector<int>>ans(2,vector<int>(c.size(),0));
        for(int i=0;i<n;i++)
            if(c[i]==2)
            {
                if(u==0 or l==0)
                    return {};
                u--;
                l--;
                ans[0][i]=1;
                ans[1][i]=1;
            }
        for(int i=0;i<n;i++)
        {
            if(c[i]==0)
                continue;
            else if(c[i]==1)
            {
                if(u>0)
                {
                    u--;
                    ans[0][i]=1;
                }
                else if(l>0)
                {
                    l--;
                    ans[1][i]=1;
                }
                else
                {
                    cout<<1<<" ";
                    return {};
                }    
            }
        }
        for(auto it:ans[0])
            cout<<it<<" ";
        for(auto it:ans[1])
            cout<<it<<" ";
        if(u==0 and l==0)
            return ans;
        return {};
    }
// https://leetcode.com/problems/smallest-range-ii/solution/
 int smallestRangeII(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans=v[n-1]-v[0];
        for(int i=0;i<n-1;i++)
        {
            int mx=max(v[i]+k,v[n-1]-k);
            int mn=min(v[i+1]-k,v[0]+k);
            ans=min(ans,mx-mn);
        }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1#
int maxSubarrayXOR(int arr[], int n)
    {
        set<int>s;
        for(int i=31;i>=0;i--)
        {
            int val=-1;
            for(int j=0;j<n;j++)
                if((arr[j]&(1<<i)) and s.find(j)==s.end())
                {
                    val=j;
                    s.insert(j);
                    break;
                }
            if(val!=-1)
                for(int j=0;j<n;j++)
                    if(j!=val and (arr[j]&(1<<i)))
                        arr[j]^=arr[val];
        }
        int ans=0;
        while(!s.empty())
        {
            ans^=arr[*s.begin()];
            s.erase(s.begin());
        }
        return ans;
    }
// https://www.interviewbit.com/problems/count-total-set-bits/
int Solution::solve(int A) {
    long long mod=1e9+7,ans=0;
    A++;
    for(int i=0;i<30;i++)
    {
        long long x=(1<<(i+1));
        // cout<<x<<" ";
        long long a=A/x,b=A%x;
        // cout<<a<<" "<<b<<" ";
        ans=(ans+a*(x/2))%mod;
        ans=(ans+max(1ll*0,b-x/2))%mod;
        // cout<<ans<<" ";
    }
    return ans%mod;
}
// https://codeforces.com/contest/1593/problem/D2
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
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());
        int ans = 1;

        for (int i = 0; i <= n / 2; i++) {
            int cnt = 0;
            unordered_map<int, int>mp;

            for (int j = i; j < n; j++) {
                if (v[i] == v[j])
                    cnt++;
                else {
                    int d = v[j] - v[i], s = sqrt(d);

                    for (int k = 1; k * k < d; k++)
                        if (d % k == 0) {
                            mp[k]++;
                            mp[d / k]++;
                        }

                    if (s * s == d)
                        mp[s]++;
                }
            }

            if (cnt >= n / 2)
                ans = INT_MAX;
            else
                for (auto it : mp)
                    if (it.second + cnt >= n / 2)
                        ans = max(ans, it.first);
        }

        if (ans == INT_MAX)
            ans = -1;

        cout << ans << "\n";
    }
}
// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/submissions/
 bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(auto it:deck)
            mp[it]++;
        int mx=(*mp.begin()).second;
        for(auto it:mp)
            mx=__gcd(mx,it.second);
        if(mx<2)
            return false;
        return true;
    }
// https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/
int maximumProduct(vector<int>&v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int a=v[0]*v[1]*v[n-1],b=v[n-1]*v[n-2]*v[n-3];
        return max(a,b);
    }
// https://leetcode.com/problems/prime-arrangements/submissions/
int numPrimeArrangements(int n) {
        vector<int>arr(n+1,0);
        for(int i=2;i<=n;i++)
            if(arr[i]==0)
                for(int j=i*i;j<=n;j+=i)
                    arr[j]=1;
        arr[1]=1;
        int sum=0,mod=1e9+7;
        for(int i=1;i<=n;i++)
            if(arr[i]==0)
                sum++;
        long long fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;i++)
            fact[i]=(fact[i-1]*i)%mod;
        return (fact[sum]*fact[n-sum])%mod;
    }
// https://leetcode.com/problems/largest-perimeter-triangle/submissions/
int largestPerimeter(vector<int>&v) {
        int n=v.size(),ans=0;
        sort(v.begin(),v.end());
        for(int i=n-1;i>=2;i--)
            if(v[i]<v[i-1]+v[i-2])
                return v[i]+v[i-1]+v[i-2];
        return ans;
    }
// https://leetcode.com/problems/complement-of-base-10-integer/submissions/
int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        cout<<log2(n)<<" ";
        int ans=0;
        for(int i=0;i<=log2(n);i++)
            if((n&(1<<i))==0)
                ans|=(1<<i);
        return ans;
    }
// https://leetcode.com/problems/factorial-trailing-zeroes/submissions/
int trailingZeroes(int n) {
        int a=0,b=0,i=2;
        while(i<=n)
        {
            a+=n/i;
            i*=2;
        }
        i=5;
        while(i<=n)
        {
            b+=n/i;
            i*=5;
        }
        return min(a,b);
    }
// https://codeforces.com/problemset/problem/805/B#
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
    string s = "bbaa";
    int c = n / 4;
    string ans = "";

    while (c--) {
        ans += s;
    }

    int d = n % 4;
    ans += s.substr(0, d);
    cout << ans << "\n";
}
// https://codeforces.com/problemset/problem/876/B
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
    int n, k, m, x;
    cin >> n >> k >> m;
    map<int, vector<int>>mp;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x % m].push_back(x);
    }

    vector<int>ans;

    for (auto it : mp)
        if (it.second.size() >= k) {
            ans = it.second;
            break;
        }

    if (!ans.empty()) {
        cout << "Yes" << "\n";

        for (int i = 0; i < k; i++)
            cout << ans[i] << " ";

        cout << "\n";
    } else
        cout << "No" << "\n";
}
// https://codeforces.com/problemset/problem/812/C
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define ff  first
#define ss  second
#define pii pair<int,int>
int mod = 1e9 + 7;
int func(int md, vector<int>&v) {
    vector<int>x;

    for (int i = 0; i < v.size(); i++)
        x.push_back(v[i] + (i + 1)*md);

    sort(x.begin(), x.end());
    int ans = 0;

    for (int i = 0; i < md; i++)
        ans += x[i];

    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);
#endif
    int n, s;
    cin >> n >> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int l = 0, r = n, a = 0, b = 0;

    while (l <= r) {
        int md = (l + r) / 2;
        int x = func(md, v);

        if (x <= s) {
            a = md;
            b = x;
            l = md + 1;
        } else
            r = md - 1;
    }

    cout << a << " " << b << "\n";
}
// https://codeforces.com/problemset/problem/1537/E2
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
    int n, k;
    string s, ans;
    cin >> n >> k >> s;

    if (k < n)
        s = s.substr(0, k);

    s += s;
    n = s.size();
    // cout << s << " ";
    vector<int> v(n, 0);

    for (int i = 1; i < n; i++) {
        int j = v[i - 1];

        while (j > 0 and s[i] != s[j])
            j = v[j - 1];

        if (s[i] == s[j])
            j++;

        v[i] = j;
    }

    for (int i = 1; i < n - 1; i++) {
        if (v[i] == 0 and s[v[i]] < s[i]) {
            ans = s.substr(0, i);
            break;
        } else if (v[i] > 0 and s[v[i]] < s[i + 1]) {
            ans = s.substr(0, i - v[i] + 1);
            break;
        }
    }

    // cout << ans << " ";

    if (ans.empty())
        ans = s;

    ans = ans.substr(0, k);
    string an = "";

    for (int i = 0; i < k / ans.size(); i++)
        an += ans;

    an += ans.substr(0, k % ans.size());
    cout << an << "\n";
}
