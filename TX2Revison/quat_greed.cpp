#include <iostream>
#include <algorithm>
using namespace std;

class Quat
{
private:
    string NSX;
    string color;
    int price;

public:
    Quat(string NSX, string color, int price);
    ~Quat();
    int getPrice();
    string getNSX();
};

Quat::Quat(string NSX, string color, int price)
{
    this->NSX = NSX;
    this->color = color;
    this->price = price;
}

Quat::~Quat()
{
}

int Quat::getPrice()
{
    return this->price;
}

string Quat::getNSX()
{
    return this->NSX;
}
int algo(Quat d[], int n, int p, int *S)
{
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
    }
    int i = n - 1;
    int count = 0;
    while (p > 0 && i > 0)
    {
        if (p - d[i].getPrice() > 0)
        {
            S[i]++;
            p -= d[i].getPrice();
            count++;
            i--;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    Quat d[6] = {
        Quat("Q01", "xanh", 600000),
        Quat("Q02", "do", 500000),
        Quat("Q03", "tim", 400000),
        Quat("Q04", "vang", 300000),
        Quat("Q05", "luc", 200000),
        Quat("Q06", "lam", 100000)};
    int p = 1000000;
    int n = 6;
    int *S = new int[n];
    cout << algo(d, n, p, S) << endl;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 1)
        {
            cout << d[i].getNSX() << ": " << d[i].getPrice() << endl;
        }
    }
    return 0;
}
