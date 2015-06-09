<?php
/**
 * @file
 * idi_bean_settings.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function idi_bean_settings_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'block_cta';
  $bean_type->label = 'block cta';
  $bean_type->options = '';
  $bean_type->description = 'call to action bean blocks';
  $export['block_cta'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'default_beans';
  $bean_type->label = 'default beans';
  $bean_type->options = '';
  $bean_type->description = 'Default bean block with one default body. Examples: footer content and banner content.';
  $export['default_beans'] = $bean_type;

  return $export;
}
