<?php


function THEME_FOLDER_NAME_form_system_theme_settings_alter(&$form, &$form_state) {
  global $base_url;
  // Add a checkbox to toggle the breadcrumb trail.
  // https://api.drupal.org/api/drupal/developer!topics!forms_api_reference.html/7
  // dpm($form);
  // https://www.drupal.org/node/2186031
  // http://ghosty.co.uk/2014/03/managed-file-upload-in-drupal-theme-settings/

  $form['general_elements'] = array(
    '#type' => 'fieldset',
    '#title' => t('general elements'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general_elements']['banner_image'] = array(
    '#title' => t('Banner Image'),
    '#description' => t('Image should be less than 400 pixels wide and in JPG format.'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://banners/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
    '#default_value' => theme_get_setting('banner_image'),
  );
  $form['#submit'][] = 'THEME_FOLDER_NAME_settings_form_submit';
// Get all themes.
  $themes = list_themes();
// Get the current theme
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';


//dsm($form);
}

function THEME_FOLDER_NAME_settings_form_submit(&$form, $form_state) {
  $image_fid = $form_state['values']['banner_image'];
  $image = file_load($image_fid);
  if (is_object($image)) {
    // Check to make sure that the file is set to be permanent.
    if ($image->status == 0) {
      // Update the status.
      $image->status = FILE_STATUS_PERMANENT;
      // Save the update.
      file_save($image);
      // Add a reference to prevent warnings.
      file_usage_add($image, 'THEME_FOLDER_NAME', 'theme', 1);
    }
  }
}
