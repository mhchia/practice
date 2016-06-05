#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph(const int num) : num_nodes_(num)
    {
        edges_ = vector<list<int> >(num);
        distance_to_festive_ = vector<int>(num, 2147483647);
    }
    bool AddEdge(const int& node1, const int& node2)
    {
        if (node1 == 0 || node2 == 0 || node1 > num_nodes_ || node2 > num_nodes_) {
            return false;
        }
        edges_[node1 - 1].remove(node2 - 1);
        edges_[node1 - 1].push_back(node2 - 1);
        edges_[node2 - 1].remove(node1- 1);
        edges_[node2 - 1].push_back(node1 - 1);
        return true;
    }
    void DumpEdges()
    {
        for (unsigned int i = 0; i < edges_.size(); ++i) {
            cout << i << " : ";
            for (list<int>::const_iterator it = edges_[i].begin();
                it != edges_[i].end();
                ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    void DumpDistanceToFestive()
    {
        for (vector<int>::const_iterator it = distance_to_festive_.begin();
                it != distance_to_festive_.end();
                ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    int GetDistanceToFestive(const int& node)
    {
        return distance_to_festive_[node - 1];
    }
    void SetFestive(const int& node)
    {
        if (distance_to_festive_[node - 1] != 0) {
            BFS_(node - 1);
        }
    }
    void BFS_(int s)
    {
        vector<int> visited(num_nodes_, 0);
        vector<int> distance(num_nodes_, 0);
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        distance[s] = 0;
//        cout << "visit : " << s + 1 << endl;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (list<int>::iterator it = edges_[v].begin();
                    it != edges_[v].end();
                    ++it) {
                int w = *it;
                if (!visited[w]) {
                    visited[w] = 1;
//                    cout << "visit : " << w + 1 << endl;
                    q.push(w);
                    distance[w] = distance[v] + 1;
                }
            }
        }
        for (int i = 0; i < num_nodes_; ++i) {
            if (distance[i] < distance_to_festive_[i]) {
                distance_to_festive_[i] = distance[i];
            }
        }
    }
private:
    typedef vector<list<int> > AdjList;
    const int num_nodes_;
    AdjList edges_;
    vector<int> distance_to_festive_;
};

int main(void)
{
    // n nodes, m queries.
    int n, m;
    cin >> n >> m;
    Graph g = Graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        g.AddEdge(node1, node2);
    }
    g.SetFestive(1);
    for (int i = 0; i < m; ++i) {
        int op, node;
        cin >> op >> node;
        if (op == 1) {
            g.SetFestive(node);
        } else if (op == 2) {
            cout << g.GetDistanceToFestive(node) << endl;
        }
    }
    return 0;
}

