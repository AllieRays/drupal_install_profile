<?php

/**
 * @file
 * Contains the theme settings form elements for the colors extension.
 */

/**
 * Implements hook_extension_EXTENSION_theme_settings_form_alter().
 */
function THEME_FOLDER_NAME_extension_colors_settings_form($element, &$form, $form_state) {


  /*$element['omega_rebuild_theme_registry'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rebuild the theme registry on every page load'),
    '#description' => t('While creating new templates and theme overrides the theme registry needs to be rebuilt. Note: This has a high (negative) performance impact and has to be deactivated once your website goes into production.'),
    '#default_value' => omega_theme_get_setting('omega_rebuild_theme_registry', FALSE),
  );*/


  drupal_add_css(drupal_get_path('theme','THEME_FOLDER_NAME') . '/css/partials/3_template/3_template/theme_settings.css', 'THEME_FOLDER_NAME');
  drupal_add_js(libraries_get_path('bgrins-spectrum') . '/spectrum.js');
  drupal_add_css(libraries_get_path('bgrins-spectrum') . '/spectrum.css');
  $spectrum_js = 'jQuery(".spectrum-color-picker").spectrum({
    showInput: true,
    allowEmpty: true,
    showAlpha: true,
    showInitial: true,
    showInput: true,
    preferredFormat: "hex",
    clickoutFiresChange: true,
    showButtons: false
  });';

  drupal_add_js($spectrum_js, array('type' => 'inline', 'scope' => 'footer'));

  $element['color_vals']['#prefix'] = '<div id="color-vals">';
  $element['color_vals']['#suffix'] = '</div>';

  $element['color_vals']['header_bg_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Header Background'),
      '#default_value' => theme_get_setting('header_bg_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),

  );

  $element['color_vals']['menu_bg_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Menu Background'),
      '#default_value' => theme_get_setting('menu_bg_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['menu_link_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Menu Text Links'),
      '#default_value' => theme_get_setting('menu_link_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['menu_link_hover_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Menu text Links Hover'),
      '#default_value' => theme_get_setting('menu_link_hover_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['menu_link_bg_hover_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Menu Text Links Hover'),
      '#default_value' => theme_get_setting('menu_link_bg_hover_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['body_bg_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Main Body Background'),
      '#default_value' => theme_get_setting('body_bg_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );
  $element['color_vals']['footer_bg_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Footer Background'),
      '#default_value' => theme_get_setting('footer_bg_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['button_bg_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Button Background'),
      '#default_value' => theme_get_setting('button_bg_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['text_link'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Text Link'),
      '#default_value' => theme_get_setting('text_link', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['text_link_hover'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Text Link Hover'),
      '#default_value' => theme_get_setting('text_link_hover', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['color_vals']['text_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Body Text'),
      '#default_value' => theme_get_setting('text_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );
  $element['color_vals']['h1_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('H1 Color'),
      '#default_value' => theme_get_setting('h1_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );
  $element['color_vals']['h2_color'] = array(
      '#type'          => 'textfield',
      '#title'         => t('H2 Color'),
      '#default_value' => theme_get_setting('h2_color', 'THEME_FOLDER_NAME'),
      '#attributes' => array('class' => array('spectrum-color-picker')),
  );

  $element['empty_colors'] = array(
      '#type' => 'button',
      '#value' => t('Empty Colors'),
      '#weight' => 15,
      '#ajax' => array(
          'callback' => 'THEME_FOLDER_NAME_empty_colors_form_submit',
          'method' => 'replace',
          'effect' => 'fade',
          'wrapper' => 'color-vals',
      ),
      '#attached' => array(
          'js' => array(
              drupal_get_path('theme', 'THEME_FOLDER_NAME') . '/includes/colors/js/init_spectrum.js' => array(
                  'scope' => 'footer',
              ),
          ),
      ),
      //'#submit' => array('THEME_FOLDER_NAME_empty_colors_form_submit'),
  );

  $element['default_colors'] = array(
      '#type' => 'button',
      '#value' => t('IDI Colors'),
      '#weight' => 15,
      '#ajax' => array(
          'callback' => 'THEME_FOLDER_NAME_default_colors_form_submit',
          'method' => 'replace',
          'effect' => 'fade',
          'wrapper' => 'color-vals',
      ),
      //'#submit' => array('THEME_FOLDER_NAME_default_colors_form_submit'),
  );



  $form['#submit'][] = 'THEME_FOLDER_NAME_extension_colors_settings_form_submit';
  //dsm($form);
  return $element;
}

/**
 * Form submit handler for the theme settings form to clean up stale values.
 */
function THEME_FOLDER_NAME_extension_colors_settings_form_submit($form, &$form_state) {
}

function THEME_FOLDER_NAME_default_colors_form_submit(&$form, $form_state)
{
  $defaults = array(
      'header_bg_color' => '#959699',
      'menu_bg_color' => '#1a3d73',
      'menu_link_color' => '#ffffff',
      'button_bg_color' => '#1a3d73',
      'button_bg_hover_color' => '#1a3d73',
      'menu_link_bg_hover_color' => '#25c0f1',
      'menu_link_hover_color' => '#1a3d73',
      'body_bg_color' => '#ededed',
      'footer_bg_color' => '#CCCCCC',
      'text_link' => '#1a3d73',
      'text_link_hover' => '#25c0f1',
      'text_color' => '#54565b',
      'h1_color' => '#1a3d73',
      'h2_color' => '#54565b',
  );
  foreach($defaults as $variable => $value){
    $form_state['values'][$variable] = $value;
    $form_state['input'][$variable] = $value;
    $form_state['complete form']['omega']['colors']['settings']['color_vals'][$variable]['#value'] = $value;
    $form_state['complete form']['omega']['colors']['settings']['color_vals'][$variable]['#default_value'] = $value;
  }
  $new_form = drupal_rebuild_form($form_state['build_info']['form_id'], $form_state, $old_form = NULL);
  $element = $new_form['omega']['colors']['settings']['color_vals'];
  $commands[] = ajax_command_replace(NULL, render($element));
  $commands[] = ajax_command_invoke(NULL, 'init_spectrum');
  return array('#type' => 'ajax', '#commands' => $commands);
}

function THEME_FOLDER_NAME_empty_colors_form_submit(&$form, $form_state) {

  $defaults = array(
      'header_bg_color' => '',
      'menu_bg_color' => '',
      'menu_link_color' => '',
      'button_bg_color' => '',
      'button_bg_hover_color' => '',
      'menu_link_bg_hover_color' => '',
      'menu_link_hover_color' => '',
      'body_bg_color' => '',
      'footer_bg_color' => '',
      'text_link' => '',
      'text_link_hover' => '',
      'text_color' => '',
      'h1_color' => '',
      'h2_color' => '',
  );
  foreach($defaults as $variable => $value){
    $form_state['values'][$variable] = $value;
    $form_state['input'][$variable] = $value;
    $form_state['complete form']['omega']['colors']['settings']['color_vals'][$variable]['#value'] = $value;
    $form_state['complete form']['omega']['colors']['settings']['color_vals'][$variable]['#default_value'] = $value;
  }
  $new_form = drupal_rebuild_form($form_state['build_info']['form_id'], $form_state, $old_form = NULL);
  $element = $new_form['omega']['colors']['settings']['color_vals'];
  $commands[] = ajax_command_replace(NULL, render($element));
  $commands[] = ajax_command_invoke(NULL, 'init_spectrum');
  return array('#type' => 'ajax', '#commands' => $commands);
}
