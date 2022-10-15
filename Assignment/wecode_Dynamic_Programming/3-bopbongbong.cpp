#include<iostream>
#include <vector>
using namespace std;
int n;
pair<int, int> P;
vector<int> bals;
vector<vector<int>> M;
vector<int> ans;

int o_bn(int bn, int i)
{
	return (bn & ~(1LL << i));
}
int main()
{

	cin >> n;
	bals.resize(n);
	for (int& j : bals)
		cin >> j;

	int bn_num = 1LL << n;
	M.resize(bn_num, vector<int>(n, 0));
	ans.resize(bn_num, 0);

	for (int i = 0; i < bn_num; i++)
    {
		for (int j = 0; j < n; j++)
        {
			if (i != 0 && o_bn(i, j) == 0)
				M[i][j] = bals[j];
			else if (o_bn(i, j) == i)
				M[i][j] = 0;
			else
			{
				int w = 1;
				for (int k = j + 1; k <= n - 1; k++){
					if (((1LL << k) & i) != 0){
						w *= bals[k];
						break;
					}
				}
				for (int k = j - 1; k >= 0; k--){
					if (((1LL << k) & i) != 0){
						w *= bals[k];
						break;
					}
				}
				w *= bals[j];
				M[i][j] = w + ans[o_bn(i, j)];
			}
			ans[i] = max(ans[i], M[i][j]);
		}
	}
	cout << ans[bn_num - 1] << endl;
	return 0;
}
