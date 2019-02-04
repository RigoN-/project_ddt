# --------------------------------------------------------
# Host:                         127.0.0.1
# Server version:               5.0.16-nt
# Server OS:                    Win32
# HeidiSQL version:             6.0.0.3603
# Date/time:                    2012-02-01 19:43:53
# --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

# Dumping database structure for tester
CREATE DATABASE IF NOT EXISTS `tester` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `tester`;


# Dumping structure for table tester.answers
CREATE TABLE IF NOT EXISTS `answers` (
  `id` int(10) unsigned NOT NULL,
  `job` tinytext NOT NULL,
  `answer` tinytext NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

# Dumping data for table tester.answers: 28 rows
/*!40000 ALTER TABLE `answers` DISABLE KEYS */;
INSERT INTO `answers` (`id`, `job`, `answer`) VALUES
	(4, 'A2', '1'),
	(4, 'A3', '1'),
	(4, 'A4', '2'),
	(4, 'A5', '2'),
	(4, 'A6', '3'),
	(4, 'A7', '2'),
	(4, 'A8', '3'),
	(4, 'A9', '4'),
	(4, 'A10', '1'),
	(4, 'A11', '1'),
	(4, 'A12', '2'),
	(4, 'A13', '2'),
	(4, 'B1', '160'),
	(4, 'B2', '12121'),
	(4, 'B3', '103'),
	(4, 'B4', 'УУУОУ'),
	(4, 'B5', '2'),
	(4, 'B6', '440'),
	(4, 'B7', '777'),
	(4, 'B8', '3'),
	(4, 'B9', '13'),
	(4, 'B10', '9224'),
	(4, 'B11', 'CDEA'),
	(4, 'B12', '3270'),
	(4, 'B13', '6'),
	(4, 'B14', '2'),
	(4, 'B15', '64'),
	(4, 'A1', '2');
/*!40000 ALTER TABLE `answers` ENABLE KEYS */;


# Dumping structure for table tester.indexes
CREATE TABLE IF NOT EXISTS `indexes` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `name` text NOT NULL,
  `year` int(11) NOT NULL,
  `data` longtext NOT NULL,
  `max_a` int(10) unsigned NOT NULL,
  `max_b` int(10) unsigned NOT NULL,
  `minshow` int(10) unsigned NOT NULL,
  `maxshow` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

# Dumping data for table tester.indexes: 1 rows
/*!40000 ALTER TABLE `indexes` DISABLE KEYS */;
INSERT INTO `indexes` (`id`, `name`, `year`, `data`, `max_a`, `max_b`, `minshow`, `maxshow`) VALUES
	(4, 'Информатика', 2012, 'WIP', 13, 15, 3, 9);
/*!40000 ALTER TABLE `indexes` ENABLE KEYS */;


# Dumping structure for table tester.useranswers
CREATE TABLE IF NOT EXISTS `useranswers` (
  `userid` int(10) unsigned NOT NULL,
  `workid` int(10) unsigned NOT NULL,
  `job` tinytext NOT NULL,
  `answer` tinytext,
  `iscorrect` tinyint(4) NOT NULL default '0',
  `date` timestamp NOT NULL default CURRENT_TIMESTAMP
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

# Dumping data for table tester.useranswers: 28 rows
/*!40000 ALTER TABLE `useranswers` DISABLE KEYS */;
INSERT INTO `useranswers` (`userid`, `workid`, `job`, `answer`, `iscorrect`, `date`) VALUES
	(3, 4, 'A1', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A2', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A3', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A4', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A5', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A6', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A7', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A8', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A9', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A10', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A11', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A12', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'A13', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B1', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B2', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B3', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B4', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B5', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B6', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B7', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B8', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B9', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B10', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B11', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B12', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B13', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B14', '', 0, '2012-01-31 19:03:44'),
	(3, 4, 'B15', '', 0, '2012-01-31 19:03:44'),
	(4, 4, 'A1', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A2', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A3', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A4', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A5', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A6', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A7', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A8', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A9', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A10', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A11', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A12', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'A13', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B1', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B2', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B3', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B4', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B5', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B6', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B7', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B8', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B9', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B10', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B11', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B12', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B13', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B14', '', 0, '2012-02-01 19:43:13'),
	(4, 4, 'B15', '', 0, '2012-02-01 19:43:13');
/*!40000 ALTER TABLE `useranswers` ENABLE KEYS */;


# Dumping structure for table tester.users
CREATE TABLE IF NOT EXISTS `users` (
  `id` mediumint(8) unsigned NOT NULL auto_increment,
  `login` tinytext NOT NULL,
  `password` text NOT NULL,
  `firstname` tinytext NOT NULL,
  `lastname` tinytext NOT NULL,
  `group` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

# Dumping data for table tester.users: 2 rows
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `login`, `password`, `firstname`, `lastname`, `group`) VALUES
	(1, 'admin', '123123', 'Павел', 'Матюнин', 10),
	(3, 'mpavel', '123123', 'Павел', 'Матюнин', 1);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
