import matplotlib.pyplot as plt
import numpy as np
import sympy as sp

Memory=[]
# 서열 데이터 입력
seq1="AABDBADB" 
seq2="AABDABAB"

def create_mat(nrows, ncols):
    mat=[]
    for i in range(nrows):
        mat.append([])
        for j in range(ncols):
            mat[i].append(0)
    return mat
    
def Binplot(se1, se2):
    global mat
    mat=create_mat(len(se1), len(se2))
    for i in range(len(se1)):
        for j in range(len(se2)):
            if seq1[i]==se2[j]:
                mat[i][j]=1
    return mat

def search_first_occ(seq, pattern):
    found=False
    i=0
    while i<len(seq)-len(pattern) and not found:
        j=0
        while j<len(pattern) and pattern[j]==seq[i+j]:
            j+=1
        if j==len(pattern):
            found=True
        else:
            i+=1
        if found:
            return i;
        else:
            return -1;
    
def search_all_occurrences(seq, pattern):
    res=[]
    for i in range(len(seq)-len(pattern)+1):
        j=0
        while j<len(pattern) and pattern[j]==seq[i+j]:
            j+=1
        if j==len(pattern):
            res.append(i)
    return res;

def BinFind():
    i=0
    for I in range(len(seq1)):
        j=0
        for J in range(len(seq2)):
            if mat[i][j]==1:
                Memory.append(mat[i][j])
                print([i, j])
            j+=1
        i+=1
    return Memory
##############################################################################
class BoyerMoore:
    
    def __init__(self, alphabet, pattern):
        self.alphabet=alphabet
        self.pattern=pattern
        self.preprocess()
        
    def preprocess(self):
        self.process_bcr()
        self.process_gsr()
    
    def process_bcr(self):
        self.occ={}
        for symbol in self.alphabet:
            self.occ[symbol]=-1
        for j in range(len(self.pattern)):
            c=self.pattern[j]
            self.occ[c]=j
    
    def process_gsr(self):
        self.f=[0]*(len(self.pattern)+1)
        self.s=[0]*(len(self.pattern)+1)
        i=len(self.pattern)
        j=len(self.pattern)+1
        self.f[i]=j
        while i>0:
            while j<=len(self.pattern) and self.pattern[i-1] != self.pattern[j-1]:
                if self.s[j]==0:
                    self.s[j]=j-i
                j=self.f[j]
            j-=1
            j-=1
        j=self.f[0]
        for i in range(len(self.pattern)):
            if self.s[i]==0:
                self.s[i]=j
            if i==j:
                j=self.f[j]
    
    def search_pattern(self, text):
        res=[]
        i=0
        while i<=len(text)-len(self.pattern):
            j=len(self.pattern)-1
            while j>=0 and self.pattern[j]==text[i+j]:
                j-=1
            if j<0:
                res.append(i)
                i+=self.s[0]
            else:
                c=text[i+j]
                i+=max(self.s[j+i], j-self.occ[c])
        return res
        
#def test():
#    bm=BoyerMoore("ACTG", "ACCA")
#    print(bm.search_pattern("ATAGAACCAATGAACCATGATGAACCATGGATACCCAACCACC"))
    
#test()

AR=np.array(Binplot(seq1, seq2))
print(AR)
plt.xlabel(seq1)
plt.ylabel(seq2)
plt.imshow(AR)
BinFind()