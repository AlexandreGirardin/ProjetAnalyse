-- Commandes pour insérer des valeurs par défaut dans les tables

INSERT INTO `InfoDynamiqueDossiers`.`techniciens`(`id`, `nom`) VALUES (NULL,'Jean');
INSERT INTO `InfoDynamiqueDossiers`.`techniciens`(`id`, `nom`) VALUES (NULL,'Jacques');
INSERT INTO `InfoDynamiqueDossiers`.`techniciens`(`id`, `nom`) VALUES (NULL,'Brochu');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`clients` (`id`, `nom`, `telephone`, `adresse`) VALUES (NULL, 'rejwoifdjiaso', '1454745858', 'dbshbsajkd');
INSERT INTO `InfoDynamiqueDossiers`.`clients` (`id`, `nom`, `telephone`, `adresse`) VALUES (NULL, 'dasbnmbam', '14252147582', 'dbsahdbas bdsuahdjkhsajk');
INSERT INTO `InfoDynamiqueDossiers`.`clients` (`id`, `nom`, `telephone`, `adresse`) VALUES (NULL, 'hdjfkdsfkld', '1454745858', 'dbshbsajkd');
INSERT INTO `InfoDynamiqueDossiers`.`clients` (`id`, `nom`, `telephone`, `adresse`) VALUES (NULL, 'dbsansjs dh', '21253695852', 'dsabkjdbas bdsajkhbda');
INSERT INTO `InfoDynamiqueDossiers`.`clients` (`id`, `nom`, `telephone`, `adresse`) VALUES (NULL, 'rejwsbjsbjbjoifdjiaso', '1454745858', 'hfdjkjskfn vkhvjs');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fabricants` (`id`, `nom`) VALUES (NULL, 'Lenovo');
INSERT INTO `InfoDynamiqueDossiers`.`fabricants` (`id`, `nom`) VALUES (NULL, 'Asus');
INSERT INTO `InfoDynamiqueDossiers`.`fabricants` (`id`, `nom`) VALUES (NULL, 'Acer');
INSERT INTO `InfoDynamiqueDossiers`.`fabricants` (`id`, `nom`) VALUES (NULL, 'Dell');
INSERT INTO `InfoDynamiqueDossiers`.`fabricants` (`id`, `nom`) VALUES (NULL, 'Toshiba');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`types` (`id`, `nom`) VALUES (NULL, 'Portable');
INSERT INTO `InfoDynamiqueDossiers`.`types` (`id`, `nom`) VALUES (NULL, 'Tour');
INSERT INTO `InfoDynamiqueDossiers`.`types` (`id`, `nom`) VALUES (NULL, 'Tablette');
INSERT INTO `InfoDynamiqueDossiers`.`types` (`id`, `nom`) VALUES (NULL, 'Téléphone');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`usagers` (`id`, `nom`, `motDePasse`) VALUES (NULL, 'Machin', 'chouette');
INSERT INTO `InfoDynamiqueDossiers`.`usagers` (`id`, `nom`, `motDePasse`) VALUES (NULL, 'Robert', 'deNiro');
INSERT INTO `InfoDynamiqueDossiers`.`usagers` (`id`, `nom`, `motDePasse`) VALUES (NULL, 'fndjosjfdso', 'nfdjsjfsfosd');
INSERT INTO `InfoDynamiqueDossiers`.`usagers` (`id`, `nom`, `motDePasse`) VALUES (NULL, 'dsakldjaskljkasl', 'dhasjdkljasl');
INSERT INTO `InfoDynamiqueDossiers`.`usagers` (`id`, `nom`, `motDePasse`) VALUES (NULL, 'Serge', 'Landry');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`appareils` (`id`, `idType`, `idFabricant`, `idClient`, `Description`, `motDePasse`) VALUES (NULL, '1', '2', '5', 'Manque la lettre Y sur le clavier', 'bonjour123');
INSERT INTO `InfoDynamiqueDossiers`.`appareils` (`id`, `idType`, `idFabricant`, `idClient`, `Description`, `motDePasse`) VALUES (NULL, '3', '1', '4', 'Écran cracké', '1254');
INSERT INTO `InfoDynamiqueDossiers`.`appareils` (`id`, `idType`, `idFabricant`, `idClient`, `Description`, `motDePasse`) VALUES (NULL, '2', '3', '2', 'Coté droit bossé', NULL);
INSERT INTO `InfoDynamiqueDossiers`.`appareils` (`id`, `idType`, `idFabricant`, `idClient`, `Description`, `motDePasse`) VALUES (NULL, '4', '4', '1', 'Écran cracké', NULL);

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`pieces` (`id`, `nom`, `description`, `prix`) VALUES (NULL, 'WesternDigital 1to Blue', 'Disque dur Western Digital 1to Blue', '9999');
INSERT INTO `InfoDynamiqueDossiers`.`pieces` (`id`, `nom`, `description`, `prix`) VALUES (NULL, 'Samsung EVO 120go', 'SSD Samsung EVO 120go', '12999');
INSERT INTO `InfoDynamiqueDossiers`.`pieces` (`id`, `nom`, `description`, `prix`) VALUES (NULL, 'Iphone5s LCD', 'Iphone5s LCD assembly', '4999');
INSERT INTO `InfoDynamiqueDossiers`.`pieces` (`id`, `nom`, `description`, `prix`) VALUES (NULL, 'Kingston V300 240go', 'SSD Kingston 240go', '18999');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'CCleaner', 'Supprimer les fichiers temporaires et nettoyer le registre.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Combofix', 'On sais pas trop.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'WD Health Diagnostic', 'Tester le disque dur.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Spybot', 'Supprimer les logiciels espions.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Roguekiller', 'Nettoyer le registre, les barres d''outils inutiles et autres.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Memtest', 'Tester mémoire RAM.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Graver Driver', 'Télécharger les drivers de l''ordinateur et les graver sur DVD.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Sauvegarder données', 'Faire une sauvegarde des données sur un disque externe.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Nouvelle installation', 'Réinstaller le système d''exploitation.');
INSERT INTO `InfoDynamiqueDossiers`.`actions` (`id`, `nom`, `description`) VALUES (NULL, 'Cloner', 'cloner le disque dur vers un autre.');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensembles` (`id`, `nom`, `description`) VALUES (NULL, 'Nettoyage de Virus', 'Nettoyer les virus et fichiers temporaires de l''ordinateur.');
INSERT INTO `InfoDynamiqueDossiers`.`ensembles` (`id`, `nom`, `description`) VALUES (NULL, 'Installation avec Backup', 'installation du système d''exploitation, mais en faisant une sauvegarde au préalable.');
INSERT INTO `InfoDynamiqueDossiers`.`ensembles` (`id`, `nom`, `description`) VALUES (NULL, 'Ne part pas', 'L''ordinateur ne veut pas démarrer.');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('1', '1');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('1', '2');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('1', '4');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('1', '5');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('2', '8');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('2', '9');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('3', '3');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('3', '6');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('3', '8');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('3', '10');
INSERT INTO `InfoDynamiqueDossiers`.`ensemblesActions` (`idEnsemble`, `idAction`) VALUES ('3', '9');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsTache` (`id`, `nom`) VALUES (NULL, 'Terminée');
INSERT INTO `InfoDynamiqueDossiers`.`statutsTache` (`id`, `nom`) VALUES (NULL, 'En cours');
INSERT INTO `InfoDynamiqueDossiers`.`statutsTache` (`id`, `nom`) VALUES (NULL, 'En attente');
INSERT INTO `InfoDynamiqueDossiers`.`statutsTache` (`id`, `nom`) VALUES (NULL, 'Terminée avec erreurs');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'En attente');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'Prêt, client au courant');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'Prêt, message boîte vocale');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'En attente de pièces');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'Fermée');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'En attente de confirmation du client');
INSERT INTO `InfoDynamiqueDossiers`.`statutsFiche` (`id`, `nom`) VALUES (NULL, 'En cours');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 1, 1, 2, 4, 'allo');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 1, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 2, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 2, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 1, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 2, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 1, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 2, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 2, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 1, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 3, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 3, 2, 2, 5, 'dkadmkamdklsakl');
INSERT INTO `InfoDynamiqueDossiers`.`fiches` (`id`, `idAppareil`, `priorite`, `idTechnicien`, `idStatut`, `commentaire`) VALUES (NULL, 4, 2, 2, 5, 'dkadmkamdklsakl');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`fichesPieces` (`idFiche`, `idPiece`) VALUES ('5', '2');
INSERT INTO `InfoDynamiqueDossiers`.`fichesPieces` (`idFiche`, `idPiece`) VALUES ('8', '1');

-- ------------------------------------------------------------

INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('1', '1', '2');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('1', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('2', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('2', '1', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('1', '3', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('3', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('3', '3', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('3', '4', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('3', '5', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('4', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('4', '6', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('5', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('5', '6', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('6', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('6', '6', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('7', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('8', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('9', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('10', '2', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('8', '6', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('8', '7', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('9', '8', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('9', '9', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('10', '10', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('10', '1', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('5', '4', '1');
INSERT INTO `InfoDynamiqueDossiers`.`taches` (`idFiche`, `idAction`, `idStatut`) VALUES ('7', '4', '1');