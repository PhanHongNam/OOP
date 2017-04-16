#include<stdio.h>
#include<iomanip>
#include<iostream>

using namespace std;

class Sach
{
protected:
    char tenSach[30];
    char tacGia[25];
    int soTrang;
    long giaBan;
public:
    void nhap()
    {
        cout << "Ten sach: ";
        fflush(stdin); gets(tenSach);
        cout << "Tac gia: ";
        fflush(stdin); gets(tacGia);
        cout << "So trang: ";
        cin >> soTrang;
        cout << "Gia ban: ";
        cin >> giaBan;
    }

    void nhapDS(Sach s[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nSach thu " << i + 1 << endl;
            s[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(30) << tenSach << setw(25) << tacGia;
        cout << setw(10) << soTrang << setw(10) << giaBan << endl;
    }

    void xuatDS(Sach s[], int n)
    {
        cout << endl;
        cout << setw(3) << "STT" << setw(30) << "Ten Sach" << setw(25) << "Tac Gia";
        cout << setw(10) << "So Trang" << setw(10) << "Gia Ban" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(3) << i + 1;
            s[i].xuat();
        }
    }
};

class Bia : protected Sach
{
protected:
    char maHinhAnh[14];
    long tienVe;
public:
    void nhap()
    {
        cout << "Ten sach: ";
        fflush(stdin); gets(tenSach);
        cout << "Tac gia: ";
        fflush(stdin); gets(tacGia);
        cout << "So trang: ";
        cin >> soTrang;
        cout << "Gia ban: ";
        cin >> giaBan;
        cout << "Ma hinh anh: ";
        fflush(stdin); gets(maHinhAnh);
        cout << "Tien ve: ";
        cin >> tienVe;
    }

    void nhapDS(Bia b[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Sach thu " << i + 1 << endl;
            b[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(30) << tenSach << setw(25) << tacGia;
        cout << setw(10) << soTrang << setw(10) << giaBan;
        cout << setw(14) << maHinhAnh << setw(15) << tienVe;
    }

    void xuatDS(Bia b[], int n)
    {
        cout << endl;
        cout << setw(3) << "STT" << setw(30) << "Ten Sach" << setw(25) << "Tac Gia";
        cout << setw(10) << "So Trang" << setw(10) << "Gia Ban";
        cout << setw(14) << "Ma Hinh Anh" << setw(15) << "Tien Ve" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(3) << i + 1;
            b[i].xuat();
        }
    }
};

class HoaSy
{
protected:
    char tenHoaSy[25];
    char diaChi[25];
public:
    void nhap()
    {
        cout << "Ten hoa sy: ";
        fflush(stdin); gets(tenHoaSy);
        cout << "Dia chi: ";
        fflush(stdin); gets(diaChi);
    }

    void xuat()
    {
        cout << setw(25) << tenHoaSy << setw(25) << diaChi;
    }
};

class SachVeBia : private Bia, private HoaSy
{
public:
    void nhap()
    {
        cout << "Ten sach: ";
        fflush(stdin); gets(tenSach);
        cout << "Tac gia: ";
        fflush(stdin); gets(tacGia);
        cout << "So trang: ";
        cin >> soTrang;
        cout << "Gia ban: ";
        cin >> giaBan;
        cout << "Ma hinh anh: ";
        fflush(stdin); gets(maHinhAnh);
        cout << "Tien ve: ";
        cin >> tienVe;
        cout << "Ten hoa sy: ";
        fflush(stdin); gets(tenHoaSy);
        cout << "Dia chi: ";
        fflush(stdin); gets(diaChi);
    }

    void nhapDS(SachVeBia svb[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nSach thu " << i + 1 << endl;
            svb[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(30) << tenSach << setw(25) << tacGia;
        cout << setw(10) << soTrang << setw(10) << giaBan;
        cout << setw(14) << maHinhAnh << setw(15) << tienVe;
        cout << setw(25) << tenHoaSy << setw(25) << diaChi << endl;
    }

    void xuatDS(SachVeBia svb[], int n)
    {
        cout << endl;
        cout << setw(3) << "STT" << setw(30) << "Ten Sach" << setw(25) << "Tac Gia";
        cout << setw(10) << "So Trang" << setw(10) << "Gia Ban";
        cout << setw(14) << "Ma Hinh Anh" << setw(15) << "Tien Ve";
        cout << setw(25) << "Ten Hoa Sy" << setw(25) << "Dia Chi Hoa Sy" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(3) << i + 1;
            svb[i].xuat();
        }
    }

    friend long tienVeBiaMin(SachVeBia svb[], int n);
    friend void danhSachSachVeBiaMin(SachVeBia svb[], int n);
};

long tienVeBiaMin(SachVeBia svb[], int n)
{
    long min  = svb[0].tienVe;
    for (int i = 1; i < n; i++)
        if (svb[i].tienVe < min)
            min = svb[i].tienVe;

    return min;
}

void danhSachSachVeBiaMin(SachVeBia svb[], int n)
{
    cout << endl;
    cout << setw(3) << "STT" << setw(30) << "Ten Sach" << setw(25) << "Tac Gia";
    cout << setw(10) << "So Trang" << setw(10) << "Gia Ban";
    cout << setw(14) << "Ma Hinh Anh" << setw(15) << "Tien Ve";
    cout << setw(25) << "Ten Hoa Sy" << setw(25) << "Dia Chi Hoa Sy" << endl;
    for (int i = 0; i < n; i++)
    {
        if (svb[i].tienVe == tienVeBiaMin(svb,n))
        {
            cout << setw(3) << i + 1;
            svb[i].xuat();
        }
    }
}

int main()
{
    Sach s[100];
    SachVeBia svb[100];
    int m, n;
    do
    {
        cout << "\nSo sach khong bia: ";
        cin >> m;
    }while  (m < 1 || m > 100);
    do
    {
        cout << "\nSo sach ve bia: ";
        cin >> n;
    }while(n < 1 || n > 100);
    cout << "\nNhap thong tin sach khong bia" << endl;
    s[1].nhapDS(s,m);
    cout << "\nNhap thong tin sach ve bia: " << endl;
    svb[1].nhapDS(svb,n);
    cout << "\nDanh sach sach khong bia: ";
    s[1].xuatDS(s,m);
    cout << "\nDanh sach sach ve bia: ";
    svb[1].xuatDS(svb,n);
    cout << "\nCac sach co so tien ve bia it nhat: ";
    danhSachSachVeBiaMin(svb,n);

    return 0;
}
