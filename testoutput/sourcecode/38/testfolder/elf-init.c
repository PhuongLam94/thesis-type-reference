// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    OPTIONS2.bits.TESTSDOWNS2 = 1;
    OPTIONS.bits.COMP = 0;
    return OPTIONS.byte;
}

