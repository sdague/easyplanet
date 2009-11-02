<?php
// $Id$

/**
 * @file
 * Generate any display content
 */

/**
 * Page Content
 */
function udplanet_page_content() {
  // Add nice pretty CSS
  drupal_add_css(drupal_get_path('module', 'udplanet') . '/udplanet-style.css');

  // Get content of all feeds
  $feeds = udplanet_get_items();

  // Generate themed planet content
  foreach ($feeds as $feed) {
    $planet .= udplanet_content_heading($feed['time'], $lastday);
    $planet .= theme('page_udplanet', $feed['title'], $feed['url'], $feed['heading'], $feed['link'], $feed['content'], $feed['time'], $feed['uid']);
  }

  // Make sure we return a meaningful message if no content exists
  if ($planet == '') {
    $planet = 'No planet content available.';
  }

  return $planet;
}

/**
 * Function to pull the planet data from the database
 */
function udplanet_get_items() {
  $items_limit = variable_get('udplanet_feed_items', 40);

  $items = db_query('SELECT
                     users.uid AS uid,
                     aggregator_feed.title AS title,
                     aggregator_feed.url AS url,
                     aggregator_item.title AS heading,
                     aggregator_item.link AS link,
                     aggregator_item.description AS content,
                     aggregator_item.timestamp AS time
                     FROM udplanet_feeds
                     LEFT JOIN users ON udplanet_feeds.uid = users.uid
                     LEFT JOIN aggregator_feed ON udplanet_feeds.fid = aggregator_feed.fid
                     LEFT JOIN aggregator_item ON aggregator_feed.fid = aggregator_item.fid
                     WHERE udplanet_feeds.disabled IS NOT TRUE
                     AND udplanet_feeds.frozen IS NOT TRUE
                     LIMIT %d', $items_limit);

  $feeds = array();

  while ($item = db_fetch_object($items)) {
    $feeds[] = array(
      'title' => $item->title,
      'url' => $item->url,
      'heading' => $item->heading,
      'link' => $item->link,
      'content' => $item->content,
      'time' => $item->time,
      'uid' => $item->uid,
    );
  }

  return $feeds;
}

/**
 * Function to manage chang in heading
 */
function udplanet_content_heading($time, &$day_last) {
  $day_this = format_date($time, 'custom', 'F d, Y');
  if ($day_last != $day_this) {
    $day_last = $day_this;
    $output = theme('heading_udplanet', $day_this);
  }

  return $output;
}

/**
 * Implementation of hook_theme().
 */
function udplanet_theme() {
  return array(
    'page_udplanet' => array(
      'arguments' => array(
        'title',
        'url',
        'heading',
        'link',
        'content',
        'time',
        'picture',
      ),
    ),
    'heading_udplanet' => array(
      'arguements' => array(
        'date',
      )
    )
  );
}

/**
 * Custom theme function: page output
 */
function theme_page_udplanet($title, $url, $heading, $link, $content, $time, $uid) {
  $timestamp = format_date($time, 'custom', 'F d, Y g:i A');
  $picture = theme('user_picture', user_load($uid));

  $output  = '';
  $output .= '<div class="udp-entry">';
  $output .= '  <div class="udp-person-info">';
  $output .= '    <a href="' . $url . '">';
  //$output .= '      <img class="udp-face" src="' . $picture . '" />';
  $output .= '      ' . $picture;
  $output .= '      <br />' . $title;
  $output .= '    </a>';
  $output .= '  </div>';
  $output .= '  <div class="udp-post">';
  $output .= '    <div class="udp-post2">';
  $output .= '      <div class="udp-post-header">';
  $output .= '        <h4 class="udp-post-title">';
  $output .= '          <a href="' . $link . '">' . $heading . '</a>';
  $output .= '        </h4>';
  $output .= '      </div>';
  $output .= '      <div class="udp-post-contents">';
  $output .= '        ' . $content;
  $output .= '      </div>';
  $output .= '      <div class="udp-post-footer">';
  $output .= '        <p>';
  $output .= '          <a href="' . $link . '">' . $timestamp . '</a>';
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
  $output  = '';
  $output .= '<h2 class="udp-date">';
  $output .=   $date;
  $output .= '</h2>';

  return $output;
}
