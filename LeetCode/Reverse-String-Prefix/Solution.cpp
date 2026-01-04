string reversePrefix(string s, int k) {
    for (int8_t i = 0; i < k >> 1; ++i)
        swap(s[i], s[k-i-1]);    
    return s;
}