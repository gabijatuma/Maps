#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>

using namespace std;


//using the map container
void read();
void write( map<string, vector<int>> words, vector<string> links);

int main()
{
    read();


    return 0;
}


void read()
{
    ifstream fd ("duomenys.txt");
    string word;
    map<string, vector<int>> words;
    vector<string> links;

    string row;
    std::istringstream rowStream;
    int numOfLine = 0;

    while (getline(fd, row))
        {       // Continue reading lines until the end of file is reached
            rowStream.clear();                // Delete previous error flags
            rowStream.str(row);               // Make the line readable
            numOfLine ++;

            while (rowStream >> word)
            {
                if((word.find("www.")!=string::npos)||(word.find("http://")!=string::npos)||(word.find("https://")!=string::npos))
                {
                    links.push_back(word);
                    break;
                }
                else
                {
                    word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); } ), word.end());
                    if (word != "")
                    {
                        transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return tolower(c); });
                        words[word].push_back(numOfLine);
                    }
                }
            }
        }
        fd.close();

        write(words, links);

}

void write( map<string, vector<int>> words, vector<string> links)
{

    ofstream fr("rezultatai.txt");
    fr<<"     Words      |       Times      |      Lines"<<endl<<endl;


    for (auto w : words)
        if (w.second.size() > 1)
        {
            fr << setw(15) << w.first<< setw(15) << w.second.size()<<"      ";
            for (auto line : w.second)
                fr << line << " ";
            fr<<endl;
        }


    fr<<endl<<"Links:"<<endl;

    for(int i = 0; i < links.size(); i++)
    fr<<links[i]<<endl;

    fr.close();
}
