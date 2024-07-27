/* Insert keys into an array with linear probing technique of collision resolution technique. */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <vector>

#define MAX 10

std::vector<int> a(MAX, -1);

void lp(int key, std::vector<int>& a);
void lpsr(int key, const std::vector<int>& a);
void display(const std::vector<int>& a);

int main() {
    int key, ch;

    do {
        std::cout << "\n\n Program for insertion/searching keys with linear probing ";
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
                    lp(key, a);
            } while (key != -1);
            display(a);
            break;
        case 2:
            std::cout << "\n Enter search key value ";
            std::cin >> key;
            lpsr(key, a);
            break;
        case 3:
            display(a);
            break;
        }
    } while (ch != 4);

    return 0;
}

/* function lp finds a location for a key and inserts it */
void lp(int key, std::vector<int>& a) {
    int loc = key % MAX;
    while (a[loc] != -1) // -1 indicates an empty location
        loc = (loc + 1) % MAX;
    a[loc] = key;
}

/* function lpsr finds a location for a key */
void lpsr(int key, const std::vector<int>& a) {
    int loc = key % MAX;
    while ((a[loc] != key) && (a[loc] != -1))
        loc = (loc + 1) % MAX;
    if (a[loc] == key)
        std::cout << "\n Search successful at index " << loc;
    else
        std::cout << "\n Search unsuccessful ";
}

void display(const std::vector<int>& a) {
    std::cout << "\n List of keys (-1 indicates that the location is empty): \n";
    for (int i = 0; i < MAX; ++i)
        std::cout << " " << a[i] << " ";
    std::cout << std::endl;
}
