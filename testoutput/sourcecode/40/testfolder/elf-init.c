// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    OPTIONS2.bits.bit4 = 1;
    OPTIONS.bits.bit3 = 0;
    return OPTIONS.byte;
}

