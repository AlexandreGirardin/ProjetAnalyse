-- phpMyAdmin SQL Dump
-- version 4.4.15
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Jeu 29 Octobre 2015 à 19:07
-- Version du serveur :  10.0.21-MariaDB
-- Version de PHP :  5.6.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

-- --------------------------------------------------------

--
-- Structure de la table `modifications`
--

CREATE TABLE IF NOT EXISTS `date` (
  `derniereModification` TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO date
	(derniereModification)
VALUES
	(CURRENT_TIMESTAMP)

-- --------------------------------------------------------

--
-- Structure de la table `actions`
--

CREATE TABLE IF NOT EXISTS `actions` (
  `id` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `etat` tinyint(1) NOT NULL DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `appareils`
--

CREATE TABLE IF NOT EXISTS `appareils` (
  `id` int(10) NOT NULL,
  `idType` int(10) NOT NULL,
  `idFabricant` int(10) NOT NULL,
  `idClient` int(10) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `motDePasse` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `clients`
--

CREATE TABLE IF NOT EXISTS `clients` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `telephone` varchar(255) NOT NULL,
  `adresse` varchar(255) DEFAULT NULL,
  `courriel` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `ensembles`
--

CREATE TABLE IF NOT EXISTS `ensembles` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `ensemblesActions`
--

CREATE TABLE IF NOT EXISTS `ensemblesActions` (
  `idEnsemble` int(10) NOT NULL,
  `idAction` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `fabricants` et données de base
--

CREATE TABLE IF NOT EXISTS `fabricants` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `fabricants`
    (`id`, `nom`)
VALUES
    (1, "Lenovo"),
    (2, "Asus"),
    (3, "Acer"),
    (4, "Dell"),
    (5, "Toshiba"),
    (6, "Autre");

-- --------------------------------------------------------

--
-- Structure de la table `fiches`
--

CREATE TABLE IF NOT EXISTS `fiches` (
  `id` int(10) NOT NULL,
  `idAppareil` int(10) NOT NULL,
  `priorite` int(10) NOT NULL,
  `idStatut` int(10) NOT NULL,
  `commentaire` varchar(1023) DEFAULT NULL,
  `description` varchar(1023) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `fichesPieces`
--

CREATE TABLE IF NOT EXISTS `fichesPieces` (
  `idFiche` int(10) NOT NULL,
  `idPiece` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `pieces`
--

CREATE TABLE IF NOT EXISTS `pieces` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `prix` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `statutsFiche`
--

CREATE TABLE IF NOT EXISTS `statutsFiche` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `statutsFiche`
    (`id`, `nom`)
VALUES
    (0, "Fermée"),
    (1, "En cours"),
    (2, "En attente"),
    (3, "Prêt, client au courant"),
    (4, "Prêt, message boîte vocale"),
    (5, "En attente de pièces"),
    (6, "En attente de confirmation du client");

-- --------------------------------------------------------

--
-- Structure de la table `statutsTache`
--

CREATE TABLE IF NOT EXISTS `statutsTache` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `statutsTache`
    (`id`, `nom`)
VALUES
    (0, "Terminée"),
    (1, "En cours"),
    (2, "En attente"),
    (3, "Terminée avec erreurs");

-- --------------------------------------------------------

--
-- Structure de la table `taches`
--

CREATE TABLE IF NOT EXISTS `taches` (
  `id` int(10) NOT NULL,
  `idFiche` int(10) NOT NULL,
  `idAction` int(10) NOT NULL,
  `idStatut` int(10) NOT NULL,
  `commentaire` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `types`
--

CREATE TABLE IF NOT EXISTS `types` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `types`
    (`id`, `nom`)
VALUES
    (1, "Portable"),
    (2, "Tour"),
    (3, "Tablette"),
    (4, "Téléphone");

-- --------------------------------------------------------

--
-- Structure de la table `usagers`
--

CREATE TABLE IF NOT EXISTS `usagers` (
  `id` int(10) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `motDePasse` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour la table `actions`
--
ALTER TABLE `actions`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- Index pour la table `appareils`
--
ALTER TABLE `appareils`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idType` (`idType`),
  ADD KEY `idFabricant` (`idFabricant`),
  ADD KEY `idClient` (`idClient`);

--
-- Index pour la table `clients`
--
ALTER TABLE `clients`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `ensembles`
--
ALTER TABLE `ensembles`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `ensemblesActions`
--
ALTER TABLE `ensemblesActions`
  ADD PRIMARY KEY (`idEnsemble`,`idAction`),
  ADD KEY `ensemblesActionsActions` (`idAction`);

--
-- Index pour la table `fabricants`
--
ALTER TABLE `fabricants`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- Index pour la table `fiches`
--
ALTER TABLE `fiches`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idAppareil` (`idAppareil`),
  ADD KEY `idStatut` (`idStatut`);

--
-- Index pour la table `fichesPieces`
--
ALTER TABLE `fichesPieces`
  ADD PRIMARY KEY (`idFiche`,`idPiece`),
  ADD KEY `fichesPiecesPiece` (`idPiece`);

--
-- Index pour la table `pieces`
--
ALTER TABLE `pieces`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `statutsFiche`
--
ALTER TABLE `statutsFiche`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- Index pour la table `statutsTache`
--
ALTER TABLE `statutsTache`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- Index pour la table `taches`
--
ALTER TABLE `taches`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idStatut` (`idStatut`),
  ADD KEY `tachesAction` (`idAction`);

--
-- Index pour la table `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- Index pour la table `usagers`
--
ALTER TABLE `usagers`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nom` (`nom`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `actions`
--
ALTER TABLE `actions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `appareils`
--
ALTER TABLE `appareils`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `clients`
--
ALTER TABLE `clients`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `ensembles`
--
ALTER TABLE `ensembles`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `fabricants`
--
ALTER TABLE `fabricants`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `fiches`
--
ALTER TABLE `fiches`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `pieces`
--
ALTER TABLE `pieces`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `statutsFiche`
--
ALTER TABLE `statutsFiche`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `statutsTache`
--
ALTER TABLE `statutsTache`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `taches`
--
ALTER TABLE `taches`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `types`
--
ALTER TABLE `types`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `usagers`
--
ALTER TABLE `usagers`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- Contraintes pour les tables exportées
--

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
