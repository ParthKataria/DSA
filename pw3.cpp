// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
vector<int> searchRange(vector<int>& nums, int target) {       
        if(nums.empty())
            return {-1,-1};
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(x==nums.size() or nums[x]!=target)
            return {-1,-1};
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        y--;
        return {x,y};
    }
// https://leetcode.com/problems/binary-search/submissions/
int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int md=l-(l-r)/2;
            if(nums[md]==target)
                return md;
            if(nums[md]>target)
                r=md-1;
            else
                l=md+1;
        }
        return -1;
    }
// https://leetcode.com/problems/container-with-most-water/submissions/
int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=INT_MIN;
        while(l<r)
        {
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
// https://atcoder.jp/contests/abc186/submissions/27035244
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v.begin(),v.end());
  vector<int>w=v;
  for(int i=1;i<n;i++)
    w[i]+=w[i-1];
  int sum=0;
  for(int i=n-1;i>=1;i--)
    sum+=i*v[i] - w[i-1];
  cout<<sum<<endl;
}
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
int findMin(vector<int>&v) {
        int l=0,r=v.size()-1;
        int mn=INT_MAX;
        while(l<=r)
        {
            int md=(l+r)/2;
            mn=min(mn,v[md]);
            if(v[r]<v[md])
                l=md+1;
            else
                r=md-1;
        }
        return mn;
	    // while(low < high)
	    // {
	    //     int mid = low + (high - low)/2;
	    //     if (arr[mid] == arr[high])
	    //         high--;
	    //     else if(arr[mid] > arr[high])
	    //         low = mid + 1;
	    //     else
	    //         high = mid;
	    // }
	    // return arr[high];
    }
// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
int bin(vector<int>&v,int l,int r,int s)
    {
        if(l>r)
            return -1;
        int md=l-(l-r)/2;
        if(v[md]==s)
            return md;
        if(v[md]>s)
            return bin(v,l,md-1,s);
        return bin(v,md+1,r,s);
    }
    int search(vector<int>& v, int s) {
        int l=0,r=v.size()-1;
        while(l<r)
        {
            int md=l-(l-r)/2;
            if(v[md]==v[r])
                r--;
            else if(v[md]>v[r])
                l=md+1;
            else
                r=md;
        }
        int x=bin(v,0,r-1,s);
        if(x!=-1)
            return x;
        return bin(v,r,v.size()-1,s);
    }
// https://leetcode.com/problems/koko-eating-bananas/submissions/
bool check(vector<int>&v,int x,int h)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i]/x;
            if((v[i]%x)>0)
                sum++;
        }
        if(sum<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>&v, int h) {
        int n=v.size();
        int l=1,r=INT_MIN;
        for(int i=0;i<n;i++)
            r=max(r,v[i]);
        while(l<r)
        {
            int md=l-(l-r)/2;
            if(check(v,md,h))
                r=md;
            else 
                l=md+1;
        }
        return l;
    }
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/
bool check(vector<int>&v,int x,int d)
    {
        int sum=0,ans=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum>x)
            {
                sum=v[i];
                ans++;
            }
        }
        ans++;
        if(ans<=d)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& v, int d) {
        int l=INT_MIN,r=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            l=max(l,v[i]);
            r+=v[i];
        }
        while(l<r)
        {
            int md=l-(l-r)/2;
            if(check(v,md,d))
                r=md;
            else
                l=md+1;
        }
        return l;
    }
// https://leetcode.com/problems/set-matrix-zeroes/submissions/
void setZeroes(vector<vector<int>>&v) {
        map<int,int>mp1,mp2;
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(v[i][j]==0)
                {
                    mp1[i]=1;
                    mp2[j]=1;
                }
        for(auto it:mp1)
            for(int i=0;i<m;i++)
                v[it.first][i]=0;
        for(auto it:mp2)
            for(int i=0;i<n;i++)
                v[i][it.first]=0;
    }
// https://leetcode.com/problems/game-of-life/submissions/
void gameOfLife(vector<vector<int>>&v) {
        vector<int>x={-1,-1,-1,0,0,1,1,1};
        vector<int>y={-1,0,1,-1,1,-1,0,1};
        int n=v.size(),m=v[0].size(),mod=1e6;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int l=v[i][j]%mod;
                vector<int>z(2,0);
                for(int k=0;k<8;k++)
                    if(i+x[k]<n and i+x[k]>=0 and j+y[k]<m and j+y[k]>=0)
                        z[(v[i+x[k]][j+y[k]])%mod]++;
                if(l==0 and z[1]==3)
                    v[i][j]+=mod;
                if(l==1 and (z[1]==2 or z[1]==3))
                    v[i][j]+=mod;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                v[i][j]/=mod;
    }
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#
long long maxSubarraySum(int arr[], int n){
        
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
// https://leetcode.com/problems/max-consecutive-ones-iii/submissions/
 int longestOnes(vector<int>& v, int k) {
        queue<int>q;
        int i=0,n=v.size();
        int mx=INT_MIN,id=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                q.push(i);
                if(k==0)
                {
                    id=q.front();
                    q.pop();
                }
                else
                    k--;
            }    
            mx=max(mx,i-id);
        }
        return mx;
    }
// https://leetcode.com/problems/max-chunks-to-make-sorted/
int maxChunksToSorted(vector<int>&v) {
        int x=0,y=0,n=v.size(),ans=0;
        vector<vector<int>>w;
        for(int i=0;i<n;i++)
            w.push_back({v[i],i});
        sort(w.begin(),w.end());
        for(int i=0;i<n;i++)
        {
            x|=(1<<i);
            y|=(1<<w[i][1]);
            if(x==y)
                ans++;
        }
        return ans;
    }
