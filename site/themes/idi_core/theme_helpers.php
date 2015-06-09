<?php


function Truncate($string, $length, $stopanywhere = FALSE) {
  //truncates a string to a certain char length, stopping on a word if not specified otherwise.
  if (strlen($string) > $length) {
    //limit hit!
    $string = substr($string, 0, ($length - 3));
    if ($stopanywhere) {
      //stop anywhere
      $string .= '...';
    }
    else {
      //stop on a word.
      $string = substr($string, 0, strrpos($string, ' ')) . '...';
    }
  }
  return $string;
}

/**
 * Move array element by index.  Only works with zero-based,
 * contiguously-indexed arrays
 *
 * @param array $array
 * @param integer $from Use NULL when you want to move the last element
 * @param integer $to New index for moved element. Use NULL to push
 *
 * @throws Exception
 *
 * @return array Newly re-ordered array
 */
function moveValueByIndex(array $array, $from = NULL, $to = NULL) {
  if (NULL === $from) {
    $from = count($array) - 1;
  }

  if (!isset($array[$from])) {
    throw new Exception("Offset $from does not exist");
  }

  if (array_keys($array) != range(0, count($array) - 1)) {
    throw new Exception("Invalid array keys");
  }

  $value = $array[$from];
  unset($array[$from]);

  if (NULL === $to) {
    array_push($array, $value);
  }
  else {
    $tail = array_splice($array, $to);
    array_push($array, $value);
    $array = array_merge($array, $tail);
  }

  return $array;
}


/**
 * Get a block suitable for rendering.
 * Note: the block does not have to be enabled in $region.
 * @see includes/block.module/_block_render_blocks()
 * @see includes/block.module/_block_get_renderable_array()
 */
function siteoverride_embed_block($module, $delta, $region = 'content') {
  // Create block stub.
  $block = new stdClass();
  $block->module = $module;
  $block->delta = $delta;
  $block->region = $region;
  // Load title.
  global $theme_key;
  drupal_theme_initialize();
  $block1 = db_query("SELECT title FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme",
    array(':module' => $module, ':delta' => $delta, ':theme' => $theme_key))->fetchObject();
  if (is_object($block1) && isset($block1->title)) {
    $block->title = $block1->title;
  }
  // Render the content and subject for the block.
  $blocks = _block_render_blocks(array($block));
  // Get an array of blocks suitable for drupal_render().
  $array = _block_get_renderable_array($blocks);
  return $array;
}


//strips GTs and makes reg marks super
function make_it_super($value) {

  //$value = str_replace("&lt;br&gt;", " ", $value);
  //$value = str_replace("&lt;br/&gt;", " ", $value);
  //$value = str_replace("&lt;br /&gt;", " ", $value);
  $value = str_replace("®", "<sup>&reg;</sup>", $value);

  return $value;

}

?>
