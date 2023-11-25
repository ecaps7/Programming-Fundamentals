#include<bits/stdc++.h>
using namespace std;

int compare(char a, char b)
{
    string order = "2AKQJT9876543";
    return order.find(a) - order.find(b);
}

void sortCards(char* cards, int length)
{
    for (int i = 0; i < length; i++)
    {
        char key = *(cards + i);
        int j = i - 1;
        while (j >= 0 && compare(key, *(cards + j)) < 0)
        {
            *(cards + j + 1) = *(cards + j);
            j--;
        }
        *(cards + j + 1) = key;
    }
}


int main()
{
    char* cards = new char[130];
    cin.getline(cards, 130);
    int length = 0;
    while(true)
    {
        if (*(cards + length) == '\0')
        {
            break;
        }
        length++;
    }
    sortCards(cards, length);
    for (int m = 0; m < length; m++)
    {
        cout << *(cards + m);
    }
    delete[] cards;
    return 0;
}
