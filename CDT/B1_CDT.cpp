#include <iostream>
#include <string>
#include <algorithm> // sử dụng std::sort
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    int birthYear;
    string address;
};

// hàm so sánh tên của 2 học sinh
bool compareName(const Student &a, const Student &b)
{
    return a.firstName < b.firstName;
}

// hàm tìm kiếm sử dụng thuật toán chia để trị
int binarySearch(const Student arr[], int l, int r, const string &x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;
    if (arr[mid].firstName == x)
        return mid;
    if (arr[mid].firstName < x)
        return binarySearch(arr, mid + 1, r, x);
    return binarySearch(arr, l, mid - 1, x);
}

int main()
{
    // khởi tạo danh sách học sinh
    Student students[] = {
        {"Minh", "Nguyen", 2000, "Ha Noi"},
        {"Linh", "Tran", 2001, "Ho Chi Minh"},
        {"Anh", "Le", 2002, "Hai Phong"},
        {"Huong", "Pham", 2000, "Da Nang"},
        {"Tuan", "Doan", 2003, "Hue"},
        {"Hieu", "Nguyen", 2001, "Quang Ninh"}};

    // sắp xếp danh sách học sinh theo tên
    const int numStudents = sizeof(students) / sizeof(students[0]);
    sort(students, students + numStudents, compareName);

    // nhập tên học sinh cần tìm
    string nameToSearch;
    cout << "Nhap ten hoc sinh can tim: ";
    getline(cin, nameToSearch);

    // tìm kiếm học sinh trong danh sách
    int index = binarySearch(students, 0, numStudents - 1, nameToSearch);

    // hiển thị thông tin của học sinh nếu tìm thấy
    if (index != -1)
    {
        cout << "Thong tin hoc sinh can tim: " << endl;
        cout << "Ho ten: " << students[index].lastName << " " << students[index].firstName << endl;
        cout << "Nam sinh: " << students[index].birthYear << endl;
        cout << "Dia chi: " << students[index].address << endl;
    }
    else
    {
        cout << "Khong tim thay hoc sinh co ten la " << nameToSearch << " trong danh sach." << endl;
    }

    return 0;
}