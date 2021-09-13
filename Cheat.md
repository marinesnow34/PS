# cpp

## std::string

`std::erase()`
```cpp
#include <string>
str.erase(size_t pos = 0, size_t len = npos); // 범위
str.erase(const_iterator p); // 한 글자
str.erase(const_iterator first, const_iterator last); //범위
```

## str::pair
`std::pair<T1, T2> p`

```cpp
T1 = p.first; T2 = p.second;
make_pair(1,2);
```

## str::deque
`std::deque<[Data Type]> dq`

```cpp
dq.front;
dq.back;

dq.push_back(1);
dq.pop_fron(2);
dq.clear();
```

