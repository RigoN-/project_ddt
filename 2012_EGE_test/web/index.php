<?php
session_start();
include_once("config/config.php");
?>

<html>
	<meta http-equiv="content-type" content="text/html; charset=UTF8">
	<head>
		<title>Online-тестер</title>
		<link href="style.css" rel="stylesheet" type="text/css">
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
						<li>Главная</li>
						<?php
						if($_SESSION['group']>=5)
						printf("<li><a href=\"admin.php\">Админ-панель</a></li>");
						if(empty($_SESSION['id']))
						printf("<li><a href=\"login.php\">Войти</a></li><li><a href=\"reg.php\">Регистрация</a></li>");
						else
						printf("<li><a href=\"test.php?workid=4\">Пройти тест</a></li><li><a href=\"result.php\">Личная статистика</a></li><li><a href=\"logout.php\">Выйти</a></li>");
						?>
				</ul>
				</td>
				<?php
				//if(!empty($_SESSION['id']))
				//header("Refresh: 0; url=view.php");
				?>
				<td class="text2">
					<table class="main2" border="0">
						<tr>
							<td class="text2">Добро пожаловать на сайт, который представляет собой систему онлайн-тестирования по предметам на основе Единого Государственного Экзамена! На данном сайте представлены тестовые контрольно-измерительные материалы (КИМ).<br> Для полноценного просмотра Вам понадобится браузер с поддержкой HTML5.<br><br>Следующие браузеры поддерживают HTML5:<br>Mozilla Firefox 4 и выше<br>Opera 11.00 и выше</td>
						</tr>
					</table>
				</td>
			</tr>
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
