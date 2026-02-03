#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// 그래프 컬러링에 사용할 색상
unordered_map<unsigned, string> color_map = {
    {1, "Red"},
    {2, "Blue"},
    {3, "Green"},
    {4, "Yellow"},
    {5, "Black"},
    {6, "White"},
};

// 간선 구조체
template<typename T>
struct Edge {
    unsigned src; // 시작점
    unsigned dst; // 도착점
    T weight;

    bool operator<(const Edge<T>& e) const {
        return this->weight < e.weight;
    }

    bool operator>(const Edge<T>& e) const {
        return this->weight > e.weight;
    }
};

// 그래프 클래스
template<typename T>
class Graph {
private:
    unsigned V;  // 정점 개수
    vector<Edge<T>> edge_list; // 간선 리스트

    // 정점과 간선에 대한 정보를 출력
    template <typename U>
    friend ostream& operator<<(ostream& os, const Graph<U>& G) { 
        for (unsigned i = 1; i < G.vertices(); i++) {
            os << i << ":\t";
            auto edges = G.edges(i);
            for (auto& e : edges) {
                os << "{" << e.dst << ": " << e.weight << "}, ";
            }
            os << endl;
        }
        return os;
    }

public:
    Graph(unsigned N) : V(N) {}

    // 정점 개수 반환
    auto vertices() const {
        return V;
    }

    // 간선 리스트 반환
    auto& edges() const {
        return edge_list;
    }

    // 특정 정점 v와 연결된 모든 간선 리스트를 반환
    auto edges(unsigned v) const {
        vector<Edge<T>> edges_from_v;
        for (auto& e : edge_list) {
            if (e.src == v) {
                edges_from_v.emplace_back(e);
            }
        }
        return edges_from_v;
    }

    // 정점에 간선을 추가하는 함수
    void add_edge(const Edge<T>& e) {
        // 추가할 정점 ID가 범위(1부터 마지막 정점까지) 안에 있는지 검사
        if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V) {
            edge_list.emplace_back(e);
        } else {
            cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
        }
    }
};

// 그래프 컬러링 함수
template<typename T>
vector<unsigned> greedy_coloring(Graph<T>& G) {
    auto size = G.vertices(); // 존재하는 정점 개수만큼 사이즈 할당
    vector<unsigned> assigned_colors(size, 0); // 정점에 칠해진 색 정보를 저장하는 벡터. 0은 색이 칠해지지 않은 상태

    for (unsigned i = 1; i < size; i++) { // for문으로 모든 정점을 검사
        auto outgoing_edges = G.edges(i); // i번째 정점과 연결된 모든 간선 리스트를 반환

        set<unsigned> neighbours; // i번째 정점과 인접한 정점들의 현재 색상을 저장할 세트
        for (auto& e : outgoing_edges) { // i번째 정점과 인접한 모든 정점에 대해:
            if (assigned_colors[e.dst] != 0) {
                neighbours.insert(assigned_colors[e.dst]);
            }
            // 간선의 도착점 정점에 할당된 색상 정보를 저장
            // 특정 색이 칠해진 경우에만 해당 정보를 추가
            // 
        }

        // 사용할 수 있는 가장 작은 색상 찾기
        for (unsigned smallest = 1; smallest <= color_map.size(); smallest++) {
            if (neighbours.find(smallest) == neighbours.end()) { // 가장 마지막에 추가된 정점에 대해:
                assigned_colors[i] = smallest; // 가장 작은 숫자의 색상 선택
                break;
                
            }
        }
    }

    return assigned_colors;
}

// 색상 출력 함수
void print_colors(const vector<unsigned>& colors) {
    for (unsigned i = 1; i < colors.size(); i++) {
        cout << i << ": " << color_map.at(colors[i]) << endl;
    }
}

int main() {
    using T = unsigned;

    Graph<T> G(9); // 정점 번호는 1~8(0은 안씀)

    map<unsigned, vector<pair<unsigned, T>>> edge_map = {
        {1, {{2, 0}, {5, 0}}},
        {2, {{1, 0}, {5, 0}, {4, 0}}},
        {3, {{4, 0}, {7, 0}}},
        {4, {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}}},
        {5, {{1, 0}, {2, 0}, {4, 0}, {8, 0}}},
        {6, {{4, 0}, {7, 0}, {8, 0}}},
        {7, {{3, 0}, {6, 0}}},
        {8, {{4, 0}, {5, 0}, {6, 0}}}
    };

    for (auto& [u, vec] : edge_map) { // u: unsigned, vec: pair<unsigned, string>
        for (auto& [v, w] : vec) {
            G.add_edge({u, v, w});
        }
    }

    cout << "[입력 그래프]" << endl;
    cout << G << endl;

    auto colors = greedy_coloring<T>(G);
    cout << "[그래프 컬러링 결과]" << endl;
    print_colors(colors);

    return 0;
}