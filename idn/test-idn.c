#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int ret;
    int dev;
    char buffer[1024];
    short wait_result;
    dev=ibdev(0,1,0,T3s,0,0);
    ibwrt(dev,"*IDN?\n",6);
    ret=ibrd(dev, (void*)buffer, 1024);
    printf("%d\n",ret);
    printf("%d\n",ibcnt);
    assert(ibcnt>0);
    buffer[ibcnt]=0;
    printf("%s\n",buffer);
}
