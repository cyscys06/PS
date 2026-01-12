#include <bits/stdc++.h>
using namespace std;

template<typename ... Args>
auto build_array(Args&&... args) -> 
// 후행 리턴 타입: 데이터를 반환할때, 데이터 타입을 유동적으로 처리하기 위한 문법
// 함수가 반환할 데이터 타입을 함수 이름 뒤에 명시함
// 템플릿 함수에서 데이터의 반환 타입을 명확하게 명시하기 어려울 경우 사용함
array<typename common_type<Args...>::type, sizeof...(args)> {
    using commonType = typename common_type<Args...>:;type;
    return {forward<commonType>((Args&&)args)...};
}

int main() {
    forward_list<int> list = {1, 2, 3};
    list.sort(greater<int>());
}