int addDigits(int num)
{
    int ans = num;
    int temp = 0;

    while(ans>=10)
    {
        temp++;
        ans = ans/10;
    }

    if(temp==0)
    {
        return ans;
    }

    int sum=0;

    for(;temp>=0;temp--)
    {
        sum += num%10;
        num = num/10;
    }

    return addDigits(sum);
}