<?php
/**
 * @file
 * idi_user_permission_roles.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function idi_user_permission_roles_filter_default_formats() {
  $formats = array();

  // Exported format: ck editor.
  $formats['ck_editor'] = array(
    'format' => 'ck_editor',
    'name' => 'ck editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
