--
-- Contraintes pour la table `appareils`
--
ALTER TABLE `appareils`
  ADD CONSTRAINT `appareilClient` FOREIGN KEY IF NOT EXISTS (`idClient`) REFERENCES `clients` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `appareilFabricant` FOREIGN KEY IF NOT EXISTS (`idFabricant`) REFERENCES `fabricants` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `appareilType` FOREIGN KEY IF NOT EXISTS (`idType`) REFERENCES `types` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `ensemblesActions`
--
ALTER TABLE `ensemblesActions`
  ADD CONSTRAINT `ensemblesActionsActions` FOREIGN KEY IF NOT EXISTS (`idAction`) REFERENCES `actions` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `ensemblesActionsEnsemble` FOREIGN KEY IF NOT EXISTS (`idEnsemble`) REFERENCES `ensembles` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `fiches`
--
ALTER TABLE `fiches`
  ADD CONSTRAINT `fichesAppareil` FOREIGN KEY IF NOT EXISTS (`idAppareil`) REFERENCES `appareils` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fichesStatut` FOREIGN KEY IF NOT EXISTS (`idStatut`) REFERENCES `statutsFiche` (`id`),
  ADD CONSTRAINT `fichesTechnicien` FOREIGN KEY IF NOT EXISTS (`idTechnicien`) REFERENCES `techniciens` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `fichesPieces`
--
ALTER TABLE `fichesPieces`
  ADD CONSTRAINT `fichesPiecesFiche` FOREIGN KEY IF NOT EXISTS (`idFiche`) REFERENCES `fiches` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fichesPiecesPiece` FOREIGN KEY IF NOT EXISTS (`idPiece`) REFERENCES `pieces` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `taches`
--
ALTER TABLE `taches`
  ADD CONSTRAINT `tachesAction` FOREIGN KEY IF NOT EXISTS (`idAction`) REFERENCES `actions` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `tachesFiche` FOREIGN KEY IF NOT EXISTS (`idFiche`) REFERENCES `fiches` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `tachesStatut` FOREIGN KEY IF NOT EXISTS (`idStatut`) REFERENCES `statutsTache` (`id`) ON UPDATE CASCADE;
