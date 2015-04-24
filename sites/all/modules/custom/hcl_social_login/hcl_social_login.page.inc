<?php

function hcl_social_login_add_to_form($form, $form_state) {
  $form = array();
  $form['hcl_social_login_form_id'] = array(
    '#type' => 'textarea',
    '#title' => t('Form Id'),
    '#description' => t('Please enter each form id in a new line'),
    '#default_value' => variable_get('hcl_social_login_form_id', ''),
  );
  return system_settings_form($form);
}
