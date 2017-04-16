#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

class SanPham
{
protected:
    char tenSP[25];
    int namSX;
    long giaThanh;
public:
    void nhap()
    {
        cout << "Ten san pham: ";
        fflush(stdin); gets(tenSP);
        cout << "Nam san xuat: ";
        cin >> namSX;
        cout << "Gia thanh: ";
        cin >> giaThanh;
    }

    void xuat()
    {
        cout << setw(25) << tenSP << setw(10) << namSX << setw(20) << giaThanh << endl;
    }


};

class HoaDon : private SanPham
{
private:
    int soLuong;
    long giaBan;
public:
    void nhap()
    {
        cout << "Ten san pham: ";
        fflush(stdin); gets(tenSP);
        cout << "Nam san xuat: ";
        cin >> namSX;
        cout << "Gia thanh: ";
        cin >> giaThanh;
        cout << "So luong: ";
        cin >> soLuong;
        cout << "Gia ban: ";
        cin >> giaBan;
    }

    void nhapDS(HoaDon hd[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nHoa don thu " << i + 1 << endl;
            hd[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(25) << tenSP << setw(15) << giaThanh;
        cout << setw(10) << soLuong  << setw(15) << giaBan;
        cout << setw(15) << thanhTien() << setw(10) << tinhThue();
        cout << setw(15) << tinhLai() << endl;
    }

    void xuatDS(HoaDon hd[], int n)
    {
        cout << endl;
        cout << setw(5) <<  "STT" << setw(25)  << "Ten San Pham" << setw(15) << "Gia Thanh";
        cout <<  setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
        cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
        for(int i = 0; i < n; i++)
        {
            cout << setw(5) << i + 1;
            hd[i].xuat();
        }
    }

    long thanhTien()
    {
        return soLuong * giaBan;
    }

    long tinhThue()
    {
        return thanhTien() * 10 / 100;
    }

    long tinhLai()
    {
        return (giaBan - giaThanh) * soLuong;
    }

    friend void sapXepTienLaiGiam(HoaDon hd[], int n);
    friend long tienThueCaoNhat(HoaDon hd[], int n);
    friend void danhDachTienThueCaoNhat(HoaDon hd[], int n);
};

void sapXepTienLaiGiam(HoaDon hd[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (hd[j].tinhLai() > hd[j-1].tinhLai())
            {
                HoaDon temp = hd[j];
                hd[j] = hd[j-1];
                hd[j-1] = temp;
            }
        }
    }
}

long tongTienHoaDon(HoaDon hd[], int n)
{
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong = tong + hd[i].thanhTien();
    }
    return tong;
}

long tienThueCaoNhat(HoaDon hd[], int n)
{
    long max = hd[0].tinhThue();
    for (int i = 1; i < n; i++)
    {
        if (hd[i].tinhThue() > max)
            max = hd[i].tinhThue();
    }
    return max;
}

void danhDachTienThueCaoNhat(HoaDon hd[], int n)
{
    cout << endl;
    cout << setw(5) <<  "STT" << setw(25)  << "Ten San Pham" << setw(15) << "Gia Thanh";
    cout <<  setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
    cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
    for (int i = 0; i < n; i++)
    {
        if (hd[i].tinhThue() == tienThueCaoNhat(hd,n))
        {
            cout << setw(5) << "STT";
            hd[i].xuat();
        }
    }
}

int main()
{
    HoaDon hd[100];
    int n;
    do
    {
        cout << "\nSo hoa don: ";
        cin >> n;
    }while  (n < 1 || n > 100);
    cout << "\nNhap thong tin cac hoa don:" << endl;
    hd[1].nhapDS(hd,n);
    sapXepTienLaiGiam(hd,n);
    cout << "\nDanh sach hoa don sau khi sap xep tien lai giam dan" << endl;
    hd[2].xuatDS(hd,n);
    cout << "\nTong tien cac hoa don: " << setw(47) << "" << setw(15) << tongTienHoaDon(hd,n) << endl;
    cout << "\nCac hoa don co tien thue cao nhat " << endl;
    danhDachTienThueCaoNhat(hd,n);

    return 0;
}
