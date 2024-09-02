void mem_copy(char* source, char* dest, int num_bytes) {
    if (num_bytes == 0) return;
    for (int i=0; i<num_bytes; i++) {
        *(dest + i) = *(source + i); 
    }
}