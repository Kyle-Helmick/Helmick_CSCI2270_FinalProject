#include "Graph.h"
#include <string>
#include <iostream>

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
        for(int j = 0; j < vertices.size(); j++)
        {
            int randomval = rand()%5;
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
    v.namecat = city_name;
    v.aggression = rand() % 10 + 15;
    v.attack = rand() % 10 + 15;
    v.def = 40 - v.attack;
    vertices.push_back(v);
}

bool Graph::findecity(string p_name, string e_name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == p_name)
        {
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                if((vertices[i].adj[j].v->name == e_name) && (vertices[i].adj[j].v->p_controlled == false))
                {
                    return true;
                }
            }
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
            cout << vertices[i].name << " (" << vertices[i].namecat << ") -- " << "Health: " << vertices[i].health << " -- " << "Resources: " << vertices[i].resources << " -- " << "Defense: " << vertices[i].def << " -- " << "Attack: " << vertices[i].attack << endl;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "\t" << "City: " << vertices[i].adj[j].v->name << " (" << vertices[i].adj[j].v->namecat << ") -- " << "H: " << vertices[i].adj[j].v->health << " -- " << "R: " << vertices[i].adj[j].v->resources << " -- " << "D: " << vertices[i].adj[j].v->def << " -- " << "A: " << vertices[i].adj[j].v->attack << endl;
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
            cout << "║  -" << vertices[i].name << " (" << vertices[i].namecat << ") -- " << "H: " << vertices[i].health << " -- " << "R: " << vertices[i].resources << " -- " << "D: " << vertices[i].def << " -- " << "A: " << vertices[i].attack << endl;
        }
    }
}

void Graph::print_p_adj(string name)
{
    bool found = false;

    //insert check for player cities
    for(int i = 0; i < vertices.size(); i++)
    {
        if(name == vertices[i].name)
        {
            found = true;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "║  -City: " << vertices[i].adj[j].v->name << " (" << vertices[i].adj[j].v->namecat << ") -- " << "H: " << vertices[i].adj[j].v->health << " -- " << "R: " << vertices[i].adj[j].v->resources << " -- " << "D: " << vertices[i].adj[j].v->def << " -- " << "A: " << vertices[i].adj[j].v->attack << endl;
            }
        }
    }
    if(found == false)
    {
        cout << "ERROR: City not found, use exact case." << endl;
    }
}

void Graph::playerattack(string attack, string def)
{
    vertex_city *attacker = &returncity(attack);
    vertex_city *defender = &returncity(def);

    int damage = ((2*attacker->attack) - (.4*defender->def));
    if(damage < 0)
    {
        damage = damage*-1;
    }
    defender->health = defender->health - damage;
    attacker->resources -= 5;
    //cout<<"you attacked City "<<defender->name<<" for "<<damage<<" damage!"<<endl;

    if((defender->health < 0) || (defender->health == 0))
    {
        if(attacker->p_controlled == true)
        {
            defender->p_controlled = true;
        }
        else if(attacker->p_controlled == false)
        {
            defender->p_controlled = false;
        }
        defender->namecat = attacker->namecat;
        defender->ID = attacker->ID;
        defender->health = 60;
    }
}

void Graph::checkTakeover(string attack, string def)
{
    vertex_city *attacker = &returncity(attack);
    vertex_city *defender = &returncity(def);

    if((defender->health < 0) || (defender->health == 0))
    {
        if(attacker->p_controlled == true)
        {
            defender->p_controlled = true;
        }
        else if(attacker->p_controlled == false)
        {
            defender->p_controlled = false;
        }
        defender->namecat = attacker->namecat;
        defender->ID = attacker->ID;
        defender->health = 60;
    }
}

int Graph::vertexAttack(vertex_city attacker, vertex_city attackee){
    int damage = 2*(attacker.attack - .4*(attackee.def));
    //cout<<attacker.name<<" attacking "<<attackee.name<<", damage done should be: "<<damage<<endl;
    int newhealth = attackee.health - damage;
    //cout<<"attackee new health should be: "<<attackee.health<<endl;
    return newhealth;
}

void Graph::fortify(string city)
{
    vertex_city *defender = &returncity(city);
    defender->def += 2;
    defender->resources -= 3;
}

vertex_city& Graph::returncity(string cityname){
    int x;
    for (int i=0;i<vertices.size();i++){
        if (vertices[i].name == cityname){
            x = i;
            break;
        }
    }
    return vertices[x];
}

void Graph::resources(string from_s, string to_s, int amount)
{
    vertex_city *from = &returncity(from_s);
    vertex_city *to = &returncity(to_s);

    from->resources -= amount;
    to->resources += amount;
}

void Graph::pwait()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            vertices[i].resources += 4;
        }
    }
}

void Graph::ewait(string city)
{
    vertex_city *waiter = &returncity(city);
    waiter->resources += 4;
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
        if (vertices[i].p_controlled == false)
        {
            int ai_dec = genRand();

            if (ai_dec < vertices[i].aggression){

                if (vertices[i].resources>=5){
                    int att_dec = genRand2(vertices[i].adj.size());
                    int newhealth = vertexAttack(vertices[i], *vertices[i].adj[att_dec].v);
                    for(int j = 0; j < vertices[i].adj.size(); j++)
                    {
                        if(vertices[i].adj[j].v->p_controlled == true)
                        {
                            cout<<"City "<<vertices[i].name << " (" << vertices[i].namecat << ") attacked city " << vertices[i].adj[att_dec].v->name << " (" << vertices[i].adj[att_dec].v->namecat << ")"<<endl;
                            break;
                        }
                    }
                    vertices[i].adj[att_dec].v->health = newhealth;
                    vertices[i].resources = vertices[i].resources - 5;
                    checkTakeover(vertices[i].name, vertices[i].adj[att_dec].v->name);
                }
                else if (vertices[i].resources<5){
                    ai_dec = 60;
                }
            }
            if ((ai_dec >= vertices[i].aggression) && (ai_dec<=50))
            {
                if (vertices[i].resources >= 4){
                    fortify(vertices[i].name);
                    for(int j = 0; j < vertices[i].adj.size(); j++)
                    {
                        if(vertices[i].adj[j].v->p_controlled == true)
                        {
                            cout<<"City "<<vertices[i].name<< " (" << vertices[i].namecat << ") fortified."<<endl;
                            break;
                        }
                    }
                }
                else if (vertices[i].resources<4){
                    ai_dec = 60;
                }
            }

            if (ai_dec > 50)
            {
                ewait(vertices[i].name);
                for(int j = 0; j < vertices[i].adj.size(); j++)
                {
                    if(vertices[i].adj[j].v->p_controlled == true)
                    {
                        cout<<"City "<<vertices[i].name<< " (" << vertices[i].namecat << ") waited."<<endl;
                        break;
                    }
                }
            }

        }
    }
}

int Graph::genRand(){
    int randnum = rand() % 70 + 1;
    return randnum;
}

bool Graph::win_check()
{
    bool win = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            win = true;
        }
        if(vertices[i].p_controlled == false)
        {
            win = false;
            break;
        }
    }
    if(win == true)
    {
        return true;
    }
    else if(win == false)
    {
        return false;
    }
}

bool Graph::lose_check()
{
    bool lose = true;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            lose = false;
            break;
        }
        if(vertices[i].p_controlled == false)
        {
            lose = true;
        }
    }
    if(lose == true)
    {
        return true;
    }
    else if(lose == false)
    {
        return false;
    }
}

int Graph::genRand2(int adjsize){
    srand(time(NULL));
    int randnum = rand() % adjsize;
    return randnum;
}

Graph::~Graph()
{
    //dtor
}
