# Geometry Slime
## _A Geometry Dash like game_

Geometry Slime a simple game where you have to make a slime goes from the begining of a map all the way to the end.

This game is programmed in CSFLM which is a library of C based on the C++'s SFML library.

# Sommaire

- [Requirements](#requirements)
- [Installation](#installation)
- [Menus](#menus)
- [Gameplay](#gameplay)
- [Map Creation](#map_creation)

## Requirements <a name="Requirements"></a>

In order to use this game, there is some dependencies to install the CSFML library.

CSFML is the official binding of SFML for C language. It can be install using this [website](https://www.sfml-dev.org/download/csfml/).

Also, if you want to use a github project, you should have git installed !
If that's not the case, just install it following the tutorial on the [website](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Installation <a name="installation"></a>

Every game need to be installed at one point, so here we are !
In order to install it properly, you can just follow the steps below.

#### Clone the repository

In order to recupate the code and it's assests, just use the following command :

```
git clone git@github.com:Just1truc/GeometrySlime.git
```

#### Build the game

First thing, enter the *repository* :

```
cd GeometrySlime
```

Then, you can *build* the game using this command :

```
make
```

After the end of the compilation, you can use the following command to launch the game on the *base map*

```
./my_runner maps/map5.txt
```

Congratulation, you successfully launched the game.

## Menus <a name="menus"></a>

Once the game is launched, you should have a window that look like the one below :

![set image](https://github.com/Just1truc/GeometrySlime/blob/main/assets/main_menu_screen.png)

To quit the game you can use 3 ways:
- press Echap key
- Click on the button to close the window
- Click the *butiful* red button

Also, on this first page you can launch the game by either pressing the *space* bar or clicking in the center of the screen on the play button.

Furthermore, you can setup the parameters by clicking on the cog icon or customize your character by clicking on the slime icon.

## GAMEPLAY <a name="gameplay"></a>

The game is far from difficult. All you have to do to finish a level is to avoid obstacles in order to get to the right side of the map.

The slime is constantly moving on the forward and rotate on itself if not in contact with the ground.


Environement interactions:
- press the *space* bar to **jump**
- press the *p* key to **pause/play** the game

Score interactions:
- coin : **+1**
- cross:  **-1**

The differents obstacles can kill except one : the **jump pad**

## Map Creation <a name="map_creation"></a>

Indeed, you can create your on map !
And it's not complicated. All you have to do is create a text file containing specific characters representing map elements.

To get the id of each map element, execute the following command:

```
./my_runner -h
```

When your done creating your map, just select your file as an argument like for the command below:

```
./my_runner [file]
```



