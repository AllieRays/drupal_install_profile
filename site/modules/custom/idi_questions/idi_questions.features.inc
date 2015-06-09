<?php
/**
 * @file
 * idi_questions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function idi_questions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function idi_questions_node_info() {
  $items = array(
    'question' => array(
      'name' => t('Question'),
      'base' => 'node_content',
      'description' => t('Questions for the FAQs page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Title of the question'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
