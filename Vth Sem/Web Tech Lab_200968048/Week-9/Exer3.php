<title>Visit Count</title>
<?php 
   session_start();
  if(isset($_SESSION['views']))
      $_SESSION['views'] = $_SESSION['views']+1;
  else
      $_SESSION['views']=1;    
  ?>
<div><?php echo"View Count: ".$_SESSION['views'];?></div>
