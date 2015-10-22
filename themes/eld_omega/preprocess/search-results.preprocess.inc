<?php 

function eld_omega_preprocess_search_results(&$variables) {
	if (!$variables['search_results']) {
		$msg = search_help('search#noresults', drupal_help_arg());
		$msg = str_replace('bike', 'hypertext', $msg);
		$msg = str_replace('shed', 'poetry', $msg);
		$variables['no_results'] = $msg;
	}
}