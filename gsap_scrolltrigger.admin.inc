<?php

/**
 * @file
 * Contains the administration pages for GSAP ScrollTrigger.
 *
 */
function gsap_scrolltrigger_settings($form_state) {

  $form['gsap_scrolltrigger_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show animations on specific pages'),
    '#options' => array(0 => t('All pages except those listed'), 1 => t('Only the listed pages')),
    '#default_value' => config_get('gsap_scrolltrigger.settings', 'gsap_scrolltrigger_visibility'),
  );
  $form['gsap_scrolltrigger_pages'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => config_get('gsap_scrolltrigger.settings', 'gsap_scrolltrigger_pages'),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  $form['gsap_scrolltrigger_cdn'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable loading library from CDN '),
    '#default_value' => config_get('gsap_scrolltrigger.settings', 'gsap_scrolltrigger_cdn'),
    '#description' => t('This enables loading the js library from the CDN (Content Delivery Network).'),
  );

  $form['gsap_scrolltrigger_jsmain'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for loading the GSAP Main js file'),
    '#default_value' => config_get('gsap_scrolltrigger.settings', 'gsap_scrolltrigger_jsmain'),
    '#description' => t('Load the js GSAP main file from this URL.'),
  );

  $form['gsap_scrolltrigger_jsst'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for loading the GSAP ScrollTrigger js file from.'),
    '#default_value' => config_get('gsap_scrolltrigger.settings', 'gsap_scrolltrigger_jsst'),
    '#description' => t('Load the GSAP ScrollTrigger js file from the URL.'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Submit handler for module_settings_form().
 */
function gsap_scrolltrigger_settings_submit($form, &$form_state) {
    $config = config('gsap_scrolltrigger.settings');
    foreach ($form_state['values'] as $key => $value)
    {
      $config->set($key, $value);
    }

    $config->save();
    backdrop_set_message(t('The configuration options have been saved.'));
}
?>
