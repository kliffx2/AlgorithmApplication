// #include <iostream>

// using namespace std;

// class HoiThao
// {
// private:
//     string topic;
//     int startTime;
//     int endTime;

// public:
//     HoiThao(string topic, int startTime, int endTime);
//     ~HoiThao();
//     string getTopic();
//     int getStartTime();
//     int getEndTime();
// };

// HoiThao::HoiThao(string topic, int startTime, int endTime)
// {
//     this->topic = topic;
//     this->startTime = startTime;
//     this->endTime = endTime;
// }

// HoiThao::~HoiThao()
// {
// }

// string HoiThao::getTopic()
// {
//     return this->topic;
// }

// int HoiThao::getStartTime()
// {
//     return this->startTime;
// }

// int HoiThao::getEndTime()
// {
//     return this->endTime;
// }

// int algo(HoiThao ht[], int n, int *S)
// {
//     for (int i = 0; i < n; i++)
//     {
//         S[i] = 0;
//     }
//     int i = 0;
//     int count = 0;
//     while (i < n)
//     {
//         if (ht[i].getEndTime() <= ht[i + 1].getStartTime())
//         {
//             S[i]++;
//             count++;
//             i++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return count;
// }

// int main(int argc, char const *argv[])
// {
//     HoiThao ht[5] = {
//         HoiThao("T01", 2, 3),
//         HoiThao("T02", 3, 5),
//         HoiThao("T03", 2, 6),
//         HoiThao("T04", 7, 8),
//         HoiThao("T05", 9, 10)};
//     int n = 5;
//     int *S = new int[n];
//     cout << algo(ht, n, S) << endl;
//     for (int i = 0; i < n; i++)
//     {
//         if (S[i] == 1)
//         {
//             cout << ht[i].getTopic() << endl;
//         }
//     }
//     return 0;
// }
#include <iostream>

using namespace std;

class HoiThao
{
private:
    string topic;
    int startTime;
    int endTime;

public:
    HoiThao(string topic, int startTime, int endTime);
    ~HoiThao();
    string getTopic();
    int getStartTime();
    int getEndTime();
};

HoiThao::HoiThao(string topic, int startTime, int endTime)
{
    this->topic = topic;
    this->startTime = startTime;
    this->endTime = endTime;
}

HoiThao::~HoiThao()
{
}

string HoiThao::getTopic()
{
    return this->topic;
}

int HoiThao::getStartTime()
{
    return this->startTime;
}

int HoiThao::getEndTime()
{
    return this->endTime;
}

int algo(HoiThao ht[], int n, int *S, string *topics)
{
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
    }
    int i = 0;
    int count = 0;
    while (i < n)
    {
        if (ht[i].getEndTime() <= ht[i + 1].getStartTime())
        {
            S[i]++;
            topics[count] = ht[i].getTopic();
            count++;
            i++;
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
    HoiThao ht[5] = {
        HoiThao("T01", 4, 6),
        HoiThao("T02", 6, 7),
        HoiThao("T03", 7, 9),
        HoiThao("T04", 10, 11),
        HoiThao("T05", 11, 12)};
    int n = 5;
    int *S = new int[n];
    string *topics = new string[n];
    int maxConferences = algo(ht, n, S, topics);
    cout << "So hoi thao toi da co the tham du: " << maxConferences << endl;
    cout << "Danh sach:" << endl;
    for (int i = 0; i < maxConferences; i++)
    {
        cout << topics[i] << endl;
    }
    delete[] S;
    delete[] topics;
    return 0;
}
