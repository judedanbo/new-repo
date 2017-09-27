<form class="form" action="processaddauditee.php" method="post" > 
	
	<h3>Set up new Auditee</h3>
	<div class="row">
		<div class="col-md-6">
			<div class="form-group">
				<label for="auname">Auditee Name</label>
				<input type=text name="auname" id="auname" class="form-control" class="inp" required autofocus placeholder ="Enter Auditee Name" />
			</div>
		</div>
		<div class="col-md-4">
			<div class="form-group">
				<label for="aucode">Auditee Code</label>
				<input type=text name="aucode" id="aucode" class="form-control" class="inp" required autofocus placeholder ="Auditee Code" />
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-4">
			<div class="form-group">
				<label for="audtype">Auditee Type</label>
				<select name="audtype" id="audtype" class="form-control" required="true">
					<option value="">Select One</option>
					<?php 
						if($auditeetype = DB::getInstance()->get("auditeetypes")){ 
							foreach ($auditeetype->results() as $audtyps) {?>
								<option value="<?php echo($audtyps->AuditeetypeID) ?>"><?php echo "$audtyps->AuditeetypeName"; ?></option>
							<?php }
						}

					 ?>
				</select>
			</div>
			
		</div>
		<div class="col-md-3">
			<div class="form-group">
				<label for="audcat">Auditee Category</label>
				<select name="audcat" id="audcat" class="form-control" required="true">
					<option value="">Select One</option>
					<option value="A">A</option>
					<option value="B">B</option>
					<option value="C">C</option>
				</select>
			</div>
			
		</div>
		<div class="col-md-5">
			Auditee Has Parent Organization
			<div class="row">
				<div class="col-md-6">
					<div class="form-group">
						<input type="radio" name="audparent" id="audparentyes" value="Yes" class="radio-inline "control-label"">
						<label for="audparentyes" class="radio-inline control-label">  Yes </label>
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<input type="radio" name="audparent" value="No" id="audparentno" class="radio-inline">
						<label for="audparentno" class="radio-inline control-label"> No </label>
					</div>
					
				</div>
			</div>
		</div>
		<div class="col-md-6">
			<div class="form-group">
				<label for="audparentname">Parent Organization</label>
				<select name="audparentname" id="audparentname" class="form-control">
						<option value="">Selected Parent Organization</option>
						<?php if($parentorg = DB::getInstance()->get("allauditee") ){
							foreach ($parentorg->results() as $orgs) { ?>
								<option value="<?php echo($orgs->AuditeeID) ?>"><?php echo ($orgs->OrgName); ?></option>
							<?php }
						} ?>

				</select>
			</div>
		</div>
		<div class="col-md-12">
			<div class="row">
				<div class="col-md-6">
					<div class="form-group">
						<label for="addbuilding">Name of Building</label>
						<input type="text" name="addbuilding" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="addstreet">Street Address</label>
						<input type="text" name="addstreet" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="addsuburb">Suburb</label>
						<input type="text" name="addsuburb" class="form-control">
					</div>
				</div>
				<div class="col-md-6">
					<div class="form-group">
						<label for="addcity">City/Town</label>
						<input type="text" name="addcity" class="form-control">
					</div>
				</div>
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
				

			</div>
		</div>

		<div class="col-md-4">
			<div class="form-group">
				<label for="telephone">Phone Number</label>
				<input type="tel" name="telephone" class="form-control">
			</div>
		</div>

	</div>
	<input type="submit" value="Add Auditee" class="btn btn-success pull-right">
	
</form>