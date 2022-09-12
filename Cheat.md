# cpp

## std::vector
```cpp
#include <vector>
vector.size()
```

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


## str::map
`std::map<key[Data Type], value[Data Type]> map`
dictionary 역할

```cpp
//insert
map[key]=value; // value 지정 안하면 0 들어감
map.insert(make_pair(key,value));

map.erase(key);

map.count(key); // 존재하면 1 없으면 0 반환

// 값 변경
map[key]+=a;
map[key]=value;

//delete
map.erase('A');

// 모든 값 찾기
for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) cout << it->first << ' ' << it->second << '\n';
```