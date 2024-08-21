ll lowNum(ll n)
{
    return (n&~(n-1));
}

ll lowBit(ll n)
{
    return log2(n&~(n-1));
}