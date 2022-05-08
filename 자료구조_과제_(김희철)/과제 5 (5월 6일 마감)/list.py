class addrCLass:
    def __init__(self):
        self.addrList = ["www.hufs.ac.kr"]
        self.go_history = []
        self.position = 0


    def go(self, addr):
        # addrList의 현 방문 사이트 주소 다음에 addr 추가
        try:
            self.addrList[self.position + 1] = addr
        except IndexError:
            self.addrList.append(addr)
        # 이후에 있는 방문사이트 주소들을 무시
        
        # 현 방문 사이트 주소를 addr로 바꾸고 이를 출력
        self.position += 1
        print(self.addrList[self.position])
        
        # history 기록에 addr 추가 (중복 시 추가 X)
        for elem in self.go_history:
            if elem == addr:
                return
        self.go_history.append(addr)


    def forward(self):
        try:
            self.position += 1
            print(self.addrList[self.position])
        except:
            pass

    
    def backward(self):
        try:
            self.position -= 1
            print(self.addrList[self.position])
        except:
            pass
    

    def history(self):
        size = len(self.go_history)

        for i in range(size, -1, -1):
            print(self.go_history[i])


