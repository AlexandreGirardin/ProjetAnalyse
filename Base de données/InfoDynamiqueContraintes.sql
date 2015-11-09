--
-- Contraintes pour la table `appareils`
--
ALTER TABLE `appareils`
  ADD CONSTRAINT `appareilClient` FOREIGN KEY (`idClient`) REFERENCES `clients` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `appareilFabricant` FOREIGN KEY (`idFabricant`) REFERENCES `fabricants` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `appareilType` FOREIGN KEY (`idType`) REFERENCES `types` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `ensemblesActions`
--
ALTER TABLE `ensemblesActions`
  ADD CONSTRAINT `ensemblesActionsActions` FOREIGN KEY (`idAction`) REFERENCES `actions` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `ensemblesActionsEnsemble` FOREIGN KEY (`idEnsemble`) REFERENCES `ensembles` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `fiches`
--
ALTER TABLE `fiches`
  ADD CONSTRAINT `fichesAppareil` FOREIGN KEY (`idAppareil`) REFERENCES `appareils` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fichesStatut` FOREIGN KEY (`idStatut`) REFERENCES `statutsFiche` (`id`),
  ADD CONSTRAINT `fichesTechnicien` FOREIGN KEY (`idTechnicien`) REFERENCES `techniciens` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `fichesPieces`
--
ALTER TABLE `fichesPieces`
  ADD CONSTRAINT `fichesPiecesFiche` FOREIGN KEY (`idFiche`) REFERENCES `fiches` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fichesPiecesPiece` FOREIGN KEY (`idPiece`) REFERENCES `pieces` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `taches`
--
ALTER TABLE `taches`
  ADD CONSTRAINT `tachesAction` FOREIGN KEY (`idAction`) REFERENCES `actions` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `tachesFiche` FOREIGN KEY (`idFiche`) REFERENCES `fiches` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `tachesStatut` FOREIGN KEY (`idStatut`) REFERENCES `statutsTache` (`id`) ON UPDATE CASCADE;
