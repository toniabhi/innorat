<?php

include_once './' . drupal_get_path('theme', 'md_alpine') . '/inc/template.process.inc';
include_once './' . drupal_get_path('theme', 'md_alpine') . '/inc/superfish.theme.inc';
include_once './' . drupal_get_path('theme', 'md_alpine') . '/inc/template.view.process.inc';
include_once './' . drupal_get_path('theme', 'md_alpine') . '/inc/template.node.process.inc';
/**
 * Global $base_url
 */
function base_url() {
    global $base_url;
    return $base_url;
}
/**
 * Overrides theme_menu_tree().
 */
function md_alpine_menu_tree(&$variables) {
    return '<ul class="menu nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function md_alpine_menu_tree__primary(&$variables) {
    return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the secondary menu links.
 */
function md_alpine_menu_tree__secondary(&$variables) {
    return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
}
/**
 * Overrides theme_menu_link().
 */
function md_alpine_menu_link(array $variables) {
    $frontpage = variable_get('site_frontpage','node');
    $element = $variables['element'];
    $sub_menu = '';
    //kpr($element);
    if ($element['#below']) {
        // Prevent dropdown functions from being added to management menu so it
        // does not affect the navbar module.
        if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
            $sub_menu = drupal_render($element['#below']);
        }
        elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
            // Add our own wrapper.
            unset($element['#below']['#theme_wrappers']);
            $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
            // Generate as standard dropdown.
            $element['#title'] .= ' <i class="fa fa-angle-down"></i>';
            $element['#attributes']['class'][] = 'dropdown';
            $element['#localized_options']['html'] = TRUE;

            // Set dropdown trigger element to # to prevent inadvertant page loading
            // when a submenu link is clicked.
            $element['#localized_options']['attributes']['data-target'] = '#';
            $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
            $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
        }
    }
    // On primary navigation menu, class 'active' is not set on active menu item.
    // @see https://drupal.org/node/1896674
    if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
        //$element['#attributes']['class'][] = 'active';
    }
    /*if ($menu_item['link']['menu_name'] == 'menu-home-menu') {
        if (isset($menu_item['link']['localized_options']['fragment'])) {
            return '<a href="/#' . $menu_item ['link']['localized_options']['fragment'] . '">' . $menu_item['link']['title'] . '</a>';
        }
    }
    if ($menu_item['link']['link_path'] == '<front>' && $menu_item['link']['menu_name'] == 'main-menu') {
        if (isset($menu_item['link']['localized_options']['fragment'])) {
            return '<a href="' . $GLOBALS['base_url'] . '#' . $menu_item ['link']['localized_options']['fragment'] . '">' . $menu_item['link']['title'] . '</a>';
        }
    }*/
    if(current_path() == $frontpage && drupal_is_front_page()) {
        if(!$element['#below'] && $element['#href'] == '<front>') {
            $element['#localized_options']['attributes']['class'] = array('int-collapse-menu');
            return '<li><a class="int-collapse-menu" href="#'.$element['#localized_options']['fragment'].'">'.$element['#title'].'</a></li>';
        }
    }
    if(!$element['#below'] && $element['#href'] == '<front>') {
        $element['#localized_options']['attributes']['class'] = array('int-collapse-menu');
        return '<li><a class="int-collapse-menu" href="'.$GLOBALS['base_url'].'/#'.$element['#localized_options']['fragment'].'">'.$element['#title'].'</a></li>';
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
/**
 * Implements theme_field__field_type().
 */
function md_alpine_field__taxonomy_term_reference($variables) {
    $output = '';

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
        $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
    }

    // Render the items.
    $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
    foreach ($variables['items'] as $delta => $item) {
        $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    $output .= '</ul>';

    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '">' . $output . '</div>';

    return $output;
}

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */
function md_alpine_textarea($variables) {
    $element = $variables['element'];
    $element['#attributes']['name'] = $element['#name'];
    $element['#attributes']['id'] = $element['#id'];
    $element['#attributes']['cols'] = $element['#cols'];
    $element['#attributes']['rows'] = $element['#rows'];
    _form_set_class($element, array('form-textarea'));

    $wrapper_attributes = array(
        'class' => array('form-textarea-wrapper'),
    );

    // Add resizable behavior.
    if (!empty($element['#resizable'])) {
        $wrapper_attributes['class'][] = 'resizable';
    }

    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
}

function phptemplate_preprocess_page(&$vars){
    if ( isset($_GET['ajax']) && $_GET['ajax'] == 1 ) {
        $vars['template_file'] = 'page-ajax';
    }
}

/**
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function md_alpine_form_alter(&$form, &$form_state, $form_id) {
    if (strpos($form_id,"webform_client_form") === false) {
        switch ($form_id) {
            case 'user_login':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '<div class="row">
							<div class="col-md-12 text-center">
									<div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
							</div>
						</div>';
                break;
            case 'user_register_form':
                $form['account']['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['account']['name']['#suffix'] = '</div>';
                $form['account']['mail']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['mail']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['account']['mail']['#suffix'] = '</div>';

                $form['actions']['submit']['#value'] = t('Create new account');
                $form['actions']['submit']['#prefix'] = '<div class="row">
							<div class="col-md-12 text-center">
									<div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
							</div>
						</div>';
                break;
            case 'user_login_block':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '<div class="row">
							<div class="col-md-12 text-center">
									<div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
							</div>
						</div>';
                break;
            case 'user_pass':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Request new password');
                $form['actions']['submit']['#prefix'] = '<div class="row">
							<div class="col-md-12 text-center">
									<div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
							</div>
						</div>';
                break;
        }
    } else {

        $form['#attributes']['class'][] = 'element-inline';
        $form['actions']['submit']['#prefix'] = '<div class="row">
							<div class="col-md-12 text-center">
								<div class="action form-button medium">
									<div class="mybutton medium"><span>';
        $form['actions']['submit']['#sufix'] = '</span></div>
								</div>
							</div>
						';
    }


}
/**
 * Process variables for comment.tpl.php.
 *
 * @see comment.tpl.php
 */
function md_alpine_preprocess_comment(&$variables) {
    $comment = $variables['elements']['#comment'];
    $node = $variables['elements']['#node'];
    $variables['comment']   = $comment;
    $variables['node']      = $node;
    $variables['author']    = theme('username', array('account' => $comment));

    $variables['created']   = date('d F Y',$comment->created);

    // Avoid calling format_date() twice on the same timestamp.
    if ($comment->changed == $comment->created) {
        $variables['changed'] = $variables['created'];
    }
    else {
        $variables['changed'] = format_date($comment->changed);
    }

    $variables['new']       = !empty($comment->new) ? t('new') : '';
    $variables['picture']   = theme_get_setting('toggle_comment_user_picture') ? theme('user_picture', array('account' => $comment)) : '';
    $variables['signature'] = $comment->signature;

    $uri = entity_uri('comment', $comment);
    $uri['options'] += array('attributes' => array('class' => 'permalink', 'rel' => 'bookmark'));

    $variables['title']     = l($comment->subject, $uri['path'], $uri['options']);
    $variables['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']);
    $variables['submitted'] = t('!username  on !datetime', array('!username' => $variables['author'], '!datetime' => date('d F Y',$comment->created)));

    // Preprocess fields.
    field_attach_preprocess('comment', $comment, $variables['elements'], $variables);

    // Helpful $content variable for templates.
    foreach (element_children($variables['elements']) as $key) {
        $variables['content'][$key] = $variables['elements'][$key];
    }

    // Set status to a string representation of comment->status.
    if (isset($comment->in_preview)) {
        $variables['status'] = 'comment-preview';
    }
    else {
        $variables['status'] = ($comment->status == COMMENT_NOT_PUBLISHED) ? 'comment-unpublished' : 'comment-published';
    }

    // Gather comment classes.
    // 'comment-published' class is not needed, it is either 'comment-preview' or
    // 'comment-unpublished'.
    if ($variables['status'] != 'comment-published') {
        $variables['classes_array'][] = $variables['status'];
    }
    if ($variables['new']) {
        $variables['classes_array'][] = 'comment-new';
    }
    if (!$comment->uid) {
        $variables['classes_array'][] = 'comment-by-anonymous';
    }
    else {
        if ($comment->uid == $variables['node']->uid) {
            $variables['classes_array'][] = 'comment-by-node-author';
        }
        if ($comment->uid == $variables['user']->uid) {
            $variables['classes_array'][] = 'comment-by-viewer';
        }
    }
}

/**
 * template_preprocess_user_picture()
 */
function md_alpine_preprocess_user_picture(&$variables) {
    $variables['user_picture'] = '';
    if (variable_get('user_pictures', 0)) {
        $account = $variables['account'];
        if (!empty($account->picture)) {
            // @TODO: Ideally this function would only be passed file objects, but
            // since there's a lot of legacy code that JOINs the {users} table to
            // {node} or {comments} and passes the results into this function if we
            // a numeric value in the picture field we'll assume it's a file id
            // and load it for them. Once we've got user_load_multiple() and
            // comment_load_multiple() functions the user module will be able to load
            // the picture files in mass during the object's load process.
            if (is_numeric($account->picture)) {
                $account->picture = file_load($account->picture);
            }
            if (!empty($account->picture->uri)) {
                $filepath = $account->picture->uri;
            }
        }
        elseif (variable_get('user_picture_default', '')) {
            $filepath = variable_get('user_picture_default', '');
        }
        if (isset($filepath)) {
            $alt = t("@user's picture", array('@user' => format_username($account)));
            // If the image does not have a valid Drupal scheme (for eg. HTTP),
            // don't load image styles.
            if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
                $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt, 'attributes' => array('class' => array('thumb img-rounded'))));
            }
            else {
                $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
            }
            if (!empty($account->uid) && user_access('access user profiles')) {
                $attributes = array(
                    'attributes' => array('title' => t('View user profile.')),
                    'html' => TRUE,
                );
                $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
            }
        }
    }

}

/**
 * @param $variables
 * @return string
 * theme_links()
 */
function md_alpine_links($variables) {
    $links = $variables['links'];
    $attributes = $variables['attributes'];
    $heading = $variables['heading'];
    global $language_url;
    $output = '';

    if (count($links) > 0) {
        $output = '';

        // Treat the heading first if it is present to prepend it to the
        // list of links.
        if (!empty($heading)) {
            if (is_string($heading)) {
                // Prepare the array that will be used when the passed heading
                // is a string.
                $heading = array(
                    'text' => $heading,
                    // Set the default level of the heading.
                    'level' => 'h2',
                );
            }
            $output .= '<' . $heading['level'];
            if (!empty($heading['class'])) {
                $output .= drupal_attributes(array('class' => $heading['class']));
            }
            $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
        }

        $output .= '<ul' . drupal_attributes($attributes) . '>';

        $num_links = count($links);
        $i = 1;

        foreach ($links as $key => $link) {
            $class = array($key);

            // Add first, last and active classes to the list of links to help out themers.
            if ($i == 1) {
                $class[] = 'first';
            }
            if ($i == $num_links) {
                $class[] = 'last';
            }
            if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
                && (empty($link['language']) || $link['language']->language == $language_url->language)) {
                $class[] = 'active';
            }
            $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

            if (isset($link['href'])) {
                // Pass in $link as $options, they share the same keys.
                $output .= l($link['title'], $link['href'], $link);
            }
            elseif (!empty($link['title'])) {
                // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
                if (empty($link['html'])) {
                    $link['title'] = check_plain($link['title']);
                }
                $span_attributes = '';
                if (isset($link['attributes'])) {
                    $span_attributes = drupal_attributes($link['attributes']);
                }
                $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
            }

            $i++;
            $output .= "</li>\n";
        }

        $output .= '</ul>';
    }

    return $output;
}
/**
 * Remove N/A options
 */
function md_alpine_form_element($variables) {
$element = $variables['element'];
  // Disable radio button N/A
  if ($element['#type'] == 'radio' && $element['#return_value'] === '_none') {
      $variables['element']['#attributes']['disabled'] = TRUE;
  }
  return theme_form_element($variables);
}
/**
 * Check file path upload in theme setting
 */
function md_alpine_theme_setting_check_path($path) {
    $path_scheme = file_uri_scheme($path);
    if ($path_scheme == 'public') {
        $return_path = file_create_url($path);
    } else if (($path_scheme == 'http') || ($path_scheme == 'https')) {
        $return_path = $path;
    } else {
        $return_path = file_create_url(file_build_uri($path));
    }
    return $return_path;
}

/**
 * Display the simple view of rows one after another
 */
function md_alpine_preprocess_views_view_unformatted(&$vars) {
  $view = $vars['view'];
  $rows = $vars['rows'];
  $result = $vars['view']->result;
  $style = $view->style_plugin;
  $options = $style->options;

  $vars['classes_array'] = array();
  $vars['classes'] = array();
  $vars['mentor_ids'] = array();
  $vars['mentee_ids'] = array();
  $default_row_class = isset($options['default_row_class']) ? $options['default_row_class'] : FALSE;
  $row_class_special = isset($options['row_class_special']) ? $options['row_class_special'] : FALSE;
  // Set up striping values.
  $count = 0;
  $max = count($rows);
  foreach ($rows as $id => $row) {
    $count++;
    if ($default_row_class) {
      $vars['classes'][$id][] = 'views-row';
      $vars['classes'][$id][] = 'views-row-' . $count;
    }
    if ($row_class_special) {
      $vars['classes'][$id][] = 'views-row-' . ($count % 2 ? 'odd' : 'even');
      if ($count == 1) {
        $vars['classes'][$id][] = 'views-row-first';
      }
      if ($count == $max) {
        $vars['classes'][$id][] = 'views-row-last';
      }
    }

    if ($row_class = $view->style_plugin->get_row_class($id)) {
      $vars['classes'][$id][] = $row_class;
    }

    // Flatten the classes to a string for each row for the template file.
    $vars['classes_array'][$id] = isset($vars['classes'][$id]) ? implode(' ', $vars['classes'][$id]) : '';

    // Mentor ids.
    $vars['mentor_ids'][$id] = $result[$id]->users_name;
    // Mentee ids.
    $vars['mentee_ids'][$id] = $result[$id]->users_name;
  }
}
