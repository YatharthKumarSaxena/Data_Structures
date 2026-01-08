from os import *
from sys import *
from collections import *
from math import *





def removeAllOccurrencesOfChar(string,c):
    
    #Your code goes here.

    ans = ""
    for i in range(len(string)):
        if string[i]!=c :
            ans += string[i]
    return ans

    










string = input()
c = input()
output = removeAllOccurrencesOfChar(string,c)
print(output)
