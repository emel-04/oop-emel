#include <iostream>
#include "Rectangle.h"
using namespace std;

int menu() {
	int choice;
	cout << "Hien tai, chung toi co hai du an can ho tai:\n";
	cout << "\t1. Quan Go Vap\n";
	cout << "\t2. Quan 12\n";
	cout << "\t0. Khong co du an ban quan tam.\n";
	cout << "\nDu an ban muon xem: ";
	cin >> choice;
	return choice;
}

int main() {
	cout << "052304013358 - Dang My Linh\n\n";
	cout << "\t\t\tCHAO MUNG BAN DEN VOI BDS Oxyz!!!\n\n\n";
	int choice;
	CRectangle rect1, * rect2;
	choice = menu();
start:
	switch (choice) {
	case 1:
		system("cls");
		rect1.setHeight(3);
		rect1.setWidth(4);
		cout << "\n Du an can ho A tai 123 duong X, phuong Y, quan Go Vap, tp.HCM:\n";
		cout << "\t- Height1: " << rect1.getHeight() << "m" << endl;
		cout << "\t- Width1: " << rect1.getWidth() << "m" << endl;
		cout << "\t*S: " << rect1.area() << "m2" << endl;
		break;
	case 2:
		system("cls");
		rect2 = new CRectangle();
		rect2->setHeight(5);
		rect2->setWidth(4);
		cout << "\n Du an can ho B tai 147 duong X, phuong Y, quan 12, tp.HCM:\n";
		cout << "\t- Height2: " << rect2->getHeight() << "m" << endl;
		cout << "\t- Width2: " << rect2->getWidth() << "m" << endl;
		cout << "\t*S: " << rect2->area() << "m2" << endl;
		break;
	case 0:
		system("cls");
		cout << "\nCam on ban da quan tam den BDS Oxyz, mong se duoc hop tac voi ban trong thoi gian gan nhat!\n";
		cout << "Neu co thac mac gi vui long lien he hotline: 012345678.\n\n";
		break;
	default:
		system("cls");
		cout << "\n!!!Lua chon khong hop le.\n\n";
		break;
	}
	if (choice == 0) { return 0; }
	else if (choice == 1 || choice == 2) {
		int yk;
		cout << "\nBan co muon xem du an con lai?\n\t1. Co\n\t2. Khong\n Y kien cua ban: ";
		cin >> yk;
		system("cls");
		if (yk == 1) {
			if (choice == 1) { choice = 2; }
			else {
				choice = 1;
			}
		}
		else { choice = 0; }
		goto start;
	}
	else {
		choice = menu();
		goto start;
	}

	return 0;
}