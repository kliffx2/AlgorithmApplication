#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Thuật toán Boyer Moore Horspool để tìm vị trí xuất hiện của xâu P trong xâu T
int boyerMooreHorspool(const string &T, const string &P)
{
    int n = T.length();
    int m = P.length();

    if (m > n)
        return -1;

    int badShift[256];
    memset(badShift, m, sizeof(badShift));

    for (int i = 0; i < m - 1; i++)
        badShift[P[i]] = m - 1 - i;

    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && P[j] == T[i + j])
            j--;

        if (j < 0)
            return i;

        i += badShift[T[i + m - 1]];
    }

    return -1;
}

// Thuật toán Z để kiểm tra xâu P có xuất hiện trong xâu T hay không
bool zAlgorithm(const string &T, const string &P)
{
    string concat = P + "$" + T;
    int n = concat.length();
    int m = P.length();
    int *Z = new int[n];
    memset(Z, 0, sizeof(Z));

    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && concat[R - L] == concat[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && concat[R - L] == concat[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m)
            return true;
    }
    return false;
}

class Laptop
{
private:
    string manufacturer;
    string configuration;
    int price;

public:
    Laptop(string manufacturer, string configuration, int price)
    {
        this->manufacturer = manufacturer;
        this->configuration = configuration;
        this->price = price;
    }
    string getManu()
    {
        return this->manufacturer;
    }
    string getConfig()
    {
        return this->configuration;
    }
    int getPrice()
    {
        return this->price;
    }
};

int main()
{

    Laptop laptops[5] = {
        Laptop("HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 100),
        Laptop("ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 200),
        Laptop("Dell", "CPU 2.5GHz upto 3.5GHz-RAM 12GB-SSD 128GB", 300),
        Laptop("Lenovo", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 1TB", 400),
        Laptop("Asus", "CPU 2.5GHz upto 3.5GHz-RAM 32GB-SSD 256GB", 500)};

    int count16GB = 0;
    cout << "\nDanh sach laptop co RAM 16GB:\n";
    for (int i = 0; i < 5; i++)
    {
        if (laptops[i].getConfig().find("RAM 16GB") != string::npos)
        {
            count16GB++;
            cout << "Laptop " << i + 1 << ":\n";
            cout << "Nha san xuat: " << laptops[i].getManu() << endl;
            cout << "Cau hinh: " << laptops[i].getConfig() << endl;
            cout << "Gia ban: " << laptops[i].getPrice() << endl;
        }
    }
    cout << "Tong so laptop co RAM 16GB: " << count16GB << endl;

    cout << "\nDanh sach laptop su dung o cung loai SSD:\n";
    for (int i = 0; i < 5; i++)
    {
        if (laptops[i].getConfig().find("SSD") != string::npos)
        {
            cout << "Laptop " << i + 1 << ":\n";
            cout << "Nha san xuat: " << laptops[i].getManu() << endl;
            cout << "Cau hinh: " << laptops[i].getConfig() << endl;
            cout << "Gia ban: " << laptops[i].getPrice() << endl;
            ;
        }
    }

    return 0;
}
