/* Creating a MST from Kruskal's algorithm */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 20

using namespace std;

struct Edge {
    int u, v, weight;
    Edge* link;
};

Edge* front = nullptr;
int parent[MAX]; // Holds parent of each node
Edge tree[MAX];  // Will contain the edges of spanning tree
int n;           // Denotes total number of nodes in the graph
int wt = 0;      // Weight of the spanning tree
int count = 0;   // Denotes number of edges included in the tree

void create_graph();
void make_tree();
void insert_tree(int i, int j, int wt);
void insert_pque(int i, int j, int wt);
Edge* del_pque();

int main() {
    cout << "\n\t MST from Kruskal's algorithm \n";
    cout << "\t**************************\n\n";
    create_graph();
    make_tree();
    cout << "\nEdges to be included in spanning tree are:\n";
    for (int i = 1; i <= count; ++i) {
        cout << tree[i].u << "->" << tree[i].v << endl;
    }
    cout << "\nWeight of this MST is: " << wt << endl;
    return 0;
}

void create_graph() {
    int wt, max_edges, origin, dest;
    cout << "Enter number of nodes: ";
    cin >> n;
    max_edges = (n * (n - 1)) / 2;
    
    for (int i = 1; i <= max_edges; ++i) {
        cout << "Enter edge " << i << " (0 0 to quit): ";
        cin >> origin >> dest;
        if (origin == 0 && dest == 0)
            break;
        cout << "Enter weight for this edge: ";
        cin >> wt;
        if (origin > n || dest > n || origin <= 0 || dest <= 0) {
            cout << "Invalid edge!" << endl;
            --i;
        } else {
            insert_pque(origin, dest, wt);
        }
    }
    if (count < n - 1) {
        cout << "Spanning tree is not possible" << endl;
        exit(1);
    }
}

void make_tree() {
    Edge* tmp;
    int node1, node2, root_n1, root_n2;

    while (count < n - 1) { // Loop till n-1 edges are included in the tree
        tmp = del_pque();
        node1 = tmp->u;
        node2 = tmp->v;

        cout << "n1=" << node1 << "  ";
        cout << "n2=" << node2 << "  ";

        while (node1 > 0) {
            root_n1 = node1;
            node1 = parent[node1];
        }
        while (node2 > 0) {
            root_n2 = node2;
            node2 = parent[node2];
        }
        cout << "rootn1=" << root_n1 << "  ";
        cout << "rootn2=" << root_n2 << endl;

        if (root_n1 != root_n2) {
            insert_tree(tmp->u, tmp->v, tmp->weight);
            wt += tmp->weight;
            parent[root_n2] = root_n1;
        }
    }
}

void insert_tree(int i, int j, int wt) {
    cout << "This edge inserted in the spanning tree" << endl;
    ++count;
    tree[count].u = i;
    tree[count].v = j;
    tree[count].weight = wt;
}

void insert_pque(int i, int j, int wt) {
    Edge* tmp = new Edge;
    Edge* q;

    tmp->u = i;
    tmp->v = j;
    tmp->weight = wt;

    // Queue is empty or edge to be added has weight less than first edge
    if (front == nullptr || tmp->weight < front->weight) {
        tmp->link = front;
        front = tmp;
    } else {
        q = front;
        while (q->link != nullptr && q->link->weight <= tmp->weight) {
            q = q->link;
        }
        tmp->link = q->link;
        q->link = tmp;
    }
}

Edge* del_pque() {
    Edge* tmp = front;
    cout << "\nEdge selected is " << tmp->u << "->" << tmp->v << " and weight is " << tmp->weight << endl;
    front = front->link;
    return tmp;
}


