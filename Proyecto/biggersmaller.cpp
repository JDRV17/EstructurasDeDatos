#include <vector>
#include <stack>

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


BigInteger::BigInteger()
{
    vector<int> num;
    number = num;
    sign = true;
}

BigInteger::BigInteger(string& digits)
{
    int i;
    if(digits[0] == '-')
    {
        sign = false;
        i = 1;
        digits[0] = '0';
    }
    else
    {
        sign = true;
        i = 0;
    }
    while(i < digits.size())
    {
        number.push_back(digits[i] - 48);
        ++i;
    }
}

BigInteger::BigInteger(const BigInteger& copied)
{
    int i;
    for(i = 0; i < copied.number.size(); i++)
    {
        number.push_back(copied.number[i]);
    }
    sign = copied.sign;
}

void BigInteger::add(BigInteger& num)
{
    int size1, size2, i;
    vector<int> aux;
    size1 = this->number.size();
    size2 = num.number.size();
    if(this->sign != num.sign)
    {
        num.sign = this->sign;
        substract(num);
    }
    else
    {
        if(size1 > size2)
        {
            for(i = 0; i < size2; i++)
            {
                if((this->number[size1 - (i+1)] + num.number[size2 - (i+1)]) < 10)
                {
                    this->number[size1 - (i+1)] = this->number[size1 - (i+1)] + num.number[size2 - (i+1)];
                }
                else
                {
                    this->number[size1 - (i+1)] = (this->number[size1 - (i+1)] + num.number[size2 - (i+1)])%10;
                    this->number[size1 - (i+2)]++; 
                }
            }
        }
        else
        {
            aux = num.number;
            num.number = this->number;
            this->number = aux;
            for(i = 0; i < size1; i++)
            {
                if((this->number[size2 - (i+1)] + num.number[size1 - (i+1)]) < 10)
                {
                    this->number[size2 - (i+1)] = this->number[size2 - (i+1)] + num.number[size1 - (i+1)];
                }
                else
                {
                    this->number[size2 - (i+1)] = (this->number[size2 - (i+1)] + num.number[size1 - (i+1)])%10;
                    this->number[size2 - (i+2)]++; 
                }
            }
            num.number = aux;
            aux.clear();
        }
    }
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    else
    {
        cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    cout <<"\n";
}

void BigInteger::substract(BigInteger& num)
{
    int size1, size2, i;
    vector<int> aux;
    size1 = this->number.size();
    size2 = num.number.size();
    if(this->sign != num.sign)
    {
        num.sign = this->sign;
        this->add(num);
    }
    else
    {
        if(size1 >= size2 && this->number[0] > num.number[0])
        {
            for(i = 0; i < size2; i++)
            {
                if((this->number[size1 - (i+1)] >= num.number[size2 - (i+1)]))
                {
                    this->number[size1 - (i+1)] = this->number[size1 - (i+1)] - num.number[size2 - (i+1)];
                }
                else
                {
                    this->number[size1 - (i+1)] = (this->number[size1 - (i+1)] + 10) - num.number[size2 - (i+1)];
                    this->number[size1 - (i+2)]--; 
                }
            }
        }
        else
        {
            this->sign = false;
            aux = num.number;
            num.number = this->number;
            this->number = aux;
            aux.clear();

            for(i = 0; i < size2; i++)
            {
                if((this->number[size1 - (i+1)] >= num.number[size2 - (i+1)]))
                {
                    this->number[size1 - (i+1)] = this->number[size1 - (i+1)] - num.number[size2 - (i+1)];
                }
                else
                {
                    this->number[size1 - (i+1)] = (this->number[size1 - (i+1)] + 10) - num.number[size2 - (i+1)];
                    this->number[size1 - (i+2)]--; 
                }
            }
        }
    }
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    else
    {
        cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    cout <<"\n";
}

void BigInteger::product(BigInteger& num)
{
    int size1, size2, i, j, pilsize, lleva = 0;
    vector<int> aux, vectobi;
    vector<BigInteger> sumas;
    stack<int> stacktobi;
    BigInteger sum2, sumfin;
    size1 = this->number.size();
    size2 = num.number.size();

    if(this->sign != num.sign)
    {
        this->sign = false;
    }
    else
    {
        this->sign = true;
    }
    if(size1 > size2)
    {
        for(i = 0; i < size2; i++)
        {
            vectobi.clear();
            for(j = 0; j < i; j++)
            {
                stacktobi.push(0);
            }
            for(j = 0; j < size1; j++)
            {
                if((this->number[size1 - (j+1)] * num.number[size2 - (i+1)]) < 10)
                {
                    stacktobi.push((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])+lleva);
                    lleva = 0;
                }
                else
                {
                    if((((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10)+lleva) < 10)
                    {
                        stacktobi.push(((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10)+lleva);
                        lleva = 0;
                    }
                    else
                    {
                        stacktobi.push((((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10)+lleva)%10);
                        lleva = ((((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10)+lleva) - ((((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10)+lleva)%10))/10;
                    }
                    lleva = lleva + (((this->number[size1 - (j+1)] * num.number[size2 - (i+1)]) - ((this->number[size1 - (j+1)] * num.number[size2 - (i+1)])%10))/10); 
                    if(this->number[size1 - (j+2)]>=10)
                    {
                        stacktobi.push(lleva);
                    }
                }
            }
            pilsize = stacktobi.size();
            for(j = 0; j < pilsize; j++)
            {
                vectobi.push_back(stacktobi.top());
                stacktobi.pop();
            }
            sum2.number = vectobi;
            sumas.push_back(sum2);
        }
        
        sumfin = sumas[0];
        
        for(i = 1; i < sumas.size(); i++)
        {
            sumfin.add(sumas[i]);
        }
        this->number = sumfin.number;
    }
    else
    {
        aux = num.number;
        num.number = this->number;
        this->number = aux;

        for(i = 0; i < size1; i++)
        {
            vectobi.clear();
            for(j = 0; j < i; j++)
            {
                stacktobi.push(0);
            }
            for(j = 0; j < size2; j++)
            {
                if((this->number[size2 - (j+1)] * num.number[size1 - (i+1)]) < 10)
                {
                    stacktobi.push((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])+lleva);
                    lleva = 0;
                }
                else
                {
                    if((((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10)+lleva) < 10)
                    {
                        stacktobi.push(((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10)+lleva);
                        lleva = 0;
                    }
                    else
                    {
                        stacktobi.push((((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10)+lleva)%10);
                        lleva = ((((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10)+lleva) - ((((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10)+lleva)%10))/10;
                    }
                    lleva = lleva + (((this->number[size2 - (j+1)] * num.number[size1 - (i+1)]) - ((this->number[size2 - (j+1)] * num.number[size1 - (i+1)])%10))/10); 
                    if(this->number[size2 - (j+2)]>=10)
                    {
                        stacktobi.push(lleva);
                    }
                }
            }
            pilsize = stacktobi.size();
            for(j = 0; j < pilsize; j++)
            {
                vectobi.push_back(stacktobi.top());
                stacktobi.pop();
            }
            sum2.number = vectobi;
            sumas.push_back(sum2);
        }
        
        sumfin = sumas[0];
        
        for(i = 1; i < sumas.size(); i++)
        {
            sumfin.add(sumas[i]);
        }
        this->number = sumfin.number;
        num.number = aux;
        aux.clear();
    }
    
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            //cout << this->number[i];
        }
    }
    else
    {
        //cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            //cout << this->number[i];
        }
    }
    //cout <<"\n";
}

void BigInteger::quotient(BigInteger& num)
{
    string charind1, charind2;
    int size1, size2, i, j;
    BigInteger ans, dividendo, index, div1, div2, sumita;
    sumita.number.push_back(1);
    size1 = this->number.size();
    size2 = num.number.size();
    if(this->sign != num.sign)
    {
        this->sign = false;
    }
    else
    {
        this->sign = true;
    }
    if(size2 > size1)
    {
        this->number.clear();
        this->sign = true;
        this->number.push_back(0);
    }
    else
    {
        for(i = 0; i < size2; i++)
        {
            dividendo.number.push_back(this->number[i]);
        }
        if(dividendo < num)
        {
            dividendo.number.push_back(this->number[i]);
        }

        while(dividendo > num)
        {
            for(i = 0; i < 10; i++)
            {
                div1 = num;
                div2 = num;
                charind1 = i + 48;
                index = charind1;
                for(j = 0; j < div1.number.size(); j++)
                {
                    cout <<div1.number[j];
                }
                cout << "a  ";
                div1.product(index);
                for(j = 0; j < div1.number.size(); j++)
                {
                    cout <<div1.number[j];
                }
                cout << "b  ";
                for(j = 0; j < index.number.size(); j++)
                {
                    cout <<index.number[j];
                }
                cout << "c  ";
                charind2 = (i + 1) + 48;
                cout << charind2 << "d   ";
                index = charind2;
                div2.product(index);
                /*for(j = 0; j < dividendo.number.size(); j++)
                {
                    cout <<dividendo.number[j];
                }*/
                if((div1 < dividendo) & (div2 > dividendo))
                {
                    ans.number.push_back(i);
                    dividendo.substract(div1);
                    
                    i = 0;
                }
            }
            break;
        }
        this->number.clear();
        this->number = ans.number;
    }  
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    else
    {
        cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    cout <<"\n"; 
}

void BigInteger::remainder(BigInteger& num)
{
    string charind1, charind2;
    int size1, size2, i, j;
    BigInteger ans, dividendo, index, div1, div2;
    size1 = this->number.size();
    size2 = num.number.size();
    this->sign = true;
    if(size2 > size1)
    {
        this->number.clear();
        this->sign = true;
        this->number.push_back(0);
    }
    else
    {
        for(i = 0; i < size2; i++)
        {
            dividendo.number.push_back(this->number[i]);
        }
        if(dividendo < num)
        {
            dividendo.number.push_back(this->number[i]);
        }

        while(dividendo > num)
        {
            for(i = 0; i < 10; i++)
            {
                div1 = num;
                div2 = num;
                charind1 = i + 48;
                index = charind1;
                for(j = 0; j < div1.number.size(); j++)
                {
                    cout <<div1.number[j];
                }
                cout << "a  ";
                div1.product(index);
                for(j = 0; j < div1.number.size(); j++)
                {
                    cout <<div1.number[j];
                }
                cout << "b  ";
                for(j = 0; j < index.number.size(); j++)
                {
                    cout <<index.number[j];
                }
                cout << "c  ";
                charind2 = (i + 1) + 48;
                cout << charind2 << "d   ";
                index = charind2;
                div2.product(index);
                /*for(j = 0; j < dividendo.number.size(); j++)
                {
                    cout <<dividendo.number[j];
                }*/
                if((div1 < dividendo) & (div2 > dividendo))
                {
                    dividendo.substract(div1);
                    
                    i = 0;
                }
            }
            break;
        }
        for(i = 0; i < dividendo.number.size(); i++)
        {
            ans.number.push_back(dividendo.number[i]);
        }
        this->number.clear();
        this->number = ans.number;
    }  
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    else
    {
        cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    cout <<"\n"; 
}

void BigInteger::pow(int& num)
{
    BigInteger num2, num3;
    num2.sign = this->sign;
    num2.number = this->number;
    int i;
    if(num == 0)
    {
        this->number.clear();
        this->number.push_back(1);
    }
    if(this->sign == true && num > 0)
    {
        for(int i = 1; i < num; i++)
        {
            this->product(num2);
        }
    }
    if(this->sign == false && num > 0)
    {
        if(num%2 == 0)
        {
            for(int i = 1; i < num; i++)
            {
                this->product(num2);
            }
            this->sign = true;
        }
        else
        {
            for(int i = 1; i < num; i++)
            {
                this->product(num2);
            }
        }
    }
    if(num < 0)
    {
        num3.number.push_back(1);
        num = num*(-1);
        for(int i = 1; i < num; i++)
        {
            this->product(num2);
        }
        num2.number = this->number;
        num3.quotient(num2);
        this->number = num3.number;
    }
    if(this->sign)
    {
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
    else
    {
        cout << "-";
        for(i = 0; i < this->number.size(); i++)
        {
            cout << this->number[i];
        }
    }
}
void BigInteger::operator+(BigInteger& num)
{
    this->add(num);
}
void BigInteger::operator-(BigInteger& num)
{
    this->substract(num);
}
void BigInteger::operator*(BigInteger& num)
{
    this->product(num);
}
void BigInteger::operator/(BigInteger& num)
{
    this->quotient(num);
}
void BigInteger::operator%(BigInteger& num)
{
    this->remainder(num);
}
bool BigInteger::operator<(BigInteger& num)
{
    int i = 0, suma1 = 0, suma2 = 0, j = 0;
    bool ans, exit = false;
    for (j = 0; j < this->number.size(); j++)
    {
        suma1 = suma1 + this->number[j];
        suma2 = suma2 + num.number[j];
    }
    if(this->sign != num.sign)
    {
        if(this->sign == true)
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
    }
    else
    {
        if(this->sign == true)
        {
            if(this->number.size() > num.number.size() && !(suma1 == 0 && suma2 == 0))
            {
                ans = false;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = true;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = true;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = false;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = false;
                    }
                }
            }
        }
        else
        {
            if(this->number.size() > num.number.size())
            {
                ans = true;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = false;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = false;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = true;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
    }
    if(suma1 == suma2)
    {
        ans = false;
    }
    return ans;
}
bool BigInteger::operator>(BigInteger& num)
{
    int i = 0, suma1 = 0, suma2 = 0, j = 0;
    bool ans, exit = false;
    for (j = 0; j < this->number.size(); j++)
    {
        suma1 = suma1 + this->number[j];
        suma2 = suma2 + num.number[j];
    }
    if(this->sign != num.sign)
    {
        if(this->sign == true)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    else
    {
        if(this->sign == true)
        {
            if(this->number.size() > num.number.size() && !(suma1 == 0 && suma2 == 0))
            {
                ans = true;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = false;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = false;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = true;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
        else
        {
            if(this->number.size() > num.number.size())
            {
                ans = false;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = true;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = true;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = false;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = false;
                    }
                }
            }
        }
    }
    if(suma1 == suma2)
    {
        ans = false;
    }
    return ans;
}
bool BigInteger::operator==(BigInteger& num)
{
    int i = 0, suma1 = 0, suma2 = 0, j = 0;
    bool ans, exit = false;
    for (j = 0; j < this->number.size(); j++)
    {
        suma1 = suma1 + this->number[j];
        suma2 = suma2 + num.number[j];
    }
    if(this->sign != num.sign)
    {
        ans = false;
    }
    else
    {
        if(this->number.size() > num.number.size())
        {
            ans = false;
        }
        else
        {
            if(this->number.size() < num.number.size() && suma1 != 0 && suma2 != 0) 
            {
                ans = false;
            }
            else
            {
                while(!exit && i < this->number.size())
                {
                    if(this->number[i] < num.number[i])
                    {
                        ans = false;
                        i--;
                        exit = true;
                    }
                    else
                    {
                        if(this->number[i] > num.number[i])
                        {
                            ans = false;
                            i--;
                            exit = true;
                        }
                    }
                    i++;
                }
                if(i == this->number.size())
                {
                    ans = true;
                }
            }
        }
    }
    if(suma1 == suma2)
    {
        ans = true;
    }
    return ans;
}
bool BigInteger::operator<=(BigInteger& num)
{
    int i = 0;
    bool ans, exit = false;
    if(this->sign != num.sign)
    {
        if(this->sign == true)
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
    }
    else
    {
        if(this->sign == true)
        {
            if(this->number.size() > num.number.size())
            {
                ans = false;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = true;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = true;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = false;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
        else
        {
            if(this->number.size() > num.number.size())
            {
                ans = true;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = false;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = false;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = true;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
    }
    return ans;
}
bool BigInteger::operator>=(BigInteger& num)
{
    int i = 0;
    bool ans, exit = false;
    if(this->sign != num.sign)
    {
        if(this->sign == true)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    else
    {
        if(this->sign == true)
        {
            if(this->number.size() > num.number.size())
            {
                ans = true;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = false;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = false;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = true;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
        else
        {
            if(this->number.size() > num.number.size())
            {
                ans = false;
            }
            else
            {
                if(this->number.size() < num.number.size())
                {
                    ans = true;
                }
                else
                {
                    while(!exit && i < this->number.size())
                    {
                        if(this->number[i] < num.number[i])
                        {
                            ans = true;
                            i--;
                            exit = true;
                        }
                        else
                        {
                            if(this->number[i] > num.number[i])
                            {
                                ans = false;
                                i--;
                                exit = true;
                            }
                        }
                        i++;
                    }
                    if(i == this->number.size())
                    {
                        ans = true;
                    }
                }
            }
        }
    }
    return ans;
}
#include <iostream>

int main()
{
    int n = 500, i = 0, j;
    while(i < n)
    {
        int cont = 0, separatorpos1, separatorpos2;
        string n1, n2, intn1, flon1, intn2, flon2;
        char separator = '.';
        cin >> n1;
        cin >> n2;
        separatorpos1 = n1.find(separator);
        intn1 = n1.substr(0, separatorpos1);
        flon1 = n1.substr(separatorpos1 + 1);
        separatorpos2 = n2.find(separator);
        intn2 = n2.substr(0, separatorpos2);
        flon2 = n2.substr(separatorpos2 + 1);
        
        BigInteger n1int = intn1;
        BigInteger n1flo = flon1;

        BigInteger n2int = intn2;
        BigInteger n2flo = flon2;

        if(n1int > n2int || (n1int == n2int && n1flo > n2flo))
        {
            cout << "Case " << i+1 << ": Bigger\n";
        }
        if(n1int < n2int || (n1int == n2int && n1flo < n2flo))
        {
            cout << "Case " << i+1 << ": Smaller\n";
        }
        if(n1int == n2int && n1flo == n2flo)
        {
            cout << "Case " << i+1 << ": Same\n";
        }
        i++;
    }
}