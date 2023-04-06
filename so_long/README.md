# so_long
first mini game in 2D for macOS systems

# How to install and run so_long
from directory so_long2/so_long write on the console `make` or `make re` and after compilation run `./so_long map.ber` you can choose or build other maps, but the following rules should be respected. When you are tired of play you can delete the output files by typing `make fclean` on the console.

# How to write a valid map.ber
make sure that the perimeter of the map have only "1" characters and there is only one "P" (for the player) and one "E" (for the exit) "C" characters is for collectables, the program will counts automatically the number of "C" you need to collect all of them to open and spawn the exit. "0" is for empty spaces where the player can move. You can add any number of enemy you want with "X" character BUT ONLY THE LAST ONE READED WILL BE MOVE! Press ESC any time you want to close the window is running the game.

e.g.:	
`````
11111111111
1P0000000C1
100000000X1
1C0000000E1
11111111111
`````
