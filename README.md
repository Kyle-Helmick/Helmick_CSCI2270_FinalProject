# Helmick_Stevenson_CSCI2270_FinalProject
This repository is where we store our files for our final project.

TO SEE MENU IDEAS VIEW THIS DOCUMENT IN RAW FORM

The game is comprised of multiple cities including the one that you are in charge of. Each city gains 5 resources every two seconds, resources will be calculated at the end of a while loop (dictated by the time it takes for the while loop to cycle through once) and used to either fortify a city or attack an adjacent one, kind of like risk but unlimited resources. The goal is to spread your control by taking over cities adjacent to you but not all cities are adjacent, specific paths must be takenn. Enemy cities will hopefully be able to attack back on their own. Each time the map is random, saving and resuming is a last priority.

By April 21st have interaction between graph nodes, have resource generation working.
By April 23rd have resource management (resource movement between nodes (just a teleport so we dont have to do shortest path...)), have weights for increasing attack or defense figured out and ability to use resources to raise either.
By April 25th have algorithm to attack adjacent cities and take control, be able to play game completely, implement breadth search for end game check (all cities are controlled by player), try to create ability for enemy cities to attack eachother/you (random value based on connections to pick which adjacent city, random value on either attack or fortify or neither)
By April 27th have completely working game. On April 25th we will decide if we want to add saving capabilites.

Menu ideas.

##########Main Menu##########
#  -Play Game (Y)
#  -Quit Game (N)
#############################
Input: 
(If menu key not in menu repeat and state error above menu)

Showing adjacent cities

Player's City
    Adjacent Enemy -- (Health)
    (etc) -- (Health)
Player's Second City (etc)
    Adjacent Enemy -- (Health)
    (etc) -- (Health
#########Action Menu#########
#  -Attack (A)
#  -Fortify (F)
#  -Wait (W)
#############################
Input: 
(If action key not in menu repeat and state error above menu)
(If not enough resources repeat and state error above menu)

Fortify Menu

#########Fortify Menu#########
#  -Pick a city to fortify-  #
#  -Player's City
#  -Player's City 2 etc
##############################
Input:
(If city not found repeat and state error above menu)

Attack Menu

###########Attack Menu###########
#  -Pick a city to attack from- #
#  -Player's City
#  -Player's City 2 etc
#################################
Input:
(If city not found repeat and state error above menu)

###########Attack Menu###########
#    -Pick a city to attack-    #
#  -Adjacent City 1
#  -Adjacent City 2 etc
#################################
Input:
(If city not found repeat and state error above menu)
