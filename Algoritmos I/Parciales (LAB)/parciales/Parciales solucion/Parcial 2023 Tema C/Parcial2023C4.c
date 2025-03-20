#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 2
typedef struct {
    int addr;
    int value;
    int datum;
    bool present;
} babbage_output;

babbage_output alonzo_to_babbage(int tam, int a_output[]) {
    assert(tam == 2 || tam == 3); 

    babbage_output b_out;
    b_out.addr = a_output[0];
    b_out.value = a_output[1];

    if (tam == 2) {
        b_out.datum = 0;
        b_out.present = false;
    } else if (tam == 3) {
        b_out.datum = a_output[2];
        b_out.present = true;
    }
    return b_out;
}

int main (void) {
    int a_output[N] = { 4242, 10 };

    babbage_output b_output1 = alonzo_to_babbage(N, a_output);

    babbage_output b_out1 = alonzo_to_babbage(2, a_output);
    printf("Babbage Output 1: addr=%d, value=%d, datum=%d, present=%s\n",
           b_out1.addr, b_out1.value, b_out1.datum, b_out1.present ? "true" : "false");

}
    