/* Program for traversing a graph through BFS */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <vector>
#include <queue>

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
void bfs(int start);
void adj_nodes(int v);

int main() {
    int choice, v;

    cout << "\n\tTraversing of a graph through BFS\n";
    cout << "\t**********************************\n\n";
    create_graph();

    while (true) {
        cout << "\n";
        cout << "1. Adjacency matrix\n";
        cout << "2. Breadth First Search\n";
        cout << "3. Adjacent vertices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Adjacency Matrix\n";
                display();
                break;

            case 2:
                cout << "Enter starting node for Breadth First Search: ";
                cin >> v;
                fill(visited.begin(), visited.end(), Bool::False);
                bfs(v);
                break;

            case 3:
                cout << "Enter node to find adjacent vertices: ";
                cin >> v;
                cout << "Adjacent Vertices are: ";
                adj_nodes(v);
                break;

            case 4:
                return 0;

            default:
                cout << "Wrong choice\n";
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

void bfs(int start) {
    vector<int> queue;
    queue.push_back(start);
    visited[start] = Bool::True;

    cout << start << " ";

    while (!queue.empty()) {
        int v = queue.front(); // Delete from queue
        queue.erase(queue.begin());

        for (int i = 1; i <= n; ++i) {
            if (adj[v][i] == 1 && visited[i] == Bool::False) {
                cout << i << " ";
                visited[i] = Bool::True;
                queue.push_back(i);
            }
        }
    }
    cout << endl;
}

void adj_nodes(int v) {
    for (int i = 1; i <= n; ++i) {
        if (adj[v][i] == 1)
            cout << i << " ";
    }
    cout << endl;
}
