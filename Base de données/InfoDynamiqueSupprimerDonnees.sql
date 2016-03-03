-- Commandes pour supprimer toutes les données de la base de données

-- première vague
DELETE FROM ensemblesActions;
DELETE FROM taches;
DELETE FROM fichesPieces;
DELETE FROM pieces;
DELETE FROM usagers;

-- deuxième vague
DELETE FROM ensembles;
DELETE FROM actions;

-- troisième vague
DELETE FROM appareils;
DELETE FROM clients;
DELETE FROM fiches;
