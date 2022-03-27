a, b, c = tuple(map(int, input().split()))


# 두 수의 최대공약수를 계산하는 함수를 작성합니다.
def gcd(x, y):
	while y != 0:
		temp = x % y
		x = y
		y = temp

	return x

# 두 수의 최소공배수를 계산하는 함수를 작성합니다.
def lcm(x, y, gcd):
	return (x * y) // gcd


# GCD(a, b, c) == GCD(GCD(a, b), c)임을 이용하여 GCD(a, b, c)를 계산합니다.
gcd_ab = gcd(a, b)
gcd_abc = gcd(gcd_ab, c)

# LCM(a, b, c) == LCM(LCM(a, b), c)임을 이용하여 LCM(a, b, c)를 계산합니다.
lcm_ab = lcm(a, b, gcd_ab)
lcm_abc = lcm(lcm_ab, c, gcd(lcm_ab, c))


# 결과를 출력합니다.
print(gcd_abc, lcm_abc)