#include <iostream>
#include <list>
#include <stdexcept> // out_of_range 사용을 위해 추가
#include <algorithm> // std::copy 사용을 위해 추가
using namespace std;

class MyIntVector {
private:
    int* data;           // 동적 배열을 가리키는 포인터
    size_t capacity;     // 현재 할당된 배열 크기
    size_t length;       // 실제 저장된 요소 개수

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        /* TODO */
        // capacity의 크기를 2배로 늘리고, 새로운 배열을 생성하세요.
        size_t new_capacity = capacity * 2;
        int* new_data = new int[new_capacity];

        // 기존 데이터를 새로운 배열로 복사한 뒤, 기존 배열을 해제하세요.
        // std::copy(data, data + length, new_data); // 또는 for 루프
        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        capacity = new_capacity;
    }

public:

    // 초기 capacity를 2로 설정하고, length는 0으로 초기화하세요.
    MyIntVector() : capacity(2), length(0) {
        /* TODO */
        // data는 capacity 크기의 배열을 동적 할당하세요.
        data = new int[capacity];
    }

    ~MyIntVector() {
        /* TODO */
        // 동적 할당된 data를 해제하세요.
        delete[] data;
    }

    void push_back(const int& value) {
        /* TODO */
        // length가 capacity에 도달하면 resize()를 호출하세요.
        if (length == capacity) {
            resize();
        }

        /* TODO */
        // 새로운 요소를 배열 끝에 추가하고 length를 증가시키세요.
        data[length++] = value;
    }

    // 마지막 항목을 리턴하세요.
    int pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; // 마지막 요소 제거
    }

    // 주어진 index의 요소를 반환하세요.
    int& operator[](const int index){
        if (index < 0 || (size_t)index >= length)
            throw out_of_range("Index out of bounds");
        return data[index];
    }

    // 현재 저장된 요소 개수를 반환하세요.
    size_t size() const {
        return length;
    }

    // 범위 기반 for문 지원을 위한 begin() / end() (심화 학습)
    int* begin() { return data; }
    int* end() { return data + length; }

};

void testVector(const string& name, std::list<int> values) {

    cout << "------------------" << endl;
    MyIntVector vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    // 심화 학습: 범위 기반 for문 사용
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
    testVector("IntVec", {1, 2, 3, 4, 5, 6});
    return 0;
}