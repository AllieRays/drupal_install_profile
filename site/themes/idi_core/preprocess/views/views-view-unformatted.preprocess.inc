<?php

/**
 * Implements hook_preprocess_views_view_unformatted().
 */
function THEME_FOLDER_NAME_preprocess_views_view_unformatted(&$variables) {
  // For some reason views puts row classes into the classes array. Instead of
  // classes arrays we should always use proper attributes arrays and never
  // abuse the default versions of those for row classes. Instead, we should use
  // a custom variable for that, which is exactly what we convert it to here.
  //dpm($variables);

  if ($variables['view']->name == 'slide_rotator') {

    drupal_add_js(libraries_get_path('jq-ui', FALSE) . '/jquery-ui.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 5));

    drupal_add_js(libraries_get_path('JS_class', FALSE) . '/core.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 6));
    drupal_add_js(libraries_get_path('JS_class', FALSE) . '/enumerable.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 7));
    drupal_add_js(libraries_get_path('JS_class', FALSE) . '/linked_list.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 8));
    drupal_add_js(libraries_get_path('rotator', FALSE) . '/rotator.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 9));

  }


  foreach ($variables['rows'] as $delta => $row) {
    $variables['row_attributes_array'][$delta] = isset($variables['row_attributes_array'][$delta]) ? $variables['row_attributes_array'][$delta] : array();

    if (!empty($variables['classes_array'][$delta])) {
      $variables['row_attributes_array'][$delta]['class'] = explode(' ', $variables['classes_array'][$delta]);
    }
  }
}
