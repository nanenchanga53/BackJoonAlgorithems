#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
long long b;
typedef vector<vector<int>> matrix;
matrix operator*(const matrix& m1, const matrix& m2)
{
        matrix res(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        int sum = 0;
                        for (int k = 0; k < n; k++)
                        {
                                sum += (m1[i][k] * m2[k][j]) % 1000;
                        }
                        res[i][j] = sum % 1000;
                }
        }
        return res;
}

matrix PowMatrix(matrix a, long long m)
{
        matrix res(n, vector<int>(n));

        for (int i = 0; i < n; i++)
                res[i][i] = 1;

        if (m == 0)
                return res;
        else
        {
                if (m % 2 == 1)
                        res = res * a;

                return res * PowMatrix(a * a, m / 2);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n >> b;
        matrix mulMat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cin >> mulMat[i][j];
                }
        }

        matrix res = PowMatrix(mulMat, b);

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cout << res[i][j] << ' ';
                }
                cout << '\n';
        }
        cout << '\n';

        return 0;
}