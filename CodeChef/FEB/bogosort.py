def gcd2(a,b):
    while b!=0:
        c=a%b;
        a=b;
        b=c;
    return a;

def gcd(a,b):
    return gcd2(a,b);
    if b==0:
        return a;
    else:
        return gcd(b,a%b);
    
def fact(n):
    ans=1;
    while n>0:
        ans*=n;
        n=n-1;
    return ans;


#A/B + C/D
def add(A,B,C,D):
    g=gcd(B,D);
    lcm=(B/g)*D;
    a1=D/g;
    a2=B/g;
    a=A*a1 + C*a2;
    b=lcm;
    g=gcd(a,b);
    a/=g;
    b/=g;
    #print A,"/",B," + ",C,"/",D," = ",a,"/",b
    return [a,b];

f=[1 for i in range(200)];
num=[0 for i in range(200)];
den=[1 for i in range(200)];
K=[0l for i in range(200)];
K[0]=1l;
K[1]=1l;
for i in range(1,152):
    #print "for ",i," is ",fact(i);
    f[i-1]=fact(i-1);
for i in range(2,152):
    K[i]=f[i]-(2*f[i-1]-f[i-2]);

#for i in range(7,19):
    #aD=add(i,i+1,i+2,i+3);
    #print "val of ",i,"/",i+1," and ",i+2,"/",i+3," is ",aD[0],"/",aD[1]


num[0]=0;
num[1]=0;
num[2]=2;
num[3]=10;
den[3]=3;


def solve(n):
    tn=0;
    td=1;
    cn=0;
    cd=0;
    for i in range(2,n):
       cn=((n-i+1)*K[i])*num[i];
       cd=den[i];
       T=add(tn,td,cn,cd);
       tn=T[0];
       td=T[1];
    T=add(f[n],1,tn,td);
    tn=T[0];
    td=T[1];
    p1=2*f[n-1]-f[n-2];
    td*=p1;
    g=gcd(tn,td);
    tn/=g;
    td/=g;
    num[n]=tn;
    den[n]=td;
    return;

    
for i in range(4,151):
    solve(i);
    #print "FOR ",i," = ",num[i],"/",den[i];
    
tt=input("");
tests=int(tt);
while tests>0:
    tests=tests-1;
    nn=input("");
    N=int(nn);
    if den[N]!=1:
        print (str((num[N]))+"/"+str((den[N])));
    else:
        print(str(num[N]));
