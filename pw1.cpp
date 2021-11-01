// https://practice.geeksforgeeks.org/problems/last-index-of-15847/1
int lastIndex(string s) 
    {
        for(int i=s.size()-1;i>=0;i--)
            if(s[i]=='1')
                return i;
        return -1;
    }
// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
int MissingNumber(vector<int>& array, int n) {
        int sum=0; 
        // Another method using xor
        for(int i=0;i<n-1;i++)
        {
            sum+=i+1;
            sum-=array[i];
        }
        sum+=n;
        return sum;
    }
// https://leetcode.com/problems/majority-element/
int majorityElement(vector<int>& nums) {
        int x=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(cnt==0)
                x=nums[i];
            if(nums[i]==x)
                cnt++;
            else           
                cnt--;
        }
        return x;
    }
// https://leetcode.com/problems/max-consecutive-ones/
 int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else    
                cnt=0;
        }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
void zigZag(int arr[], int n) {
	   for(int i=0;i<n-1;i++)
	   {
	        if((i%2)==1 and arr[i]<arr[i+1])
	            swap(arr[i],arr[i+1]);
	        if((i%2)==0 and arr[i]>arr[i+1])
	            swap(arr[i],arr[i+1]);
	   }
	}
// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1
void rearrange(long long *arr, int n) 
    { 
        int mod=1e5;
    	int cnt=n-1;
    	for(int i=0;i<n;i+=2)
    	{
    	    int z=arr[cnt]%mod;
    	    arr[i]+=z*mod;
    	    cnt--;
    	}
    	cnt=0;
    	for(int i=1;i<n;i+=2)
    	{
    	    int z=arr[cnt]%mod;
    	    arr[i]+=z*mod;
    	    cnt++;
    	}
    	for(int i=0;i<n;i++)
    	    arr[i]/=mod;
    }
// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1
void reverseInGroups(vector<long long>& arr, int n, int k){
        int i=0;
        vector<long long>v;
        for(i=1;i*k<=n;i++)
            for(int j=i*k-1;j>=(i-1)*k;j--)
                v.push_back(arr[j]);
        for(int j=n-1;j>=(i-1)*k;j--)
            v.push_back(arr[j]);
        arr=v;
    }
// https://leetcode.com/problems/majority-element-ii/
vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        int x=nums[0],y=nums[1],cnt1=0,cnt2=0,n=nums.size();
        for(int i=1;i<n;i++)
            if(nums[i]!=x)
            {
                y=nums[i];
                break;
            }    
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)
                cnt1++;
            else if(nums[i]==y)
                cnt2++;
            else if(cnt1==0)
            {
                x=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                y=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int sum=0;
        vector<int>v;
        for(int i=0;i<n;i++)
            if(nums[i]==x)
                sum++;
        if(sum>n/3)
            v.push_back(x);
        if(y!=x)
        {sum=0;
        for(int i=0;i<n;i++)
            if(nums[i]==y)
                sum++;
        if(sum>n/3)
            v.push_back(y);}
        return v;
    }
// https://leetcode.com/problems/rotate-array/     Require better
// Reverse(a,a+n-k)
// Reverse(a+n-k+1, a+n)
// Reverse(a,a+n)
void rotate(vector<int>& nums, int k) {
        int mod=1e8,n=nums.size();
        vector<int>v(n);
        k=k%n;
        for(int i=0;i<n;i++)
        {
            int z=(i-k+n)%n;
            v[i]=nums[z];
        }
        for(int i=0;i<n;i++)
            nums[i]=v[i];
    }
// https://leetcode.com/problems/third-maximum-number/
int thirdMax(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            if(s.size()>3)
                s.erase(s.begin());
        }
        if(s.size()==3)
            return *s.begin();
        while(s.size()>1)
            s.erase(s.begin());
        return *s.begin();
    }
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
long long trappingWater(int v[], int n){
        long long sum=0,i;
        vector<int> maxl(n),maxr(n);
        maxl[0]=v[0];
        maxr[n-1]=v[n-1];
        for(i=1;i<n;i++)
            maxl[i]=max(maxl[i-1],v[i]);
        for(i=n-2;i>=0;i--)
            maxr[i]=max(maxr[i+1],v[i]);
        for(i=0;i<n;i++)
            sum=sum+min(maxl[i],maxr[i])-v[i];
        return sum;
    }
// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
int equilibriumPoint(long long a[], int n) {
        if(n==1)
            return 1;
        for(int i=1;i<n;i++)
            a[i]+=a[i-1];
        for(int i=1;i<n-1;i++)
            if(a[i-1]==a[n-1]-a[i])
                return i+1;
        return -1;
    }
// https://practice.geeksforgeeks.org/problems/unsorted-array4925/1
int findElement(int arr[], int n) {
    vector<int>mx(n),mn(n);
    for(int i=0;i<n;i++)
    {
        mx[i]=arr[i];
        mn[i]=arr[i];
    }
    for(int i=1;i<n;i++)
        mx[i]=max(mx[i],mx[i-1]);
    for(int i=n-2;i>=0;i--)
        mn[i]=min(mn[i],mn[i+1]);
    for(int i=1;i<n-1;i++)
        if(arr[i]>=mx[i-1] and arr[i]<=mn[i+1])
            return arr[i];
    return -1;
}
// https://leetcode.com/problems/product-of-array-except-self/
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>p(n+1,1),s(n+1,1),ans(n);
        for(int i=1;i<=n;i++)
            p[i]=p[i-1]*nums[i-1];
        for(int i=n-1;i>=0;i--)
            s[i]=s[i+1]*nums[i];
        for(int i=1;i<=n;i++)
            ans[i-1]=p[i-1]*s[i];
        return ans;
    }
// https://leetcode.com/problems/rotate-image/
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        int x=m/2;
        for(int i=0;i<n;i++)
            for(int j=0;j<x;j++)
                swap(matrix[i][j],matrix[i][m-1-j]);
    }
// https://leetcode.com/problems/spiral-matrix-ii/
// https://leetcode.com/problems/spiral-matrix/
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int t=0,b=r,l=0,ri=c;
        vector<int>v;
        while(t<b and l<ri)
        {
            for(int i=l;i<ri;i++)
                v.push_back(matrix[t][i]);
            t++;
            for(int i=t;i<b;i++)
                v.push_back(matrix[i][ri-1]);
            ri--;
            if(t<b)
            {   for(int i=ri-1;i>=l;i--)
                    v.push_back(matrix[b-1][i]);
                b--;
            }
            if(l<ri)
            {
                for(int i=b-1;i>=t;i--)
                    v.push_back(matrix[i][l]);
                l++;
            }
        }
    return v;
    }
//leetcode.com/problems/plus-one/
 void func(int x,int i,vector<int>&v)
    {
        if(x==0)
            return;
        v[i]+=x;
        int z=v[i]/10;
        v[i]=v[i]%10;
        func(z,i-1,v);
    }
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>v(n+1);
        for(int i=1;i<=n;i++)
            v[i]=digits[i-1];
        func(1,n,v);
        if(v[0]==0)
        {
            reverse(v.begin(),v.end());
            v.pop_back();
            reverse(v.begin(),v.end());
        }
        return v;
    }
