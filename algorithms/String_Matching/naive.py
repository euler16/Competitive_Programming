# Naive approach to pattern matching

def isSubstring(pattern,text):
	n = len(text)
	m = len(pattern)
	for s in range(n-m):
		if pattern == text[s+1:s+m+1]:
			print("pattern match found at "+str(s+1))

text = input("Enter text: ")
pattern = input("Enter pattern: ")

isSubstring(pattern,text)