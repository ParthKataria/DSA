// Coin Change Problem
// O(m*n),O(n)
long long int count( int S[], int m, int n )
{
	long long int table[n + 1] = {0};
	table[0] = 1;
	for (int i = 0; i < m; i++)
		for (int j = S[i]; j <= n; j++)
			table[j] += table[j - S[i]];
	return table[n];
}
// O(M*n),O(m*n)
for (int i = 1; i <= n; i++)
	for (int j = 0; j < m; j++)
		dp[i][j] = dp[i - S[j]][j - 1] + dp[i][j - 1];
return dp[i][m - 1];

// Knapsack 0-1 Bottom-Up Table
int knapSack(int W, int wt[], int val[], int n)
{
	vector<vector<int>>dp(n + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= W; j++)
		{
			if (j - wt[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	return dp[n][W];
}

// nCr by dp
//  nCr % p = (fac[n]* modIverse(fac[r]) % p *
//  modIverse(fac[n-r]) % p) % p;
//  nCr=n-1Cr-1+n-1Cr   nCr==1 if(r=0 or r=n)
int nCr(int n, int r) {
	vector<vector<int>>dp(n + 1, vector<int>(r + 1, 0));
	int mod = 1e9 + 7;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= r; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	return dp[n][r];
}
// nth Catalan Number
// Cn=sigma (Ci*Cn-i-1) for i=[0,n-1]
int ncatalan(int n)
{
	if(n<=0)
		return 1;
	int sum=0;
	for(i=0;i<n;i++)
		sum+=ncatalan(i)*ncatalan(n-1-i);
	return sum;
}
// Matrix Chain Multiplication
// i=1 to j=n-1
int matrixChainMemoised(vector<int>&p, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k)+ matrixChainMemoised(p, k + 1, j)+ p[i - 1] * p[k] * p[j]);
    return dp[i][j];
}
// Edit Distance
int recur(int n,int m,string A,string B,vector<vector<int>>&dp)
{
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(n==0 and m==0)
        return dp[n][m]=0;
    if(n==0 and m>0)
        return dp[n][m]=1+recur(n,m-1,A,B,dp);
    if(m==0 and n>0)
        return dp[n][m]=1+recur(n-1,m,A,B,dp);
    if(A[n-1]==B[m-1])
        return dp[n][m]=recur(n-1,m-1,A,B,dp);
    return dp[n][m]=min(1+recur(n-1,m-1,A,B,dp),min(1+recur(n-1,m,A,B,dp),1+recur(n,m-1,A,B,dp)));
}
// Equal Sum Partition
int recur(int i,int j,int arr[],vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0)
            return dp[i][j]=1;
        if(i==0)
            return dp[i][j]=0;
        if(j-arr[i-1]>=0)
            return dp[i][j]=recur(i-1,j,arr,dp) or recur(i-1,j-arr[i-1],arr,dp);
        return dp[i][j]=recur(i-1,j,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2==1)
            return 0;
        vector<vector<int>>dp(N+1,vector<int>(sum/2 +1,-1));
        return recur(N,sum/2,arr,dp);
    }
// Friends Pairing Problem
int countFriendsPairings(int n) 
    { 
        // if(n<=2)
        //     return n;
        // return countFriendsPairings(n-1)+(n-1)*countFriendsPairings(n-2);
        int mod=1e9+7;
        vector<long long>dp(n+1);
        for(int i=0;i<=2;i++)
            dp[i]=i;
        for(int i=3;i<=n;i++)
            dp[i]=(dp[i-1]+((i-1)*dp[i-2])%mod)%mod;
        return dp[n];
    }
// Painting fence with k colors
// Nice one
long long recur(int n,int &k,vector<long long>&dp)
    {
        int mod=1e9+7;
        if(dp[n]!=-1)
            return dp[n];
        if(n==1)
            return dp[n]=k%mod;
        if(n==2)
            return dp[n]=(k*k)%mod;
        return dp[n]=((k-1)*(recur(n-1,k,dp)+recur(n-2,k,dp)))%mod;
    }
    long long countWays(int n, int k){
        vector<long long>dp(n+1,-1);
        return recur(n,k,dp);
    }
// Maximise Cuts --Problem in Memoization 
int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++)
            if(dp[i]!=-1)
            {
                if(i+x<=n)
                    dp[i+x]=max(dp[i+x],dp[i]+1);
                if(i+y<=n)
                    dp[i+y]=max(dp[i+y],dp[i]+1);
                if(i+z<=n)
                    dp[i+z]=max(dp[i+z],dp[i]+1);
            }
        if(dp[n]!=-1)
        return dp[n];
        return 0;
    }
// LCS
int recur(int n,int m,string A,string B,vector<vector<int>>&dp)
{
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(n==0 || m==0)
        return dp[n][m]=0;
    if(A[n-1]==B[m-1])
        return dp[n][m]=1+recur(n-1,m-1,A,B,dp);
    return dp[n][m]=max(recur(n-1,m,A,B,dp),recur(n,m-1,A,B,dp));
}
// ####Space Optimised LCS
int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
    int L[2][n + 1];
    bool bi;
    for (int i = 0; i <= m; i++)
    {
        bi = i & 1;
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
            else if (X[i-1] == Y[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1;
            else
                L[bi][j] = max(L[1 - bi][j],L[bi][j - 1]);
        }
    }
    return L[bi][n];
}
// Longest Repeating Subsequence in a string
int recur(int n,int m,string &a,string &b,vector<vector<int>>&dp)
    {
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(n==0 or m==0)
            return dp[n][m]=0;
       if(n==m)
            return dp[n][m]=max(recur(n-1,m,a,b,dp),recur(n,m-1,a,b,dp));
       if(a[n-1]==b[m-1])
            return dp[n][m]=1+recur(n-1,m-1,a,b,dp);
       return dp[n][m]=max(recur(n-1,m,a,b,dp),recur(n,m-1,a,b,dp));
    }
        int LongestRepeatingSubsequence(string str){
            int n=str.size();
            vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            return recur(n,n,str,str,dp);
        }
// Longest Increasing Subsequence
int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}
// Uisng LCS create new vector of unique elements sort it and find LCS of original vector and new vector
// LCS of three strings
int recur(int a,int b,int c,string &A,string &B,string &C,vector<vector<vector<int>>>&dp)
{
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    if(a==0 or b==0 or c==0)
        return dp[a][b][c]=0;
    if(A[a-1]==B[b-1] and B[b-1]==C[c-1])
        return dp[a][b][c]=1+recur(a-1,b-1,c-1,A,B,C,dp);
    return dp[a][b][c]=max(recur(a-1,b,c,A,B,C,dp),max(recur(a,b-1,c,A,B,C,dp),recur(a,b,c-1,A,B,C,dp)));
}
// Variation of LIS--Maximum Sum Increasing SUbsequence
int maxSumIS(int arr[], int n)  
    {  
        vector<int>dp(n);
        for(int i=0;i<n;i++)
            dp[i]=arr[i];
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(arr[i]>arr[j] and dp[i]<dp[j]+arr[i])
                    dp[i]=dp[j]+arr[i];
       return *max_element(dp.begin(),dp.end());
    }  
// Count all subsequences having product less than K
int recur(int i,int j,int &k,vector<int>&v)
{
    if(i==0)
        return 1;
    if(j*v[i-1]<k)
        return recur(i-1,j*v[i-1],k,v)+recur(i-1,j,k,v);
    return recur(i-1,j,k,v);
}
// LIS variation - Longest subsequence such that difference between adjacent is one
 int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N,1);
        for(int i=N-2;i>=0;i--)
            for(int j=i+1;j<N;j++)
                if(abs(A[j]-A[i])==1)
                    dp[i]=max(dp[i],dp[j]+1);
        return *max_element(dp.begin(),dp.end());
    }
// No three consecutive
int recur(int n,vector<int>&v)
{
    if(n==0)
        return 0;
    if(n==1)
        return v[n-1];
    return max(max(v[n-1]+v[n-2]+recur(n-3,v),v[n-1]+recur(n-2,v)),recur(n-1,v));
}
// *****EGG Droping Problem
int recur(int n,int k,vector<vector<int>>&dp)
    {
        if(dp[n][k]!=-1)
            return dp[n][k];
        if(k<=1)
            return dp[n][k]=k;
        if(n==1)
            return dp[n][k]=k;
        int mx=INT_MAX;
        for(int i=1;i<=k;i++)
            mx=min(mx,(max(recur(n-1,i-1,dp),recur(n,k-i,dp))));
        return dp[n][k]=mx+1;
    }
// LIS Variation --Flipkart Q-3 Same
bool compare(struct val a,struct val b)
{
    if(a.first<b.first)
        return true;
    if(a.first==b.first and a.first<b.first)
        return true;
    return false;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compare);
    vector<int>dp(n,1);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(p[i].first>p[j].second and dp[i]<dp[j]+1)
                dp[i]=max(dp[i],dp[j]+1);
    return *max_element(dp.begin(),dp.end());
}
// **************Pair sum - Selection only depends on the previous element
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N);
        int dp[N];
        dp[0] = 0;
        dp[1]=0;
        if(arr[1]-arr[0]<K)
            dp[1]=max(dp[1],arr[1]+arr[0]);
        for (int i = 2; i < N; i++)
        {    
            dp[i]=dp[i-1];
            if (arr[i] - arr[i-1] < K)
                    dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
        }
        return dp[N - 1];
    }
// Maximum Path Sum
int maximumPath(int N, vector<vector<int>>v)
    {
        vector<vector<int>>dp(N,vector<int>(N,INT_MIN));
        int mx=INT_MIN;
        for(int i=0;i<N;i++)
            dp[N-1][i]=v[N-1][i];
        for(int i=N-2;i>=0;i--)
            for(int j=0;j<N;j++)
            {
                if(j-1>=0)
                    dp[i][j]=max(dp[i][j],v[i][j]+dp[i+1][j-1]);
                if(j+1<N)
                    dp[i][j]=max(dp[i][j],v[i][j]+dp[i+1][j+1]);
                dp[i][j]=max(dp[i][j],v[i][j]+dp[i+1][j]);
            }
        for(int i=0;i<N;i++)
            mx=max(mx,dp[0][i]);
        return mx;
    }
// Maximum difference of zeros and ones in binary string
int maxSubstring(string S)
    {
        int mx=-1,sum=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='0')
                sum+=1;
            else 
                sum+=-1;
           if(sum<0)
                sum=0;
           else 
               mx=max(mx,sum);
        }
        return mx;
    }
// Minimum removals from array to make max – min <= K
int recur(int i,int j,int &K,vector<int>&v)
{
    if(v[j]-v[i]<=K)
        return 0;
    return 1+min(recur(i+1,j,K,v),recur(i,j-1,K,v);
}
// Binary Trees with Height h
long long int countBT(int h) { 
        vector<long long>dp(h+1,1);
        int mod=1e9+7;
        for(int i=2;i<=h;i++)
            dp[i]=(dp[i-1]*dp[i-1] + 2*dp[i-1]*dp[i-2])%mod;
        return dp[h];
    }
// Kadane's Algorithm
int maxSubarraySum(int arr[], int n){
        int mx=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            mx=max(sum,mx);
            if(sum<0)
                sum=0;
        }
        return mx;
    }
// Smallest sum contiguous subarray
//Kadane Variation
int maxSubarraySum(int arr[], int n){
        int mx=INT_MAX;
        int sum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(sum>0)
                sum=arr[i];
            else
                sum+=arr[i];
            mx=min(sum,mx);
        }
        return mx;
    }
// Unbounded Knapsack
int recur(int n,int sum,int val[],int wt[],vector<vector<int>>&dp)
{
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(n==0 or sum==0)
        return dp[n][sum]=0;
    if(sum-wt[n-1]>=0)
        return dp[n][sum]=max(recur(n-1,sum,val,wt,dp),val[n-1]+recur(n,sum-wt[n-1],val,wt,dp));
    return dp[n][sum]=recur(n-1,sum,val,wt,dp);
}
// Word Break Problem
int recur(int i,int j,string &A,vector<string>&B,vector<vector<int>>&dp)
    {
        if(i>j)
            return dp[i][j]=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        string s=A.substr(i,j-i+1);
        for(int x=0;x<B.size();x++)
            if(s.compare(B[x])==0)
                return dp[i][j]=1;
        for(int x=i;x<j;x++)
        {
            int l=recur(i,x,A,B,dp),m=0;
            if(l==1)
                m=recur(x+1,j,A,B,dp); //Trick if not used will give tle
            if(l==1 and m==1)
                return 1;
        }
        return dp[i][j]=0;
    }
    int wordBreak(string A, vector<string> &B) {
        int n=A.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recur(0,n-1,A,B,dp);
    }
// It can become space optimised O(n)
bool wordBreak(string str)
{
    int size = str.size();
    if (size == 0)   return true;
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // Initialize all values as false.
    for (int i=1; i<=size; i++)
    {
        if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
            wb[i] = true;
        if (wb[i] == true)
        {
            if (i == size)
                return true;
            for (int j = i+1; j <= size; j++)
            {
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
                    wb[j] = true;
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
}
// Equal Sum Subset
int recur(int i,int j,int arr[],vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0)
            return dp[i][j]=1;
        if(i==0)
            return dp[i][j]=0;
        if(j-arr[i-1]>=0)
            return dp[i][j]=recur(i-1,j,arr,dp) or recur(i-1,j-arr[i-1],arr,dp);
        return dp[i][j]=recur(i-1,j,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2==1)
            return 0;
        vector<vector<int>>dp(N+1,vector<int>(sum/2 +1,-1));
        return recur(N,sum/2,arr,dp);
    }
// Longest Palindromic Substring
 bool ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }    
        return true;
    }
    int recur(int i,int j,string &s)
    {
        if(i>j)
            return 0;
        if(ispalindrome(i,j,s))
            return j-i+1;
        return max(recur(i+1,j,s),recur(i,j-1,s));
    }
// Stock Selling at most k transactions
// O(N*n*k)
int recur(int i,int k,int &n,int a[],vector<vector<int>>&dp)
  {
      if(dp[i][k]!=-1)
            return dp[i][k];
        if(i>=n-1 or k==0)
            return dp[i][k]=0;
        int mx=INT_MIN;
        for(int x=i+1;x<n;x++)
            mx=max(mx,a[x]-a[i]+recur(x+1,k-1,n,a,dp));
        mx=max(mx,recur(i+1,k,n,a,dp));
        return dp[i][k]=mx;
  }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>>dp(N+1,vector<int>(K+1,-1));
        return recur(0,K,N,A,dp);
    }
// Longest Common Substring--Memoization problem,easy tabulation
int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(S1[i-1]==S2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
        int mx=INT_MIN;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                mx=max(mx,dp[i][j]);
        return mx;
    }
// Weighted Job Scheduling
int recur(int n,vector<vector<int>>&v)
{
    if(n==v.size())
        return 0;
    int i;
    for(i=n+1;i<v.size();i++)
        if(v[i][0]>=v[n][1])
            break;
    return max(recur(n+1,v),v[n][2]+recur(i,v));
}
// Coin game winner where every player has three choices x,y,1
int ans(int n,int x,int y)
{
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int l=1;
        l=l&dp[i-1];
        if(i-x>=0)
            l=l&dp[i-x];
        if(i-y>=0)
            l=l&dp[i-y];
        if(l==0)
            dp[i]=1;
        else
            dp[i]=0;
    }
    return dp[n];
}
// Count Dearrangements
int countDer(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;
 
  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}
// Optimal Game Stratergy
int recur(int i,int j,int arr[],vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==j)
            return dp[i][j]=arr[i];
        return dp[i][j]=max(arr[i]+min(recur(i+1,j-1,arr,dp),recur(i+2,j,arr,dp)),arr[j]+min(recur(i+1,j-1,arr,dp),recur(i,j-2,arr,dp)));
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recur(0,n-1,arr,dp);
    }
// Optimal BST cost *******
int optCost(int freq[], int i, int j)
{
    // Base cases
    if (j < i)  // no elements in this subarray
        return 0;
    if (j == i) // one element in this subarray
        return freq[i];
    // Get sum of freq[i], freq[i+1], ... freq[j] Instead creating other state of node number and multiplying by frequency.
    int fsum = sum(freq, i, j); 
     
    // Initialize minimum value
    int min = INT_MAX;
    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) +
                   optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }
    return min + fsum;
}
// Palindromic Partitioning
bool ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    int recur(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(ispalindrome(i,j,s))
            return dp[i][j]=0;
        int mn=INT_MAX;
        for(int x=i;x<j;x++)
            mn=min(mn,1+recur(i,x,s,dp)+recur(x+1,j,s,dp));
        return dp[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recur(0,n-1,str,dp);
    }
