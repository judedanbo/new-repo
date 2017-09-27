<form class="form" action="processaddstaff.php" method="post" > 
	
	<h3>Add Branch</h3>
	<div class="row">
		<div class="col-md-12">
			<div class="form-group">
				<label for="stffdept">Select Department</label>
				<select name="stffdept" id="stffdept" required="true" class="form-control">
					<option value="">Select One</option>
					<?php if($depts = DB::getInstance()->get('department')){
						foreach($depts->results() as $dept){ ?>
							<option value="<?php echo($dept->DepartmentID); ?>"> <?php echo ($dept->DepartmentName); ?></option>
						<?php 
						}
					}
					?>
				</select>
			</div>
		</div>
		<div class="col-md-12">
			<div class="form-group">
				<label for="unitname">Branch / Unit Name</label>
				<input type=text name="unitname" id="unitname" class="form-control" class="inp" required autofocus placeholder =" Enter Unit Name" />
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="row">
				<div class="col-md-6">
					<div class="form-group">
						<label for="addregion">Region</label>
						<select name="addregion" id="addregion" class="form-control">
							<option value="">Select Region</option>
							<option value="GAR">Greater Accra</option>
							<option value="EST">Eastern</option>
							<option value="WES">Western</option>
							<option value="CEN">Central</option>
							<option value="VOL">Volta</option>
							<option value="ASH">Ashanti</option>
							<option value="BAR">Brong Ahafo</option>
							<option value="NOR">Northern</option>
							<option value="UER">Upper East</option>
							<option value="UWR">Upper West</option>
						</select>
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="district">District</label>
						<input type="text" name="district" id="district" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="addcity">City/Town</label>
						<input type="text" name="addcity" id="addcity" class="form-control">
					</div>
				</div>
				
				<div class="col-md-6">
					<div class="form-group">
						<label for="addstreet">Address Address</label>
						<input type="text" name="addstreet" id="addstreet" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="telephone">Phone Number</label>
						<input type="text" name="telephone" id="telephone" class="form-control">
					</div>
				</div>
				
				<div class="col-md-6">
					<div class="form-group">
						<label for="email">Email Address</label>
						<input type="email" name="email" id="email" class="form-control">
					</div>
				</div>
				

			</div>
		</div>
	</div>
	<input type="submit" value="Add Staff" class="btn btn-success pull-right">
	
</form>