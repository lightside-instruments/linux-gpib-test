#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int ret;
    int brd;
    short wait_result;
    short is_srq_active;
    //dev=ibdev(0,1,0,T3s,0,0);
    brd=ibfind("raspi_gpio_interface");
    wait_result=-1;
    TestSRQ(brd, &is_srq_active);
    printf("is_srq_active=%d\n",(int)is_srq_active);
    printf("waiting...\n");
    do {
        WaitSRQ(brd, &wait_result);
        printf("%u\n", (unsigned int)wait_result);
    } while(wait_result==0);
    printf("%u\n", (unsigned int)wait_result);
    assert(wait_result==1 || wait_result==0);
    printf("done\n");
}
