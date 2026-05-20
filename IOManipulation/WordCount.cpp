#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int CountWord ( string &aStr )
{
    ifstream lvFp;
    string lvWord;
    int lvCount {0};
    lvFp.open ( "./WordCount.txt" );
    if ( !lvFp.is_open() )
    {
        cout << "Can't open the file" << endl;
        return 0;
    }
    while ( !lvFp.eof() )
    {
        lvFp >> lvWord;
        if ( lvWord.find ( aStr ) != string::npos)
        {
            lvCount++;
        }
    }
    return lvCount;
}
int main()
{
    string lvStr {""};
    cout << "Enter the string: ";
    cin >> lvStr;

    cout << "Word: "<< lvStr << " is " << CountWord( lvStr ) <<" times in the file." << endl;
    return 0;
}