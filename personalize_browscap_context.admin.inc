<?php

/**
 * @file
 * Contains functionality for administering the module.
 */

/**
 * Returns form for managing loading user agent's parameters to context.
 */
function personalize_browscap_context_admin_form($form, &$form_state) {
  $personalize_browscap_contexts = variable_get('personalize_browscap_contexts', array());
  $user_agent_options = personalize_browscap_context_get_all_browscap_options();

  $form['personalize_browscap_context'] = array(
    '#title' => t('User Agent'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  // Browser context.
  $form['personalize_browscap_context']['browser'] = array(
    '#title' => t('Browsers'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $browser_visibility = isset($personalize_browscap_contexts['browser']['visibility']) ? $personalize_browscap_contexts['browser']['visibility'] : 0;
  $form['personalize_browscap_context']['browser']['visibility'] = array(
    '#title' => t('Show specific browsers'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('All browsers except those listed.'),
      1 => t('Only the listed browsers.'),
    ),
    '#default_value' => $browser_visibility,
  );

  asort($user_agent_options['browser'], SORT_NATURAL);
  $browser_list = isset($personalize_browscap_contexts['browser']['list']) ? $personalize_browscap_contexts['browser']['list'] : array();
  $form['personalize_browscap_context']['browser']['list'] = array(
    '#title' => t('Browsers List'),
    '#type' => 'checkboxes',
    '#options' => $user_agent_options['browser'],
    '#description' => t('Specify browsers for processing. <strong>Note:</strong> rest of browsers will be marked as <i>"Other"</i>.'),
    '#default_value' => $browser_list,
    '#field_prefix' => '<div style="height: 250px; overflow-y: scroll">',
    '#field_suffix' => '</div>',
  );

  // Platform context.
  $form['personalize_browscap_context']['platform'] = array(
    '#title' => t('Platforms'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $platform_visibility = isset($personalize_browscap_contexts['platform']['visibility']) ? $personalize_browscap_contexts['platform']['visibility'] : 0;
  $form['personalize_browscap_context']['platform']['visibility'] = array(
    '#title' => t('Show specific platforms'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('All platforms except those listed.'),
      1 => t('Only the listed platforms.'),
    ),
    '#default_value' => $platform_visibility,
  );

  asort($user_agent_options['platform'], SORT_NATURAL);
  $platform_list = isset($personalize_browscap_contexts['platform']['list']) ? $personalize_browscap_contexts['platform']['list'] : array();
  $form['personalize_browscap_context']['platform']['list'] = array(
    '#title' => t('Platforms List'),
    '#type' => 'checkboxes',
    '#options' => $user_agent_options['platform'],
    '#description' => t('Specify platforms for processing. <strong>Note:</strong> rest of platforms will be marked as <i>"Other"</i>.'),
    '#default_value' => $platform_list,
    '#field_prefix' => '<div style="height: 250px; overflow-y: scroll">',
    '#field_suffix' => '</div>',
  );

  // Device Type context.
  $form['personalize_browscap_context']['device_type'] = array(
    '#title' => t('Device Type'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $device_type_visibility = isset($personalize_browscap_contexts['device_type']['visibility']) ? $personalize_browscap_contexts['device_type']['visibility'] : 0;
  $form['personalize_browscap_context']['device_type']['visibility'] = array(
    '#title' => t('Show specific device types'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('All device types except those listed.'),
      1 => t('Only the listed device types.'),
    ),
    '#default_value' => $device_type_visibility,
  );

  asort($user_agent_options['device_type'], SORT_NATURAL);
  $device_type_list = isset($personalize_browscap_contexts['device_type']['list']) ? $personalize_browscap_contexts['device_type']['list'] : array();
  $form['personalize_browscap_context']['device_type']['list'] = array(
    '#title' => t('Device Types List'),
    '#type' => 'checkboxes',
    '#options' => $user_agent_options['device_type'],
    '#description' => t('Specify device types for processing. <strong>Note:</strong> rest of device types will be marked as <i>"Other"</i>.'),
    '#default_value' => $device_type_list,
    '#field_prefix' => '<div style="height: 250px; overflow-y: scroll">',
    '#field_suffix' => '</div>',
  );

  $form['#validate'][] = 'personalize_browscap_context_admin_form_validate';
  $form['#submit'][] = 'personalize_browscap_context_admin_form_submit';
}

/**
 * Validation callback for validating user agent options for context.
 */
function personalize_browscap_context_admin_form_validate($form, &$form_state) {
  // @TODO: add validating browsers.
  // @TODO: add validating availability of contexts combinations.
}

/**
 * Submission callback for saving user agent options for context.
 */
function personalize_browscap_context_admin_form_submit($form, &$form_state) {
  $personalize_browscap_contexts = array();
  if (!empty($form_state['values']['personalize_browscap_context'])) {
    $personalize_browscap_contexts = $form_state['values']['personalize_browscap_context'];
    foreach (array('browser', 'platform', 'device_type') as $param) {
      $options_values = array_filter($personalize_browscap_contexts[$param]['list']);
      $personalize_browscap_contexts[$param]['list'] = $options_values;
    }
  }
  variable_set('personalize_browscap_contexts', $personalize_browscap_contexts);
}
