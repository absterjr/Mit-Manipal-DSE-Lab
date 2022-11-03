<?php
    $exptime = 60 * 60 * 24 * 30 + time();
    setcookie('lastVisit', date("G:i - m/d/y"), $exptime);
    
    
?>
    <?php
    if(isset($_COOKIE['lastVisit'])){
        $visit = $_COOKIE['lastVisit'];
    ?>
    <div class="container" style="top: 50%;"><?php echo "Last Visit: ". $visit;?></div>
    <?php
    }
    else{
    ?>
    <div class="container" style="top: 50%;"><?php echo "Unvisited!";?></div>
    <?php
    }
    ?>
</body>
</html>