//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
   //mistakes I did:
    //1. INT_MAX
    //2. long long
    //3. n-m+1 in for loop
    //4. forgot to sort 

    sort(a.begin(),a.end());
    long long ans=INT_MAX;
    for(int i=0; i<n-m+1 ; i++){
        int d = a[i+m-1] - a[i];
        if(d<ans) ans = d;
    }
    return ans;

    /*
     long long ans=INT_MAX;
        sort(a.begin(),a.end());
        for(int i=0;i+m-1<n;i++)
        ans=min(ans,a[i+m-1]-a[i]);
        return ans;
    */
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
