<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * ELD Omega Subtheme theme.
 */


function eld_omega_form_alter(&$form, &$form_state, $form_id) {
	// Add a default prompt to the search form
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t('SEARCH');
  }
	// Hide "Your name" from the comment form
	elseif (substr($form_id, 0, strlen('comment_node_')) === 'comment_node_') {
		$form['author']['#access'] = FALSE;
	}
}


// Can't get this to fire
// function eld_omega_views_oai_pmh_response($variables) {
// 	watchdog("oai", "themed");
// }