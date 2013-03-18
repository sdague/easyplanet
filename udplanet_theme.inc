<?php

/**
 * @file
 * This file is used to hold all themed output functions
 */

/**
 * Custom theme function: page output
 */
function theme_page_udplanet($vars) {
  error_log("Vars: $vars");
  // $title, $url, $heading, $link, $content, $time, $uid) {
  $timestamp = format_date($vars['time'], 'custom', 'F d, Y g:i A');
  $picture = theme('user_picture', array('account' => user_load($vars['uid'])));

  $output  = '<div class="udp-entry">';
  $output .= '  <div class="udp-person-info">';
  $output .= '    <a href="' . $vars['url'] . '">';
  $output .= '      ' . $picture;
  $output .= '      <br />' . $vars['title'];
  $output .= '    </a>';
  $output .= '  </div>';
  $output .= '  <div class="udp-post">';
  $output .= '    <div class="udp-post2">';
  $output .= '      <div class="udp-post-header">';
  $output .= '        <h4 class="udp-post-title">';
  $output .= '          <a href="' . $vars['link'] . '">' . $vars['heading'] . '</a>';
  $output .= '        </h4>';
  $output .= '      </div>';
  $output .= '      <div class="udp-post-contents">';
  $output .= '        ' . $vars['content'];
  $output .= '      </div>';
  $output .= '      <div class="udp-post-footer">';
  $output .= '        <p>';
  $output .= '          <a href="' . $vars['link'] . '">' . $timestamp . '</a>';
  $output .= '        </p>';
  $output .= '      </div>';
  $output .= '    </div>';
  $output .= '  </div>';
  $output .= '</div>';

  return $output;
}

/**
 * Custom theme function: date heading
 */
function theme_heading_udplanet($date) {
  $output  = '<h2 class="udp-date">';
  $output .=   $date;
  $output .= '</h2>';

  return $output;
}

/**
 * Custom theme function: block feeds
 */
function theme_sidebar_udplanet_feeds_open() {
  $output  = '<div class="udp-inside">';
  $output .= '  <ul>';

  return $output;
}

/**
 * Custom theme function: block feeds
 */
function theme_sidebar_udplanet_feeds_list($title, $feed, $link) {
  $output  = '    <li>';
  $output .= '      <a href="' . $vars['link'] . '">' . $title . '</a> <a href="' . $feed . '"> (feed)</a>';
  $output .= '    </li>';

  return $output;
}

/**
 * Custom theme function: block feeds
 */
function theme_sidebar_udplanet_feeds_close() {
  $output  = '  </ul>';
  $output .= '</div>';

  return $output;
}