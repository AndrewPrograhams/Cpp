#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1,T2> const& pair) const {
        std::size_t h1 = std::hash<T1>{}(pair.first);
        std::size_t h2 = std::hash<T2>{}(pair.second);
        return h1 ^ h2;
    }
};

struct Node {
    int x, y;
    float g;
    float h;
    Node* parent;

    Node(int x, int y, float g, float h, Node* parent)
        : x(x), y(y), g(g), h(h), parent(parent) {}
};

struct CompareF {
    bool operator()(const Node* a, const Node* b) const {
        return (a->g + a->h) > (b->g + b->h);
    }
};

using NodePtr = Node*;
using OpenList = std::priority_queue<NodePtr, std::vector<NodePtr>, CompareF>;
using NodeMap = std::unordered_map<std::pair<int, int>, NodePtr, PairHash>;

float manhattan_distance(const Node& a, const Node& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::vector<std::pair<int, int>> reconstruct_path(Node* current) {
    std::vector<std::pair<int, int>> path;
    while (current) {
        path.emplace_back(current->x, current->y);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<std::pair<int, int>> a_star(const std::vector<std::vector<int>>& grid,
                                        std::pair<int, int> start, std::pair<int, int> goal) {
    NodeMap all_nodes;
    NodeMap closed_list;
    OpenList open_list;
    Node* start_node = new Node(start.first, start.second, 0, manhattan_distance(Node(start.first, start.second, 0, 0, nullptr), Node(goal.first, goal.second, 0, 0, nullptr)), nullptr);
    open_list.push(start_node);
    all_nodes[start] = start_node;

    while (!open_list.empty()) {
        Node* current = open_list.top(); open_list.pop();
        if (current->x == goal.first && current->y == goal.second) {
            return reconstruct_path(current);
        }

        closed_list[{current->x, current->y}] = current;

        for (const auto& [dx, dy] : std::vector<std::pair<int, int>>{{0, -1}, {1, 0}, {0, 1}, {-1, 0}}) {
            int x = current->x + dx, y = current->y + dy;

            if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
                continue;
            }

            if (grid[y][x] == 1 || closed_list.count({x, y})) {
                continue;  // Skip obstructed nodes or nodes that are already closed
            }

            Node* neighbor = nullptr;
            float new_g = current->g + 1.0;
            
            if (all_nodes.count({x, y})) {
                neighbor = all_nodes[{x, y}];
                if (new_g >= neighbor->g) {
                    continue;
                }
            } else {
                float h_value = manhattan_distance(Node(x, y, 0, 0, nullptr), Node(goal.first, goal.second, 0, 0, nullptr));
                neighbor = new Node(x, y, std::numeric_limits<float>::infinity(), h_value, nullptr);
                all_nodes[{x, y}] = neighbor;
            }

            neighbor->g = new_g;
            neighbor->parent = current;
            open_list.push(neighbor);
        }
    }

    return {};
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {4, 4};
    auto path = a_star(grid, start, goal);

    if (path.empty()) {
        std::cout << "No path found.\n";
    } else {
        std::cout << "Path:\n";
        for (const auto& [x, y] : path) {
            std::cout << "(" << x << ", " << y << ")\n";
        }
    }

    return 0;
}