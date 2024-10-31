#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int i;
    int ret;
//    int dev;
    int brd;

    short wait_result;
//    dev=ibdev(0,1,0,T3s,0,0);
    brd=ibfind("gpib0");
    printf("Setting ibtmo to T10s\n");
    ibtmo(brd,T10s);
    printf("ibsta==0x%08X\n", ibsta);
    printf("iberr==0x%08X\n", iberr);
for(i=0;i<10;i++) {
    printf("waiting event=%d ...\n", i);
//    ret = ibwait(dev, RQS);
    ret = ibwait(brd, SRQI);
    printf("ibsta==0x%08X\n", ibsta);
    printf("iberr==0x%08X\n", iberr);
//    assert(ibsta&RQS);
    assert(ibsta&SRQI);
    printf("done\n");

    sleep(1);
}
    return 0;
}
