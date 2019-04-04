# Navy
*Unix System Programming | Epitech | Tek1*

##### Purpose of the project :
- [x] Create a battleship game in CLI with signals

## Usage
```
$> ./navy -h
USAGE
	./navy [first_player_pid] navy_positions
DESCRIPTION
	first_player_pid: only for the 2nd player. pid of the first player.
	navy_positions: file representing the positions of the ships.
```

## Positions files exemples

```
$> cat navy_positions1.txt
2:E5:F5
3:A2:C2
4:C5:C8
5:H1:H5
$> cat navy_positions2.txt
2:G7:G8
3:F3:H3
4:A8:D8
5:C1:C5
```

## Game exemple

### Player 1
```
$> ./navy navy_positions1.txt
my_pid: 12345
waiting for enemy connection...

enemy connected

my positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . 5
2|3 3 3 . . . . 5
3|. . . . . . . 5
4|. . . . . . . 5
5|. . 4 . 2 2 . 5
6|. . 4 . . . . .
7|. . 4 . . . . .
8|. . 4 . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: H2
H2: missed

waiting for enemy's attack..
E5: hit

my positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . 5
2|3 3 3 . . . . 5
3|. . . . . . . 5
4|. . . . . . . 5
5|. . 4 . x 2 . 5
6|. . 4 . . . . .
7|. . 4 . . . . .
8|. . 4 . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . o
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack:

```

### PLayer 2
```
$> ./navy 12345 navy_positions2.txt
my_pid: 23456
successfully connected

my positions:
 |A B C D E F G H
-+---------------
1|. . 5 . . . . .
2|. . 5 . . . . .
3|. . 5 . . 3 3 3
4|. . 5 . . . . .
5|. . 5 . . . . .
6|. . . . . . . .
7|. . . . . . 2 .
8|4 4 4 4 . . 2 .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy's attack...
H2: missed

attack: E5
E5: hit

my positions:
 |A B C D E F G H
-+---------------
1|. . 5 . . . . .
2|. . 5 . . . . o
3|. . 5 . . 3 3 3
4|. . 5 . . . . .
5|. . 5 . . . . .
6|. . . . . . . .
7|. . . . . . 2 .
8|4 4 4 4 . . 2 .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . x . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy's attack...

```

## Ncurses bonus

![Ncurses bonus](https://github.com/mrCaelum/Navy/blob/master/bonus.png)
