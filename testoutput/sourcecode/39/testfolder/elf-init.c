// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    OPTIONS2.bits.bit1 = 1;
    OPTIONS.bits.CBR = 0;
    return OPTIONS.byte;
}

