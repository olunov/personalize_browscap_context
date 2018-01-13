<?php

/**
 * @file
 * Provides a visitor context plugin for user agents (browsers options).
 */

class BrowscapContext extends PersonalizeContextBase {

  /**
   * Implements PersonalizeContextInterface::create().
   */
  public static function create(PersonalizeAgentInterface $agent = NULL, $selected_context = array()) {
    return new self($agent, $selected_context);
  }

  /**
   * Implements PersonalizeContextInterface::getOptions().
   */
  public static function getOptions() {
    $options = array();
    $options['browser'] = array(
      'name' => t('Browser'),
      'group' => 'User Agent',
      'cache_type' => 'session',
    );

    $options['platform'] = array(
      'name' => t('Platform'),
      'group' => 'User Agent',
      'cache_type' => 'session',
    );

    $options['device_type'] = array(
      'name' => t('Device Type'),
      'group' => 'User Agent',
      'cache_type' => 'session',
    );

    $options['ismobiledevice'] = array(
      'name' => t('Is Mobile Device'),
      'group' => 'User Agent',
      'cache_type' => 'session',
    );

    $options['istablet'] = array(
      'name' => t('Is Tablet'),
      'group' => 'User Agent',
      'cache_type' => 'session',
    );

    return $options;
  }

  /**
   * Implements PersonalizeContextInterface::getPossibleValues().
   */
  public function getPossibleValues($limit = FALSE) {
    $possible_values = array();
    $options = $this->getOptions();

    $fields_contexts_options = _personalize_browscap_get_fields_contexts_options();

    // @TODO: refactor it.
    foreach ($options as $name => $info) {
      switch ($name) {
        case 'browser':
          $possible_values[$name] = array(
            'friendly name' => t('Browscap: Browser'),
            'value type' => 'predefined',
            'values' => $fields_contexts_options[$name],
          );
          break;

        case 'platform':
          $possible_values[$name] = array(
            'friendly name' => t('Browscap: Platform'),
            'value type' => 'predefined',
            'values' => $fields_contexts_options[$name],
          );
          break;

        case 'device_type':
          $possible_values[$name] = array(
            'friendly name' => t('Browscap: Device Type'),
            'value type' => 'predefined',
            'values' => $fields_contexts_options[$name],
          );
          break;

        case 'ismobiledevice':
          $possible_values[$name] = array(
            'friendly name' => t('Browscap: Is Mobile Device'),
            'value type' => 'predefined',
            'values' => $fields_contexts_options[$name],
          );
          break;

        case 'istablet':
          $possible_values[$name] = array(
            'friendly name' => t('Browscap: Is Tablet'),
            'value type' => 'predefined',
            'values' => $fields_contexts_options[$name],
          );
          break;
      }
    }

    if ($limit) {
      $possible_values = array_intersect_key($possible_values, array_flip($this->selectedContext));
    }

    return $possible_values;
  }
}
