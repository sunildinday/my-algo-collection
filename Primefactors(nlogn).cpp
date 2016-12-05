//after some pre-processnig we can find all prime factor in logn time
int sp[10000001];
bool prime[10000001];
//preprocessing function
void sieve()
{
    for(int i=2;i<=10000001;i+=2)
        sp[i]=2;
    for(int i=3;i*i<=10000001;i+=2)
    {
        if(!prime[i])
        {
            sp[i]=i;
            for(int j=i*2;(j)<=10000001;j+=i)
{
                    prime[j]=true;
                    sp[j]=i;
                }
        }
    }
    for(int i=3;i<=10000001;i+=2)
        if(!prime[i])
            sp[i]=i;
}
//function to find prime factors of k in logn time
while(k>1)
{
    fact.push_back(sp[k]);
    k/=sp[k];
}
//fact has all the prime factor of k
