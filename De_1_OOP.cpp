#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(int t = 0, int m = 1)
    {
        tu = t;
        mau = m;
    }

    PhanSo(const PhanSo &obj)
    {
        tu = obj.tu;
        mau = obj.mau;
    }

    PhanSo operator+(PhanSo &obj)
    {
        int t = tu * obj.mau + obj.tu * mau;
        int m = mau * obj.mau;
        return PhanSo(t,m);
    }

    PhanSo operator-(PhanSo &obj)
    {
        int t = tu * obj.mau - obj.tu * mau;
        int m = mau * obj.mau;
        return PhanSo(t,m);
    }

    PhanSo operator*(PhanSo &obj)
    {
        int t = tu * obj.tu;
        int m = mau * obj.mau;
        return PhanSo(t,m);
    }

    PhanSo operator/(PhanSo &obj)
    {
        int t = tu * obj.mau;
        int m = mau * obj.tu;
        return PhanSo(t,m);
    }

    PhanSo operator-()
    {
        if (tu * mau < 0)
            return PhanSo(abs(tu),abs(mau));
        return PhanSo(-tu,mau);
    }

    PhanSo operator!()
    {
        return PhanSo(mau,tu);
    }

    void operator=(const PhanSo &obj)
    {
        tu = obj.tu;
        mau = obj.mau;
    }

    int ucln()
    {
        int a = tu, b = mau;
        if (a == b) return a;
        while (a % b != 0)
        {
              int r = a % b;
              a = b;
              b = r;
        }
        return b;
    }

    void toiGian()
    {
        int uc = ucln();
        tu = tu / uc;
        mau = mau / uc;
    }

    bool operator==(PhanSo &obj)
    {
        toiGian();
        obj.toiGian();
        if (tu == obj.tu && mau == obj.mau)
            return true;
        return false;
    }

    bool operator!=(PhanSo &obj)
    {
        toiGian();
        obj.toiGian();
        if (tu != obj.tu || mau != obj.mau)
            return true;
        return false;
    }

    bool operator>=(PhanSo &obj)
    {
        int t1 = tu * obj.mau;
        int t2 = obj.tu * mau;
        if (t1 >= t2)
            return true;
        return false;
    }

    bool operator<(PhanSo &obj)
    {
        int t1 = tu * obj.mau;
        int t2 = obj.tu * mau;
        if (t1 < t2)
            return true;
        return false;
    }

    friend istream& operator>>(istream &is, PhanSo &ps);
    friend ostream& operator<<(ostream &os,const PhanSo &ps);
};

istream& operator>>(istream &is, PhanSo &ps)
{
    cout << "Tu so ";
    is >> ps.tu;
    cout << "Mau so ";
    is >> ps.mau;
    return is;
}

ostream& operator<<(ostream &os, const PhanSo &ps)
{
    if (ps.tu % ps.mau == 0)
        os << ps.tu << "/" << ps.mau << "(" << ps.tu/ps.mau  << ")";
    else os << ps.tu << "/" << ps.mau;
}

int main()
{
    PhanSo a, b, c, d, e;
    cout << "Nhap 2 phan so" << endl;
    cin >> a >> b;
    cout << "\nTong 2 phan so: ";
    c = a + b;
    cout << c;
    cout << "\nHieu 2 phan so: ";
    c = a - b;
    cout << c;
    cout << "\nTich 2 phan so: ";
    c = a * b;
    cout << c;
    cout << "\nThuong 2 phan so: ";
    c = a / b;
    cout << c;
    cout << "\nNhap phan so d" << endl;
    cin >> d;
    cout << "\nDao dau phan so d: ";
    cout << -d;
    cout << "\nNgich dao phan so d: ";
    cout << !d;
    cout << "\nPhan so e hien tai: ";
    cout << e;
    cout << "\nGan e bang d: ";
    e = d;
    cout << "e = " << e;
    cout << "\nGan e bang a: ";
    e = a;
    cout << "e = " << e;
    if (e == d)
        cout << "\ne bang d";
    if (e != d)
        cout << "\ne khac d";
    if (e >= d)
        cout << "\ne lon hon hoac bang d";
    if (e < d)
        cout << "\ne be thua d";

    return 0;
}
