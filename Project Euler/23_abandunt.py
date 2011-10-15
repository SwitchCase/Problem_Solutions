max= 28123;
arr = [0 for i in range(0,max+10)];
sumd = [1 for i in range(0,max+10)];
def preprocess():
    for i in range(1,max+1):
        j=2;
        #print "doing ",i
        while(j*j <=i):
            if (i%j==0):
                sumd[i]+=j;
                if (i/j != j):sumd[i]+=i/j;
            j=j+1;

        if (sumd[i] > i):
            arr[i]=1;
    print "PREPROCESSING DONE"
    return;
nums = [0 for i in range(0,2*max + 10)];
def search(arr,val):
    print "searching for ",val
    lo=0;
    hi=len(arr);
    while(lo<=hi):
        mid=(lo+hi)/2;
        if arr[mid]==val: return mid;
        elif arr[mid]>val: hi=mid-1;
        else: lo=mid+1;
    return -1;

print "START"

preprocess();
ans=0;
use=[];
for i in range(1,max+1):
    if arr[i]==1:
        use.append(i);
poss = [0 for i in range(0,2*max + 10)];


for i in range(1,max+1):
    j=0;
    ff=0;
    while(j<len(use)):
        if use[j]>=i:break;
        left=i-use[j];
        if(arr[left]==1):
            ff=1;
            break;
        j=j+1;
    if ff==0: ans=ans+i;

print ans;









            
