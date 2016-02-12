-- Commandes pour insérer des valeurs par défaut dans les tables

INSERT INTO `InfoDynamiqueDossiers`.`techniciens`
    (`id`, `prenom`, `nom`)
VALUES
    (1, "Ajax",    "Archambeault"),
    (2, "Bruno",   "Beaudoin"),
    (3, "Charles", "Chartrand");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`clients`
    (`id`, `prenom`, `nom`, `telephone`, `adresse`)
VALUES
    (1, "Dilbert",   "Daiquiri",    "5558501111", "1 rue Dickens"),
    (2, "Elphège",   "Éléphant",    "5554502222", "2 rue Eddings"),
    (3, "Franny",    "Fréchette",   "5554183333", "3 rue Franck"),
    (4, "Gaston",    "Gaboury",     "5554714444", "4 rue Galt"),
    (5, "Henriette", "Hospitalité", "5558185555", "5 rue Hemmingway");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fabricants`
    (`id`, `nom`)
VALUES
    (1, "Lenovo"),
    (2, "Asus"),
    (3, "Acer"),
    (4, "Dell"),
    (5, "Toshiba");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`types`
    (`id`, `nom`)
VALUES
    (1, "Portable"),
    (2, "Tour"),
    (3, "Tablette"),
    (4, "Téléphone");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`appareils`
    (`id`, `idType`, `idFabricant`, `idClient`, `description`, `motDePasse`)
VALUES
    (1, 1, 2, 5, "Manque la lettre Y sur le clavier", "bonjour123"),
    (2, 3, 1, 4, "Écran craqué",                      "1254"),
    (3, 2, 3, 2, "Côté droit bossé",                  NULL),
    (4, 4, 4, 1, "Écran craqué",                      NULL);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`pieces`
    (`id`, `nom`, `description`, `prix`)
VALUES
    (1, "WesternDigital 1to Blue", "Disque dur Western Digital 1to Blue", "9999"),
    (2, "Samsung EVO 120go",       "SSD Samsung EVO 120go",              "12999"),
    (3, "Iphone5s LCD",            "Iphone5s LCD assembly",               "4999"),
    (4, "Kingston V300 240go",     "SSD Kingston 240go",                  "18999");

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`actions`
    (`id`, `nom`, `description`, `etat`)
VALUES
    (1,  "CCleaner",              "Supprimer les fichiers temporaires et nettoyer le registre.",    1),
    (2,  "Combofix",              "On sais pas trop.",                                              0),
    (3,  "WD Health Diagnostic",  "Tester le disque dur.",                                          1),
    (4,  "Spybot",                "Supprimer les logiciels espions.",                               1),
    (5,  "Roguekiller",           "Nettoyer le registre, les barres d'outils inutiles et autres.",  1),
    (6,  "Memtest",               "Tester mémoire RAM.",                                            0),
    (7,  "Graver Driver",         "Télécharger les drivers de l'ordinateur et les graver sur DVD.", 1),
    (8,  "Sauvegarder données",   "Faire une sauvegarde des données sur un disque externe.",        0),
    (9,  "Nouvelle installation", "Réinstaller le système d'exploitation.",                         0),
    (10, "Cloner",                "cloner le disque dur vers un autre.",                            1);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensembles`
    (`id`, `nom`, `description`)
VALUES
    (1, "Nettoyage de virus",       "Nettoyer les virus et fichiers temporaires de l'ordinateur."),
    (2, "Installation avec backup", "installation du système d'exploitation, mais en faisant une sauvegarde au préalable."),
    (3, "Ne part pas",              "L'ordinateur ne veut pas démarrer.");

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
    (`id`, `nom`)
VALUES
    (1, "Terminée"),
    (2, "En cours"),
    (3, "En attente"),
    (4, "Terminée avec erreurs");

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
    (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`)
VALUES
    (1,  1, 1, 2, 4, "Nettoyage du disque dur"),
    (2,  1, 2, 2, 0, "Nettoyage des virus"),
    (3,  2, 2, 2, 0, "Réparation de l'écran"),
    (4,  2, 2, 2, 0, "Transfert de données"),
    (5,  1, 2, 2, 0, "Ne démarre pas"),
    (6,  2, 2, 2, 0, "Mise à niveau Windows 10"),
    (7,  1, 2, 2, 0, "Nettoyage du disque dur"),
    (8,  2, 2, 2, 0, "Problème de son"),
    (9,  2, 2, 2, 0, "Nettoyage du disque dur"),
    (10, 1, 2, 2, 0, "Nettoyage des virus"),
    (11, 3, 2, 2, 0, "Réparation de l'écran"),
    (12, 3, 2, 2, 0, "Transfert de données"),
    (13, 4, 2, 2, 0, "Ne démarre pas");

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