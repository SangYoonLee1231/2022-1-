class Queue:
    MAX_QSIZE = 100
    def __init__(self):
        self.list = [None] * Queue.MAX_QSIZE
        self.front = -1
        self.rear =-1
        self.size = 0

    def isEmpty(self):
        return self.size == 0
    
    def isFull(self):
        # 큐가 full일 경우 리스트 길이를 2배로 확장
        if self.list.size < self.MAX_QSIZE:
            # 리스트 용량이 넉넉한 경우
            print()

            # 정상적으로 enqueue 과정 수행

        else: # A.n == A.capacity # 리스트 용량이 더 필요한 경우 (자동으로 용량 크기 ↑)
            n = self.size()
            list_temp = [None] * Queue.MAX_QSIZE * 2 # B는 임시용 리스트, *2는 용량을 늘린다는 의미

            for i in range(n):
                list_temp[i] = self.list[i]
            self.list = list_temp
            del list_temp
            self.list[n] = item
            self.list.n = n + 1


    def enqueue(self, item):
        self.isFull()


        
    def dequeue(self):
        self.isEmpty()
    
    def peek(self):
        self.isEmpty()

    def size(self):
        return self.size()