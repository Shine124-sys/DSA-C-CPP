/* Insert keys into an array with double hashing technique of collision resolution technique. */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <vector>

#define MAX 10

std::vector<int> a(MAX, -1);

void dh(int key, std::vector<int>& a);
void dhsr(int key, const std::vector<int>& a);
void display(const std::vector<int>& a);

int main() {
    int key, ch;

    do {
        std::cout << "\n\n Program for insertion/searching keys with double hashing ";
        std::cout << "\n************************************************************\n\n";
        std::cout << "\n 1. Insert keys ";
        std::cout << "\n 2. Search key ";
        std::cout << "\n 3. Display keys ";
        std::cout << "\n 4. Exit ";
        std::cout << "\n Select operation ";
        std::cin >> ch;

        switch (ch) {
        case 1:
            do {
                std::cout << "\n Enter key value [type -1 for termination] ";
                std::cin >> key;
                if (key != -1)
                    dh(key, a);
            } while (key != -1);
            break;
        case 2:
            std::cout << "\n Enter search key value ";
            std::cin >> key;
            dhsr(key, a);
            break;
        case 3:
            display(a);
            break;
        }
    } while (ch != 4);

    return 0;
}

/* Find the location for a key and insert it */
void dh(int key, std::vector<int>& a) {
    int loc, i = 0;
    loc = key % MAX;
    while (a[loc] != -1) // -1 indicates an empty location
        loc = (loc + ++i * (key % (MAX - 1))) % MAX;
    a[loc] = key;
    display(a);
}

/* Find the location for a key */
void dhsr(int key, const std::vector<int>& a) {
    int loc, i = 0;
    loc = key % MAX;
    while ((a[loc] != key) && (a[loc] != -1))
        loc = (loc + ++i * (key % (MAX - 1))) % MAX;
    if (a[loc] == key)
        std::cout << "\n Search successful at index " << loc;
    else
        std::cout << "\n Search unsuccessful ";
}

void display(const std::vector<int>& a) {
    std::cout << "\n List of keys, -1 indicates that the location is empty \n";
    for (int i = 0; i < MAX; i++)
        std::cout << " " << a[i] << " ";
    std::cout << std::endl;
}
