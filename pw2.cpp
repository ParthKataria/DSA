// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1#
bool compare(string a,string b)
	{
	    int x=a.size(),y=b.size();
	    for(int i=0;i<min(x,y);i++)
	        return a[i]>=b[i];
	    return x<=y;
	}
string printLargest(vector<string> &arr) {
	    sort(arr.begin(),arr.end(),compare);
	    string s="";
	    for(int i=0;i<arr.size();i++)
	        s+=arr[i];
	   return s;
	}
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
vector<int> subarraySum(int v[], int n, long long s)
    {
        int k=0,sum=0,j=-1;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            while(sum>s)
            {
                sum-=v[k];
                k++;
            }
            if(sum==s)
            {
                j=i;
                break;
            }
        }
        if(j==-1)
            return {-1};
        return {k+1,j+1};
    }
// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long ans=1e10;
        for(int i=0;i<=n-m;i++)
            if(a[i+m-1]-a[i]<ans)
                ans=a[i+m-1]-a[i];
        return ans;
    }  
// https://leetcode.com/problems/sort-colors/submissions/
void sortColors(vector<int>&v) {
        int l=0,r=v.size()-1,md=0;
        while(md<=r)
        {
            if(v[md]==0)
                swap(v[l++],v[md++]); 
            else if(v[md]==1)
                md++;
            else
                swap(v[md],v[r--]);
        }
    }
// https://leetcode.com/problems/minimum-increment-to-make-array-unique/submissions/
int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=1;i<n;i++)
            if(nums[i]<=nums[i-1])
            {
                ans+=nums[i-1]+1-nums[i];
                nums[i]=nums[i-1]+1;
            }
        return ans;
    }
// https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=1;
        int i=1;
        while(1)
        {
            if(mp.find(i)==mp.end())
                return i;
            i++;
        }
    }
// https://leetcode.com/problems/two-sum/submissions/
vector<int> twoSum(vector<int>& v, int target) {
        int l=0,r=v.size()-1;
        map<int,vector<int>>mp;
        for(int i=0;i<=r;i++)
            mp[v[i]].push_back(i);
        for(auto it:mp)
        {
            if(2*it.first==target and it.second.size()>1)
                return {it.second[0],it.second[1]};
            else if(mp.find(target-it.first)!=mp.end())
                return {it.second[0],mp[target-it.first][0]};
        }
        return {-1};
    }
// https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1#
bool twoSum(int r,vector<int>& v, int target) {
        int l=0;
        while(l<r)
        {
            if(v[l]+v[r]==target)
                return true;
            if(v[l]+v[r]<target)
                l++;
            else
                r--;
        }
        return false;
    }
bool checkTriplet(int arr[], int n) {
	    vector<int>v;
	    for(int i=0;i<n;i++)
	        v.push_back(arr[i]*arr[i]);
	   sort(v.begin(),v.end());
	   for(int i=n-1;i>=2;i--)
	        if(twoSum(i-1,v,v[i]))
	            return true;
	   return false;
	}
// https://leetcode.com/problems/3sum/submissions/
vector<vector<int>> twoSum(int r,vector<int>& v, int target) {
        int l=0;
        vector<vector<int>>ans;
        while(l<r)
        {
            if(v[l]+v[r]==target)
                ans.push_back({v[l],v[r]});
            if(v[l]+v[r]<target)
                l++;
            else
                r--;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>&v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=n-1;i>=2;i--)
        {
            if(i<n-1 and v[i+1]==v[i])
                continue;
            vector<vector<int>>z=twoSum(i-1,v,-v[i]);
            auto it=unique(z.begin(),z.end());
            z.resize(distance(z.begin(),it));
            for(int k=0;k<z.size();k++)
                ans.push_back({z[k][0],z[k][1],v[i]});
        }
        return ans;
    }
