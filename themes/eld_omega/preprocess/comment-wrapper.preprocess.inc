<?php 

function eld_omega_preprocess_comment_wrapper(&$variables) {
	if (empty($variables['content']['comments'])) {
		$variables['content']['comments'] = array(
			'#markup' => 'There are no comments for this '.node_type_get_name($variables['node']),
		);
	}
}