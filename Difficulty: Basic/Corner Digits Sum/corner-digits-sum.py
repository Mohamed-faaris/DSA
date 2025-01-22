#User function Template for python3

class Solution:
	def corner_digitSum(self, n):
		# Code here
		if(n//10 == 0):
		    return n
		s = str(n)
		return int(s[0]) + int(s[-1])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n= int(input())
		ob = Solution()
		ans = ob.corner_digitSum(n)
		print(ans)
# } Driver Code Ends