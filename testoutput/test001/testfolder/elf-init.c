// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    if (LOCATION_11.bits.SMPDUP != 0) {
        if (OPTIONS2.bits.bit6 == 1) {
            BTS.bits.MASTER = 1;
            OPTIONS2.bits.SIMP = 0;
        }
    } else {
        LOCATION_38.bits.TESTUPS6 = 1;
        *(__size8*)(SLVFLGMAP + 20) = LOCATION_38.byte;
    }
    return LOCATION_38.byte;
}

