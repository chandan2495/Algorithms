def squareDigits(n):
	sum=0
	while n:
		temp=n%10
		sum+=(temp**2)
		n/=10
	return sum

count=0
for i in range(2,10000001):
	temp=i
	while temp!=89 and temp!=1:
		temp=squareDigits(temp)
	if temp==89:
		count+=1	
	

print count