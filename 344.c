char* reverseString(char* s)
{
    int len = strlen(s);
    int i;
    for(i=0;i<=(len/2-1);i++)
    {
        s[i] = s[i]+s[len-1-i];
        s[len-1-i] = s[i]-s[len-1-i];
        s[i] = s[i]-s[len-1-i];
    }
    return s;
}


