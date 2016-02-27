#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;

vector<string> tokenizeString(string input)
{
    vector<string> tString;
    int index = 0;
    while ( input.find("\n", index) == string::npos)
    {
        size_t end = input.find("\n", index);
        tString.push_back( input.substr(index, end - index) );
        index = static_cast<int>(end) + 1;
    }
    tString.push_back( input.substr(index, input.length() - index) );
    return tString;
}

int main()
{
    string input ="Jack and Jill went up the hill to fetch a pail of water.\nAll work and no play makes Jack and Jill a dull couple.\nThe Manchester United Junior Athletic Club (MUJAC) karate team was super good at kicking.\nThe MUJAC playmaker actually kinda sucked at karate.";
    
    vector<string> tString = tokenizeString(input);
	
    return 0;
}

