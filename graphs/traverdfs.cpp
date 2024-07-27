/* Program for traversing a graph through DFS */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <vector>
#include <stack>

#define MAX 20

using namespace std;

enum class Bool {
    False,
    True
};

int adj[MAX][MAX];
vector<Bool> visited(MAX, Bool::False);
int n;

void create_graph();
void display();
void dfs(int start);
void dfs_rec(int start);
void components();

int main() {
    int choice, v;

    cout << "\n\tTraversing of a graph through DFS\n";
    cout << "\t**********************************\n\n";
    create_graph();

    while (true) {
        cout << "\n";
        cout << "1. Adjacency matrix\n";
        cout << "2. Depth First Search using stack\n";
        cout << "3. Depth First Search through recursion\n";
        cout << "4. Number of components\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Adjacency Matrix is\n";
                display();
                break;

            case 2:
                cout << "Enter starting node: ";
                cin >> v;
                fill(visited.begin(), visited.end(), Bool::False);
                dfs(v);
                break;

            case 3:
                cout << "Enter starting node: ";
                cin >> v;
                fill(visited.begin(), visited.end(), Bool::False);
                dfs_rec(v);
                cout << endl;
                break;

            case 4:
                cout << "Components are: ";
                components();
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Enter a correct choice\n";
                break;
        }
    }

    return 0;
}

void create_graph() {
    int max_edges, origin, dest;

    cout << "Enter number of nodes: ";
    cin >> n;
    max_edges = n * (n - 1);

    for (int i = 1; i <= max_edges; ++i) {
        cout << "Enter edge " << i << " (0 0 to quit): ";
        cin >> origin >> dest;

        if (origin == 0 && dest == 0)
            break;

        if (origin > n || dest > n || origin <= 0 || dest <= 0) {
            cout << "Invalid edge!\n";
            --i;
        } else {
            adj[origin][dest] = 1;
        }
    }
}

void display() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void dfs_rec(int start) {
    visited[start] = Bool::True;
    cout << start << " ";
    for (int i = 1; i <= n; ++i) {
        if (adj[start][i] == 1 && visited[i] == Bool::False) {
            dfs_rec(i);
        }
    }
}

void dfs(int start) {
    stack<int> stk;
    stk.push(start);
    visited[start] = Bool::True;

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();

        cout << v << " ";

        for (int i = n; i >= 1; --i) {
            if (adj[v][i] == 1 && visited[i] == Bool::False) {
                stk.push(i);
                visited[i] = Bool::True;
            }
        }
    }
    cout << endl;
}

void components() {
    int component_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == Bool::False) {
            dfs_rec(i);
            ++component_count;
        }
    }
    cout << "\nTotal number of components: " << component_count << endl;
}
