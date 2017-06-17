#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>

using namespace std;

class Date
{
private:
    int ngay, thang, nam;
public:
    void nhap()
    {
        cout << "Ngay: ";
        cin >> ngay;
        cout << "Thang: ";
        cin >> thang;
        cout << "Nam: ";
        cin >> nam;
    }

    void xuat()
    {
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class PhieuHangHoa
{
private:
    char maPhieu[10];
    Date ngay;
    char nguoiLap[10];
    char tenNguoiLap[25];
public:
    void nhap()
    {
        cout << "Nhap thong tin Phieu Hang" << endl;
        cout << "Ma phieu: ";
        fflush(stdin); gets(maPhieu);
        ngay.nhap();
        cout << "Nguoi lap: ";
        fflush(stdin); gets(nguoiLap);
        cout << "Ten nguoi lap: ";
        fflush(stdin); gets(tenNguoiLap);
    }

    void xuat()
    {
        cout << "Ma Phieu:" << setw(11) << "" << maPhieu << setw(5) << "" << "Ngay lap:" << setw(7) << "";
        ngay.xuat();
        cout << "\nNguoi lap:" << setw(10) << "" << nguoiLap << setw(5) << "" << "Ho Ten:" << setw(9) << "" << tenNguoiLap << endl;
    }

};

class HangHoa
{
private:
    char maHang[10], tenHang[10];
    int soLuong, donGia, thanhTien, soHangHoa;
public:
    int tongThanhTien = 0;
    HangHoa *hh;
    void nhap()
    {
        cout << "Nhap thong tin Hang Hoa" << endl;
        do
        {
            cout << "Nhap so luong Hang Hoa: ";
            cin >> soHangHoa;
        }while(soHangHoa <= 0);
        hh = new HangHoa[soHangHoa];
        for(int i = 0; i < soHangHoa; i++)
        {
            cout << "Ma hang: ";
            fflush(stdin); gets(hh[i].maHang);
            cout << "Ten hang: ";
            fflush(stdin); gets(hh[i].tenHang);
            cout << "So luong: ";
            cin >> hh[i].soLuong;
            cout << "Don gia: ";
            cin >> hh[i].donGia;
            hh[i].thanhTien = hh[i].donGia * hh[i].soLuong;
            tongThanhTien += hh[i].thanhTien;
        }
    }

    void xuat()
    {
        cout << "Ma Hang" << setw(7) << "" << "Ten Hang " << "So luong ";
        cout << "Don Gia" << setw(9) << "" << "Thanh Tien" << setw(5) << "" << endl;
        for(int i = 0; i < soHangHoa; i++)
        {
            cout << hh[i].maHang << setw(7) << "" << setw(9) << hh[i].tenHang << setw(9) << hh[i].soLuong;
            cout << setw(10) << hh[i].donGia << setw(19) << hh[i].thanhTien << endl;
        }
        cout << "Tong Thanh Tien:" << setw(30) << tongThanhTien << endl;
    }
};

class CongTy
{
private:
    char tenCongTy[25];
    PhieuHangHoa phh;
    HangHoa hh;
public:
    void nhap()
    {
        cout << "Ten cong ty: ";
        fflush(stdin); gets(tenCongTy);
        phh.nhap();
        hh.nhap();
    }

    void xuat()
    {
        cout << setw(30) << "Cong Ty " << tenCongTy << endl;
        cout << setw(35) << "Phieu Hang Hoa"  <<  endl;
        phh.xuat();
        cout << "Thong tin Hang Hoa"  << endl;
        hh.xuat();
        cout << "Truong Don Vi " << "Thu Ky " << "Thu Quy" << " Nguoi Lap Phieu" << endl;
    }
};

int main()
{
    CongTy ct;
    ct.nhap();
    ct.xuat();

    return 0;
}
