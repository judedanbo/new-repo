<?php 
	require "header.inc";
	require "nav.inc";
 ?>
<main>
	<div class="content container"></div>
	<div class="row">
		<div class="col-md-8 col-md-offset-1">
			<?php require "newaudit.inc"; ?>
		</div>
		<div class="col-md-3">
			<a href="createaudit.php" id="addauditee" class="btn btn-primary"> <span></span>Add Audit</a> <br>
			<a href="" id="editauditee" class="btn btn-primary"> <span></span>View/Edit Units Details</a>
			

		</div>
	</div>
	

</main>

 <?php require "footer.inc"  ?>