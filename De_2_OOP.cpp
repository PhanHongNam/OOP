#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

class Diem
{
private:
    double toan, ly, hoa;
public:
    Diem()
    {
        toan = ly = hoa = 0;
    }

    void setToan(double t)
    {
        toan = t;
    }

    void setLy(double l)
    {
        ly = l;
    }

    void setHoa(double h)
    {
        hoa = h;
    }

    double getToan()
    {
        return toan;
    }

    double getLy()
    {
        return ly;
    }

    double getHoa()
    {
        return hoa;
    }

    friend class Student;
};

class Student
{
private:
    char ten[32];
    int namSinh;
    Diem diemHocTap;
public:
    Student()
    {
        strcpy(ten,"");
        namSinh = 1900;
    }

    Student(const Student &obj)
    {
        //ten = new char[32];
        strcpy(ten,obj.ten);
        namSinh = obj.namSinh;
        diemHocTap = obj.diemHocTap;
    }

    void input()
    {
        cout << "Ten sinh vien: ";
        fflush(stdin); gets(ten);
        cout << "Nam sinh: ";
        cin >> namSinh;
        cout << "Diem tong ket 3 mon" << endl;
        cout << "\tToan: ";
        cin >> diemHocTap.toan;
        cout << "\tLy: ";
        cin >> diemHocTap.ly;
        cout << "\tHoa: ";
        cin >> diemHocTap.hoa;

    }

    void inputList(Student s[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Sinh vien thu " << i + 1 << endl;
            s[i].input();
        }
    }

    void output()
    {
        cout << setw(25) << ten << setw(13) << namSinh;
        cout << setw(6) << diemHocTap.toan << setw(6) << diemHocTap.ly << setw(6) << diemHocTap.hoa << endl;
    }

    void outputList(Student s[], int n)
    {
        cout << setw(5) << "STT" << setw(25) << "Ten Sinh Vien" << setw(13) << "Nam Sinh";
        cout << setw(18) << "Diem Tong Ket" << endl;
        cout << setw(43) << "" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Hoa" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(5) << i + 1;
            s[i].output();
        }
    }

    double maxDTB(Student s[], int n)
    {
        double max = (s[0].diemHocTap.toan + s[0].diemHocTap.ly + s[0].diemHocTap.hoa) / 3;
        for (int i = 1; i < n; i++)
        {
            if (max < ((s[i].diemHocTap.toan + s[i].diemHocTap.ly + s[i].diemHocTap.hoa) / 3))
            {
                max = (s[i].diemHocTap.toan + s[i].diemHocTap.ly + s[i].diemHocTap.hoa) / 3;
            }
        }
        return max;
    }

    void showMaxDTB(Student s[], int n)
    {
        cout << setw(5) << "STT" << setw(25) << "Ten Sinh Vien" << setw(13) << "Nam Sinh";
        cout << setw(18) << "Diem Tong Ket" << endl;
        cout << setw(43) << "" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Hoa" << endl;
        for (int i = 0; i < n; i++)
        {
            if ((s[i].diemHocTap.toan + s[i].diemHocTap.ly + s[i].diemHocTap.hoa) / 3 == maxDTB(s,n))
            {
                cout << setw(5) << i + 1;
                s[i].output();
            }
        }
    }
};

int main()
{
    Student st[100], s;
    int n;
    do
    {
        cout << "So sinh vien: ";
        cin >> n;
    }while(n < 1 || n > 100);
    cout << "\nNhap danh sach sinh vien" << endl;
    s.inputList(st,n);
    cout << "Danh sach vua nhap" << endl;
    s.outputList(st,n);
    cout << "Danh sach sinh vien co dtb cao nhat" << endl;
    s.showMaxDTB(st,n);

    return 0;
}
