<?php

/**
 * Implements hook_preprocess_page().
 */
function eld_omega_preprocess_page(&$variables) {
		
	// Add the Google fonts we will be using
	drupal_add_html_head_link(array("href"=>"http://fonts.googleapis.com/css?family=Karla:400,700,400italic,700italic", "rel"=>"stylesheet", "type"=>"text/css"));
	
	// Force the right sidebar to render even if empty
	if (empty($variables['page']['sidebar_second'])) {
  	$variables['page']['sidebar_second'] = array('#markup' => '&nbsp;');
	}
	
	// Hide page title on home page
	if ($variables['is_front']) {
		$variables['title'] = '';
	}	
	
	// Handle node page
	if (!empty($variables['node'])) {
		$node = $variables['node'];
		// Prefix node types
		if ($node->type == 'author' || $node->type == 'article' || $node->type == 'publisher' || $node->type == 'work' || $node->type == 'e_lit_resource') {
			$type = node_type_get_name($node);	
			$variables['title'] = "<div class='title-prefix-heading'>$type</div> ".check_plain($node->title);
		}
		// Add antecedent suffix if needed
		// if ($node->type == 'work') {
		// 			if ($node->field_is_antecedent['und'][0]['value'] == 1) {
		// 				$title = $title.'<div class="title-suffix-heading">This work has been marked as an e-Lit Antecedent</div>';
		// 			}
		// 		}
		
	}
	
	// Handle taxonomy term page. This is harder than it should be because the page variables 
	// do not include an information about the term nor the page title.
	elseif (arg(0) === 'taxonomy' && arg(1) === 'term' && is_numeric(arg(2))) {
		$term = taxonomy_term_load(arg(2));
		$variables['title'] = "<div class='title-prefix-heading'>Term:</div> ".check_plain($term->name);
	}
	
}
