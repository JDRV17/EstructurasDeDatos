#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <list> 
#include <vector>

using namespace std;

class BigInteger
{
    private:
        

    public:
        vector<int>number;
        bool sign;

        BigInteger();
        BigInteger(string& digits);
        BigInteger(const BigInteger& copied);

        void add(BigInteger& num);
        void product(BigInteger& num);
        void substract(BigInteger& num);
        void quotient(BigInteger& num);
        void remainder(BigInteger& num);
        void pow(int& num);
        string toString(BigInteger& num);

        void operator+(BigInteger& num);
        void operator-(BigInteger& num);
        void operator*(BigInteger& num);
        void operator/(BigInteger& num);
        void operator%(BigInteger& num);
        bool operator==(BigInteger& num);
        bool operator<(BigInteger& num);
        bool operator>(BigInteger& num);
        bool operator<=(BigInteger& num);
        bool operator>=(BigInteger& num);

        BigInteger sumarListaValores(list<BigInteger>& l1);
        BigInteger multiplicarListaValores(list<BigInteger>& l1);
};

#endif

