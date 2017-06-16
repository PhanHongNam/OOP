
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

    double getDTB()
    {
        double dtb = (toan + ly + hoa)/3;
        dtb = (int)(dtb * 100);
        dtb = dtb + 5;
        dtb = dtb / 100;
        return dtb;
    }
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

    void inputList(Student s[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Sinh vien thu " << i + 1 << endl;
            cin >> s[i];
        }
    }

    void outputList(Student s[], int n)
    {
        cout << setw(5) << "STT" << setw(25) << "Ten Sinh Vien" << setw(13) << "Nam Sinh";
        cout << setw(18) << "Diem Tong Ket" << setw(6) << "DTB" << endl;
        cout << setw(43) << "" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Hoa" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(5) << i + 1;
            cout << s[i];
        }
    }

    double maxDTB(Student s[], int n)
    {
        double max = s[0].diemHocTap.getDTB();
        for (int i = 1; i < n; i++)
        {
            if (max < s[i].diemHocTap.getDTB())
            {
                max = s[i].diemHocTap.getDTB();
            }
        }
        return max;
    }

    void showMaxDTB(Student s[], int n)
    {
        cout << setw(5) << "STT" << setw(25) << "Ten Sinh Vien" << setw(13) << "Nam Sinh";
        cout << setw(18) << "Diem Tong Ket" << setw(6) << "DTB" << endl;
        cout << setw(43) << "" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Hoa" << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i].diemHocTap.getDTB() == maxDTB(s,n))
            {
                cout << setw(5) << i + 1;
                cout << s[i];
            }
        }
    }

    friend istream& operator>>(istream &is, Student &s)
    {
        double d;
        cout << "Ten sinh vien: ";
        fflush(stdin); gets(s.ten);
        cout << "Nam sinh: ";
        is >> s.namSinh;
        cout << "Diem tong ket 3 mon" << endl;
        cout << "\tToan: ";
        cin >> d;
        s.diemHocTap.setToan(d);
        cout << "\tLy: ";
        cin >> d;
        s.diemHocTap.setLy(d);
        cout << "\tHoa: ";
        cin >> d;
        s.diemHocTap.setHoa(d);

        return is;
    }

    friend ostream& operator<<(ostream &os, Student &s)
    {
        os << setw(25) << s.ten << setw(13) << s.namSinh;
        os << setw(6) << s.diemHocTap.getToan() << setw(6) << s.diemHocTap.getLy() << setw(6) << s.diemHocTap.getHoa();
        os << setw(6) << s.diemHocTap.getDTB() << endl;

        return os;
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
