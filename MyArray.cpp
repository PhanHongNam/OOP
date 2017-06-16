#include<iostream>

using namespace std;

class MyArray
{
private:
    int length;
    int *p;
public:
    MyArray(int l = 0)
    {
        length = l;
        p = new int[length];
        for(int i = 0; i < length; i++)
        {
            p[i] = 0;
        }
    }

    ~MyArray()
    {
        delete[] p;
        length = 0;
    }

    friend istream &operator>>(istream &is, MyArray &arr)
    {
        do
        {
            cout << "\nNhap so phan tu cua mang: ";
            is >> arr.length;
        }while(arr.length <= 0);
        delete[] arr.p;
        arr.p = new int[arr.length];
        for(int i = 0; i < arr.length; i++)
        {
            cout << "Arr[" << i << "]= ";
            is >> arr.p[i];
        }

        return is;
    }

    friend ostream &operator<<(ostream &os,const MyArray &arr)
    {
        os << "\nMang co " << arr.length << " phan tu nhu sau" << endl;
        for(int i = 0; i < arr.length; i++)
        {
            os << arr.p[i] << " ";
        }

        return os;
    }

    MyArray operator+(MyArray &arr)
    {
        MyArray mArr;
        if(length == arr.length)
        {
            mArr.length = length;
            delete[] mArr.p;
            mArr.p = new int[mArr.length];
            for(int i = 0; i < mArr.length; i++)
            {
                mArr.p[i] = p[i] + arr.p[i];
            }
        }
        else
        {
            cout << "\nDo so phan tu cua hai mang khong bang nhau nen khong the thuc hien phep cong";
        }
        return mArr;
    }

    MyArray operator-(MyArray &arr)
    {
        MyArray mArr;
        if(length == arr.length)
        {
            mArr.length = length;
            delete[] mArr.p;
            mArr.p = new int[mArr.length];
            for(int i = 0; i < mArr.length; i++)
            {
                mArr.p[i] = p[i] - arr.p[i];
            }
        }
        else
        {
            cout << "\nDo so phan tu cua hai mang khong bang nhau nen khong the thuc hien phep tru";
        }
        return mArr;
    }

    void operator=(const MyArray &arr)
    {
        delete[] p;
        length = arr.length;
        p = new int[length];
        for(int i = 0; i < length; i++)
        {
            p[i] = arr.p[i];
        }
    }

    void sapXepTang()
    {
        for(int i = 0; i < length - 1; i++)
        {
            int k = i;
            for(int j = i + 1; j < length; j++)
            {
                if(p[j] < p[k])
                    k = j;
            }

            if(k != i)
            {
                int temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }

    }

    void sapXepGiam()
    {
        for(int i = 0; i < length - 1; i++)
        {
            int k = i;
            for(int j = i + 1; j < length; j++)
            {
                if(p[j] > p[k])
                    k = j;
            }

            if(k != i)
            {
                int temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }

    }
};

int main()
{
    //Khoi tao 3 mang
    MyArray arr1, arr2(6), arr3;
    //In ra man hinh 3 mang sau khi khoi tao
    cout << arr1 << arr2 << arr3;
    //Nhap 2 mang arr1 va arr2
    cin >> arr1;
    cin >> arr2;
    //arr3 bang tong cua 2 mang vua nhap
    arr3 = arr1 + arr2;
    //In ra arr3
    cout << arr3;
    //arr3 bang hieu cua 2 mang vua nhap
    arr3 = arr1 - arr2;
    //In ra arr3
    cout << arr3;
    //Sap xep lai 2 mang arr1 va arr2
    arr1.sapXepTang();
    arr2.sapXepGiam();
    //In ra 2 mang sau khi sap xep
    cout << arr1 << arr2;

    return 0;
}
