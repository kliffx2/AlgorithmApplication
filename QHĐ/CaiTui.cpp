#include <iostream>
using namespace std;

const int MAX = 100;

int F[MAX][MAX]; // max value in n packages with max m weight

void algorithm(int n, int m, int w[], int v[])
{
    for (int j = 0; j <= m; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j]; // Không lấy gói thứ i
            int temp = F[i - 1][j - w[i]] + v[i];
            if (w[i] <= j && F[i][j] < temp)
            { // Lấy gói thứ i
                F[i][j] = temp;
            }
        }
    }
}

void result(int n, int m, int w[])
{
    cout << "Max value: " << F[n][m] << endl; // max value in n packages with max m weight
    int i = n, j = m;
    while (i != 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << i << " ";
            j = j - w[i]; // Lấy gói thứ i
        }
        i--;
    }
    cout << endl;
}

int main()
{
    int n = 6;  // Số lượng gói hàng
    int m;      // Khối lượng tối đa của túi
    int w[MAX]; // Mảng chứa trọng lượng các gói hàng
    int v[MAX]; // Mảng chứa giá trị các gói hàng

    // Khởi tạo danh sách gói hàng
    w[1] = 1;
    v[1] = 5;
    w[2] = 2;
    v[2] = 3;
    w[3] = 4;
    v[3] = 7;
    w[4] = 2;
    v[4] = 2;
    w[5] = 5;
    v[5] = 8;
    w[6] = 3;
    v[6] = 4;

    cout << "Nhap khoi luong toi da: ";
    cin >> m;

    algorithm(n, m, w, v);
    result(n, m, w);

    return 0;
}
