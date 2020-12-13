// Function Call from within a function Program
int sum (int var0, int var1, int var2, int var3, int var4);

int main(void)
{
    int a = 5;
    int b = 12;
    int c = 4;
    int d = 3;
    int e = 10;
    int ans;
    
    
    ans = sum(a,b,c,d,e);
    
    (void)ans;
    
    return 0;
}

int sum (int var0, int var1, int var2, int var3, int var4) {
    int lvar0 = var0;
    int lvar1 = var1;
    int lvar2 = var2;
    int lvar3 = var3;
    int lvar4 = var4;
    
    int sum;
    
    sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
    
    return sum;
}
