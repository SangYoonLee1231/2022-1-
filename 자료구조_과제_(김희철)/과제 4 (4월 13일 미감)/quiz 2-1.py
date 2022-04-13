class Queue:
    MAX_QSIZE = 100
    def __init__(self):
        self.list = [None] * Queue.MAX_QSIZE
        self.front = -1
        self.rear =-1
        self.size = 0


    def resize(self, cap):
        olditems = self.list
        self.list = [None] * cap
        walk = self.front
        for k in range(self.size):
            self.list[k] = olditems[walk]
            walk = (walk + 1) % len(olditems)
        self.front = -1
        self.rear = self.size - 1


    def isEmpty(self):
        return self.size == 0
    

    def isFull(self):
        # 큐가 full일 경우 리스트 길이를 2배로 확장
        if self.list.size < self.MAX_QSIZE:
            # 리스트 용량이 넉넉한 경우
            print()

            # 정상적으로 enqueue 과정 수행

        else: # A.n == A.capacity # 리스트 용량이 더 필요한 경우 (자동으로 용량 크기 ↑)
            Queue.MAX_QSIZE *= 2
            self.resize(Queue.MAX_QSIZE)


    def enqueue(self, e):
        if self.size == len(self.list):
            print("Queue is full")
            self.resize(2 * len(self.list))
        else:
            self.rear = (self.rear + 1) % (len(self.list))    
            self.list[self.rear] = e
            self.size += 1


    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty")
        else:        
            self.front = (self.front + 1) % (len(self.list))
            e = self.list[self.front]
            self.size -= 1
            return e

    
    def peek(self):
        if self.isEmpty():
            print("Queue is empty")
        else:
            return self.list[0]


    def size(self):
        return self.size



n = int(input())

people_lst = [
    tuple(map(int, input().split()))  # (arrive, elapse)
    for _ in range(n)
]

q = Queue()
time = 0
total_time = 0

q.enqueue(people_lst[0])

while not q.isEmpty():
    q.peek()
    time += 1
