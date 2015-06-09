<?php

/**
 * Implements hook_process_page().
 */
function THEME_FOLDER_NAME_process_page(&$variables) {
  // You can use process hooks to modify the variables before they are passed to
  // the theme function or template file.
  $variables['title'] = make_it_super($variables['title']);

}
