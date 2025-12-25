#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("timetravel.in");

string s;

vector <bool> v;

string longDivision(string number, int divisor)
{
    string ans;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';

        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}


int main()
{
    short int k=1,a,b,i;
    unsigned int x;
    bool r;
    fin >> s;
    a=(k-1)*7;
    b=(k-1)*7+6;
    x=0;
    i=0;
    while(s.compare("0") != 0)
    {
        r=(s.back()-'0')%2;
        if((195-i)>=a && (195-i)<=b)
        {
            x+=(r<<i-a);
        }
        i++;
        s=longDivision(s,2);
    }
    x&=0b1111111;
    
    v.resize((x>>2)*8*1048576*8);

    if(x&0b11 == 0)
    {
        return 0;
    }
    if(int(x&0b11) == 1)
    {
        return 7;
    }
    if(int(x&0b11) == 2)
    {
        int * p=NULL;
        (*p)++;
        return 0;
    }
    if(int(x&0b11) == 3)
    {
        while(true);
        return 0;
    }
}