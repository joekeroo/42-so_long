# 42-so_long

In this project, We will create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, we will use any character, any collectible and any place we want.

![Game Demo](https://github.com/joekeroo/42-so_long/assets/58316168/cd8d5bb0-8fc9-4fb6-983f-1333c0018592)

## About

- You must use [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html). Either the version available on the school machines, or installing it using its sources.
- The program will take a map as an argument.
- Map file extension must end with `.ber`.
- Game must be in a 2d top-down view.
- Player must collect all collectibles and find the closest exit to win the game.
- `W`, `A`, `S`, `D` keys must control the player movement.
- total number of moves will be shown on the top left of the game.
- `ESC` key will exit the game.
- The use of images of the [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) is mandatory.

## Installation & Usage

- GNU make (v3.81)
- GCC (v4.2.1)
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

### Building the program

1. Download/Clone this repository

```bash
git clone https://github.com/joekeroo/42-so_long.git so_long
```

2. `cd` into the root directory and run `make`

```bash
cd so_long && make
```

### Compilation

- `make` - compiles the program into `so_long`
- `make clean` - removes all `.o` files
- `make fclean` - clean and removes `so_long`
- `make re` - fclean and recompiles

### Run the Program

```bash
./so_long maps/bonus4.ber
```

### Map Requirements

- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters:

|    Characters     |                           Description                           |
| :---------------: | :-------------------------------------------------------------: |
|`0`| an empty space|
|`1`|  a wall|
|`C`|  a collectible|
|`E`|  a map exit|
|`P`|  the player’s starting position|

- The map must contain at least 1 exit, 1 collectible, and 1 starting position.
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return `error`.
- Any kind of maps will be accepted as long as it respects the above rules.
- Example of a valid map:

<img alt="map" src="https://github.com/joekeroo/42-so_long/assets/58316168/c4fb1504-25ef-4c6e-ac81-a18cf19876c5">
<img alt="map demo" src="https://github.com/joekeroo/42-so_long/assets/58316168/5a51a2cd-8b46-4fdc-a522-00109483305e">

## Bonus

- Add some sprite animation.
- Make the player lose when they touch an enemy patrol.
