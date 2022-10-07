# cpp

## 자료형
int –2,147,483,648 ~ 2,147,483,647

long long (%lld) –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807

double 1.7E +/- 308 (15 digits)

접미사 (long long) LL ex) 0LL

## 문자열
```cpp
cin.ignore(); // 입력버퍼 초기화
getline(cin, string); // 한 줄 입력
reverse(string.begin(), string.end()); //문자열 뒤집기
```

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


## Sort
```cpp
bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.first == b.first){
        if(a.second.first == b.second.first) return a.second.second < b.second.second; // 1, 2 같으면 3작은거
        return a.second.first < b.second.first; // 1 같으면 2 작은거
    }
    return a.first < b.first; // 1작은거
} 

sort(v.begin(), v.end(), com;
```

## 유클리드 호제법(GCD)
```cpp
int gcd(int a, int b){
  int c;
  whlie(b){
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
```

## 소수 판정
```cpp
bool prime(int n){
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0) return false;
  }
  return true;
}
```

## 이진 탐색
```cpp
int binarySearch(int data[], int size, int d)
{
    int s = 0; //시작
    int e = size - 1; //끝
    int m;
    while (s <= e) {
        m = (s + e) / 2;
        if (data[m] == d) return m;
        else if (data[m] > d) e = m - 1;
        else s = m + 1;
    }
    return -1;
}
```