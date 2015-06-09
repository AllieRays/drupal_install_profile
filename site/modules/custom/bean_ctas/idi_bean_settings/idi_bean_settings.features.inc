<?php
/**
 * @file
 * idi_bean_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function idi_bean_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
