/* Sort a list of N string using insertion sort */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int i = 0, j, k, m;
    char fname[10], name[200][30], s[30];
    ifstream fp;

    cout << "Enter the file name: ";
    cin >> fname;

    fp.open(fname);
    if (!fp) {
        cout << "Can't open file " << fname << endl;
        exit(0);
    }

    cout << "The names in " << fname << " file are:" << endl;
    while (fp >> s) {
        strcpy(name[i++], s);
        cout << s << " ";
    }
    m = i;

    cout << "\nThe sorted order is:" << endl;
    for (j = 0; j < m; j++) {
        strcpy(s, name[j]);
        for (k = j - 1; (k >= 0 && strcmp(name[k], s) > 0); k--) {
            strcpy(name[k + 1], name[k]);
        }
        strcpy(name[k + 1], s);
    }

    for (i = 0; i < m; i++)
        cout << name[i] << endl;

    fp.close();
    return 0;
}
