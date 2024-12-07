#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findPaths(int x, int y, int N, vector<vector<bool>>& visited, string path, vector<string>& paths) {
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    // Right
    if (y + 1 < N && !visited[x][y + 1]) {
        findPaths(x, y + 1, N, visited, path + "->" + to_string(x + 1) + "," + to_string(y + 2), paths);
    }
    // Down
    if (x + 1 < N && !visited[x + 1][y]) {
        findPaths(x + 1, y, N, visited, path + "->" + to_string(x + 2) + "," + to_string(y + 1), paths);
    }
    // Left
    if (y - 1 >= 0 && !visited[x][y - 1]) {
        findPaths(x, y - 1, N, visited, path + "->" + to_string(x + 1) + "," + to_string(y), paths);
    }
    // Up
    if (x - 1 >= 0 && !visited[x - 1][y]) {
        findPaths(x - 1, y, N, visited, path + "->" + to_string(x) + "," + to_string(y + 1), paths);
    }

    visited[x][y] = false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<string> paths;

    findPaths(0, 0, N, visited, "1,1", paths);

    for (int i = 0; i < paths.size(); ++i) {
        cout << i + 1 << ":" << paths[i] << endl;
    }

    return 0;
}
