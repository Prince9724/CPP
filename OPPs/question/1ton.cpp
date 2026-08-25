#include <iostream>
#include <string>

// 1 to n number print and n to 1 number print
using namespace std;

class Assec
{
    int number;

public:
    void setNumber(int number)
    {
        this->number = number;
    };
    void getNumber()
    {
        cout << " your n is " << number << endl;
    };

    void start()
    {
        for (int i = 1; i <= number; i++)
        {
            cout << i << endl;
        };
    };
    void end()
    {
        for (int i = number; i >= 1; i--)
        {
            cout << i << endl;
        };
    };
    void whileSum()
    {
        int i = 1;
        int sum = 0;
        while (i <= number)
        {
            sum = sum + i;
            i++;
        };
        cout << "1 to " << number << " sum : " << sum << endl;
    };
    void doWhile()
    {
        int i = 1;
        int sum = 0;
        do
        {
            sum = sum + i;
            i++;
        } while (i <= number);
        cout << "1 to " << number << " sum : " << sum << endl;

    }
};

int main()
{
    int x;
    cout << "Enter your n number : ";
    cin >> x;
    Assec num;
    num.setNumber(x);
    // num.start();
    // num.end();
    // num.whileSum();
    num.doWhile();
    num.getNumber();
}