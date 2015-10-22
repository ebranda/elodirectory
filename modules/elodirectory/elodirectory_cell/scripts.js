
// Support for searching CELL in a new tab/window
jQuery(document).ready(function () { 
	jQuery('#edit-cell-search').click(function() {
		window.open(window.cellSearchUrl);
		return false;
	});
});