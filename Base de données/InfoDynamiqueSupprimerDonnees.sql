-- Commandes pour supprimer toutes les données de la base de données

-- première vague
DELETE FROM "ensemblesactions";
DELETE FROM "taches";
DELETE FROM "fichespieces";
DELETE FROM "pieces";
DELETE FROM "usagers";

-- deuxième vague
DELETE FROM "ensembles";
DELETE FROM "actions";
DELETE FROM "statutstache";
DELETE FROM "statutsfiche";
DELETE FROM "techniciens";

-- troisième vague
DELETE FROM "appareils";
DELETE FROM "clients";
DELETE FROM "fabricants";
DELETE FROM "types";