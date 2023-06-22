#include <iostream>
#include <algorithm>
using namespace std;

struct KienHang
{
    int khoi_luong;
    int kich_thuoc;
};

bool compare(KienHang a, KienHang b)
{
    return a.khoi_luong > b.khoi_luong;
}

int main()
{
    int k, n;
    cin >> k >> n;
    KienHang *ds_kien_hang = new KienHang[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ds_kien_hang[i].khoi_luong >> ds_kien_hang[i].kich_thuoc;
    }

    sort(ds_kien_hang, ds_kien_hang + n, compare);

    int tong_khoi_luong = 0, so_kien_hang = 0;
    while (tong_khoi_luong < k && so_kien_hang < n)
    {
        if (tong_khoi_luong + ds_kien_hang[so_kien_hang].kich_thuoc <= k)
        {
            tong_khoi_luong += ds_kien_hang[so_kien_hang].kich_thuoc;
            so_kien_hang++;
        }
        else
        {
            break;
        }
    }

    cout << so_kien_hang << endl;
    for (int i = 0; i < so_kien_hang; i++)
    {
        cout << ds_kien_hang[i].khoi_luong << " " << ds_kien_hang[i].kich_thuoc << endl;
    }

    delete[] ds_kien_hang;
    return 0;
}
