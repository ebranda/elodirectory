<?php


function eld_omega_preprocess_node(&$variables) { 
  $variables['display_submitted'] = FALSE;
  if ($variables['teaser']) {
		// Do not display links in teasers
    if (!empty($variables['content']['links'])) {
      unset($variables['content']['links']);
    }
  } else {
	
		// Add default message if author full node body is empty
		if ($variables['type'] == 'author' && empty($variables['content']['body'][0]['#markup'])) {
			$variables['content']['body'][0]['#markup'] = 'No author biography available.';
		}
		// Add default message if publisher full node body is empty
		if ($variables['type'] == 'publisher' && empty($variables['content']['body'][0]['#markup'])) {
			$variables['content']['body'][0]['#markup'] = 'No publisher information available.';
		}
	}
	
	// Hide empty text fields in Work nodes. For some reason, the Author Statement field is
	// included in the content array even if it is empty.
	if ($variables['type'] == 'work') {
		if (empty($variables['field_author_statement'][0]['value'])) {
			$variables['content']['field_author_statement']['#access'] = FALSE;
		}
	}
	
	// Do not display comment link with node
	if (!empty($variables['content']['links']['comment'])) {
		unset($variables['content']['links']['comment']);
	}
	
	
}