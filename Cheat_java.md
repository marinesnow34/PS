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
