#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination, weight;
};

struct Node {
    int id, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

class ReliefRouting {
private:
    int numOfAreas;
    vector<vector<Edge>> adjacencyList;
    vector<int> areaPriorities;

public:
    ReliefRouting(int areas) : numOfAreas(areas), adjacencyList(areas), areaPriorities(areas, 0) {}

    void addEdge(int from, int to, int weight) {
        adjacencyList[from].push_back({to, weight});
        adjacencyList[to].push_back({from, weight});
    }

    void setAreaPriority(int area, int priority) {
        areaPriorities[area] = priority;
    }

    void computeOptimizedPaths(int start) {
        vector<int> shortestDistances(numOfAreas, INT_MAX); 
        vector<bool> processed(numOfAreas, false);
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        shortestDistances[start] = 0;
        pq.push({start, 0});

        while (!pq.empty()) {
            int currentNode = pq.top().id;
            pq.pop();

            if (processed[currentNode]) continue;
            processed[currentNode] = true;

            for (const Edge& edge : adjacencyList[currentNode]) {
                int neighbor = edge.destination;
                int weight = edge.weight;

                if (areaPriorities[neighbor] > 0) {
                    weight = static_cast<int>(weight * 0.8); // Reduced cost for high-priority areas
                }

                if (shortestDistances[currentNode] + weight < shortestDistances[neighbor]) {
                    shortestDistances[neighbor] = shortestDistances[currentNode] + weight;
                    pq.push({neighbor, shortestDistances[neighbor]});
                }
            }
        }

        cout << "Calculated shortest distances from area " << start << ":\n";
        for (int i = 0; i < numOfAreas; i++) {
            if (shortestDistances[i] == INT_MAX) {
                cout << "Area " << i << " is inaccessible.\n";
            } else {
                cout << "Area " << i << " -> Distance: " << shortestDistances[i] << endl;
            }
        }
    }
};

int main() {
    int totalAreas;
    cout << "Enter the number of areas: ";
    cin >> totalAreas;

    ReliefRouting reliefSystem(totalAreas);

    int totalConnections;
    cout << "Enter the number of connections between areas: ";
    cin >> totalConnections;

    for (int i = 0; i < totalConnections; i++) {
        int start, end, length;
        cout << "Enter connection " << i + 1 << " (start area, end area, length): ";
        cin >> start >> end >> length;
        reliefSystem.addEdge(start, end, length);
    }

    int numPriorityLevels;
    cout << "Enter the number of priority areas: ";
    cin >> numPriorityLevels;

    for (int i = 0; i < numPriorityLevels; i++) {
        int area, priority;
        cout << "Enter area index and priority level for area " << i + 1 << ": ";
        cin >> area >> priority;
        reliefSystem.setAreaPriority(area, priority);
    }

    int originArea;
    cout << "Enter the origin area for optimized path calculation: ";
    cin >> originArea;

    reliefSystem.computeOptimizedPaths(originArea);

    return 0;
}
