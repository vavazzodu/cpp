#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int CalcScore ( const string &aCorrAns, const string &aActAns )
{
    int lvScore = 0;
    int i;
    for ( i=0; i<5; i++ )
    {
        if ( aActAns[i] == aCorrAns[i] )
        {
            lvScore ++;
        }
    }
    return lvScore;
}
int main()
{
    ifstream lvFile {"./StudentScore.txt"};
    if ( !lvFile.is_open() )
    {
        cout <<"Can not open the file\n";
        return -1;
    }
    string lvCorrAns, lvName, lvActAns;
    int lvScore, lvCount = 0, lvTotal = 0;
    getline ( lvFile, lvCorrAns );
    cout << setw(10) << left << "Name" << "Score" << endl;
    cout << setw(15) << setfill ('-') << "" << endl;
    cout << setw(15) << setfill (' ');
    while ( !lvFile.eof() )
    {
        getline ( lvFile, lvName );
        getline ( lvFile, lvActAns );
        lvScore = CalcScore ( lvCorrAns, lvActAns );
        lvTotal = lvTotal + lvScore;
        lvCount++;
        cout << setw(10) << left << lvName << setw(5) << right << lvScore << endl;
    }
    cout << setw(15) << setfill ('-') << "" << endl;
    cout << setfill (' ');
    cout << setw(10) << left << "Average" << setw(5) << right 
         << setprecision (2) << fixed << (double)(lvTotal/lvCount) << endl;
    return 0;
}