// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    char a_1; 		// r8{40}
    char *b; 		// r9

    if (LOCATION_39.bits.SMPDUP == 0) {
        OPTIONS.bits.bit5 = 1;
        OPTIONS.bits.CARB = 0;
        if (OPTIONS.bits.bit5 == 0) {
            OPTIONS.bits.bit1 = 1;
        }
        LOCATION_24.bits.bit7 = 0;
        LOCATION_24.bits.bit6 = 0;
        LOCATION_24.bits.bit1 = 1;
    }
    if (BTS.bits.bit6 == 1) {
        if (BTS.bits.MASTER == 1) {
            *(char*)b = BTS.byte & 0xc0;
        }
        if (LOCATION_52.bits.SIMP == 1) {
            *(char*)b = LOCATION_52.byte & 0xc0;
            a_1 = LOCATION_24.byte & 0xc0 | b;
        }
    }
    return a_1;
}

