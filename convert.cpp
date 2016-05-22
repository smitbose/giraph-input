#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{
    ifstream dataset; //contains the dataset given as input
    ofstream giraph; //file to be given as input to giraph
    if(argc <=1)
    {
        cout<<"Usage ./convert <filename>"<<endl;
        return 1;
    }
    dataset.open(argv[1]);
    giraph.open("generated.txt"); //this will create a file "generated.txt"
    
    vector<int> adj[100005]; //assuming that graph will have at-most 10^5 edges
    for(int i=0;i<100005;i++)
        adj[i].clear();
    int start,end;
    while(!dataset.eof())
    {
        dataset>>start;
        dataset>>end;
        adj[start].push_back(end);
    }
    for(int i=1;i<100005;i++)
    {
        int s = adj[i].size();
        if(s == 0)
        {
            continue;
        }
        else
        {
            giraph<<"["<<i<<", "<<"0"<<", [";
            for(int j=0;j<s;j++)
            {
                giraph<<"["<<adj[i][j]<<", 1]";
                if(j!=s-1)
                    giraph<<", ";
                else
                    giraph<<"]]"<<endl;
            }
        }
    }
    dataset.close();
    giraph.close();
    return 0;
}
