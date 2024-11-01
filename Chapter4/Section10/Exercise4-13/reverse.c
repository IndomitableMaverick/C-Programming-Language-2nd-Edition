/* reverses the string s in place (recursive version) */
void reverse(char s[], int from, int to)
{
    if(from < to){
        char c;
        c = s[from], s[from] = s[to], s[to] = c;
        reverse(s, from + 1, to - 1);
    }
}