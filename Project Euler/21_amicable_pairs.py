import numpy
mp=numpy.zeros(10005,int);
def preprocess():
    mx=0
    for x in range(1,10000):
        sum=0;
        i=1;
        while (i*i<=x):
            if x%i==0:
                sum+=i;
                if int(x/i) !=i and int(x/i)!=x:
                    sum+=int(x/i);
            i=i+1            
        mp[x]=sum;
        #print 'sum of ',x,' is ',sum;
        if mx<sum:
            mx=sum;

    return mx;

sz=preprocess();
print "PREPROCESS DONE "
done=numpy.zeros(sz+5,int);
for i in range(1,10000):
    done[mp[i]]=1;
sum=0;
for i in range(1,10000):
    kk=mp[i];
    if(kk>=10000):continue
    if ( mp[kk]==i and i > kk):
        sum+= (i + kk);
print sum;

