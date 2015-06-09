<?php
/**
 * @file
 * idi_user_permission_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function idi_user_permission_roles_user_default_roles() {
  $roles = array();

  // Exported role: ADMINISTRATOR.
  $roles['ADMINISTRATOR'] = array(
    'name' => 'ADMINISTRATOR',
    'weight' => 1,
  );

  // Exported role: Content approver.
  $roles['Content approver'] = array(
    'name' => 'Content approver',
    'weight' => 2,
  );

  // Exported role: Content editor.
  $roles['Content editor'] = array(
    'name' => 'Content editor',
    'weight' => 1,
  );

  return $roles;
}
