#include <iostream>

using namespace std;

const int MAX = 100;

int F[MAX][MAX];

class Phone
{
private:
    string brand;
    int size;
    int price;

public:
    Phone(string brand, int size, int price);
    string getBrand();
    int getSize();
    int getPrice();
};

Phone::Phone(string brand, int size, int price)
{
    this->brand = brand;
    this->size = size;
    this->price = price;
}

string Phone::getBrand()
{
    return this->brand;
}

int Phone::getSize()
{
    return this->size;
}

int Phone::getPrice()
{
    return this->price;
}

void algorithm(int s, int n, Phone d[])
{
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
    }
    for (int j = 0; j <= s; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (d[i - 1].getSize() <= j)
            {
                int temp = F[i - 1][j - d[i - 1].getSize()] + d[i - 1].getPrice();
                F[i][j] = max(F[i - 1][j], temp);
            }
            else
            {
                F[i][j] = F[i - 1][j];
            }
        }
    }
}

void result(int s, int n, Phone d[])
{
    cout << "Max value: " << F[n][s] << endl;

    int i = n, j = s;
    while (i > 0 && j > 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << d[i - 1].getBrand() << " - $" << d[i - 1].getPrice() << endl;
            j = j - d[i - 1].getSize();
        }
        i--;
    }
}

int main()
{
    int s;
    int n = 5;
    Phone d[5] = {
        Phone("B01", 1, 5),
        Phone("B02", 2, 3),
        Phone("B03", 4, 7),
        Phone("B04", 2, 2),
        Phone("B05", 5, 8)};

    cout << "Nhap size cua tui: ";
    cin >> s;

    algorithm(s, n, d);
    result(s, n, d);
    return 0;
}
