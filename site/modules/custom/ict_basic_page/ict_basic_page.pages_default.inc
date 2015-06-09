<?php
/**
 * @file
 * ict_basic_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ict_basic_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'Basic Page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page',
  );
  $display = new panels_display();
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '113b7628-2c7f-4640-aee9-01780e0f064d';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_basic_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faqs';
  $page->task = 'page';
  $page->admin_title = 'faqs';
  $page->admin_description = '';
  $page->path = 'faqs';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'FAQs',
    'name' => 'main-menu',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_faqs__panel_context_ec661702-d5f4-4953-8e12-9649a7dab085';
  $handler->task = 'page';
  $handler->subtask = 'faqs';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Faqs',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'right' => NULL,
      'footer' => NULL,
      'left' => NULL,
      'sidebar' => NULL,
      'content_main' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'Frequently Asked Questions';
  $display->uuid = '10f05641-ea39-42b6-b781-66d437a42879';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ab592d7a-2806-47b0-b115-163b9a5876ef';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ab592d7a-2806-47b0-b115-163b9a5876ef';
    $display->content['new-ab592d7a-2806-47b0-b115-163b9a5876ef'] = $pane;
    $display->panels['content_main'][0] = 'new-ab592d7a-2806-47b0-b115-163b9a5876ef';
    $pane = new stdClass();
    $pane->pid = 'new-b214fb10-7079-4a01-8f51-2e6598d272e0';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '2',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b214fb10-7079-4a01-8f51-2e6598d272e0';
    $display->content['new-b214fb10-7079-4a01-8f51-2e6598d272e0'] = $pane;
    $display->panels['content_main'][1] = 'new-b214fb10-7079-4a01-8f51-2e6598d272e0';
    $pane = new stdClass();
    $pane->pid = 'new-5a5cb180-3111-40d1-a1fa-da19fad9f941';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '3',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5a5cb180-3111-40d1-a1fa-da19fad9f941';
    $display->content['new-5a5cb180-3111-40d1-a1fa-da19fad9f941'] = $pane;
    $display->panels['content_main'][2] = 'new-5a5cb180-3111-40d1-a1fa-da19fad9f941';
    $pane = new stdClass();
    $pane->pid = 'new-6d0132a5-e6fc-4ada-91b7-19af41526e9d';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '4',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6d0132a5-e6fc-4ada-91b7-19af41526e9d';
    $display->content['new-6d0132a5-e6fc-4ada-91b7-19af41526e9d'] = $pane;
    $display->panels['content_main'][3] = 'new-6d0132a5-e6fc-4ada-91b7-19af41526e9d';
    $pane = new stdClass();
    $pane->pid = 'new-e5014ef9-67ec-484a-bd94-58c93b74210d';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '5',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e5014ef9-67ec-484a-bd94-58c93b74210d';
    $display->content['new-e5014ef9-67ec-484a-bd94-58c93b74210d'] = $pane;
    $display->panels['content_main'][4] = 'new-e5014ef9-67ec-484a-bd94-58c93b74210d';
    $pane = new stdClass();
    $pane->pid = 'new-235531c3-8d44-4a45-8089-7ca391c0410f';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '6',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '235531c3-8d44-4a45-8089-7ca391c0410f';
    $display->content['new-235531c3-8d44-4a45-8089-7ca391c0410f'] = $pane;
    $display->panels['content_main'][5] = 'new-235531c3-8d44-4a45-8089-7ca391c0410f';
    $pane = new stdClass();
    $pane->pid = 'new-6c023384-0f2c-497a-961f-25dc5ad7fb80';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '7',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '6c023384-0f2c-497a-961f-25dc5ad7fb80';
    $display->content['new-6c023384-0f2c-497a-961f-25dc5ad7fb80'] = $pane;
    $display->panels['content_main'][6] = 'new-6c023384-0f2c-497a-961f-25dc5ad7fb80';
    $pane = new stdClass();
    $pane->pid = 'new-2f1d25bc-2952-402e-b71f-436a7e0fe7a5';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '8',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '2f1d25bc-2952-402e-b71f-436a7e0fe7a5';
    $display->content['new-2f1d25bc-2952-402e-b71f-436a7e0fe7a5'] = $pane;
    $display->panels['content_main'][7] = 'new-2f1d25bc-2952-402e-b71f-436a7e0fe7a5';
    $pane = new stdClass();
    $pane->pid = 'new-52dbdbee-d1e9-451a-a0d0-f4cb0c529008';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '10',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '52dbdbee-d1e9-451a-a0d0-f4cb0c529008';
    $display->content['new-52dbdbee-d1e9-451a-a0d0-f4cb0c529008'] = $pane;
    $display->panels['content_main'][8] = 'new-52dbdbee-d1e9-451a-a0d0-f4cb0c529008';
    $pane = new stdClass();
    $pane->pid = 'new-bc369382-a3e3-474b-ad9c-31e0a887c69b';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'bean-see-who-can-take-part';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bc369382-a3e3-474b-ad9c-31e0a887c69b';
    $display->content['new-bc369382-a3e3-474b-ad9c-31e0a887c69b'] = $pane;
    $display->panels['sidebar'][0] = 'new-bc369382-a3e3-474b-ad9c-31e0a887c69b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ab592d7a-2806-47b0-b115-163b9a5876ef';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faqs'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'front';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front__panel_context_46eb1b47-c135-4f9d-a4e9-5b75c77cd5d9';
  $handler->task = 'page';
  $handler->subtask = 'front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'left' => NULL,
      'right' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1566ae6e-876e-49ef-be62-01231ac5ba34';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-831b1cb3-2fcc-4d13-8bd0-a3acfb36d294';
    $pane->panel = 'content_main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '11',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '831b1cb3-2fcc-4d13-8bd0-a3acfb36d294';
    $display->content['new-831b1cb3-2fcc-4d13-8bd0-a3acfb36d294'] = $pane;
    $display->panels['content_main'][0] = 'new-831b1cb3-2fcc-4d13-8bd0-a3acfb36d294';
    $pane = new stdClass();
    $pane->pid = 'new-e9f72d70-8243-4800-ba93-5faa6ee25d70';
    $pane->panel = 'content_main';
    $pane->type = 'block';
    $pane->subtype = 'bean-see-who-can-take-part';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e9f72d70-8243-4800-ba93-5faa6ee25d70';
    $display->content['new-e9f72d70-8243-4800-ba93-5faa6ee25d70'] = $pane;
    $display->panels['content_main'][1] = 'new-e9f72d70-8243-4800-ba93-5faa6ee25d70';
    $pane = new stdClass();
    $pane->pid = 'new-54ca9d4c-0d74-440a-88a0-cf79442e5112';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'bean-about-the-study';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54ca9d4c-0d74-440a-88a0-cf79442e5112';
    $display->content['new-54ca9d4c-0d74-440a-88a0-cf79442e5112'] = $pane;
    $display->panels['sidebar'][0] = 'new-54ca9d4c-0d74-440a-88a0-cf79442e5112';
    $pane = new stdClass();
    $pane->pid = 'new-603ffe84-c5c6-4009-aa59-4114f75f7989';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'bean-faqs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '603ffe84-c5c6-4009-aa59-4114f75f7989';
    $display->content['new-603ffe84-c5c6-4009-aa59-4114f75f7989'] = $pane;
    $display->panels['sidebar'][1] = 'new-603ffe84-c5c6-4009-aa59-4114f75f7989';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}
