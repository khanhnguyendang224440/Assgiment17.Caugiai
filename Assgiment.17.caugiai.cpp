#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 100;
int adjMatrix[MAX][MAX];
int visited[MAX];
int n; // So dinh cua do thi
char vertices[MAX]; // Ten cac dinh

// Tim vi tri cua dinh trong mang
int getIndex(char c) {
    for (int i = 0; i < n; i++) {
        if (vertices[i] == c) return i;
    }
    return -1;
}

// Nhap cac dinh va lien ket cua do thi
void inputGraph() {
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;

    cout << "Nhap ten cac dinh: \n";
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    memset(adjMatrix, 0, sizeof(adjMatrix));

    cout << "Nhap cac canh (nhap '0 0' de ket thuc):\n";
    while (true) {
        char u, v;
        cin >> u >> v;
        if (u == '0' && v == '0') break;

        int i = getIndex(u);
        int j = getIndex(v);

        if (i != -1 && j != -1) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // Vi do thi vo huong
        } else {
            cout << "Dinh khong hop le. Vui long nhap lai!\n";
        }
    }
}

// Duyet do thi theo BFS
void BFS(int start) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));

    cout << "BFS: ";
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << vertices[u] << " ";

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] && !visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// Duyet do thi theo DFS
void DFS(int start) {
    stack<int> s;
    memset(visited, 0, sizeof(visited));

    cout << "DFS: ";
    s.push(start);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            visited[u] = 1;
            cout << vertices[u] << " ";

            for (int v = n - 1; v >= 0; v--) {
                if (adjMatrix[u][v] && !visited[v]) {
                    s.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    inputGraph();

    char startVertex;
    cout << "Nhap dinh bat dau duyet: ";
    cin >> startVertex;
    int startIndex = getIndex(startVertex);

    if (startIndex == -1) {
        cout << "Dinh bat dau khong hop le!";
        return 1;
    }

    BFS(startIndex);
    DFS(startIndex);

    return 0;
}

