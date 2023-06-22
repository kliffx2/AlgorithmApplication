#include <iostream>

using namespace std;

float s[5] = {8, 9, 10, 11, 12};
float f[5] = {8.5, 11, 11.5, 12.5, 13};
int kq[5] = {0, 0, 0, 0, 0};

void schedule()
{
    float last_finish = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i] >= last_finish)
        {
            kq[i] = 1;
            last_finish = f[i];
        }
    }
}
int main(int argc, char const *argv[])
{
    schedule();
    for (int i = 0; i < 5; i++)
    {
        cout << kq[i] << " ";
    }

    return 0;
}
