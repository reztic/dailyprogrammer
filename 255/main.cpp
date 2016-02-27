#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>

using namespace std;


string cleanString(string input)
{
    string output = "";
    for ( string::iterator it = input.begin(); it != input.end(); it ++)
    {
        if (isalpha(*it))
        {
            output += *it;
        }
    }
    return output;
}

vector<string> tokenizeString(string input)
{
    vector<string> tString;
    string temp = "";
    for ( string::iterator it = input.begin(); it != input.end(); it ++)
    {
        if ( *it == '\n' || it+1 == input.end() )
        {
            tString.push_back(temp);
            temp = "";
        }
        else if (*it != ' ' && *it != '.')
        {
            temp += *it;
        }
    }
    return tString;
}

//Some weird method to do it.
vector<string> methodOne(int groupingSize, vector<string> vString)
{
    //key = occurances, vector string = cause we could has mutliple string with same occurance.
    map< int, vector<string> > everyBestCandidates;
    
    vector<string> output;
    for( vector<string>::iterator it = vString.begin(); it != vString.end();++it)
    {
        string current = *it;
        string largestFoundString = "";
        int sizeOfLargestFoundSet = 0;
        for( int x = 0; x < current.size(); x++)
        {
            int currentFoundSet = 0;
            string groupString = current.substr(x, groupingSize);
            if (groupString.size() == groupingSize)
            {
                //data[distance(vString.begin(),it)].push_back(groupString);
                for( vector<string>::iterator rt = it; rt != vString.end();++rt)
                {
                    if ((*rt).find(groupString) != string::npos)
                    {
                        currentFoundSet++;
                    }
                }
                if (currentFoundSet > sizeOfLargestFoundSet)
                {
                    largestFoundString = groupString;
                    sizeOfLargestFoundSet = currentFoundSet;
                }
            }
        }
        everyBestCandidates[sizeOfLargestFoundSet].push_back(largestFoundString);
    }
    
    int counter = 0;
    for ( map< int, vector<string> >::reverse_iterator it = everyBestCandidates.rbegin(); it != everyBestCandidates.rend(); ++it)
    {
        for( vector<string>::iterator vt = (*it).second.begin(); vt != (*it).second.end(); ++vt)
        {
            counter ++;
            int occurances = 0;
            for( vector<string>::iterator rt = vString.begin(); rt != vString.end();)
            {
                if ((*rt).find((*vt)) != string::npos)
                {
                    occurances++;
                    rt = vString.erase(rt);
                }
                else
                {
                    ++rt;
                }
            }
            if (occurances > 0)
                output.push_back(*vt);
        }
        if ( vString.size() == 0) //Quick escape
            break;
    }
    return output;
}


int main()
{
    int groupingSize = 5;
    
    //string input ="Jack and Jill went up the hill to fetch a pail of water.\nAll work and no play makes Jack and Jill a dull couple.\nThe Manchester United Junior Athletic Club (MUJAC) karate team was super good at kicking.\nThe MUJAC playmaker actually kinda sucked at karate.";
    //vector<string> vString = tokenizeString(input);
    
    vector<string> vString;
    ifstream file("oneliners.txt");
    string str;
    while (std::getline(file, str))
    {
        vString.push_back(cleanString(str));
    }
    
    vector<string> output = methodOne(groupingSize, vString);
    
    cout << output.size() << endl;
    return 0;
}

