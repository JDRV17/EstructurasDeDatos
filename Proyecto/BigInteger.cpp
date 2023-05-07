#include "BigInteger.h"
#include <vector>

BigInteger::BigInteger(string digits)
{
    int i = 0;
    vector<int>number;
    while(digits[i]!='/0')
    {
        number.push_back((int)digits[i]);
        ++i;
    }
}

BigInteger::BigInteger(BigInteger& copied)
{
    int i;
    vector<int>newnumber;
    for(i = 0; i < number.size(); i++)
    {
        newnumber.push_back(number[i]);
    }
}

void add(BigInteger& num)
{
    
}

