<?php 

function eld_omega_preprocess_search_result(&$variables) {
	// Add a snippet for author nodes if it is empty.
	if ($variables['result']['node']->type === 'author' && strlen(trim($variables['snippet'])) === 0) {
		$variables['snippet'] = 'Author of e-lit works, resources, or '.variable_get('site_name').' entries.';
	}
	$variables['title_suffix']['node_type'] = array('#children' => $variables['result']['type'],
	                                              '#prefix' => '<span class="node-type-suffix">',
	                                              '#suffix' => '</span>',
	                                              );
	$variables['info'] = FALSE;
}