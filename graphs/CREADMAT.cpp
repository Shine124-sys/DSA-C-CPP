/* Program for creation of Graph through adjacency matrix */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <vector>

#define MAX 20

using namespace std;

int main() {
    int adj[MAX][MAX] = {0};
    int n;
    int max_edges, origin, dest;
    char type;

    cout << "Enter number of nodes in graph: ";
    cin >> n;

    cout << "Enter type of graph, directed or undirected (d/u): ";
    cin >> type;

    if (type == 'u') {
        max_edges = n * (n - 1) / 2;
    } else {
        max_edges = n * (n - 1);
    }

    for (int i = 1; i <= max_edges; ++i) {
        cout << "Enter edge " << i << " (0 0 to Quit): ";
        cin >> origin >> dest;

        if (origin == 0 && dest == 0) {
            break;
        }

        if (origin > n || dest > n || origin <= 0 || dest <= 0) {
            cout << "Invalid edge!" << endl;
            --i;
        } else {
            adj[origin][dest] = 1;
            if (type == 'u') {
                adj[dest][origin] = 1;
            }
        }
    }

    cout << "The adjacency matrix of the graph is:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
