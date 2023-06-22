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
    Quat();
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
Quat::Quat()
{
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

int algo(Quat d[], int n, int p, Quat *result)
{
    int current_price = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_price + d[i].getPrice() <= p)
        {
            result[count] = d[i];
            current_price += d[i].getPrice();
            count++;
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
        Quat("Q01", "xanh", 500000),
        Quat("Q02", "do", 450000),
        Quat("Q03", "tim", 400000),
        Quat("Q04", "vang", 350000),
        Quat("Q05", "luc", 200000),
        Quat("Q06", "lam", 100000)};
    int p = 1000000;
    int n = 6;
    Quat *result = new Quat[n];
    int count = algo(d, n, p, result);

    cout << "So luong it nhat: " << count << endl;
    cout << "Danh sach:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << result[i].getNSX() << ": " << result[i].getPrice() << endl;
    }

    delete[] result;

    return 0;
}
