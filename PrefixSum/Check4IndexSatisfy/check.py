# Alag function Y aur Z dhoondhne ke liye
def checkYZ(N, A, q, Y, Z):
    r = -1
    for i in range(q, N):
        if i >= N - 3:
            return False
        if A[i] - A[q - 1] == Y:
            r = i + 1
            break
            
    # Agar Y nahi mila toh aage badhne ka koi fayda nahi
    if r == -1:
        return False

    s = -1
    for i in range(r, N):
        if i >= N - 2:
            return False
        if A[i] - A[r - 1] == Z:
            s = i + 1
            break
            
    # Agar Z bhi mil gaya toh path valid hai
    return s != -1

# Main function
def isPossible(N, A, X, Y, Z):
    if N <= 4:
        return False
        
    for i in range(1, N):
        A[i] += A[i - 1]
        
    p = 1
    q = 2
    xValues = []
    
    # While loop se saare possible X collect kare
    while p < N - 5 and q < N - 4:
        pqSum = A[q - 1] - A[p - 1]
        
        if pqSum == X:
            xValues.append(q)
            p += 1
            q += 1 # Ek mil gaya, ab aage check karo
        elif pqSum > X:
            p += 1
        else:
            q += 1
            
        # p aur q aapas me clash na karein uski safety
        if p >= q:
            q = p + 1
            
    # List mein se har possible q ko helper function mein daal kar check karo
    for qVal in xValues:
        if checkYZ(N, A, qVal, Y, Z):
            return True # Ek bhi bar true aaya toh seedha true return
            
    return False # Koi bhi q valid Y aur Z path nahi de paya

# Driver code
if __name__ == "__main__":
    N = 10
    X = 5
    Y = 7
    Z = 5
    A = [1, 3, 2, 2, 2, 3, 1, 4, 3, 2]

    # Function call
    answer = isPossible(N, A, X, Y, Z)
    if answer:
        print("YES")
    else:
        print("NO")