<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php
 // $active_slide = rand(0, count($rows));
$active_slide = 0;
?>
<?php foreach ($rows as $id => $row): ?>
  <div id="slide-<?php print $id ?>" <?php print ' class="view-row '; if ($classes_array[$id]) { $classes_array[$id];} print $id == $active_slide ? 'active' : 'inactive'; print '"'; ?>>


    <?php print $row; ?>
  </div>
<?php endforeach; ?>
 <?php if(count($rows) > 1 ): ?>
      <a href="#" class="previous" style="display:none;">&lt;</a>
      <a href="#" class="next" style="display:none;">&gt;</a>
    <div class="controls"><div class="inner" style="width:<?php print count($rows)*25 ?>px;">
    <?php foreach ($rows as $delta => $item): ?>
        <a class="control <?php print $delta == $active_slide ? 'active' : ''; ?>" id="slide-crtl-<?php print $delta ?>">&bullet;</a>
    <?php endforeach; ?>
      </div></div>
    <?php endif; ?>
