#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Good {
    int quantity;
    int price;
    int value;

    Good(int q, int p, int v) : quantity(q), price(p), value(v) {}
};

int main() {
    int N, budget, capacity; // 물건 종류 수, 예산, 수용량
    cin >> N >> budget >> capacity;

    vector<Good> goods;

    for (int i = 0; i < N; i++) {
        int quantity, cost, value;
        cin >> quantity >> cost >> value;

        goods.push_back(Good(quantity, cost, value));
    }

    vector<vector<vector<int>>> DP(N + 1, vector<vector<int>>(budget + 1, vector<int>(capacity + 1, 0)));

    for (int i = 1; i <= N; i++) { // 모든 종류의 물건을 순회
        Good good = goods[i - 1]; // 물건 리스트에 있는 물건들에서 한 종류씩 꺼내기
        
        for (int cost = 0; cost <= budget; cost++) { // 가격(cost)를 예산 이하까지 반복
            for (int count = 0; count <= capacity; count++) { // 구매할 개수(count)를 수용량 이하까지 반복
                // 물건을 구매하지 않는 경우
                if (cost < good.price || count < good.quantity) { 
                    DP[i][cost][count] = DP[i - 1][cost][count]; 
                    // 이전 기록을 유지(이전 기록 가져오기)
                
                // 물건을 구매하는 경우
                } else { 
                    DP[i][cost][count] = max(DP[i - 1][cost][count], 
                        // 물건을 구매하지 않았을 때의 value값이나
                        DP[i - 1][cost - good.price][count - good.quantity] + good.value);
                        // 물건을 구매했을 때의 value값중 더 큰 값을 선택
                }
            }
        }
    }

    // 순회 끝나면 최적해가 자동으로 맨 끝 원소에 저장, 해당 원소 값을 출력
    cout << DP[N][budget][capacity] << endl;
    return 0;
}