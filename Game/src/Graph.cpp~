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
    vertices[0].p_controlled = true;
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].ID = i;
        cout << "I: " << i << endl;
        for(int j = 0; j < vertices.size(); j++)
        {
            int randomval = rand()%4;
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

    }
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].adj.empty() == true)
        {
            vertex_adj av;
            vertex_adj ov;
            av.v = &vertices[0];
            ov.v = &vertices[i];
            vertices[i].adj.push_back(av);
            vertices[0].adj.push_back(ov);
        }
        //cout << "flag 2" << endl;
    }
}

void Graph::addVertex(string city_name)
{
    vertex_city v;
    v.name = city_name;
    v.aggression = rand() % 10 + 15;
    v.attack = rand() % 10 + 15;
    v.def = rand() % 10 + 15;
    vertices.push_back(v);
}

bool Graph::findecity(string city_name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if((vertices[i].name == city_name) && (vertices[i].p_controlled == false))
        {
            return true;
        }
    }
    return false;
}

bool Graph::findpcity(string city_name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if((vertices[i].name == city_name) && (vertices[i].p_controlled == true))
        {
            return true;
        }
    }
    return false;
}

void Graph::print()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            cout << vertices[i].name << " -- " << "Health: " << vertices[i].health << " -- " << "Resources: " << vertices[i].resources << " -- " << "Defense: " << vertices[i].def << " -- " << "Attack: " << vertices[i].attack << endl;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "\t" << "City: "<< vertices[i].adj[j].v->name << " -- " << "Health: " << vertices[i].adj[j].v->health << " -- " << "Resources: " << vertices[i].adj[j].v->resources << " -- " << "Defense: " << vertices[i].adj[j].v->def << " -- " << "Attack: " << vertices[i].adj[j].v->attack << endl;
            }
        }
    }
}

void Graph::print_p()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            cout << "║  -" << vertices[i].name << " -- " << "Health: " << vertices[i].health << " -- " << "Resources: " << vertices[i].resources << endl;
        }
    }
}

void Graph::print_p_adj(string name)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(name == vertices[i].name)
        {
            found = true;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "║  -City: " << vertices[i].adj[j].v->name << " -- " << "Health: " << vertices[i].adj[j].v->health << " -- " << "Resources: " << vertices[i].adj[j].v->resources << endl;
            }
        }
    }
    if(found == false)
    {
        cout << "ERROR: City not found, use exact case." << endl;
    }
}

void Graph::attack(string attack, string def)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == attack)
        {
            for(int j = 0; i < vertices[i].adj.size(); j++)
            {
                if(vertices[i].adj[j].v->name == def)
                {
                    int damage = 2*(vertices[i].attack - .25*(vertices[i].adj[j].v->def));
                    if(damage < 0)
                    {
                        damage = damage*-1;
                    }
                    vertices[i].adj[j].v->health -= damage;
                    vertices[i].resources -= 5;
                    break;
                }
            }
        }
    }
}

void Graph::fortify(string city)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == city)
        {
            vertices[i].def += 5;
            vertices[i].resources -= 3;
            break;
        }
    }

}

void Graph::resources(string from, string to, int amount)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == from)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == to)
                {
                    vertices[i].resources -= amount;
                    vertices[j].resources += amount;
                    break;
                }
            }
        }
    }
}

void Graph::pwait()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            vertices[i].resources += 5;
        }
    }
}

void Graph::ewait(string city)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == city)
        {
            vertices[i].resources += 5;
        }
    }
}

void Graph::turnresources()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].resources += 5;
    }
}

bool Graph::resourcecheck(string city, int amount)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == city)
        {
            if(vertices[i].resources >= amount)
            {
                return true;
            }
        }
    }
    return false;
}

void Graph::AIturns()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            //cout << vertices[i].name << " -- " << "Health: " << vertices[i].health << " -- " << "Resources: " << vertices[i].resources << " -- " << "Defense: " << vertices[i].def << " -- " << "Attack: " << vertices[i].attack << endl;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                int ai_dec = genRand();
                if (ai_dec <= vertices[i].adj[j].v->aggression){
                    attack(vertices[i].adj[j].v->name, vertices[i].name);
                    cout<<"City "<<vertices[i].adj[j].v->name<<" attacked "<<vertices[i].name<<"!"<<endl;
                }
                if ((ai_dec > vertices[i].adj[j].v->aggression) && (ai_dec<=50)){
                    fortify(vertices[i].adj[j].v->name);
                    cout<<"City "<<vertices[i].adj[j].v->name<<" fortified."<<endl;
                }
                if (ai_dec > 50){
                    ewait(vertices[i].adj[j].v->name);
                    cout<<"City "<<vertices[i].adj[j].v->name<<" waited."<<endl;
                }
            }
        }
    }
}

int Graph::genRand(){
    int randnum = rand() % 70 + 1;
    return randnum;
}
Graph::~Graph()
{
    //dtor
}
