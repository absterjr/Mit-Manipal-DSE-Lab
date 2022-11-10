<!DOCTYPE html>
<html lang="en">
<head>
	<!-- Setting the pages character encoding -->
	<meta charset="UTF-8">

	<!-- The meta viewport will scale my content to any device width -->
	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<!-- Link to my stylesheet -->
	<link rel="stylesheet" href="styles.css">
	<title>Finished</title>
</head>
<body>

	<h2>Records of Students Read from JSON File</h2>

	<!-- Lets start with the table element -->
	<table>
		<!-- The first row is the tables header -->
		<tr>
			<th>Name</th>
			<th>Registration No.</th>
			<th>Section</th>
			<th>Phone</th>
			<th>Address</th>
			<th>Branch</th>
			<th>Degree</th>
			<th>Year</th>
			<th>Semester</th>
			<th>College</th>
		</tr>

		<!-- Next we will have the template which we will use inside
	  		the loop and poplulate with the data from the json file. -->

		<?php

			$json_data = file_get_contents("students.json");
			$students = json_decode($json_data, true);
			if(count($students) != 0){
				foreach ($students as $student) {
					?>
						<tr>
							<td>
								<?php echo $student['name']; ?>
							</td>
							<td>
								<?php echo $student['reg']; ?>
							</td>
							<td>
								<?php echo $student['section']; ?>
							</td>
							<td>
								<?php echo $student['phone']; ?>
							</td>
							<td>
								<?php echo $student['address']; ?>
							</td>
							<td>
								<?php echo $student['branch']; ?>
							</td>
							<td>
								<?php echo $student['degree']; ?>
							</td>
							<td>
								<?php echo $student['year']; ?>
							</td>
							<td>
								<?php echo $student['semester']; ?>
							</td>
							<td>
								<?php echo $student['college']; ?>
							</td>

						</tr>
					<?php
				}
			}
		?>
	</table>
</body>
</html>
