/* Topological sorting */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <vector>

#define MAX 20

using namespace std;

int n, adj[MAX][MAX];
vector<int> queue;
vector<int> topsort;
vector<int> indeg(MAX, 0);

void create_graph();
void display();
void insert_queue(int node);
int delete_queue();
int indegree(int node);

int main() {
    cout << "\n\tTopological sorting of a graph\n";
    cout << "\t*******************************\n\n";
    create_graph();
    cout << "\nAdjacency matrix of the graph is:\n\n";
    display();

    // Find the indegree of each node
    for (int i = 1; i <= n; ++i) {
        indeg[i] = indegree(i);
        if (indeg[i] == 0)
            insert_queue(i);
    }

    while (!queue.empty()) { // Loop till queue is not empty
        int k = delete_queue();
        topsort.push_back(k); // Add node k to array

        // Delete all edges going from node k
        for (int i = 1; i <= n; ++i) {
            if (adj[k][i] == 1) {
                adj[k][i] = 0;
                indeg[i]--;
                if (indeg[i] == 0)
                    insert_queue(i);
            }
        }
    }

    cout << "\nNodes after topological sorting are:\n";
    cout << "____________________________________\n\n";
    for (const int& node : topsort)
        cout << node << " ";
    cout << endl;

    return 0;
}

void create_graph() {
    int max_edges, origin, dest;

    cout << "Enter number of vertices: ";
    cin >> n;
    max_edges = n * (n - 1);

    for (int i = 1; i <= max_edges; ++i) {
        cout << "Enter edge " << i << " (0 0 to quit): ";
        cin >> origin >> dest;

        if (origin == 0 && dest == 0)
            break;

        if (origin > n || dest > n || origin <= 0 || dest <= 0) {
            cout << "Invalid edge!" << endl;
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

void insert_queue(int node) {
    if (queue.size() >= MAX) {
        cout << "Queue Overflow" << endl;
    } else {
        queue.push_back(node);
    }
}

int delete_queue() {
    if (queue.empty()) {
        cout << "Queue Underflow" << endl;
        return 0;
    } else {
        int del_item = queue.front();
        queue.erase(queue.begin());
        return del_item;
    }
}

int indegree(int node) {
    int in_deg = 0;
    for (int i = 1; i <= n; ++i)
        if (adj[i][node] == 1)
            in_deg++;
    return in_deg;
}
