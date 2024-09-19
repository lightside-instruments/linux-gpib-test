#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int ret;
    int dev;
    short wait_result;
    dev=ibdev(0,1,0,T3s,0,0);
    printf("Setting ibtmo to T10s\n");
    ibtmo(dev,T10s);
    printf("ibsta==0x%08X\n", ibsta);
    printf("iberr==0x%08X\n", iberr);
    printf("waiting...\n");
    ret = ibwait(dev, RQS);
    printf("ibsta==0x%08X\n", ibsta);
    printf("iberr==0x%08X\n", iberr);
    assert(ibsta&RQS);
    printf("done\n");
}
