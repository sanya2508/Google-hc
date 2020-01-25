#include <bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define M 1000000007 
typedef long long int lli; 
#define tc  lli t;cin >> t;while(t--)
#define ffi(x,y) for(lli i=x;i<y;i++)
#define ffj(x,y) for(lli j=x;j<y;j++)
#define frj(x,y) for(lli j=x;j>y;j--)
#define fri(x,y) for(lli i=x;i>y;i--)
typedef long long int lli;
void dpssp(lli a[],lli n,lli k);
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  	lli i,n,k;
  	cin>>k>>n;
  	lli s=0,ans;
  	lli a[n];
  	for(i=0;i<n;i++)
  	{
  		cin>>a[i];
  		s=s+a[i];
  	}
  	dpssp(a,n,k);
return 0;
}
void dpssp(lli a[],lli n,lli k)
{
	lli i,j;
	bool dp[n+1][k+1];
	for(i=0;i<=n;i++)
	{
		dp[i][0]=true;
	}
	for(i=1;i<=k;i++)
	{
		dp[0][i]=false;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(j < a[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			if(j >= a[i-1])
			{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
			}
		}
	}
	/*
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}
	*/
	lli sum,m;
	for(m=k;m>=0;m--)
	{
	
	 if(dp[n][m]==1)
	  {
        sum=m;
        break;
	  }
	}
	//cout<<"\nanswer array is:\n"<<sum<<"\n\n";
		lli l=0,sz=0;
		lli ans[n];
		for(j=n,i=sum;j>0 && i!=0;j--)
		{
			
				/*if(dp[i][j]==1 && dp[i-1][j]==0)
				{
					ans[l]=a[i-1];
					l++;
					j=j-a[i];
				}
				else if(dp[i][j]==1 && dp[i-1][j]==1 && j<a[i-1])
				{
                    i--;
 				}
 				*/
 				if(a[j-1] != i)
 				{
 					while(dp[j-1][i])
 					{
 						j--;
 					}
 				}
 			//	ans[l]=a[j-1];
 				ans[l]=j;
 				l++;
 				i=i-a[j-1];

		}	
		sz=l;
		/*
		cout<<'\n';
		for(i=0;i<sz;i++)
		{
			cout<<ans[i]<<"  ";
		}
		sort(ans,ans+sz);
		cout<<"\nfinal answer:\n";
		*/

/*		lli in;
		in=0;
		lli an[n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<sz;j++)
			{
				if(a[i]==ans[j])
				{
					an[in]=i;
					in++;
				}
			}
		}
		lli size;
		size=in;
		cout<<size<<'\n';
		for(i=0;i<size;i++)
		{
			cout<<an[i]<<" ";
		}
*/
		
		cout<<sz<<'\n';
for(i=0;i<sz;i++)
{
	cout<<ans[i]<<" ";
}
	
}
