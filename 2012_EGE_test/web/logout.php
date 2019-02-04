<?php
session_start();
$_SESSION['id']="";
$_SESSION['login']="";
$_SESSION['group']="";
header("Refresh: 0; url=index.php");
?>
