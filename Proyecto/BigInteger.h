#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <list> 
#include <vector>

using namespace std;

class BigInteger
{
    private:
        vector<int>number;

    public:
        BigInteger(string digits);
        BigInteger(BigInteger& copied);

        void add(BigInteger& num);
        void product(BigInteger& num);
        void substract(BigInteger& num);
        void quotient(BigInteger& num);
        void remainder(BigInteger& num);
        void pow(BigInteger& num);
        string toString(BigInteger& num);

        BigInteger operator+(BigInteger num);
        BigInteger operator-(BigInteger num);
        BigInteger operator*(BigInteger num);
        BigInteger operator/(BigInteger num);
        BigInteger operator%(BigInteger num);
        bool operator==(BigInteger num);
        bool operator<(BigInteger num);
        bool operator>(BigInteger num);
        bool operator<=(BigInteger num);
        bool operator>=(BigInteger num);

        BigInteger sumarListaValores(list<int> l1);
        BigInteger multiplicarListaValores(list<int> l1);
};

#endif
