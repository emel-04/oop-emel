#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file data.txt\n";
        return 1;
    }
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
        if (line.compare(0, 1, "-") == 0) {
            cout << line << '\n';
        }
    }
    cout << "\nCo " << lineCount << " dong trong file.\n";
    file.close();

    return 0;
}