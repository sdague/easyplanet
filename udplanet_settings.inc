<?php
// $Id$

/**
 * @file General Planet Settings
 */

/**
 * Planet Settings
 */
function udplanet_admin_settings() {
  $form = array();

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
  );
  $form['general']['udplanet_feed_items'] = array(
    '#type' => 'textfield',
    '#title' => t('Feed Items'),
    '#default_value' => variable_get('udplanet_feed_items', 40),
    '#description' => t('The number of items to be displayed in the planet.'),
    '#required' => TRUE,
  );
  $form['users'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
  );
  $form['users']['udplanet_user_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum User Feeds'),
    '#default_value' => variable_get('udplanet_user_max', 0),
    '#description' => t('The maximum number of feeds a user can have attached to their account. (0 = unlimited)'),
    '#required' => FALSE,
  );
  $form['users']['udplanet_user_add'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Own Feeds'),
    '#default_value' => variable_get('udplanet_user_add', TRUE),
    '#description' => t('Allow the user to add their own feeds.'),
    '#required' => TRUE,
  );
  $form['users']['udplanet_user_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Edit Own Feeds'),
    '#default_value' => variable_get('udplanet_user_edit', TRUE),
    '#description' => t('Allow the user to edit edit their own feeds.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

