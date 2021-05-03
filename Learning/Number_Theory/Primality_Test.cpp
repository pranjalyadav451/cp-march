// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int isPrime(int N)
	{
		if (N == 1)
			return 0;
		/**
		 * '1' is a special case as it is neither prime nor composite.
		 * For All other numbers we know that the factors of the number exist in pairs
		 * The max of every pair is less than or equal to sqroot(N)
		 * If any number between 1 and sqroot(N) divides N, then N has more than '2' factors
		 * Hence 'N' is not prime otherwise IT IS.
		*/
		int count = 0;
		for (int i = 2; i * i <= N; i++)
		{
			if (N % i == 0)
				count++;
			if (count > 0)
				return 0;
		}
		return 1;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		Solution ob;
		cout << ob.isPrime(N) << endl;
	}
	return 0;
} // } Driver Code Ends