--
-- Contraintes pour la table `appareils`
--
ALTER TABLE `appareils`
  DROP FOREIGN KEY `appareilClient`,
  DROP FOREIGN KEY `appareilFabricant`,
  DROP FOREIGN KEY `appareilType`;

--
-- Contraintes pour la table `ensemblesActions`
--
ALTER TABLE `ensemblesActions`
  DROP FOREIGN KEY `ensemblesActionsActions`,
  DROP FOREIGN KEY `ensemblesActionsEnsemble`;

--
-- Contraintes pour la table `fiches`
--
ALTER TABLE `fiches`
  DROP FOREIGN KEY `fichesAppareil`,
  DROP FOREIGN KEY `fichesStatut`;

--
-- Contraintes pour la table `fichesPieces`
--
ALTER TABLE `fichesPieces`
  DROP FOREIGN KEY `fichesPiecesFiche`,
  DROP FOREIGN KEY `fichesPiecesPiece`;

--
-- Contraintes pour la table `taches`
--
ALTER TABLE `taches`
  DROP FOREIGN KEY `tachesAction`,
  DROP FOREIGN KEY `tachesFiche`,
  DROP FOREIGN KEY `tachesStatut`;
