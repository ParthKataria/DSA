// Sort array having 0,1 and 2
void sort012(int a[], int n)
    {
        int l=0,md=0,h=n-1;
        while(md<h)
        {
            if(a[md]==0)
                swap(a[l++],a[md++]);
            else if(a[md]==1)
                md++;
            else if(a[md]==2)
                swap(a[md],a[h--]);
        }
    }
// group array in neagtive and positive
void rearrange(vector<int>&v)
{
	int l=0,h=v.size()-1;
	while(l<=h)
	{
		if(v[l]<0 and v[h]<0)
			l++;
		else if(v[l]<0 and v[h]>0)
		{
		    l++;
		    h--;
		}
		else if(v[l]>0 and v[h]<0)
			swap(v[l],v[h--]);
		else
		    h--;
	}
}
// Minimize Diff of max and min Heights
int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int x=arr[n-1]-arr[0];
        for(int i=0;i<n;i++)
        if(arr[i]>=k)
        {
            int mx=max(arr[i-1]+k,arr[n-1]-k);
            int mn=min(arr[i]-k,arr[0]+k);
            x=min(x,mx-mn);
        }
        return x;
    }
