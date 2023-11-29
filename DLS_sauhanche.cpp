#include<bits/stdc++.h>

using namespace std;

int n,m;

vector<int> a[100];
bool visited[100];

void Nhap(){
    cout<<"Nhap So Dinh: "; cin>>n;
    cout<<"Nhap So Canh: "; cin>>m;

    cout<<"Nhap Danh Sach Cac Canh: \n";
    for(int i=0 ; i<m ; i++){
        int x,y;
        cout<<"Nhap Cap Thu "<<i+1<<"\n";
        cout<<"X = "; cin>>x;
        cout<<"Y = "; cin>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(visited, false ,sizeof(visited));
}

void LimitedDFS(int u, int limit){
    cout << u << " ";
    visited[u] = true;

    if (limit <= 0) {
        return;
    }

    for (auto x : a[u]) {
        if (!visited[x]) {
            LimitedDFS(x, limit - 1);
        }
    }
}

void BFS(int u, int limit) {
    queue<pair<int, int>> q; // (ð?nh, ð? sâu)
    memset(visited, false, sizeof(visited));

    q.push(make_pair(u, 0));
    visited[u] = true;

    while (!q.empty()) {
        int vertex = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth <= 0) {
            continue;
        }

        for (auto x : a[vertex]) {
            if (!visited[x]) {
                cout << x << " ";
                visited[x] = true;
                q.push(make_pair(x, depth - 1));
            }
        }
    }
}

int main(){
    Nhap();
    int start = 1; 
    int limit;

    cout << "Nhap Do Sau Han Che: ";
    cin >> limit;

    cout << "Thu Tu Duyet Cua DFS : ";
    LimitedDFS(start, limit);
  
    return 0;
}
