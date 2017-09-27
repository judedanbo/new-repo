<form class="form" action="processaddstaff.php" method="post" > 
	
	<h3>Add New Staff</h3>
	<div class="row">
		<div class="col-md-2">
			<div class="form-group">
				<label for="aucode">Staff ID</label>
				<input type=text name="aucode" id="aucode" class="form-control" class="inp" required autofocus placeholder ="Staff ID" />
			</div>
		</div>
		<div class="col-md-5">
			<div class="form-group">
				<label for="stffsurname">Surname</label>
				<input type=text name="stffsurname" id="stffsurname" class="form-control" class="inp" required autofocus placeholder ="	Staff Surname" />
			</div>
		</div>
		<div class="col-md-5">
			<div class="form-group">
				<label for="staffonames">Other Names</label>
				<input type=text name="staffonames" id="staffonames" class="form-control" class="inp" required autofocus placeholder ="Staff Other" />
			</div>
		</div>
		
	</div>
	<div class="row">
		<div class="col-md-4">
			<div class="form-group">
				<label for="staffdob">Date of Birth</label>
				<input type="text" name="staffdob" class="form-control" >
			</div>
			
		</div>
		<div class="col-md-3">
			<div class="form-group">
				<label for="stffgender">Gender</label>
				<select name="stffgender" id="stffgender" class="form-control" required="true">
					<option value="">Select One</option>
					<option value="Male">Male</option>
					<option value="Female">Female</option>
				</select>
			</div>
			
		</div>
		<div class="col-md-12">
			<div class="row">
				<div class="col-md-4">
					<div class="form-group">
						<label for="stffdept">Department</label>
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
				<div class="col-md-4">
					<div class="form-group">
						
					
					<label for="stffunit">Unit</label>
						<select name="stffunit" id="stffunit" class="form-control">
							<option value="">Select One</option>
							<?php if($units = DB::getInstance()->get('unit')){
								foreach($units->results() as $unit){ ?>
									<option value="<?php echo ($unit->UnitID) ?>"><?php echo ($unit->UnitName) ?></option>
								<?php }
							} ?>
						</select>
					</div>
				</div>
				<div class="col-md-4">
					<div class="form-group">
					<label for="stffrank">Rank</label>
						<select id="stffrank" name="stffrank" class="form-control">
							<option value="">Select One</option>
							<?php 
								if ($ranks = DB::getInstance()->get('ranks')) { 
									foreach ($ranks->results() as $rank) { ?>
										<option value="<?php echo ($rank->RankID) ?>"><?php echo ($rank->RankName) ?></option>
									<?php  }
								}
							 ?>
						</select>
					</div>
				</div>
			</div>
		</div>
		
		
		<div class="col-md-12">
			<div class="row">
				<div class="col-md-6">
					<div class="form-group">
						<label for="stffapdate">Date of First Appointment</label>
						<input type="text" id="stffapdate" name="stffapdate" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="staffacaqal">Acadamic Qualification(s)</label>
						<input type="text" name="staffacaqal"  id="staffacaqal" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="staffproqal">Professional Qualification(s)</label>
						<input type="text" name="staffproqal"  id="staffproqal" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="staffskill">Special Skills</label>
						<input type="text" name="staffskill"  id="staffskill" class="form-control">
					</div>
				</div>

			</div>
			
		</div>
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
				
				<div class="col-md-4">
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