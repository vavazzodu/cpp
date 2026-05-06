#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream myFptr;
    string str;
    //char c;
    int i=0;
    myFptr.open ( "./FileManip.txt");
    if ( myFptr.is_open() )
    {
        cout << "File opened successfully" <<endl;
        while ( !myFptr.eof() ) //Read untill end of file is reached
        {
            i++;
            /* Read each word */
            myFptr >> str;
            cout << "Word"<<i<<": "<< str << endl; //Hello
        
            /* Read each line */
            //getline (myFptr, str);
            //cout << "Line"<<i<<": "<< str << endl; //Hello Karan

            /* Read each character */
            //myFptr.get (c);
            //cout << c ;
        }
    }
    else
    {
        cout << "Can not open the file" << endl;
    }
    // always close the file once taks is completed
    myFptr.close();
    return 0;
}