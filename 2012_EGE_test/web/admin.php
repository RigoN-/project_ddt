<?php
session_start();
include_once("config/config.php");
$connect=mysql_connect($mysql_host,$mysql_user,$mysql_pass);
$db=mysql_select_db($mysql_db,$connect);
$login=$_SESSION['login'];
$me=mysql_query("SELECT * FROM `users` WHERE `login`='$login'",$connect);
$my=mysql_fetch_array($me,MYSQL_ASSOC);
$_SESSION['id']=$my['id'];
$_SESSION['group']=$my['group'];
mysql_query( 'SET NAMES utf8' );
?>

<html>
	<meta http-equiv="content-type" content="text/html; charset=UTF8">
	<head>
		<title>Tester</title>
		<link href="style.css" rel="stylesheet" type="text/css">
	</head>
	<body>
		<?php
		if($_SESSION['group']<5)
		{
		header("Refresh: 0; url=index.php");
		die;
		}
		?>
		<table class="main" border="0" align="center">
			<tr>
				<!--<td class="top" colspan="2"><img src="images/text.png"></td> !-->
			</tr>
			<tr>
				<td class="topmenu" colspan="2">
					<!--<table class="topmenu_fr">
						<tr>
							<td><img src="images/topmenu_start.png" align="right"></td>
							<td class="menuitem"><a class="menu" href="ussr.htm">СССР</a></td>
							<td class="menuitem"><a class="menu" href="usa.htm">США</a></td>
							<td class="menuitem"><a class="menu" href="europe.htm">Европа</a></td>
							<td><img src="images/topmenu_end.png" align="left"></td>
						</tr>
					</table>!-->
				</td>
			</tr>
			<tr>
				<td class="left_panel">
				<ul>
						<li><a href="index.php">Главная</a></li>
						<li>Админ-панель</li>
						<li><a href="test.php?workid=4">Пройти тест</a></li>
						<li><a href="result.php">Личная статистика</a></li>
						<li><a href="logout.php">Выйти</a></li>
				</ul>
				</td>
				
				<td class="text">
					<table class="main" border="1">
					<tr><td colspan="10" class="nojs"><noscript><p>JavaScript отключен! Для полноценной работы сайта, пожалуйста, включите JavaScript!</p></noscript></td></tr>
						<tr >
							<form action="" method="post">
							<td height="600px" colspan="10" class="framed">
							Выберите файл с КИМом в формате ".pdf"<br>
							<input type="file" name="upfile" value=""><br><br>
							Страницы:
							<input name="minsh" type="text" size="15" maxlength="15"><input name="maxsh" type="text" size="15" maxlength="15"><br><br>
							Заданий A:
							<input name="maxa" type="text" size="15" maxlength="15"><br><br>
							Заданий B:
							<input name="maxb" type="text" size="15" maxlength="15"><br><br>
							<?
							for($i=1;$i<=$maxa;$i++)
							{
							printf("Задание A$i:<input id=\"a$i\" name=\"a$i\" type=\"text\" size=\"15\" maxlength=\"1\"><br>");
							}
							printf("<br>");
							for($i=1;$i<=$maxb;$i++)
							{
							printf("Задание B$i:<input id=\"a$i\" name=\"b$i\" type=\"text\" size=\"15\" maxlength=\"15\"><br>");
							}
							?>
							<button type="submit" name="refresh">Обновить</button>
							<button type="submit" name="submit">Сохранить</button>
							<?php
							if($_POST)
							{
							//copy();
							for($i=1;$i<=$maxa;$i++)
							{
							$job=$_POST["a$i"];
							mysql_query("INSERT INTO `answers` VALUES ('4','A$i','$job')",$connect);
							}
							for($i=1;$i<=$maxb;$i++)
							{
							$job=$_POST["b$i"];
							mysql_query("INSERT INTO `answers` VALUES ('4','B$i','$job')",$connect);
							}
							mysql_query("INSERT INTO `indexes` VALUES (default,'WIP','$maxa','$maxb','$minsh','$maxsh')",$connect);
							}
							?>
							</td>
						</tr>
					</table>
				</td>
			</tr>
					<td class="bottommenu" colspan="2"><br><a href="index.php">На главную</a><br><br>
			<tr>
			<!--	<td class="bottommenu" colspan="2">
					<img src="images/opengl-logo-1-1.png" align="center" width="55px">
					<img src="images/khronos.jpeg" align="center" width="150px">
					<img src="images/webgl.gif" align="center" width="60px">
					</td>
			!-->
			</tr>
			<tr>
					<td class="copyright" colspan="2">Дом Детского Творчества<br>Разработчик - Матюнин Павел</td>
			</tr>
				</tr>
		</table>
	</body>
</html>
