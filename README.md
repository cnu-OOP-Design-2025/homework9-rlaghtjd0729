[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/T-HnLMFg)
# Template 클래스 만들기 실습

## 학습 목표
- C++ 템플릿(template) 사용법을 익히고, 제너릭 프로그밍 능력을 기른다.

## 학습 내용
1. MyIntVector.cpp
    - int 전용 Vector 클래스(MyIntVector) 코드를 완성한다.
2. MyVector.cpp
    - MyIntVector 클래스를 템플릿 기반으로 확장하여 다양한 타입을 지원하는 MyVector를 구현한다.

## 구현 요구사항

### MyIntVector.cpp
- TODO 부분 완성
    - resize() : capacity를 2배로 늘리고 기존 데이터를 복사
    - 생성자 : 초기 capacity(2)로 배열 동적 할당
    - 소멸자 : 동적 메모리 해제
    - push_back() : capacity 초과 시 resize() 호출 후 값 추가
- 컴파일 명령: g++ MyIntVector.cpp -o MyIntVector --std=c++11

#### 예상 출력 결과
```
------------------
Resize: 2 -> 4
Resize: 4 -> 8
IntVec: 1 2 3 4 5 6
Pop: 6
Pop: 5
Pop: 4
Pop: 3
Pop: 2
Pop: 1
```


### MyVector.cpp
- MyIntVector를 템플릿으로 일반화하여 MyVector<T> 클래스 구현
- 컴파일 명령: g++ MyVector.cpp -o MyVector --std=c++11

#### 예상 출력 결과
```
------------------
Resize: 2 -> 4
Resize: 4 -> 8
IntVec: 1 2 3 4 5 6
Pop: 6
Pop: 5
Pop: 4
Pop: 3
Pop: 2
Pop: 1
------------------
Resize: 2 -> 4
Resize: 4 -> 8
DoubleVec: 1.1 2.2 3.3 4.4 5.5
Pop: 5.5
Pop: 4.4
Pop: 3.3
Pop: 2.2
Pop: 1.1
------------------
Resize: 2 -> 4
Resize: 4 -> 8
CharVec: A B C D E F
Pop: F
Pop: E
Pop: D
Pop: C
Pop: B
Pop: A
------------------
Resize: 2 -> 4
Resize: 4 -> 8
StringVec: Hello World C++ Template Vector
Pop: Vector
Pop: Template
Pop: C++
Pop: World
Pop: Hello
```

## 심화 학습
- `begin()` / `end()` 메서드를 추가하여 **범위 기반 for문(range-based for loop)**을 지원한다.
- `testVector()` 함수의 for loop를 **range-based for loop** 형태로 수정해본다.
  ```cpp
  for (auto& e : vec) {
      cout << e << " ";
  }
  ```



