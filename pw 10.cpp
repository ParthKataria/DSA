// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
ll findSubarray(vector<ll> v, int n ) {
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum==0)
                ans++;
            if(mp.find(sum)!=mp.end())
                ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/
int merge_sort(int l,int r,vector<vector<int>>&v,vector<int>&ans)
    {
        if(l>=r)
            return 0;
        int md=(l+r)/2;
        int x=merge_sort(l,md,v,ans);
        int y=merge_sort(md+1,r,v,ans);
        int z=0,k=md+1,j=l,m=0,n=0;
        while(j<=md)
        {
            while(k<=r and v[j][0]>v[k][0])
            {
                n++;
                k++;
            }
            if(k==r+1 or v[j][0]<=v[k][0])
            {
                ans[v[j][1]]+=n;
                j++;
            }   
        }
        inplace_merge(v.begin()+l,v.begin()+md+1,v.begin()+r+1);
        return x+y+m;
    }
    vector<int> countSmaller(vector<int>&v) {
        int n=v.size();
        vector<vector<int>>w(n);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
            w[i]={v[i],i};
        cout<<merge_sort(0,n-1,w,ans)<<endl;
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
int findLongestConseqSubseq(int arr[], int n)
    {
        int mx=0,j=0;
        sort(arr,arr+n);
        unique(arr,arr+n);
        for(int i=1;i<n;i++)
            if(arr[i]-arr[i-1]!=1)
            {
                mx=max(mx,i-j);
                j=i;
            }
        mx=max(mx,n-j);
        return mx;
    }
// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
 bool canPair(vector<int>v, int k) {
        int x=0,y=0;
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++)
        {
            if((v[i]%k)==0)
                x++;
            else if((v[i]%k)*2==k)
                y++;
            else
                mp[v[i]%k]++;
        }
        if((x%2)==1  or (y%2)==1)
            return false;
        for(auto it:mp)
            if(mp[k-it.first]!=it.second)
                return false;
        return true;
// https://leetcode.com/problems/longest-mountain-in-array/submissions/
int longestMountain(vector<int>& v) {
        int n=v.size(),ans=0,flag=1,id=-1,i=1;
    while(i<n)
    {
        int id=i;
        while(id<n and v[id]>v[id-1])
            id++;
        if(id==i)
        {
            i++;
            continue;
        }
        if(id==n)
            break;
        int x=id;
        while(id<n and v[id]<v[id-1])
            id++;
        if(id>x)
            ans=max(ans,id-i+1);
        i=id;
    }
    return ans;
    }
// https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
int minSubArrayLen(int k, vector<int>&v) {
        int j=0,ans=INT_MAX,sum=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum>=k)
                ans=min(ans,i-j+1);
            while(j<i and sum-v[j]>=k)
            {
                sum-=v[j];
                ans=min(ans,i-j);
                j++;
            }
        }
        if(ans<INT_MAX)
            return ans;
        return 0;
    }
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/submissions/
bool valid(int md,double h,vector<int>&v)
    {
        int n=v.size();
        double t=0;
        for(int i=0;i<n-1;i++)
        {
            if((v[i]%md)==0)
                t+=v[i]/md;
            else
                t+=v[i]/md +1;
        }
        t+=v[n-1]/(double)md;
        return t<=h;
    }
    int minSpeedOnTime(vector<int>&v, double hour) {
        int l=1,r=INT_MAX-2,ans=INT_MAX;
        while(l<=r)
        {
            int md=l+(r-l)/2;
            if(valid(md,hour,v))
            {
                ans=md;
                r=md-1;
            }
            else
                l=md+1;
        }
        if(ans<INT_MAX)
            return ans;
        return -1;
    }
// https://leetcode.com/problems/nth-digit/submissions/
int findNthDigit(int n) {
        if(n<=9)
            return n;
        vector<long long>v(10);
        v[1]=9;
        for(int i=2;i<10;i++)
            v[i]=pow(10,i)-1;
        for(int i=9;i>=2;i--)
            v[i]=(v[i]-v[i-1])*i;
        for(int i=2;i<10;i++)
            v[i]+=v[i-1];
        int it=lower_bound(v.begin(),v.end(),n)-v.begin();
        n-=v[it-1];
        int x=n/it,y=n%it;
        int z=pow(10,it-1)+x-1;
        if(y==0)
            return z%10;
        z++;
        vector<int>ll;
        while(z>0)
        {
            ll.push_back(z%10);
            z/=10;
        }
        return ll[it-y];
    }
// https://leetcode.com/problems/merge-sorted-array/submissions/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++)
            nums1[i]=nums2[i-m];
        inplace_merge(nums1.begin(),nums1.begin()+m,nums1.end());
    }
    // Interview Variant
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        reverse(nums1.begin(),nums1.begin()+m);
        int i=m-1,j=0,k=m+n-1;
        while(i>=0 and j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                 nums1[k]=nums1[i];
                i--;
            }   
            else
            {
                nums1[k]=nums2[j];
                j++;
            }
            k--;
        }
        while(j<n)
            nums1[k--]=nums2[j++];
        while(i>=0)
            nums1[k--]=nums1[i--];
        reverse(nums1.begin(),nums1.end());
    }
// https://leetcode.com/problems/merge-intervals/submissions/
vector<vector<int>> merge(vector<vector<int>>&v) {
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        int s=v[0][0],e=v[0][1],i=1,n=v.size();
        while(i<n)
        {
            if(v[i][0]<=e)
                e=max(e,v[i][1]);
            else
            {
                ans.push_back({s,e});
                s=v[i][0],e=v[i][1];
            }    
            i++;
        }
        ans.push_back({s,e});
        return ans;
    }
