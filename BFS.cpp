#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>>& adj_matrix, int start_vertex) {
    int num_vertices = adj_matrix.size();
    vector<bool> visited(num_vertices, false);
    queue<int> q;

    // Mark the starting vertex as visited and enqueue it
    visited[start_vertex] = true;
    q.push(start_vertex);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and visit its neighbors
        int current_vertex = q.front();
        cout << current_vertex << " ";
        q.pop();

        for (int neighbor = 0; neighbor < num_vertices; ++neighbor) {
            if (adj_matrix[current_vertex][neighbor] == 1 && !visited[neighbor]) {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj_matrix = {{0, 1, 1, 0},
                                      {1, 0, 1, 1},
                                      {1, 1, 0, 1},
                                      {0, 1, 1, 0}};

    bfs(adj_matrix, 0); // start BFS from vertex 0
    return 0;
}
