int i, j;          
int a, b;          
int gcd, lcm;

입력(i, j);       

a <- i;
b <- j;

while (b != 0) do
    int temp <- a % b;
    a <- b;
    b <- temp;
end while
gcd <- a;        

lcm <- (i * j) / gcd;

출력(gcd, lcm);
