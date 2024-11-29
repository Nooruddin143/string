#include "string.h"
#include <fstream>
using namespace String;

void quitTester(int score)
{
    cout << "Score: " << score << endl;
    ofstream scoreFile("score.txt");
    scoreFile << score << endl;
    scoreFile.close();
    exit(0);
}

int main()
{
    int score = 0;

    cout << "Calling char[] constructor" << endl;
    string s1("abC");

    cout << "Testing size function" << endl;
    if(s1.size() == 3)
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s1.size() << endl;
    }

    cout << "Testing [] access operator" << endl;
    if(s1[0] == 'a' && s1[1] == 'b' && s1[2] == 'C')
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s1[0] << ' ' << s1[1] << ' ' << s1[2] << endl;
    }

    cout << "Testing == with a C string" << endl;
    if(s1 == "abC" && !(s1 == "ABc") && !(s1 == "abCd") && !(s1 == "a"))
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s1 << endl;
        cout << "Cannot finish testing without c-string == operator.  Exiting." << endl;
        quitTester(score);
    }

    cout << "Testing [] assignment" << endl;
    s1[2] = 'c';
    if(s1 == "abc")
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s1 << endl;
    }

    cout << "Testing copy constructor and == with string" << endl;
    string s2 = s1;
    if(s2 == s1 && s2 == string("abc") && !(s2 == string("ABc")) && !(s2 == string("abCd")) && !(s2 == string("a")))
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s2 << endl;
        cout << "Cannot finish testing without string == operator.  Exiting." << endl;
        quitTester(score);
    }

    cout << "Testing copy assignment" << endl;
    string s3 = "C++ is the best!";
    s2 = s3;
    if(s3 == s2 && s2 == "C++ is the best!")
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s2 << endl;
    }

    cout << "Testing copy assignment using a C String" << endl;
    s2 = "C strings are different than C++ strings\n";
    if(s2 == "C strings are different than C++ strings\n")
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s2 << endl;
    }


    cout << "Testing insertion << and extraction operators >>" << endl;
    ofstream ofsInsert("testOut.txt");
    ofsInsert << "antidisestablishmentarianism";
    ofsInsert.close();
    ifstream ifsExtract("testOut.txt");
    string extractStr;
    ifsExtract >> extractStr;
    if(extractStr == "antidisestablishmentarianism")
    {
        cout << "Passed.  +2" << endl;
        score+=2;
    }
    else
    {
        cout << "Failed." << endl;
        cout << extractStr << endl;
    }


    cout << "Testing str + str" << endl;
    s3 = s1 + " " + s2;
    if(s3 == "abc C strings are different than C++ strings\n")
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s3 << endl;
    }

    cout << "Testing str + char" << endl;
    s3 = s3 + 'Z';
    if(s3 == "abc C strings are different than C++ strings\nZ")
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s3 << endl;
    }


    cout << "Testing >" << endl;
    if(string("apples") > string("apple")
       && !(string("apple") > string("apple"))
       && string("zebra") > string("apples")
       && !(string("apples") > string("zebra")))
    {
        cout << "Passed.  +1" << endl;
        score++;
    }
    else
    {
        cout << "Failed." << endl;
    }


    cout << "Testing find" << endl;
    string s4 = "Do all dogs chase cats?  Are all dogs good puppers?";
    if(s4.find("Do") == 0
       && s4.find("dogs") == 7
       && s4.find("dogs", 8) == 33
       && s4.find("puppers?") == s4.size() - 8)
    {
        cout << "Passed.  +2" << endl;
        score+=2;
    }
    else
    {
        cout << "Failed." << endl;
        cout << s4.find("Do") << ' ' << s4.find("dogs") << ' ' << s4.find("dogs", 8) << ' ' << s4.find("puppers?") << endl;
    }

    quitTester(score);

    return 0;
}
