// 동적배열 구현
#include <iostream>
#include <sstream>
#include <algorithm>
#include <array>
using namespace std;

template <typename T>
class dynamic_array {
    private:
        T* data; // 자료형 T에 맞는 데이터들을 담을 배열(문자열 담을때 char* 형 배열 쓴거랑 같음)
        size_t n;

    public: 
        dynamic_array(int n) { // 사용자 정의 생성자
            this->n = n;
            data = new T[n]; // 동적 배열 생성
        }

        dynamic_array(const dynamic_array<T>& other) { // 복사 생성자
            n = other.n;
            data = new T[n];

            for (int i = 0; i < n; i++) {
                data[i] = other[i];
            }
        }

        T& operator[](int index) { // 매개변수(인덱스)에 해당하는 값을 반환하는 [] 연산자 오버로딩
            return data[index];
        }

        const T& operator[](int index) const {
            return data[index];
        }

        T& at(int index) { 
            if (index >= n) { // 전달인자가 동적배열의 최대 크기 이상인 경우 예외 처리
                throw "Index out of range";
            }
            return data[index];
        }

        size_t size() const { // 동적배열의 크기를 반환하는 메서드
            return n; 
        }

        ~dynamic_array() {
            delete[] data; // 생성한 동적배열을 삭제
        }

        T* begin() { return data; }
        const T* begin() const { return data; } 
        T* end() { return data + n; } // end: 배열의 마지막 원소의 다음 주소를 반환
        const T* end() const { return data + n; }

        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
            dynamic_array<T> result(arr1.size() + arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin()); // result의 begin 위치에 arr1의 데이터를 복사
            copy(arr2.begin(), arr2.end(), result.begin() + arr1.size()); // 바로 뒤에 arr2의 데이터를 복사

            return result;
        }

        string to_string(const string& sep = ", ") {
            ostringstream os;
            if (n == 0) {
                return "";
            }

            for (int i = 0; i < n; i++) {
                os << data[i] << sep;
            }

            return os.str();
        }
};

struct student {
    string name;
    int standard;
};

ostream& operator<<(ostream& os, const student& s) {
    return (os << "[" << s.name << ", " << s.standard << "]");    
}

int main() {
    int nStudents;
    cout << "1반 학생 수를 입력하세요: ";
    cin >> nStudents;

    dynamic_array<student> class1(nStudents); // 1반 학생수 만큼의 동적배열 생성(사용자 정의 생성자 호출)
    for (int i = 0; i < nStudents; i++) {
        string name;
        int standard;
        cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        cin >> name >> standard;
        class1[i] = student{name, standard}; // 입력받은 이름, 나이를 바탕으로 class1배열의 인덱스 값들에 넣을 student 구조체 생성
    }

    try {
        // [] 연산자의 사용: 오류 발생시 예외 처리 안돼서 프로그램 상 오류 발생
        // class1[nStudents] = student{"John", 8};
        
        // at함수 사용: 예외 처리 가능함
        class1.at(nStudents) = student{"John", 8};
    } catch(...) {
        cout << "예외 발생" << endl;
    }

    auto class2 = class1; // 복사 생성자 사용
    cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;

    auto class3 = class1 + class2; // 1반, 2반을 합친 3반 생성
    cout << "1반, 2반을 합쳐 3반 생성: " << class3.to_string() << endl;

    return 0;
}