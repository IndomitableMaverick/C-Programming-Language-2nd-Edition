/* strindex: return index of t in s, -1 if none */ 
int strindex(const char *s, const char *t) 
{ 
    const char *start_s, *start_t, *cur_s;
    start_s = s, start_t = t;
    
    while(*s) {
        t = start_t;
        cur_s = s;
        while(*t && *cur_s == *t)
            ++cur_s, ++t;
        if(!*t)
            return s - start_s;
        ++s;
    }
    return -1;
}