<?php

/**
 * @file
 * The accordian style plugin that is part of Panopoly Theme
 */

// Plugin definition
$plugin = array(
  'title' => t('Teal Background'),
  'description' => t('Sets the regions background teal.'),
  'render region' => 'YOURTHEMENAME_teal_style_render_region',
  // 'settings form' => 'activator_teal_style_settings_form',
  'weight' => -15,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_YOURTHEMENAME_teal_style_render_region($vars) {

  // Include Some Basic Information not needed but including for completeness later
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  // Display the Output
  $output = '<div class="teal-region"><div class="container">';
  foreach ($panes as $pane_id => $pane) {
    if ($pane_id != 'empty_placeholder') {
      $output .= '<div class="pane-content">' . $pane . '</div>';
    }
  }
  $output .= '</div></div>' ;

  // Handle the Empty Placeholder Panels IPE Needs
  if (!empty($panes['empty_placeholder'])) {
    $output .= $panes['empty_placeholder'];
  }

  return $output;
}

