## ArrayDeque
- `deque`, `queue` 구현체
- 기본 초기 용량 16 이후 2배씩 증가 (2배수로 할당 추천)

```java
new ArrayDeque<>(); // 기본 초기 용량 16
new ArrayDeque<>(32); // 초기 용량 지정

int size = deque.size(); // 크기 확인
boolean isEmpty = deque.isEmpty(); // 비어있는지 확인

dq.offerFirst(0); // 앞쪽에 0 추가
dq.offerLast(3);  // 뒤쪽에 3 추가

Integer polledFirst = deque.pollFirst(); // 앞쪽 요소 제거 및 반환 (없으면 null)
Integer polledLast = deque.pollLast();   // 뒤쪽 요소 제거 및 반환 (없으면 null)

Integer peekedFirst = deque.peekFirst(); // 앞쪽 요소 조회 (없으면 null)
Integer peekedLast = deque.peekLast();   // 뒤쪽 요소 조회 (없으면 null)
```

## PrioryityQueue
- `queue` 구현체
- 최소힙(array 사용)
- 기본 초기 용량 11 이후 1.5배 증가

```java
new PriorityQueue<>();
new PriorityQueue<>(Collections.reverseOrder()); // 최대 힙
new PriorityQueue<>((a, b) -> b - a); // 최대 힙 람다
// class에 implements Comparable<T> 이후
// @Override compareTo(T t) 

pq.offer(5);
Integer minElement = pq.poll(); // 가장 작은 요소를 제거하고 반환
```

## HashMap
- `map` 구현체
- 기본 초기 용량 16 이후 1.5배 증가 부하계수 0.75

```java
new HashMap<>();
new HashMap<>(16, 0.75f); // 초기 용량과 로드 팩터를 지정하여 생성

map.put(1, "Apple");
map.merge(1, "Pay", (oldValue, newValue) -> oldValue + newValue); // key: 1 이없으면 Value: "pay" 있으면 Value: "ApplePay"

String value = map.get(2)
String value = map.remove(1); // 키 1에 해당하는 "Apple" 삭제
```

## TreeMap
- `map`, `SortedMap`, `NavigableMap` 구현체
- R-B Tree로 내부 구현
- 삽입, 삭제, 조회 O(logn)
- 정렬됨

```java
new TreeMap<>();

map.put(2, "사과");
map.get(2);

String firstValue = map.pollFirstEntry().getValue(); // 가장 낮은 키와 그에 해당하는 값 제거 및 반환
String lastValue = map.pollLastEntry().getValue(); // 가장 높은 키와 그에 해당하는 값 제거 및 반환
```

## HashSet
- `set`구현체
- HashMap Value에 null 넣는 방식으로 구현

```java
HashSet<String> set = new HashSet<>();

set.add("Apple"); // 추가 성공/실패 true/false
set.remove("Banana"); // 삭제 성공/실패 true/false
set.contains("Banana"); // 존재 여부
```

## TreeSet
- `set`, `SortedSet`, `NavigableSet` 구현체
- TreeMap Value에 null 넣는 방식으로 구현

```java
new TreeSet<>();

Integer polledFirstElement = treeSet.pollFirst(); // 첫 번째 요소 제거하고 반환
Integer polledLastElement = treeSet.pollLast(); // 마지막 요소 제거하고 반환

Integer firstElement = treeSet.first(); // 첫 번째(최소) 요소 반환
Integer lastElement = treeSet.last(); // 마지막(최대) 요소 반환

Integer ceilingResult1 = treeSet.ceiling(25); // 25이상의 제일 작은 요소 반환
Integer floorResult1 = treeSet.floor(25);// 25이하의 제일 큰 요소 반환

Integer higherResult1 = treeSet.higher(25); // 25초과의 제일 작은 요소 반환
Integer lowerResult1 = treeSet.lower(25); // 25미만의 제일 작은 요소 반환
```
