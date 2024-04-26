#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "Quizz.h"
using namespace std;

int rules() {
	int choice;
	cout << "The le cua tro choi:\n";
    cout << "\t1. Tro choi se bao gom 30 cau hoi voi 5 muc do kho theo qui luat nhu sau:\n";
    cout << "\t    + Do kho cua cau hoi se tang 1 muc neu nguoi choi tra loi dung lien tiep 6 cau hoi.\n";
    cout << "\t    + Do kho cua cau hoi se giam 1 muc neu nguoi choi tra loi sai 1 cau hoi.\n";
    cout << "\t2. Cau hoi se la cac bieu thuc toan hoc co dang:\n";
    cout << "\t    + Level 1: a + b = ? hoac a - b = ? (a, b <= 30)\n";
    cout << "\t    + Level 2: a + b = ? hoac a - b = ? (30 < a, b <= 100)\n";
    cout << "\t    + Level 3: a x b = ? hoac a : b = ? (a, b <= 30)\n";
    cout << "\t    + Level 4: a # b = ? (Voi a, b la phan so, # ngau nhien)\n";
    cout << "\t    + Level 5: Bieu thuc phuc tap tu 2 den 4 phep toan (a, b <= 50)\n";
    cout << "\t3. Nguoi choi se nhap cau tra loi cho tung cau hoi:\n";
    cout << "\t    + Neu dung se duoc cong 1 diem.\n";
    cout << "\t    + Neu sai se khong duoc cong diem.\n";
    cout << "\nBan co muon bat dau tro choi? (Nhan 1: bat dau; 0: thoat) ";
    cin >> choice;
	return choice;
}

void exam() {
    srand(static_cast<unsigned int>(std::time(nullptr)));
start:
    int firstChoice = rules();
    int score = 0;
    int correct = 0;
    int ans;
    Fraction ansF;
    int randomNumber = 10;
    switch (firstChoice) {
    case 1:
        level = 1;
        for (int cau = 1; cau <= 30; cau++) {
            system("cls");
            cout << setfill(' ') << "Level: " << level << setw(50) << "Diem: " << score;
            ArithmeticExpression ques;
            cout << "\n\n\nCau hoi: " << ques << "\n\nDap an cua ban: ";
            if (level <= 3) {
                cin >> ans;
                if (ques.check(ans)) {
                    score++;
                    correct++;
                }
                else if (level > 1) {
                    level--;
                    correct = 0;
                }
                else {
                    correct = 0;
                    level = 1;
                }
            }
            else if (level == 4) {
                cin >> ansF;
                if (ques.check1(ansF)) {
                    score++;
                    correct++;
                }
                else if (level > 1) {
                    level--;
                    correct = 0;
                }
            }
            else if (level == 5) {
                cout << setfill(' ') << "Level: " << level << setw(50) << "Diem: " << score;
                cout << "Em van chua cai dat kip, mong thay thong cam a!";

                break;
            }
            if (correct == 6) {
                correct = 0;
                level++;
            }
        }
        break;
    case 0: break;
    default: goto start;
    }
}

int main() {

    exam();

    return 0;
}