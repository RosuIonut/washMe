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
-- Table structure for table `wash_vendors`
--

DROP TABLE IF EXISTS `wash_vendors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wash_vendors` (
  `idwash_vendors` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `password` varchar(45) NOT NULL,
  `details` varchar(45) DEFAULT NULL,
  `schedule` varchar(45) NOT NULL,
  `gpslocation` varchar(45) NOT NULL,
  `capacity` int(10) unsigned NOT NULL,
  `washing_types` varchar(45) NOT NULL,
  `rating` varchar(5) NOT NULL DEFAULT '00.00',
  PRIMARY KEY (`idwash_vendors`),
  UNIQUE KEY `name_UNIQUE` (`name`),
  UNIQUE KEY `gpslocation_UNIQUE` (`gpslocation`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `wash_vendors`
--

LOCK TABLES `wash_vendors` WRITE;
/*!40000 ALTER TABLE `wash_vendors` DISABLE KEYS */;
INSERT INTO `wash_vendors` VALUES (1,'nova','nova','','all day','555.3322.566',445,'all','123'),(2,'a','anbc','detaliiii','10:00 - 22:00','2355552.2415465',2556,'de toate','123'),(3,'NouaSpalatorie','Nouaparola','','00:00-00:00','GPSLOCATION',23,'de toate',''),(4,'Altaspalatorie','altaparola','','','',0,'','');
/*!40000 ALTER TABLE `wash_vendors` ENABLE KEYS */;
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
