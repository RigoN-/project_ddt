<?php
session_start();
include_once("config/config.php");
$connect=mysql_connect($mysql_host,$mysql_user,$mysql_pass);
$db=mysql_select_db($mysql_db,$connect);
$login=$_SESSION['login'];
$me=mysql_query("SELECT * FROM `users` WHERE `login`='$login'",$connect);
$my=mysql_fetch_array($me,MYSQL_ASSOC);
$id=$my['id'];
$_SESSION['id']=$my['id'];
$_SESSION['group']=$my['group'];
mysql_query( 'SET NAMES utf8' );
?>
<html>
	<meta http-equiv="content-type" content="text/html; charset=UTF8">
	<head>
		<title>Online-тестер</title>
		<link href="style.css" rel="stylesheet" type="text/css">
		<script type="text/javascript" src="scripts/pdf.js"></script>
	        <script type="text/javascript" src="scripts/viewer.js"></script>
		<script type="text/javascript" src="scripts/file.js"></script>
		<script type="text/javascript">PDFJS.workerSrc = 'scripts/pdf.js';</script>
	</head>
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
						<li>Пройти тест</li>
						<li><a href="result.php">Личная статистика</a></li>
						<li><a href="logout.php">Выйти</a></li>
				</ul>
				</td>
				<td class="text">
					<table class="main" border="1">
						<?php
						
						?>
						<tr >
							<td height="600px" colspan="10" class="framed"><canvas id="the-canvas" style="border: none;" width="500" height="500"></canvas></td>
						</tr>
							<tr><td colspan="10" class="nojs"><noscript><p>JavaScript отключен! Для полноценной работы сайта, пожалуйста, включите JavaScript!</p></noscript></td></tr>
						<tr>
						<tr><form action="" method="post">
						<?php
						$workid=$_REQUEST["workid"];
						$work=mysql_query("SELECT * FROM `indexes` WHERE `id`='$workid'",$connect);
						$mywork=mysql_fetch_array($work,MYSQL_ASSOC);
						$maxa=$mywork['max_a'];
						$maxb=$mywork['max_b'];
						$minsh=$mywork['minshow'];
						$maxsh=$mywork['maxshow'];
						$wrkname=$mywork['data'];
						printf("<script type=\"text/javascript\">workname=\"$wrkname\"; paged=$minsh; minsh=$minsh; maxsh=$maxsh;</script>");
						$swflag=1;
						for($j=1;$j<=$maxa;$j++)
						{
						printf("<td height=\"30px\" class=\"framed\">A$j</td>");
						if($j%10==0)
						{
						printf("</tr><tr>");
						for($i=1;$i<=10;$i++)
						{
						printf("<td class=\"elements\"><input type=\"radio\" name=\"A$i\" value=\"1\">1<br><input type=\"radio\" name=\"A$i\" value=\"2\">2<br><input type=\"radio\" name=\"A$i\" value=\"3\">3<br><input type=\"radio\" name=\"A$i\" value=\"4\">4<br></td>");
						if($i%10==0)
						printf("</tr><tr>");
						}
						}
						if($j==$maxa)
						{
						for($i=11;$i<=$maxa;$i++)
						{
						
						if($i==$maxa)
						{
						$k=$i%10;
						for($j=$k;$j<=$maxb+$k-1;$j++)
						{
						$tmp=$j-$k+1;
						printf("<td height=\"30px\" class=\"framed\">B$tmp</td>");
						if($j%9==0)
						{
						printf("</tr><tr>");
						for($i=1;$i<=10;$i++)
						{
						if($i<=$k)
						{
						$x=$i+10;
						printf("<td class=\"elements\"><input type=\"radio\" name=\"A$x\" value=\"1\">1<br><input type=\"radio\" name=\"A$x\" value=\"2\">2<br><input type=\"radio\" name=\"A$x\" value=\"3\">3<br><input type=\"radio\" name=\"A$x\" value=\"4\">4<br></td>");
						}
						else
						{
						$x=$i-$k;
						printf("<td class=\"elements\"><input type=\"text\" name=\"B$x\"></td>");
						}
						if($i%10==0)
						printf("</tr><tr>");
						}
						}
						if($j==$maxb)
						{
						printf("</tr><tr>");
						for($i=11;$i<=$maxb+$k;$i++)
						{
						$x=$i-$k;
						printf("<td class=\"elements\"><input type=\"text\" name=\"B$x\"></td>");
						}
						}
						}
						}
						}

						printf("</tr><tr>");

						}
						}
						?>
						</tr>
						</tr>
						<tr>
							<td colspan="10">
							<button id="Send" type="submit" name="submit">Проверить</button></form>
							<?php
							if($_POST)
							{
							for($i=1;$i<=$maxa;$i++)
							mysql_query("DELETE FROM `useranswers` WHERE (`userid`='$id' AND `workid`='$workid' AND `job`='A$i')");

							for($i=1;$i<=$maxb;$i++)
							mysql_query("DELETE FROM `useranswers` WHERE (`userid`='$id' AND `workid`='$workid' AND `job`='B$i')");

							for($i=1;$i<=$maxa;$i++)
							{
							$job="A$i";
							$answer=$_POST["A$i"];
							mysql_query("INSERT INTO `useranswers` VALUES ('$id','4','$job','$answer',default,default)",$connect);
							}
							for($i=1;$i<=$maxb;$i++)
							{
							$job="B$i";
							$answer=$_POST["B$i"];
							mysql_query("INSERT INTO `useranswers` VALUES ('$id','4','$job','$answer',default,default)",$connect);
							}

							for($i=1;$i<=$maxa;$i++)
							{
							$st2=mysql_query("SELECT * FROM `useranswers` WHERE `userid`='$id' AND `job`='A$i'",$connect);
							$st=mysql_fetch_array($st2,MYSQL_ASSOC);
							$nd2=mysql_query("SELECT * FROM `answers` WHERE `id`='$workid' AND `job`='A$i'",$connect);
							$nd=mysql_fetch_array($nd2,MYSQL_ASSOC);
							if($st['answer']==$nd['answer'])
							mysql_query("UPDATE `useranswers` SET `iscorrect`='1' WHERE `workid`='$workid' AND `job`='A$i' AND `userid`='$id'",$connect);
							}
							
							for($i=1;$i<=$maxb;$i++)
							{
							$st2=mysql_query("SELECT * FROM `useranswers` WHERE `userid`='$id' AND `job`='B$i'",$connect);
							$st=mysql_fetch_array($st2,MYSQL_ASSOC);
							$nd2=mysql_query("SELECT * FROM `answers` WHERE `id`='$workid' AND `job`='B$i'",$connect);
							$nd=mysql_fetch_array($nd2,MYSQL_ASSOC);
							if($st['answer']==$nd['answer'])
							{
							mysql_query("UPDATE `useranswers` SET `iscorrect`='1' WHERE `workid`='$workid' AND `job`='B$i' AND `userid`='$id'",$connect);
							}
							}
							echo'<META HTTP-EQUIV=Refresh Content="0;URL=result.php">';
							}
							?>
							<br><button id="Previous" onclick="paged--;PDFJS.getPdf('files/inf_ege.pdf', myCallback);" oncontextmenu="return false;">Предыдущая</button>
							<button id="Next" onclick="paged++;PDFJS.getPdf('files/inf_ege.pdf', myCallback);" oncontextmenu="return false;">Следующая</button>
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
