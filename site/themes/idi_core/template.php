<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the theme.
 */


//PULL IN HELPER FUNCTIONS
include_once "theme_helpers.php";


function THEME_FOLDER_NAME_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  //dpm($element);
  if (isset($element['#localized_options']['attributes']['id'])) {
    if ($element['#localized_options']['attributes']['id'] == 'forward') {
      $element['#href'] = 'forward';
      $element['#localized_options']['query'] = array('path' => current_path());
    }
  }
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }


  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  //Make Reg and stuff Super
  $output = make_it_super($output);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function THEME_FOLDER_NAME_search_module_menu_alter(&$items) {
  drupal_static_reset('search_get_info');
  $default_info = search_get_default_module_info();
  if ($default_info) {
    foreach (search_get_info() as $module => $search_info) {
      $path = 'result/' . $search_info['path'];
      unset($items[$path]);
      unset($items["$path/%menu_tail"]);
    }

    $items['search/%menu_tail'] = array(
      'title' => 'Search',
      'load arguments' => array('%map', '%index'),
      'page callback' => 'search_view',
      'page arguments' => array($default_info['module'], 1),
      'access callback' => '_search_menu_access',
      'access arguments' => array($default_info['module']),
      'type' => MENU_CALLBACK,
      'file' => drupal_get_path('module', 'result') . '/search.pages.inc'
    );
  }
}

function THEME_FOLDER_NAME_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  //dpm($breadcrumb);
  if (!empty($breadcrumb)) {
    $crumbs = '<div class="breadcrumbs clearfix"><ul>';

    foreach ($breadcrumb as $value) {

      //Make Reg and stuff Super
      //$value['#title'] = make_it_super($value);

      if ($value == '<a href="/">Home</a>') {

        $crumbs .= '<li class="home">' . $value . ' &gt;</li>';

      }
      else {
        if (strpos($value, 'href="') == FALSE && strpos($value, 'Disciplines') === TRUE) {

          $crumbs .= '<li>' . $value . '</li>';

        }
        else {

          $crumbs .= '<li>' . $value . ' &gt;</li>';

        }
      }
      //dpm($value);
    }
    $url_alias = drupal_get_path_alias($_GET['q']);
    $split_url = explode('/', $url_alias);
    if ($split_url[0] != 'disciplines') {
      $crumbs .= '<li>' . Truncate(str_replace("®", "<sup>&reg;</sup>", drupal_get_title()), 35, FALSE) . '</li>';
    }
    $crumbs .= '</ul></div>';

    return $crumbs;
  }

}


function THEME_FOLDER_NAME_menu_tree__main_menu(&$variables) {
  // drupal_add_js(libraries_get_path('sidr', FALSE) . '/jquery.sidr.min.js', array('type' => 'file', 'scope' => 'footer', 'weight' => 5));
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

//show banner region even if no blocks
function THEME_FOLDER_NAME_page_alter(&$page) {
  if (!isset($page["banner"]) || empty($page["banner"])) {
    $page["banner"] = array(
      '#region' => 'banner',
      '#weight' => '-10',
      '#theme_wrappers' => array('region')
    );
  }
}

function THEME_FOLDER_NAME_link(array $variables) {
//  dpm($variables);
  $attributes = $variables['options']['attributes'];
  $exclusion = array(
    'fa-lg',
    'fa-2x',
    'fa-3x',
    'fa-4x',
    'fa-5x',
    'fa-fw',
    'fa-ul',
    'fa-li',
    'fa-border',
    'fa-spin',
    'fa-rotate-90',
    'fa-rotate-180',
    'fa-rotate-270',
    'fa-flip-horizontal',
    'fa-flip-vertical',
    'fa-stack',
    'fa-stack-1x',
    'fa-stack-2x',
    'fa-inverse'
  );
  if (isset($attributes['class']) && !empty($attributes['class']) && is_array($attributes['class'])) {
    //dpm($attributes['class']);
    foreach ($attributes['class'] as $key => $class) {
      if (substr($class, 0, 3) == 'fa-' && !in_array($class, $exclusion)) {
        if (!isset($variables['options']['html']) || empty($variables['options']['html'])) {
          $variables['text'] = check_plain($variables['text']);
          $variables['options']['html'] = TRUE;
        }
        $class = 'fa ' . $class;
        $variables['text'] = '<i class="' . $class . '"></i> <span>' . $variables['text'] . '</span>';
        unset($variables['options']['attributes']['class'][$key]);
      }
    }
  }
  return theme_link($variables);
}
