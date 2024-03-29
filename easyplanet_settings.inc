<?php

/**
 * @file
 * General Planet Settings
 */

/**
 * Planet Settings
 */
function easyplanet_admin_settings() {
  $form = array();

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );

  // Fetch a list of categories.
  //
  $options = array (0 => 'No category');
  $query = db_select('aggregator_category', 'ac');
  $results = $query->fields('ac', array('cid', 'title'))->execute();
  foreach ($results as $obj) {
    $options[$obj->cid] = $obj->title;
  }

  $form['general']['easyplanet_feed_category'] = array(
    '#type' => 'select',
    '#title' => t('Aggregator Category'),
    '#description' => t('The aggregator category to assign to retrieved feed items.'),
    '#options' => $options,
    '#default_value' => variable_get('easyplanet_feed_category', 0)
  );

  $form['general']['easyplanet_feed_items'] = array(
    '#type' => 'textfield',
    '#title' => t('Feed Items'),
    '#default_value' => variable_get('easyplanet_feed_items', 40),
    '#description' => t('The number of items to be displayed in the planet.'),
    '#required' => TRUE,
  );
  $form['general']['easyplanet_cron_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cron on Modify'),
    '#default_value' => variable_get('easyplanet_cron_edit', 0),
    '#description' => t('Should the feed being added/altered be run through cron to update content? (This does hurt performance)'),
    '#required' => FALSE,
  );
  $form['general']['easyplanet_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#default_value' => variable_get('easyplanet_page_title', NULL),
    '#description' => t('The page title to be displayed with the planet feeds. (blank means disabled)'),
    '#required' => FALSE,
  );
  $form['general']['easyplanet_page_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Description'),
    '#default_value' => variable_get('easyplanet_page_desc', NULL),
    '#description' => t('The description to be displayed under the title. (blank means disabled)'),
    '#required' => FALSE,
  );
  $form['sidebar'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sidebar Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );
  $form['sidebar']['easyplanet_block_feeds'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Feeds'),
    '#default_value' => variable_get('easyplanet_block_feeds', TRUE),
    '#description' => t('Whether or not to display a list of user feeds.'),
    '#required' => TRUE,
  );
  $form['users'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );
  $form['users']['easyplanet_user_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum User Feeds'),
    '#default_value' => variable_get('easyplanet_user_max', 0),
    '#description' => t('The maximum number of feeds a user can have attached to their account. (0 = unlimited)'),
    '#required' => FALSE,
  );
  $form['users']['easyplanet_user_add'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Own Feeds'),
    '#default_value' => variable_get('easyplanet_user_add', TRUE),
    '#description' => t('Allow the user to add their own feeds.'),
    '#required' => TRUE,
  );
  $form['users']['easyplanet_user_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Edit Own Feeds'),
    '#default_value' => variable_get('easyplanet_user_edit', TRUE),
    '#description' => t('Allow the user to edit edit their own feeds.'),
    '#required' => TRUE,
  );
  $form['safety'] = array(
    '#type' => 'fieldset',
    '#title' => t('Safety Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );
  $form['safety']['notice_3'] = array(
    '#type' => 'textarea',
    '#title' => l(t('Click here to be navigated to /admin/people'), 'admin/people'),
    '#default_value' => t('The Planet module relies very heavily on the Aggregator module. For this reason, '
                        . 'the default action is to disable access to the aggregator settings. If you need '
                        . 'to access these settings you can disable this safety setting. However, do not  '
                        . 'expect any support if things break. Note: you will need to flush cache for this '
                        . 'change to take effect.'),
    '#disabled' => TRUE,
  );
  $form['safety']['easyplanet_safety_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Safety Features'),
    '#default_value' => variable_get('easyplanet_safety_enabled', TRUE),
    '#description' => t('Enable safety features to prevent issues.'),
    '#required' => TRUE,
  );
  $form['pictures'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Pictures'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );
  $form['pictures']['notice_2'] = array(
    '#type' => 'textarea',
    '#title' => l(t('Click here to be navigated to /admin/people'), 'admin/people'),
    '#default_value' => t('Managing user pictures is not implimented here for various reasons. You should visit '
                        . 'yoursite.com/admin/user/settings and scroll down to the "Pictures" section to manage '
                        . 'pictures that will be diplayed with the user blogs. It is suggested that you configure '
                        . 'this for the best results.'),
    '#disabled' => TRUE,
  );

  return system_settings_form($form);
}
