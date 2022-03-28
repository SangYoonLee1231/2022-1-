class Stack():
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)

    def pop(self):
        try:
            return self.items.pop()
        except IndexError:
            print("Stack is empty");

    
    def top(self):
        try:
            return self.items[-1]
        except IndexError:
            print("Stack is empty")

    def size(self):
        return len(self.items)

    def empty(self):
        return not self.items
        # return not self.items


def check(string):
    global error_idx, error_num

    for i, elem in enumerate(string):
        if elem == '(' or elem =='{' or elem == '[':
            s.push(elem)
        elif elem == ')' or elem == '}' or elem == ']':
            if s.empty():
                if elem == ')':
                    error_num = 1
                    return i, error_num
                if elem == '}':
                    error_num = 2
                    return i, error_num
                if elem == ']':
                    error_num = 3
                    return i, error_num

            else:
                peek_ch = s.pop()
                if (elem == ')' and peek_ch !='('):
                    error_num = 1
                    return i, error_num
                if (elem == '}' and peek_ch != '{'):
                    error_num = 2
                    return i, error_num
                if (elem == ']' and peek_ch != '['):
                    error_num = 3
                    return i, error_num
                # 위의 세 경우 모두 아나리면 정상적으로 pop 수행
        else:
            # 괄호가 아니라면 무시
            pass
    
    if s.empty():
        return None, 0
    else:
        peek_ch = s.pop()
        if peek_ch == '(':
            error_num = 4
            return i, error_num
        elif peek_ch == '{':
            error_num = 5
            return i, error_num
        elif peek_ch == '[':
            error_num = 6
            return i, error_num
        else: pass


string = input()
s = Stack()
error_idx = 0; error_num = 0

error_idx, error_num = check(string)

if error_num == 0:
    print(1)
#elif error_num == 1:
#elif error_num == 2:
#elif error_num == 3:
#elif error_num == 4:
#elif error_num == 5:
#elif error_num == 6:
else:
    print(f"{error_idx}  error{error_num}")