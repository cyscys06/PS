#include <iostream>
#include <array>
using namespace std;

// 매개변수 타입이 array<int, 5>(크기가 5인 int형 데이터를 저장하는 배열)로 고정됨
void print1(array<int, 5> arr) {
    for (auto ele : arr) {
        cout << ele << ", ";
    }
} 

// 템플릿 함수를 이용해 매개변수 타입을 유동적으로 처리
// 템플릿 선언은 템플릿 함수 바로 위에서 선언할 것
template<size_t N>
void print2(const array<int, N>& arr) {
    for (auto ele : arr) {
        cout << ele << ", ";
    }
}

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    print1(arr);
    print2(arr);

    return 0;
}
