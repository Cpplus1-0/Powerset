#include <iostream>
#include <cmath>

using namespace std;

int * convert(int cardinality, int num);

int main()
{
    cout << "This program computes and displays the powerset of a set with less than 5 elements. " << endl;

    cout << endl << "Enter the number of elements in the set: ";
    int cardinality;
    for(cin >> cardinality; cardinality > 6; cin >> cardinality)
        cout << "Sorry! THe cardinality you have entered for the set is too large for its powerset to be computed using this program. " << endl;

    int * powerset = new int[cardinality];
    int num, count, counter;

    for(count = 0; count < cardinality; count++)
    {
        cout << "Enter element#" << count+1 << ": ";
        for(cin >> num; num > 9; cin >> num)
            cout << "Sorry! The element must range between 0-9. Try again!" << endl;

        powerset[count] = num;
    }

    int * bits = new int[cardinality];

    cout << endl << "Powerset: " << endl << "{ {}, ";
    for(count = 1; count < pow(2, cardinality); count++)
    {
        cout << "{";
        bits = convert(cardinality, count);
        for(counter = 0; counter < cardinality; counter++)
            if(bits[counter])
                cout << powerset[counter] << ",";

        cout << "\b}, ";
    }

    cout << "\b\b }" << endl;

    return 0;
}

int * convert(int cardinality, int num)
{
    int * bits = new int[cardinality];
    int count;
    for(count = 0; num != 0; num / 2)
    {
        bits[count++] = num % 2;
        num /= 2;
    }

    for(int counter = count; counter < cardinality; counter++)
        bits[counter] = 0;

    return bits;
}
