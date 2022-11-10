<!-- PHP Programs to demonstrate loop -->
<html>
    <head>
        <title>
            Hello
</title>
</head>
<body>
    <?php
    $people = array("Abster", "Aryaman");

    $numbers = array(5,4,9);
    $sum = 0;
    foreach ($numbers as $number) {
        $sum = $sum + $number;
    }
    echo $sum;
 foreach ($people as $person) {
    echo $person.' '; // prints each value separated by space
 }
    ?>
    </body>
    </html>