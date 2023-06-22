#include <iostream>
using namespace std;

// Hàm trộn hai danh sách con của arr[]
// Đầu danh sách con đầu tiên là arr[left..mid]
// Đầu danh sách con thứ hai là arr[mid+1..right]
void merge(float arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float *L = new float[n1];
    float *R = new float[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp danh sách theo chiều tăng dần
void mergeSort(float arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    // Khởi tạo danh sách số thực
    float arr[] = {1.2, 4.5, 6.7, 3.4, 2.3, 8.9, 5.6, 9.1, 7.8, 10.2, 12.3, 11.1, 13.4, 14.5, 15.6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sắp xếp danh sách bằng thuật toán trộn
    mergeSort(arr, 0, n - 1);

    // Hiển thị danh sách sau khi sắp xếp
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}