-- Commandes pour insérer des valeurs par défaut dans les tables

INSERT INTO `InfoDynamiqueDossiers`.`techniciens`
	(`prenom`, `nom`)
VALUES
	("Ajax",    "Archambeault"),
	("Bruno",   "Beaudoin"),
	("Charles", "Chartrand");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`clients`
	(`prenom`, `nom`, `telephone`, `adresse`)
VALUES
	("Dilbert",   "Daiquiri",    "5558501111", "1 rue Dickens"),
	("Elphège",   "Éléphant",    "5554502222", "2 rue Eddings"),
	("Franny",    "Fréchette",   "5554183333", "3 rue Franck"),
	("Gaston",    "Gaboury",     "5554714444", "4 rue Galt"),
	("Henriette", "Hospitalité", "5558185555", "5 rue Hemmingway");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fabricants`
	(`nom`)
VALUES
	("Lenovo"),
	("Asus"),
	("Acer"),
	("Dell"),
	("Toshiba");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`types`
	(`nom`)
VALUES
	("Portable"),
	("Tour"),
	("Tablette"),
	("Téléphone");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`appareils`
	(`idType`, `idFabricant`, `idClient`, `description`, `motDePasse`)
VALUES
	(1, 2, 5, "Manque la lettre Y sur le clavier", "bonjour123"),
	(3, 1, 4, "Écran craqué",					   "1254"),
	(2, 3, 2, "Côté droit bossé",				   NULL),
	(4, 4, 1, "Écran craqué",					   NULL);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`pieces`
	(`nom`, `description`, `prix`)
VALUES
	("WesternDigital 1to Blue", "Disque dur Western Digital 1to Blue", "9999"),
	("Samsung EVO 120go", 	    "SSD Samsung EVO 120go",		       "12999"),
	("Iphone5s LCD",		    "Iphone5s LCD assembly",			   "4999"),
	("Kingston V300 240go", 	"SSD Kingston 240go",				   "18999");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`actions`
	(`nom`, `description`, `etat`)
VALUES
	("CCleaner",              "Supprimer les fichiers temporaires et nettoyer le registre.",     1),
	("Combofix",              "On sais pas trop.",												 0),
	("WD Health Diagnostic",  "Tester le disque dur.",											 1),
	("Spybot",                "Supprimer les logiciels espions.",								 1),
	("Roguekiller",           "Nettoyer le registre, les barres d'outils inutiles et autres.",  1),
	("Memtest",               "Tester mémoire RAM.",											 0),
	("Graver Driver",         "Télécharger les drivers de l'ordinateur et les graver sur DVD.", 1),
	("Sauvegarder données",   "Faire une sauvegarde des données sur un disque externe.",		 0),
	("Nouvelle installation", "Réinstaller le système d'exploitation.",						 0),
	("Cloner",                "cloner le disque dur vers un autre.",							 1);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensembles`
	(`nom`, `description`)
VALUES
	("Nettoyage de virus",		 "Nettoyer les virus et fichiers temporaires de l'ordinateur."),
	("Installation avec backup", "installation du système d'exploitation, mais en faisant une sauvegarde au préalable."),
	("Ne part pas",				 "L'ordinateur ne veut pas démarrer.");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions`
	(`idEnsemble`, `idAction`)
VALUES
	(1, 1),
	(1, 2),
	(1, 4),
	(1, 5),
	(2, 8),
	(2, 9),
	(3, 3),
	(3, 6),
	(3, 8),
	(3, 9),
	(3, 10);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsTache`
	(`nom`)
VALUES
	("Terminée"),
	("En cours"),
	("En attente"),
	("Terminée avec erreurs");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche`
	(`id`, `nom`)
VALUES
	(0, "Fermée"),
	(1, "En cours"),
	(2, "En attente"),
	(3, "Prêt, client au courant"),
	(4, "Prêt, message boîte vocale"),
	(5, "En attente de pièces"),
	(6, "En attente de confirmation du client");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fiches`
	(`idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`)
VALUES
	(1, 1, 2, 4, "Nettoyage du disque dur"),
	(1, 2, 2, 0, "Nettoyage des virus"),
	(2, 2, 2, 0, "Réparation de l'écran"),
	(2, 2, 2, 0, "Transfert de données"),
	(1, 2, 2, 0, "Ne démarre pas"),
	(2, 2, 2, 0, "Mise à niveau Windows 10"),
	(1, 2, 2, 0, "Nettoyage du disque dur"),
	(2, 2, 2, 0, "Problème de son"),
	(2, 2, 2, 0, "Nettoyage du disque dur"),
	(1, 2, 2, 0, "Nettoyage des virus"),
	(3, 2, 2, 0, "Réparation de l'écran"),
	(3, 2, 2, 0, "Transfert de données"),
	(4, 2, 2, 0, "Ne démarre pas");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fichesPieces`
	(`idFiche`, `idPiece`)
VALUES
	(5, 2),
	(8, 1);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`taches`
	(`idFiche`, `idAction`, `idStatut`)
VALUES
	(1,  1,  2),
	(1,  2,  1),
	(2,  2,  1),
	(2,  1,  1),
	(1,  3,  1),
	(3,  2,  1),
	(3,  3,  1),
	(3,  4,  1),
	(3,  5,  1),
	(4,  2,  1),
	(4,  6,  1),
	(5,  2,  1),
	(5,  6,  1),
	(6,  2,  1),
	(6,  6,  1),
	(7,  2,  1),
	(8,  2,  1),
	(9,  2,  1),
	(10, 2,  1),
	(8,  6,  1),
	(8,  7,  1),
	(9,  8,  1),
	(9,  9,  1),
	(10, 10, 1),
	(10, 1,  1),
	(5,  4,  1),
	(7,  4,  1);