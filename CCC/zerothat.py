N = int(raw_input())
nums = [int(raw_input()) for i in range(N)]
newnums = []
x = 0
while x < len(nums):
	if nums[x] == 0 and x > 0:
		newnums.pop(-1)
	else:
		newnums.append(nums[x])
	x+=1
total = 0
for n in newnums:
	total += n
print total