#include <iostream>
#include <array>
using std::array;
using std::cout;
using std::endl;

int main() {
    array<int, 10> arr1;
    arr1[0] = 1;
    cout << "배열의 첫번째 원소: " << arr1[0] << endl;

    array<int, 4> arr2 = {1, 2, 3, 4};
    cout << "배열의 모든 원소: " << endl;
    for (int a : arr2) {
        cout << a << " ";
    }
    cout << endl;

    array<int, 4> arr3 = {1, 2, 3, 4};

    try {
        cout << arr3.at(3) << endl;
        cout << arr3.at(4) << endl;
        // at(): 매개변수로 받은 인덱스에 해당하는 값을 반환하는 메서드
        // 매개변수로 전달받은 인덱스가 유효하지 않은 경우, 예외를 발생시킴
    } catch(const std::out_of_range& ex) { // catch문에서 out_of_range 에러 변수를 캐치함
        std::cerr << ex.what() << endl;
        // what(): 발생한 예외 내용을 반환하는 함수
    }

    return 0;
}