-- Commandes pour insérer des valeurs par défaut dans les tables

INSERT INTO `InfoDynamiqueDossiers`.`techniciens`
	(`id`, `prenom`, `nom`)
VALUES
	(NULL,'Jean', 'Joly'),
	(NULL,'Jacques', 'Gervais'),
	(NULL,'Eric', 'Brochu');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`clients`
	(`id`, `nom`, `prenom`, `telephone`, `adresse`)
VALUES
	(NULL, 'Chouette',  'Machin', '1454745858', 'dbshbsajkd'),
	(NULL, 'Lui-là',  'Machine', '14252147582', 'dbsahdbas bdsuahdjkhsajk'),
	(NULL, 'Là',  'Autre-là', '1454745858', 'dbshbsajkd'),
	(NULL, 'Chose',  'Machin', '21253695852', 'dsabkjdbas bdsajkhbda'),
	(NULL, 'Autre',  'Chouette', '1454745858', 'hfdjkjskfn vkhvjs');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fabricants`
	(`id`, `nom`)
VALUES
	(NULL, 'Lenovo'),
	(NULL, 'Asus'),
	(NULL, 'Acer'),
	(NULL, 'Dell'),
	(NULL, 'Toshiba');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`types`
	(`id`, `nom`)
VALUES
	(NULL, 'Portable'),
	(NULL, 'Tour'),
	(NULL, 'Tablette'),
	(NULL, 'Téléphone');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`usagers`
	(`id`, `nom`, `motDePasse`)
VALUES
	(NULL, 'Machin', 'chouette'),
	(NULL, 'Robert', 'deNiro'),
	(NULL, 'fndjosjfdso', 'nfdjsjfsfosd'),
	(NULL, 'dsakldjaskljkasl', 'dhasjdkljasl'),
	(NULL, 'Serge', 'Landry');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`appareils`
	(`id`, `idType`, `idFabricant`, `idClient`, `Description`, `motDePasse`)
VALUES
	(NULL, '1', '2', '5', 'Manque la lettre Y sur le clavier', 'bonjour123'),
	(NULL, '3', '1', '4', 'Écran cracké', '1254'),
	(NULL, '2', '3', '2', 'Coté droit bossé', NULL),
	(NULL, '4', '4', '1', 'Écran cracké', NULL);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`pieces`
	(`id`, `nom`, `description`, `prix`)
VALUES
	(NULL, 'WesternDigital 1to Blue', 'Disque dur Western Digital 1to Blue', '9999'),
	(NULL, 'Samsung EVO 120go', 'SSD Samsung EVO 120go', '12999'),
	(NULL, 'Iphone5s LCD', 'Iphone5s LCD assembly', '4999'),
	(NULL, 'Kingston V300 240go', 'SSD Kingston 240go', '18999');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`actions`
	(`id`, `nom`, `description`)
VALUES
	(NULL, 'CCleaner', 'Supprimer les fichiers temporaires et nettoyer le registre.'),
	(NULL, 'Combofix', 'On sais pas trop.'),
	(NULL, 'WD Health Diagnostic', 'Tester le disque dur.'),
	(NULL, 'Spybot', 'Supprimer les logiciels espions.'),
	(NULL, 'Roguekiller', 'Nettoyer le registre, les barres d''outils inutiles et autres.'),
	(NULL, 'Memtest', 'Tester mémoire RAM.'),
	(NULL, 'Graver Driver', 'Télécharger les drivers de l''ordinateur et les graver sur DVD.'),
	(NULL, 'Sauvegarder données', 'Faire une sauvegarde des données sur un disque externe.'),
	(NULL, 'Nouvelle installation', 'Réinstaller le système d''exploitation.'),
	(NULL, 'Cloner', 'cloner le disque dur vers un autre.');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensembles`
	(`id`, `nom`, `description`)
VALUES
	(NULL, 'Nettoyage de Virus', 'Nettoyer les virus et fichiers temporaires de l''ordinateur.'),
	(NULL, 'Installation avec Backup', 'installation du système d''exploitation, mais en faisant une sauvegarde au préalable.'),
	(NULL, 'Ne part pas', 'L''ordinateur ne veut pas démarrer.');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions`
	(`idEnsemble`, `idAction`)
VALUES
	('1', '1'),
	('1', '2'),
	('1', '4'),
	('1', '5'),
	('2', '8'),
	('2', '9'),
	('3', '3'),
	('3', '6'),
	('3', '8'),
	('3', '10'),
	('3', '9');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsTache`
	(`id`, `nom`)
VALUES
	(NULL, 'Terminée'),
	(NULL, 'En cours'),
	(NULL, 'En attente'),
	(NULL, 'Terminée avec erreurs');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche`
	(`id`, `nom`)
VALUES
	(NULL, 'En attente'),
	(NULL, 'Prêt, client au courant'),
	(NULL, 'Prêt, message boîte vocale'),
	(NULL, 'En attente de pièces'),
	(NULL, 'Fermée'),
	(NULL, 'En attente de confirmation du client'),
	(NULL, 'En cours');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fiches`
	(`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`)
VALUES
	(NULL, 1, 1, 2, 4, 'allo'),
	(NULL, 1, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 2, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 2, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 1, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 2, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 1, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 2, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 2, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 1, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 3, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 3, 2, 2, 5, 'dkadmkamdklsakl'),
	(NULL, 4, 2, 2, 5, 'dkadmkamdklsakl');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fichesPieces`
	(`idFiche`, `idPiece`)
VALUES
	('5', '2'),
	('8', '1');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`taches`
	(`idFiche`, `idAction`, `idStatut`)
VALUES
	('1', '1', '2'),
	('1', '2', '1'),
	('2', '2', '1'),
	('2', '1', '1'),
	('1', '3', '1'),
	('3', '2', '1'),
	('3', '3', '1'),
	('3', '4', '1'),
	('3', '5', '1'),
	('4', '2', '1'),
	('4', '6', '1'),
	('5', '2', '1'),
	('5', '6', '1'),
	('6', '2', '1'),
	('6', '6', '1'),
	('7', '2', '1'),
	('8', '2', '1'),
	('9', '2', '1'),
	('10', '2', '1'),
	('8', '6', '1'),
	('8', '7', '1'),
	('9', '8', '1'),
	('9', '9', '1'),
	('10', '10', '1'),
	('10', '1', '1'),
	('5', '4', '1'),
	('7', '4', '1');