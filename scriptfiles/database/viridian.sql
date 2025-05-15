CREATE TABLE IF NOT EXISTS `users` (
	`id` int NOT NULL AUTO_INCREMENT,
	`nome` varchar(26) NOT NULL,
	`senha` varchar(66) NOT NULL,
	`salt` varchar(14) NOT NULL,
	`level` int DEFAULT 0,
	`skin` int DEFAULT 29,
	`vip` int DEFAULT 0,
	`diasvip` varchar(35) NOT NULL,
	`avisos` int DEFAULT 0,
	`youtuber` int DEFAULT 0,
	`coins` int DEFAULT 0,
	`kills` int DEFAULT 0,
	`dinheiro` int DEFAULT 0,
	`admin` int DEFAULT 0,
	`familia` int DEFAULT -1,
	`cargofamilia` int DEFAULT 0,
	`discord_id` varchar(31) NOT NULL,
	`discord_name` varchar(35) NOT NULL,
	`aviso_agendado` int DEFAULT 0,
	`motivo_aviso` varchar(35) NOT NULL,
	`recuperacao` int DEFAULT 0,
	`codigodiscord` int DEFAULT 0,
	PRIMARY KEY (`id`)
);

CREATE TABLE IF NOT EXISTS `tablebanned` (
	`id` int DEFAULT 0,
	`data_banned` int DEFAULT 0,
	`motivo` varchar(30) NOT NULL,
	`admin` varchar(30) NOT NULL,
	`ip` varchar(18) NOT NULL
);

CREATE TABLE IF NOT EXISTS `codigos` (
	`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  	`codigo` VARCHAR(64) UNIQUE,
 	`tipo` ENUM('vip', 'coins'),
  	`valor` INT,
 	`dias` INT DEFAULT 0,
  	`resgatado` TINYINT(1) DEFAULT 0
);

CREATE TABLE IF NOT EXISTS `familia` (
	`id` int NOT NULL PRIMARY KEY,
	`nome` varchar(41) NOT NULL,
	`lider` int DEFAULT 0,
	`sublider` int DEFAULT 29,
	`vagas` int DEFAULT 0,
	`vip` int DEFAULT 0,
	`diasvip` varchar(36) NOT NULL,
	`posx` double DEFAULT 0,
	`posy` double DEFAULT 0,
	`posz` double DEFAULT 0,
	`posr` double DEFAULT 0
);