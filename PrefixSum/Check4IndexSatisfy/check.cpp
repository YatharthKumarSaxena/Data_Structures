#include <iostream>
#include <vector>
using namespace std;

// Neeche wala part: Alag function Y aur Z dhoondhne ke liye
bool checkYZ(int N, int A[], int q, int Y, int Z) {
    int r = -1;
    for(int i = q; i < N; i++){
        if(i >= N-3) return false;
        if(A[i] - A[q-1] == Y){
            r = i + 1;
            break;
        }
    }
    
    // Agar Y nahi mila toh aage badhne ka koi fayda nahi
    if (r == -1) return false; 

    int s = -1;
    for(int i = r; i < N; i++){
        if(i >= N-2) return false;
        if(A[i] - A[r-1] == Z){
            s = i + 1;
            break;
        }
    }
    
    // Agar Z bhi mil gaya toh path valid hai
    return (s != -1);
}

// Main function
bool isPossible(int N, int A[], int X, int Y, int Z) {
    if(N <= 4) return false;
    
    for(int i = 1; i < N; i++){
        A[i] += A[i-1];
    }
    
    int p = 1;
    int q = 2;
    vector<int> xValues;
    
    // While loop se 'pqSum != X' hata diya taaki ye end tak saare X collect kare
    while(p < N-5 && q < N-4) {
        int pqSum = A[q-1] - A[p-1];
        
        if(pqSum == X){
            xValues.push_back(q);
            p++;
            q++; // Ek mil gaya, ab aage check karo
        }
        else if(pqSum > X){
            p++;
        }
        else {
            q++;
        }
        
        // p aur q aapas me clash na karein uski safety
        if (p >= q) {
            q = p + 1;
        }
    }
    
    // Vector mein se har possible q ko helper function mein daal kar check karo
    for(int qVal : xValues) {
        if(checkYZ(N, A, qVal, Y, Z)) {
            return true; // Ek bhi bar true aaya toh seedha true return
        }
    }
    
    return false; // Koi bhi q valid Y aur Z path nahi de paya
}

// Driver code
int main()
{
    int N = 10, X = 5, Y = 7, Z = 5;
    int A[] = { 1, 3, 2, 2, 2, 3, 1, 4, 3, 2 };

    // Function call
    int answer = isPossible(N, A, X, Y, Z);
    if (answer == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}