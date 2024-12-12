int lengthOfLongestSubstring(char* s) {
    int winstart = 0, winend;
    size_t size = strlen(s);
    int hashtable[256];
    int maxlen = 0;
    memset(hashtable, -1, 256);

    for (winend = 0; winend < size; ++winend) {
        char c = s[winend];  // check this char
        if (hashtable[c] != -1) {
            winstart = (hashtable[c] >= winstart) ? hashtable[c] + 1 : winstart; 
        }
        hashtable[c] = winend;
        int count = winend - winstart + 1;
        maxlen = (count > maxlen) ? count : maxlen;
    }

    return maxlen;
}