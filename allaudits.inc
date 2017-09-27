<?php 


	if ($audits = DB::getInstance()->get('allaudits')) { ?>
		<table class="table table-striped table-hover table-condensed" >
			<thead>
				<tr>
					<th>Name</th>
					<th>Unit</th>
					<th>Year</th>
					<th>Start Date</th>
					<th>Duration</th>
					<th>Status</th>
				</tr>
			</thead>
		<?php  foreach ($audits->results() as $audit) { ?>
			<tr>
				<td><?php echo ($audit->AuditName) ?></td>
				<td><?php echo ($audit->AuditUnit) ?></td>
				<td><?php echo ($audit->FinancialYear) ?></td>
				<td><?php echo ($audit->CommencementDate) ?></td>
				<td><?php echo ($audit->Duration) ?></td>
				<td><?php echo ($audit->AuditStatus) ?></td>
			</tr>
		<?php 
		} ?>

		</table>
		<?php 
	}

 ?>