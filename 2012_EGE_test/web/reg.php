<?php
session_start();
include_once("config/config.php");
$connect=mysql_connect($mysql_host,$mysql_user,$mysql_pass);
$db=mysql_select_db($mysql_db,$connect);
mysql_query( 'SET NAMES utf8' );
?>
<html>
	<meta http-equiv="content-type" content="text/html; charset=UTF8">
	<head>
		<title>Online-тестер</title>
		<link href="style.css" rel="stylesheet" type="text/css">	</head>
	<body>
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
						<li><a href="login.php">Войти</a></li>
						<li>Регистрация</li>
				</ul>
				</td>
				
				<td class="text">
					<table class="main" border="1">
					<tr><td colspan="10" class="nojs"><noscript><p>JavaScript отключен! Для полноценной работы сайта, пожалуйста, включите JavaScript!</p></noscript></td></tr>
						<tr >
							<td height="600px" colspan="10" class="framed">

				<form action="" method="post">
				<p>

				<label>Ваш логин:<br></label>
				<input name="login" type="text" size="15" maxlength="15">
				</p>
				<?php
				if(($_POST['login']=="")&&($submit))
				printf("Введите логин!");
				?>
				<p>
				<label>Ваш пароль:<br></label>
				<input name="password" type="password" size="15" maxlength="15">
				</p>
				<?php
				if(($_POST['password']=="")&&($submit))
				printf("Введите пароль!");
				?>
				<p><label>Ваше Имя:<br></label><input name="firstname" type="text" size="15" maxlength="15"></p><p><label>Фамилия:<br></label><input name="lastname" type="text" size="15" maxlength="15"></p><input type="submit" name="submit" value="Регистрация"></p></form>
				<?php
				if($submit)
				{
				$login=$_POST['login'];
				$password=$_POST['password'];
				$me=mysql_query("SELECT * FROM `users` WHERE `login`='$login'",$connect);
				$my=mysql_fetch_array($me,MYSQL_ASSOC);
				if(($login==$my['login'])&&(!$checkme)&&(!empty($login))&&(!empty($password)))
				{
				printf("Пользователь существует!");
				}
				else if(($_POST['password']!=$my['password'])||($_POST['login']!=$my['login']))
				{
				mysql_query("INSERT INTO `users` VALUES (default,'$login','$password','$firstname','$lastname',default)",$connect);
				header("Refresh: 0; url=login.php");
				}	
					
				mysql_close();
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
