# SmashStatCalculator
A calculator that will give you a stats-based prediction of the winner of a smash bros brawl.

Asks for a total of four user inputs: 2 character names (string), as well as the nature of the brawl (boolean unarmed/armed), and the type of terrain (ints 1-4), and the program will compute a likely winner based on the characters' associated weight, airspeed, falling speed, fastfall, dash, and ground speed.

Winner algorithm:
 - final product is the sum of weight difference + avg speed difference/100
 - if battle is armed, weight difference is reduced by 50% to account for weapons
 - if terrain is air, only air speed and falling speed are taken into account when calculating speed difference
 - if terrain is water, speed difference is reduced by 50%

Sample Run:
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣴⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣦⣾⢟⢁⡄⠀⠀⠀⠀⠀⠀⠀⢀⡤⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⢟⣿⣿⣾⠟⠁⠀⣠⣾⠀⠀⠀⢠⣿⠄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⠀⠀⣼⣧⠀⢺⣿⣿⡃⠀⣴⣿⡟⠁⣼⠅⣠⣿⡗⡠⠀⠀⠀⠀
⠀⠀⠀⠀⢰⣧⣠⣾⣿⣿⣆⣼⣿⣿⣡⢀⣿⣿⣿⣾⣿⣾⣿⣷⠟⠁⠀⠀⠀⠀
⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣾⣿⣿⣿⣿⡿⠟⢛⠁⠀⠀⠀⠀⠀⠀
⠀⠀⣀⣠⣾⣿⣿⣿⡏⠉⠉⠙⠛⠿⣿⣿⣿⣿⣿⣋⣀⣤⣏⠀⠀⠀⠀⠀⠀⠀
⠀⣤⣿⣿⠋⣿⣿⣿⡇⠀⠀⠀⠀⠀⠈⢻⣿⣿⣿⣿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀
⠀⢿⣿⠃⠀⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⢻⣿⡟⠀⠀⠀⠀⣠⠆⠀⠀⠀⠀⠀
⢀⣼⡏⠀⠀⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡉⢀⣀⣤⣾⠇⠀⠀⠀⠀⣀⠄
⢻⣿⣧⣤⣤⣿⣿⣿⣧⣤⣤⣤⣤⣤⣤⣤⣤⣿⣿⣿⡿⠋⠁⠀⠀⠀⣠⣾⡁⠀
⠈⢻⣿⡍⠉⣿⣿⣿⡏⠉⠉⠉⠉⠉⠉⠉⣽⣿⣿⣿⣯⣴⣿⣥⣶⡾⢟⠉⠀⠀
⠀⢨⣿⣿⣦⣿⣿⣿⡇⠀⠀⠀⠀⠀⣀⣾⣿⣿⣿⣿⡿⠿⠿⠿⠾⠛⠁⠀⠀⠀
⠀⠀⠻⠿⢿⣿⣿⣿⣇⣀⣀⣤⣴⣾⣿⣿⣿⣿⣿⣿⠶⠄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠙⠛⠛⠻⠟⠛⠿⠿⠿⢿⣷⣤⡾⠯⠁⠀

Enter Player 1:Pikachu
Enter Player 2:Peach

 Pikachu
 vs Peach
 


Pikachu:
tier: B
weight: 79.000000
airspeed: 957.000000
falling speed: 1550.000000
fastfall: 2480.000000
dash: 1980.000000
runspeed: 2039.000000

Peach:
tier: D
weight: 89.000000
airspeed: 1029.000000
falling speed: 1190.000000
fastfall: 1904.000000
dash: 1826.000000
runspeed: 1595.000000

Pikachu outranks Peach in class
Peach has 10.0 lbs on Pikachu
Type of combat (1 for armed, 0 for unarmed):1
Type of terrain (1 - earth, 2 - air, 3 - fire, 4 - water)2

armed: 1, terrain: 2
wdiff: -1.2 , sdiff: 9
Pikachu wins this round!
