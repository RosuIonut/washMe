CREATE DATABASE  IF NOT EXISTS `wash_me` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `wash_me`;
-- MySQL dump 10.13  Distrib 5.5.53, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: wash_me
-- ------------------------------------------------------
-- Server version	5.5.53-0+deb8u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `reservs`
--

DROP TABLE IF EXISTS `reservs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservs` (
  `idreservs` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `idwash_vendor` int(10) unsigned NOT NULL,
  `iduser` int(10) unsigned NOT NULL,
  `idemployee` int(10) unsigned DEFAULT NULL,
  `washing_type` varchar(45) NOT NULL,
  `washing_hour` datetime NOT NULL,
  `status` int(10) unsigned NOT NULL DEFAULT '0',
  `wash_block` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`idreservs`),
  KEY `fk_reservs_1_idx` (`idwash_vendor`),
  KEY `fk_reservs_2_idx` (`iduser`),
  KEY `fk_reservs_3_idx` (`idemployee`),
  CONSTRAINT `fk_reservs_1` FOREIGN KEY (`idwash_vendor`) REFERENCES `wash_vendors` (`idwash_vendors`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_reservs_2` FOREIGN KEY (`iduser`) REFERENCES `users` (`iduser`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservs`
--

LOCK TABLES `reservs` WRITE;
/*!40000 ALTER TABLE `reservs` DISABLE KEYS */;
INSERT INTO `reservs` VALUES (3,1,8,2,'interior + exterior','2015-09-11 21:30:00',2,5),(4,1,7,1,'564564','0000-00-00 00:00:00',1,1);
/*!40000 ALTER TABLE `reservs` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-11-23 18:16:17
