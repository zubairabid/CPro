import math
for _ in range(input()):
	n, k = map( int, raw_input().split() )
	if(n==1):
		if(k==0):
			print 1
		else:
			print -1

		continue
	b=float(1)
	c=float(b+k*math.sqrt(2*n))
	d=float(b+(k*math.sqrt(2*n))/2)
	print b," ",c," ", 
	for i in range(n-2):
		print d," ",
	print ""