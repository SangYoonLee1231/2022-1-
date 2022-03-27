# 3번
num = input()

# 리스트 슬라이싱을 이용하여 입력 받은 정수 num의 자릿수들을 거꾸로 배열합니다.
# (리스트 슬리이싱은 문자열에서도 사용할 수 있습니다.)
num = num[::-1]

# 거꾸로 배열한 정수를 맨 왼쪽부터 순서대로 탐색하며 출력합니다.
gate = False
for i, elem in enumerate(num):
	if elem == '0':
		# 거꾸로 배열한 수가 0으로 시작하는 경우
		if i == 0:
			gate = True
		
		# 거꾸로 배열한 수가 0으로 시작하는 경우만 값을 출력하지 않습니다.
		if gate:
			pass
		# 중간에 오는 0은 그대로 출력합니다.
		else:
			print(elem, end="")
	# 0으로 시작하던 배열에 다른 값이 나오면 그 뒤의 0은 출력해야 하므로 gate를 False로 바꿉니다.
	else:
		gate = False
		print(elem, end="")