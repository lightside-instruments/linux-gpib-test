#include <stdio.h>
#include <unistd.h>
#include <gpib/ib.h>
#include <assert.h>

int main() {
    int i;
    int ret;
    int dev;
    int brd;
    int dev_gpib1;
    int iface_gpib;

    brd=ibfind("gpib0");
    dev_gpib1=ibdev(0,1,0,T3s,0,0);

    printf("Setting ibtmo to T10s\n");
    ibtmo(brd,T10s);
    printf("ibsta==0x%08X\n", ibsta);
    printf("iberr==0x%08X\n", iberr);

    iface_gpib = brd;
    dev_gpib1 = dev;

    while(1) {

        char SRQ_result1;

        ibwait(iface_gpib,SRQI);//iface_gpib:board name
        printf("ibsta==0x%08X\n", ibsta);
        printf("iberr==0x%08X\n", iberr);

        if (ibsta & ERR) {
            printf("ibwait error: %d\n", iberr);
        }

        ibrsp(dev_gpib1, &SRQ_result1); // SRQ polling
        printf("ibsta==0x%08X\n", ibsta);
        printf("iberr==0x%08X\n", iberr);
        if (ibsta & ERR) {
            printf("ibrsp error: %d\n", iberr);
            continue;//In case of error, measurement data is not read.
        }
	if(SRQ_result1 & 0x01 /*?*/){//If the status byte means SRQ transmission
	    usleep(1000);
	    char buf[255]={};
            ibrd(dev_gpib1, buf, 255);//dev_gpib1:device name, Read the measurement data
	}
    }
}
