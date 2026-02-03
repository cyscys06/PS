#include <bits/stdc++.h>
using namespace std;

class SimpleDisjointSet {
    private:
        struct Node {
            unsigned id; // 노드 고유 id -> 벡터에서 이터레이터로 쓰임
            unsigned rank; // 노드 랭크
            unsigned parent; // 현재 노드의 부모 노드

            Node(unsigned _id) : id(_id), rank(0), parent(_id) {}

            bool operator!=(const Node& n) const { // != 연산자 오버로딩(노드 고유의 id끼리 비교)
                return this->id != n.id;
            }
        };

        vector<Node> nodes;

    public:
        SimpleDisjointSet(unsigned N) {
            nodes.reserve(N); // 벡터 수용량 초기화
        }

        void make_set(const unsigned& x) {
            nodes.emplace_back(x); // 해당 id를 가진 노드를 벡터에 추가한다고 생각하면 됨
        }

        unsigned find(unsigned x) { // 부모 포인터를 따라 이동하면서 마지막에는 루트 노드의 포인터를 반환하는 함수
            // 이터레이터를 현재 노드의 주소로 초기화
            auto node_it = find_if(nodes.begin(), nodes.end(), 
                [x](auto n) { return n.id == x; }); // 조건자함수 람다식으로 설정
            
            // 현재 노드의 id를 받아옴
            unsigned node_id = (*node_it).id;

            
            while (node_id != nodes[node_id].parent) {
                node_id = nodes[node_id].parent;
            }

            return node_id;
        }


        void union_sets(unsigned x, unsigned y) {
            auto root_x = find(x);
            auto root_y = find(y);

            // x, y가 같은 트리에 있으면 그대로 종료
            if (root_x == root_y) {
                return;
            }

            // 작은 랭크 트리를 큰 랭크 트리쪽으로 병합
            if (nodes[root_x].rank > nodes[root_y].rank) {
                swap(root_x, root_y);
            }

            nodes[root_x].parent = nodes[root_y].parent;
            nodes[root_y].rank++;
        }
};

// 간선 구조체
template<typename T>
struct Edge {
    unsigned src;
    unsigned dst;
    T weight;

    // 객체 비교: 가중치 이용
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
        unsigned V;  // 정점 수
        vector<Edge<T>> edge_list;  // 정점별 간선 목록

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
        }
    public:
        // 생성자
        Graph(unsigned N) : V(N) {}

        // 그래프 정점 개수 반환
        auto vertices() const {
            return V;
        }

        auto& edges() const {
            return edge_list;
        }

        auto edges(unsigned v) const {
            vector<Edge<T>> edges_from_v;
            for (auto& e : edge_list) {
                if (e.src == v) {
                    edges_from_v.emplace_back(e);
                }
            }

            return edges_from_v;
        }

        void add_edge(Edge<T>&& e) {
            if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V) {
                edge_list.emplace_back(e); 
            } else {
                cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
            }
        }
};