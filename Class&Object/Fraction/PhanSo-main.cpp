#include <iostream>
#include "PhanSo.h"
using namespace std;

int nhap(string s) {
    int x;
    cout << s;
    cin >> x;
    return x;
}

PhanSo doiTuong(PhanSo& ps) {
    int tu1, mau1, tu2, mau2;
start:
    cout << "- Nhap tu so va mau so cua phan so thu nhat: ";
    tu1 = nhap("\n\t+ Tu so: ");
    mau1 = nhap("\t+ Mau so: ");
    cout << "- Nhap tu so va mau so cua phan so thu hai: ";
    tu2 = nhap("\n\t+ Tu so: ");
    mau2 = nhap("\t+ Mau so: ");
    ps.setTu1(tu1);
    ps.setMau1(mau1);
    ps.setTu2(tu2);
    ps.setMau2(mau2);
    if (ps.getMau1() == 0 || ps.getMau2() == 0) {
        system("cls");
        cout << "***Mau so khong hop le (mau so bang 0). Hay nhap lai.\n\n";
        goto start;
    }
    return ps;
}

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void cong(PhanSo& ps) {
    int tu, mau;
    tu = ps.getTu1() * ps.getMau2() + ps.getTu2() * ps.getMau1();
    mau = ps.getMau1() * ps.getMau2();
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    cout << "\n *Ket qua: " << tu << "/" << mau << "\n";
}

void tru(PhanSo& ps) {
    int tu, mau;
    tu = ps.getTu1() * ps.getMau2() - ps.getTu2() * ps.getMau1();
    mau = ps.getMau1() * ps.getMau2();
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    cout << "\n *Ket qua: " << tu << "/" << mau << "\n";
}

void nhan(PhanSo& ps) {
    int tu, mau;
    tu = ps.getTu1() * ps.getTu2();
    mau = ps.getMau1() * ps.getMau2();
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    cout << "\n *Ket qua: " << tu << "/" << mau << "\n";
}

void chia(PhanSo& ps) {
    int tu, mau;
    tu = ps.getTu1() * ps.getMau2();
    mau = ps.getTu2() * ps.getMau1();
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    cout << "\n *Ket qua: " << tu << "/" << mau << "\n";
}

int menu() {
    int choice;
    cout << "\nCHUC NANG:\n";
    cout << "\t1. Cong hai phan so\n";
    cout << "\t2. Tru hai phan so\n";
    cout << "\t3. Nhan hai phan so\n";
    cout << "\t4. Chia hai phan so\n";
    cout << "\t0. Thoat\n";
    cout << "\nLua chon cua ban: ";
    cin >> choice;
    return choice;
}

int main() {
    PhanSo ps;
    cout << "052304013358 - Dang My Linh\n\n";
    int choice;
    do {
        choice = menu();
        switch (choice) {
        case 1: {
            system("cls");
            cout << " Cong hai phan so\n";
            doiTuong(ps);
            cong(ps);
            break;
        }
        case 2: {
            system("cls");
            cout << " Tru hai phan so\n";
            doiTuong(ps);
            tru(ps);
            break;
        }
        case 3: {
            system("cls");
            cout << " Nhan hai phan so\n";
            doiTuong(ps);
            nhan(ps);
            break;
        }
        case 4: {
            system("cls");
            cout << " Chia hai phan so\n";
            doiTuong(ps);
            chia(ps);
            break;
        }
        case 0: {
            system("cls");
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default: {
            system("cls");
            cout << "Lua chon khong hop le.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}