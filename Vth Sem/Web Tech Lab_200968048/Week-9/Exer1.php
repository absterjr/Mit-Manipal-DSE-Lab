<?php
if(isset($_FILES['resume'])){
    // $file = $_FILES['resume'];
    $errors= array(); 
    $f_name = $_FILES['resume']['name'];
    $f_type = $_FILES['resume']['type'];
    $f_size = $_FILES['resume']['size'];
    $f_temp_loc = $_FILES['resume']['tmp_name'];
    $f_store = "../upload/".$f_name;
    $temp = explode('.',$f_name);
    $f_ext = end($temp);
    // print_r($f_temp_loc);
    if($f_ext <> 'pdf'){
        $errors[]="<h3>extension not allowed, please choose a PDF file.</h3>"; 
    }
    if($f_size > 2097152){
        $errors[]="<h3>File size must be less than 2 MB</h3>";
    }
    $size = round($f_size/1000000,2);
    if(empty($errors)==true){
        move_uploaded_file($f_temp_loc,$f_store);
        echo "Success"; 
        echo "<ul> <li>Sent file: ".$f_name." 
                    <li>File size: ".$size."MB"."
                    <li>File type:".$f_type." 
                </ul>"; 
    }
    else{
        print_r($errors);
    }
}
else{
    echo "<h3>Choose a file<h3>";
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Resume Upload</title>
    <link rel="stylesheet" href="css/Exer1.css">
    <link rel="POST" href="php/Exer1.php">
</head>
<body>
    <div class="container">
        <form action="?" method="POST" enctype="multipart/form-data">
            <div class="entry">
                <label for="resume" style="font-size: 1.5rem;color:brown;">Upload your Resume</label>
                <input type="file" name="resume"/>
            </div>
            <input type="submit" class="submit" name="upload"/>
        </form>
    </div>
</body>
</html>