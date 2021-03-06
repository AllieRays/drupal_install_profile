<?php

/**
 * Implements hook_preprocess_page().
 */
function THEME_FOLDER_NAME_preprocess_region(&$variables) {

  // dpm($variables);

  if ($variables['is_front'] == TRUE || arg(0) == 'home') {
    $variables['title'] = '';
  }
  if ($variables['logged_in'] == FALSE && arg(0) == 'user') {
    $variables['title'] = 'Sign In';
    $variables['login_link'] = '<a href="/user/password">Request a new password</a>';
  }
  if ($variables['logged_in'] == FALSE && arg(1) == 'password') {
    $variables['title'] = 'Request Password';
    $variables['login_link'] = '<a href="/user">Return back to Sign In</a>';
  }


  //add new variables
  if ($variables['region'] == 'banner') {
    $variables['banner_image'] = '<img src="sites/SITE_FOLDER_NAME/files/banners/banner.png">';
  }
}
