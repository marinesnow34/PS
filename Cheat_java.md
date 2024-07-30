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
- 최소힙
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
