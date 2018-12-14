# Lemin-in

Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière lière par n fourmis.

Évidemment, il y a quelques contraintes. Pour arriver le premier, il faut prendre le chemin le plus court (et pas forcément pour autant le plus simple), ne pas marcher sur ses congénères, tout en évitant les embouteillages.

Au début du jeu, toutes les fourmis sont sur la salle indiquée par la commande ##start. Le but est de les amener sur la salle indiquée par la commande ##end en prenant le moins de tours possible. Chaque salle peut contenir une seule fourmi à la fois (sauf ##start et ##end qui peuvent en contenir autant qu’il faut).

On considère que les fourmis sont toutes dans la salle ##start au démarrage

On n’aﬃchere à chaque tour que les fourmis qui ont bougé

À chaque tour on peut déplacer chaque fourmi une seule fois et ce suivant un tube (la salle réceptrice doit être libre).

On doit sortir le résultat sur la sortie standard sous la forme suivante :

nombre_de_fourmis
les_salles
les_tubes
Lx-y Lz-w Lr-o ...

Où x, z, r sont des numéros de fourmis (allant de 1 à nombre_de_fourmis) et y, w, o des noms de salles.
