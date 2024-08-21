ll calcSumOfMultiplesFromOneToN(ll a,ll n)
{
    // How many numbers a in range from 1 -> n
    ll numberOfMultiples=n/a;
    // calculate the sum of the numbers from 1 - > n/a 
    // a + 2 * a + 3 * a .... + (n/a)*a  -> a*(1+2+3...+(n/a))
    ll sum=(numberOfMultiples*(numberOfMultiples+1))/2;
    return a*sum;
}