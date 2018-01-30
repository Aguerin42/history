History - Gestion de l'historique d'un Shell
------------------------------------

La bibliothèque _history_ offre des fonctions pour la gestion de l'historique d'un Shell. Elle permet de charger l'historique depuis un fichier puis d'y écrire les modifications.

## Fonctionnalités

- [x] Lire l'historique depuis un fichier
	+ [x] création du fichier si celui-ci n'existe pas
	+ [x] création d'une liste à partir de la lecture du fichier
- [x] Ajout de commandes en début d'historique
- [x] Écriture des modifications dans le fichier
- [x] Suppression du contenu de l'historique
- [ ] Limitation du nombres de commandes

## Utilisation et compilation

_history_ utilise des fonctions de la [libft][] et de la [libag][] et a besoin de leurs headers pour pouvoir être compilé. Il faut fournir au _Makefile_ le chemin vers les dossiers les contenant à l'aide de la variable *LIBFT_INC* et *LIBAG_INC*.

	$> make LIBFT_INC=../libft/includes LIBAG_INC=../libag/includes all

Le programme devra être compilé avec la bibliothèque `termcap`.

La documentation peut être créée avec la commande suivante :

	$> make doxygen

La documentation est générée grâce à [Doxygen][]. Le _Makefile_ utilise l'alias `doxygen` pour faire appel à l'exécutable, mais si celui-ci n'est pas défini il faut utiliser la commande :

	$> make doxygen DOXYGEN=/CHEMIN/VERS/EXECUTABLE/DE/DOXYGEN

[libft]: https://github.com/aguerin42/libft.git
[libag]: https://github.com/aguerin42/libag.git
[Doxygen]: https://github.com/doxygen/doxygen
