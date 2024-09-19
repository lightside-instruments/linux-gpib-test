#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int ret;
    int dev;
    short wait_result;
    dev=ibdev(0,1,0,T3s,0,0);
    wait_result=-1;
    printf("waiting...\n");
    WaitSRQ(dev, &wait_result);
    printf("%u\n", (unsigned int)wait_result);
    assert(wait_result==1 || wait_result==0);
    printf("done\n");
}
