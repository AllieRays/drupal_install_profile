<?php

/**
 * Preprocesses the wrapping HTML.
 *
 * @param array &$variables
 *   Template variables.
 */
function THEME_FOLDER_NAME_preprocess_html(&$variables) {


  // theme settings located in admin/appearance/settings/THEME_FOLDER_NAME
  # https://api.drupal.org/api/drupal/includes!theme.inc/function/theme_get_setting/7
  global $base_url;
  $css = "";
  $themepath = drupal_get_path('theme', $GLOBALS['theme']);

  if (theme_get_setting('header_bg_color')) {
    $css .= '.l-header {background-color:' . theme_get_setting('header_bg_color') . '}' . "\n";
  }
  if (theme_get_setting('menu_bg_color')) {
    $css .= '.l-region.l-region--navigation {background-color:' . theme_get_setting('menu_bg_color') . '}' . "\n";
    $css .= '#block-system-main-menu {background-color:' . theme_get_setting('menu_bg_color') . '}' . "\n";
    $css .= '.l-footer {border-top:2px solid ' . theme_get_setting('menu_bg_color') . '}' . "\n";

  }
  if (theme_get_setting('menu_link_color')) {
    $css .= '#block-system-main-menu li a {color:' . theme_get_setting('menu_link_color') . '}' . "\n";
    $css .= '#main-menu-burger {color:' . theme_get_setting('menu_link_color') . '}' . "\n";
  }
  if (theme_get_setting('menu_link_hover_color')) {
    $css .= '#block-system-main-menu li a:hover {color:' . theme_get_setting('menu_link_hover_color') . '}' . "\n";
    $css .= '#block-system-main-menu li a.active {color:' . theme_get_setting('menu_link_hover_color') . '}' . "\n";
    $css .= '#main-menu-burger:hover {color:' . theme_get_setting('menu_link_hover_color') . '}' . "\n";
  }
  if (theme_get_setting('menu_link_bg_hover_color')) {
    $css .= '#block-system-main-menu li a:hover {background-color:' . theme_get_setting('menu_link_bg_hover_color') . '}' . "\n";
    $css .= '#block-system-main-menu li a.active {background-color:' . theme_get_setting('menu_link_bg_hover_color') . '}' . "\n";
    $css .= '#main-menu-burger:hover {background-color:' . theme_get_setting('menu_link_bg_hover_color') . '}' . "\n";
  }
  if (theme_get_setting('footer_bg_color')) {
    $css .= '.l-footer {background-color:' . theme_get_setting('footer_bg_color') . '}' . "\n";
  }
  if (theme_get_setting('body_bg_color')) {
    $css .= '.l-main {background-color:' . theme_get_setting('body_bg_color') . '}' . "\n";
    $css .= '.l-content {background-color:' . theme_get_setting('body_bg_color') . '}' . "\n";
    $css .= 'body {background-color:' . theme_get_setting('body_bg_color') . '}' . "\n";
  }
  if (theme_get_setting('button_bg_color')) {
    $css .= '.flip-button {background-color:' . theme_get_setting('button_bg_color') . '}' . "\n";
    $css .= '.field--name-field-question-title {background-color:' . theme_get_setting('button_bg_color') . '}' . "\n";
  }
  if (theme_get_setting('button_bg_hover_color')) {
    $css .= '.button-bottom {background-color:' . theme_get_setting('button_bg_hover_color') . '}' . "\n";
    $css .= '.field--name-field-question-title:hover {background-color:' . theme_get_setting('button_bg_hover_color') . '}' . "\n";
  }
  if (theme_get_setting('text_link')) {
    $css .= 'a {color:' . theme_get_setting('text_link') . '}' . "\n";
  }
  if (theme_get_setting('text_link_hover')) {
    $css .= 'a:hover {color:' . theme_get_setting('text_link_hover') . '}' . "\n";
  }
  if (theme_get_setting('text_color')) {
    $css .= '.l-content {color:' . theme_get_setting('text_color') . '}' . "\n";
    $css .= 'body {color:' . theme_get_setting('text_color') . '}' . "\n";
  }
  if (theme_get_setting('h2_color')) {
    $css .= 'h2 {color:' . theme_get_setting('h2_color') . '}' . "\n";
  }
  if (theme_get_setting('h1_color')) {
    $css .= 'h1 {color:' . theme_get_setting('h1_color') . '}' . "\n";
  }

  $variables['theme_setting_css'] = $css;


  // Code borrowed/adapted from D7 core.
  // Classes originally added by D7 core, then removed by Omega 4 and now put back (ish) by this function.
  // NOTE: D7 core used hyphens in class names, we need to use different classes so we're
  // replacing hyphens with underscores (make sure your CSS is expecting this).
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-sidebars';
  }
}
