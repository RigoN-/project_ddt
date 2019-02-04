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
						<?php
						if($_SESSION['group']>=5)
						printf("<li><a href=\"admin.php\">Админ-панель</a></li>");
						if(empty($_SESSION['id']))
						header("Refresh: 0; url=login.php");
						?>
						<li><a href="test.php?workid=4">Пройти тест</a></li>
						<li>Личная статистика</li>
						<li><a href="logout.php">Выйти</a></li>
				</ul>
				</td>
				
				<td class="text">
					<table class="main" border="1">
						<tr>
							<td width="25%" height="15px" class="framed">Предмет/год</td>
							<td width="20%" height="15px" class="framed">Выполнено заданий</td>
							<td width="20%" height="15px" class="framed">Процент выполнения</td>
							<td width="50%" height="15px" class="framed">Дата сдачи</td>
						</tr>
						<?php
						$workid=4;
						$work2=mysql_query("SELECT * FROM `indexes` WHERE `id`='$workid'",$connect);
						$work=mysql_fetch_array($work2,MYSQL_ASSOC);
						$id=$_SESSION['id'];
						$myinfo2=mysql_query("SELECT * FROM `useranswers` WHERE `userid`='$id'",$connect);
						$myinfo=mysql_fetch_array($myinfo2,MYSQL_ASSOC);
						$maxa=$work['max_a'];
						$maxb=$work['max_b'];
						$job=$work['name'];
						$year=$work['year'];
						$date=$myinfo['date'];
						$ansall=28;
						$corra=0;
						$corrb=0;
						for($i=1;$i<=$maxa;$i++)
						{
						$jobA2=mysql_query("SELECT `iscorrect` FROM `useranswers` WHERE `userid`='$id' AND `job`='A$i' AND `workid`='$workid' AND `iscorrect`='1'",$connect);
						$jobA=mysql_fetch_array($jobA2,MYSQL_ASSOC);
						if($jobA['iscorrect']==1)
						$corra++;
						}
						for($i=1;$i<=$maxb;$i++)
						{
						$jobB2=mysql_query("SELECT `iscorrect` FROM `useranswers` WHERE `userid`='$id' AND `job`='B$i' AND `workid`='$workid' AND `iscorrect`='1'",$connect);
						$jobB=mysql_fetch_array($jobB2,MYSQL_ASSOC);
						if($jobB['iscorrect']==1)
						$corrb++;
						}
						$corr=$corra+$corrb;
						$secnd=floor($corr/$ansall*100);
						echo("<tr><td width=\"25%\" height=\"15px\" class=\"framed\">$job $year</td><td width=\"20%\" height=\"15px\" class=\"framed\">$corr/$ansall</td><td width=\"20%\" height=\"15px\" class=\"framed\">$secnd/100</td><td width=\"50%\" height=\"15px\" class=\"framed\">$date</td></tr>");
						?>
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
