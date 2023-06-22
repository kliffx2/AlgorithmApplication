#include <iostream>
#include <algorithm>

int main()
{
    int n, m;
    std::cout << "Nhap do dai cua day a: ";
    std::cin >> n;
    int a[n];
    std::cout << "Nhap cac phan tu cua day a: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::cout << "Nhap do dai cua day b: ";
    std::cin >> m;
    int b[m];
    std::cout << "Nhap cac phan tu cua day b: ";
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int c_length = dp[n][m];
    int c[c_length];
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            c[c_length - 1] = a[i - 1];
            i--;
            j--;
            c_length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    std::cout << "Day con chung lon nhat cua a va b: ";
    for (int k = 0; k < dp[n][m]; k++)
    {
        std::cout << c[k] << " ";
    }
    std::cout << std::endl;

    return 0;
}
