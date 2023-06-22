#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Max(int a[], int l, int r)
{
    if (l == r)
    {
        return a[l];
    }
    else
    {
        int m = (l + r) / 2;
        int max1 = Max(a, l, m);
        int max2 = Max(a, m + 1, r);
        return (max1 > max2) ? max1 : max2;
    }
}

int main(int argc, char const *argv[])
{
    int a[15];
    srand(time(NULL)); // Thiết lập giá trị khởi tạo cho hàm rand()
    for (int i = 0; i < 15; i++)
    {
        a[i] = (double)rand() / RAND_MAX * 100; // Sinh ra một số thực ngẫu nhiên trong khoảng từ 0 đến 100
    }
    for (int i = 0; i < 15; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << Max(a, 0, 16);
    return 0;
}
