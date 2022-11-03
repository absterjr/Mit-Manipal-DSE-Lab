    <title>Employee Json data</title>
    <style>
        .container{
            position: relative;
            width: 400px;
            height: 400px;
            text-align: center;
            justify-content: center;
            left: 25%;
            transform: translate(50%,0);
            font-size: 1.7em;

        }
        table{
            justify-content: center;
            border: 1px solid black;
            border-collapse: collapse;
        }
        tr{
            width: 100px;
        }
        th,td{
            padding: 10px;
            border: 1px solid darkolivegreen;
        }
        th{
            padding: 10px 15px;
        }
        .msg{
            text-align: center;
        }
    </style>
<body>
    <?php
    $direc = './data/';
    $fname = 'emp1.json';
        if(file_exists($direc.$fname)){
            $data = file_get_contents($direc.$fname);
            $emps = json_decode($data);
            $msg = "<h3 class='msg'>JSON file data</h3>";
        }
        else{
            $msg = "<h3 class='msg'>JSON file Not Found</h3>";
        }
    ?>
<div class="container">
    <div class="table">
        <?php
        if(isset($msg)){
            echo $msg;
        ?>
        <table>
            <tr>
                <th>Name</th>
                <th>Age</th>
                <th>Gender</th>
                <th>Education</th>
                <th>Occupation</th>
            </tr>
            <?php foreach($emps as $emp){?>
            <tr>
                <td><?= $emp->name;?></td>
                <td><?= $emp->age;?></td>
                <td><?= $emp->gender;?></td>
                <td><?= $emp->education;?></td>
                <td><?= $emp->occupation;?></td>
            </tr>
            <?php
            }
            ?>
        </table>
        <?php
        }
        else{
            echo $msg;
        }
        ?>
    </div>
</div>
</body>
