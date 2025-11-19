#include <iostream>
#include <string>
#include <list>
#include <stdexcept> // out_of_range 사용을 위해 추가
#include <algorithm> // std::copy 사용을 위해 추가
using namespace std;

template<typename T>
class MyVector {
/* TODO */
private:
    T* data;           // 동적 배열을 가리키는 포인터
    size_t capacity;     // 현재 할당된 배열 크기
    size_t length;       // 실제 저장된 요소 개수

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        size_t new_capacity = capacity * 2;
        // 새로운 타입 T를 저장할 배열 동적 할당
        T* new_data = new T[new_capacity];

        // 기존 데이터를 새로운 배열로 복사
        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        capacity = new_capacity;
    }

public:
    // 생성자: 초기 capacity를 2로 설정하고, length는 0으로 초기화
    MyVector() : capacity(2), length(0) {
        // data는 capacity 크기의 배열을 동적 할당
        data = new T[capacity];
    }

    // 소멸자: 동적 할당된 data를 해제
    ~MyVector() {
        delete[] data;
    }

    // 값 추가
    void push_back(const T& value) {
        // length가 capacity에 도달하면 resize()를 호출
        if (length == capacity) {
            resize();
        }

        // 새로운 요소를 배열 끝에 추가하고 length를 증가
        data[length++] = value;
    }

    // 마지막 항목을 리턴
    T pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        // T 타입의 마지막 요소를 제거하고 반환
        return data[--length];
    }

    // 주어진 index의 요소를 반환
    T& operator[](const int index){
        if (index < 0 || (size_t)index >= length)
            throw out_of_range("Index out of bounds");
        return data[index];
    }

    // 현재 저장된 요소 개수를 반환
    size_t size() const {
        return length;
    }

    // 심화 학습: 범위 기반 for문 지원을 위한 begin() / end()
    T* begin() { return data; }
    T* end() { return data + length; }
};

template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    // 심화 학습: 범위 기반 for문으로 수정
    for (auto& e : vec) {
        cout << e << " ";
    }

    // 기존 코드: for (size_t i = 0; i < vec.size(); ++i)
    //     cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}