# so_long
first mini game in 2D

# How to install and run so_long
from directory so_long2/so_long run "make" and after compilation run "./so_long map.ber"

# How to write a valid map.ber
make sure that the perimeter of the map have only "1" character and there is only one "P" (for the player) and "E" (for the exit) "C" character is for collectables and the program count automatically the number of "C". "0" is for empty spaces where the player can move. You can add any number of enemy you want with "X" character BUT ONLY THE LAST ONE READED WILL BE MOVE!

e.g.:	11111111111
		1P0000000C1
		100000000X1
		1C0000000E1
		11111111111