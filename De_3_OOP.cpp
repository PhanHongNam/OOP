#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

class QuanHeGD
{
private:
    char ten[32];
    int namSinh;
    char quanHe[10];

    friend class NhanSu;
};


class NhanSu
{
private:
    char hoTen[32];
    int nS;
    double hSL;
    int soNguoi;
    QuanHeGD *qh;
public:
    void input()
    {
        cout << "Ho ten :";
        fflush(stdin); gets(hoTen);
        //cin.ignore();
        //cin.getline(hoTen,32,'\n');
        cout << "Nam sinh: ";
        cin >> nS;
        cout << "He so luong: ";
        cin >> hSL;
        cout << "So nguoi co quan he voi nhan su: ";
        cin >> soNguoi;
        qh = new QuanHeGD[soNguoi];
        for(int i = 0; i < soNguoi; i++)
        {
            cout << "Nguoi thu " << i+1 << endl;
            cout << "\tHo ten: ";
             fflush(stdin); gets(qh[i].ten);
            //cin.ignore();
            //cin.getline(qh[i].ten,31,'\n');
            cout << "\tNam sinh ";
            cin >> qh[i].namSinh;
            cout << "\tQuan he voi nhan su: ";
            fflush(stdin); gets(qh[i].quanHe);
            //cin.ignore();
            //cin.getline(qh[i].quanHe,9,'\n');
        }
    }

    void inputList(NhanSu ns[], int n)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "Nhan su thu " << j + 1 << endl;
            ns[j].input();
        }
    }

    void output()
    {
        cout << setw(25) << hoTen << setw(13) << nS << setw(13) << hSL;
        cout << setw(25) << "Ho Ten" << setw(13) << "Nam Sinh" << setw(10) << "Quan He" << endl;
        for (int i = 0; i < soNguoi; i++)
        {
            cout << setw(51) << " " << setw(25) << qh[i].ten << setw(13) << qh[i].namSinh << setw(10) << qh[i].quanHe << endl;
        }
    }

    void outputList(NhanSu ns[], int n)
    {
        cout << setw(25) << "Ho Ten" << setw(13) << "Nam Sinh" << setw(13) << "He So Luong";
        cout << setw(30) << "Quan He Gia Dinh" << endl;

        for(int j = 0; j < n; j++)
        {
            ns[j].output();
            cout << endl;
        }
    }

    double minHSL(NhanSu ns[], int n)
    {
        double min = ns[0].hSL;
        for(int i = 1; i < n; i++)
        {
            if (min > ns[i].hSL)
                min = ns[i].hSL;
        }
        return min;
    }

    void showMinHSL(NhanSu ns[], int n)
    {
        cout << setw(25) << "Ho Ten" << setw(13) << "Nam Sinh" << setw(13) << "He So Luong";
        cout << setw(30) << "Quan He Gia Dinh" << endl;
        for(int i = 0; i < n; i++)
        {
            if(ns[i].hSL == minHSL(ns,n))
            ns[i].output();
        }
    }
};

int main()
{
    int n;
    NhanSu ns[100], nss;
    do
    {
        cout << "So luong nhan su: ";
        cin >> n;
    }while (n < 1 || n > 100);
    cout << "Nhap thong tin:" << endl;
    ns[1].inputList(ns,n);
    cout << "Danh sach vua nhap:" << endl;
    ns[30].outputList(ns,n);
    cout << "\nCac nhan su co HSL nho nhat :" << endl;
    ns[1].showMinHSL(ns,n);
}
