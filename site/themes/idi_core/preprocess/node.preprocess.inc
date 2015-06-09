<?php


function THEME_FOLDER_NAME_preprocess_node(&$variables) {

  $variables['title'] = make_it_super($variables['title']);

}
