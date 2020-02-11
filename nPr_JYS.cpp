#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void perm(vector<int> picked)
{
	do
	{
		for (int i = 0; i < picked.size(); i++)
		{
			cout << picked[i];
		}
		cout << endl;
	} while (next_permutation(picked.begin(), picked.end()));
}
void comb(int n, vector<int>& picked, int topick)
{
	if (topick == 0){ 
		perm(picked);
	}
	else
	{
		int smallest = picked.empty() ? 1 : picked.back() + 1;
		for (int next = smallest; next <= n; next++)
		{
			picked.push_back(next);
			comb(n, picked, topick - 1);
			picked.pop_back();
		}
	}
}

int main()
{
	int n, r;
	cin >> n >> r;
	vector<int> p;
	comb(n, p, r);
	return 0;
}
