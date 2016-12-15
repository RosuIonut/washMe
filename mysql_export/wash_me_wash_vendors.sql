-- MySQL dump 10.13  Distrib 5.7.16, for Linux (x86_64)
--
-- Host: localhost    Database: wash_me
-- ------------------------------------------------------
-- Server version	5.7.16-0ubuntu0.16.10.1

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
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `wash_vendors`
--

LOCK TABLES `wash_vendors` WRITE;
/*!40000 ALTER TABLE `wash_vendors` DISABLE KEYS */;
INSERT INTO `wash_vendors` VALUES (1,'Nova','pass','TBD','all day','46.782922, 23.601602',3,'all','3.75'),(2,'Cristal Auto','pass','detalii','07:00 - 22:00','46.764311, 23.559874',2,'all','4.5'),(10,'Tip Top','pass','TBD','08:00 – 20:00','46.777574, 23.609112',1,'TBD','5'),(11,'Auto Mercur','pass','TBD','08:00 – 20:00','46.767963, 23.624604',1,'TBD','5'),(12,'CLEAN CAR S.R.L.','pass','TBD','unknown','46.758564, 23.618412',3,'all','4.12'),(13,'Magic Wash','pass','TBD','08:00 - 22:00','46.771067, 23.630486',4,'all','4.58');
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

-- Dump completed on 2016-12-15 10:03:43
