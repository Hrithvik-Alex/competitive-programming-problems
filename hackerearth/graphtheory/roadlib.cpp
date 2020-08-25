#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



class Graph {
    
public:
    int n;
    int **adj;
    int *visited;
    Graph(int x){
        n = x;
        visited = new int[n];
        adj = new int*[n];
        for(int i=0;i<n;i++){
            adj[i] = new int[n];
        }
        
        for(int i = 0; i <n;i++){
            for(int j = 0; j<n;j++){
                adj[i][j] = 0;
            }
            visited[i] = 0;
        }
    }
    
    void addEdge(int first, int second){
        adj[first][second] = 1;
        adj[second][first] = 1;
    }
    
    
    void dfs(int node, int& count){
        visited[node] = 1;
        count++;
        
        for(int i = 0;i<n;++i){
            if(adj[node][i]==1 && visited[i] == 0){
                dfs(i, count);
            }
        }
    }
    
};

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    if(c_lib<=c_road){
        return (long)(c_lib*n);
    }
    
    Graph graph = Graph(n);
    
    for(int i=0;i<cities.size();++i){
        graph.addEdge(cities[i][0]-1,cities[i][1]-1);
    }
    
    int count = 0;
    int connected = 0;
    for(int i=0;i<n;i++){
        if(graph.visited[i] == 0){
            graph.dfs(i, count);
            connected++;
        }
    }
    
    
    
    return (long)(c_road*(count - connected) + c_lib*connected);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);
        
        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);
        
        int n = stoi(nmC_libC_road[0]);
        
        int m = stoi(nmC_libC_road[1]);
        
        int c_lib = stoi(nmC_libC_road[2]);
        
        int c_road = stoi(nmC_libC_road[3]);
        
        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);
            
            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}

