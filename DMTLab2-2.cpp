#include<bits/stdc++.h>
#include <algorithm> 

using namespace std;

bool contains(int a[], int n, int g){
    bool cont = false;
    for(int i = 0; i < n; i++){
        if(a[i] == g)
            cont = true;
    }
    return cont;
}

int tspGA(int n, int a, int b){
    int graph[n][n];
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = (a * (i + 1) + b * (j + 1)) * (a * (i + 1) + b * (j + 1)) + 1;
                graph[j][i] = graph[i][j];
        }   
    }

    int len = 0;
    int min = INT32_MAX;
    int mini, minj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] < min && graph[i][j] != 0){
                min = graph[i][j];
                mini = i;
                minj = j;
            }
        }   
    }
    len += min;
    int cnt = 0, pomJ, pomI;
    int *visited = new int[n];

    visited[cnt++] = mini;
    visited[cnt++] = minj;
    bool drugi;
  
    while(cnt < n){
        min = INT32_MAX;
        drugi = false;
        for(int j = 0; j < n; j++){
            if(graph[mini][j] < min && (!contains(visited, cnt, j)) && graph[mini][j] != 0){
                min = graph[mini][j];
                pomJ = j;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(graph[i][minj] < min && !contains(visited, cnt, i) && graph[i][minj] != 0){
                min = graph[i][minj];
                drugi = true;
                pomI = i;
            }
        }
        len += min;
        min = INT32_MAX;
        
        if(drugi){
            minj = pomI;
            visited[cnt++] = minj;
        } else {
            mini = pomJ;
            visited[cnt++] = mini;
        }
    }
    len += graph[mini][minj];
    return len;
}

int tsp(int n, int a, int b){
    vector<int> g(n);
    for(int i = 0; i < n; i++){
        g[i] = i + 1;
    }
    int min = INT32_MAX;
    int len;
    
    do {
        len = 0;
        for(int i = 0; i < n - 1; i++){
            if(g[i] < g[i + 1])
                len += (a * g[i] + b * g[i + 1]) * (a * g[i] + b * g[i + 1]) + 1;
            else
                len += (b * g[i] + a * g[i + 1]) * (b * g[i] + a * g[i + 1]) + 1;
        }
        if(g[n - 1] < g[0])
            len += (a * g[n - 1] + b * g[0]) * (a * g[n - 1] + b * g[0]) + 1;
        else
            len += (b * g[n - 1] + a * g[0]) * (b * g[n - 1] + a * g[0]) + 1;
        if(len < min)
            min = len;
    } while(next_permutation(g.begin() + 1, g.end()));
    return min;
}

int main(void){
    int n, a, b;

    cout << "Upisi redom, odvojene razmakom parametre n, a i b: ";
    cin >> n;
    cin >> a;
    cin >> b;

    int isc = tsp(n, a, b);
    int poh = tspGA(n, a, b);

    cout << "Pohlepni algoritam nalazi ciklus duljine " << poh << endl;
    cout << "Iscrpni algoritam nalazi ciklus duljine " << isc << endl;

    if(isc == poh)
        cout << "Pohlepni algoritam na ovom grafu daje optimalno rjesenje!";
    else
        cout << "Pohlepni algoritam na ovom grafu ne daje optimalno rjesenje!";

    return 0;
}