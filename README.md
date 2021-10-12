# so_long
This project is a small 2D Bomberman game using minilibx, a graffic library used at 42. It uses textures, sprites and tiles.

## Description
* The player’s goal is to collect all the collectible bombs present on the map, then to escape from the revealed pipe with minimal movement.
* At every move the current number of movements is displayed on the window.
* Ennemy patrols cause the player to lose in case of contact.
* Collectibles include :<br />
<img src="/screenshots/item-speed.png" /> Speed = allows the player to move faster<br />
<img src="/screenshots/item-bomb.png"/> Bomb = allows the player to set an additional bomb on the field<br />
<img src="/screenshots/item-fire.png" /> Fire = increases the power of the bombs set by the player

## Commands
* QWERTY<br />
Up = W<br />
Down = S<br />
Left = A<br />
Right = D

* AZERTY<br />
Up = Z<br />
Down = S<br />
Left = Q<br />
Right = D

* Quit
ESC

## Map
* The program taked as a first argument a map description file with the .ber extension.
* The map must be composed of only 6 possible characters:<br />
0 for an empty space<br />
1 for a wall<br />
C for a collectible<br />
E for map exit<br />
P for the player’s starting position
M for an ennemy's starting position

This is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

* The map must be closed/surrounded by walls, if not the program must returns an error.
* It must have at least one exit, one collectible, and one starting position.
* It must be rectangular.

## Screenshots
<p align="center">
  <img src="/screenshots/screen_1.png" width="50%" />
</p>

<p align="center">
  <img src="/screenshots/screen_2.png" width="50%" />
</p>
