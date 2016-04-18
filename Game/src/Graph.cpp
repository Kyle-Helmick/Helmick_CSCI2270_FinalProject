#include "Graph.h"
using namespace std;

Graph::Graph()
{
    //ctor
}

void Graph::addEdge()
{
    srand(time(NULL));
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        for(int j = 0; j < vertices.size(); j++)
        {
            int randomval = rand()%4;
            //cout << randomval << endl;
            if(randomval == 1)
            {
                if(i != j)
                {
                    for(int k = 0; k < vertices[i].adj.size(); k++)
                    {
                        if(vertices[j].name == vertices[i].adj[k].v->name)
                        {
                            found = true;
                        }
                    }
                    if(found == false)
                    {
                        vertex_adj av;
                        vertex_adj ov;
                        av.v = &vertices[j];
                        ov.v = &vertices[i];
                        //cout << "flag" << endl;
                        vertices[i].adj.push_back(av);
                        vertices[j].adj.push_back(ov);
                    }
                    found = false;
                }
            }
        }
        //cout << "flag 2" << endl;
    }
}

void Graph::addVertex(string city_name)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == city_name)
        {
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex_city v;
        v.name = city_name;
        vertices.push_back(v);

    }
}

void Graph::print()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].name << endl;
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            cout << "\t" << vertices[i].adj[j].v->name << endl;
        }
    }
}

Graph::~Graph()
{
    //dtor
}
